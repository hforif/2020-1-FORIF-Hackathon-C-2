#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#pragma warning(disable:4996)

#define Cambo "C:\\Users\\rjsgn\\Documents\\īī���� ���� ����\\Cambo-04-Heart_goes_Boom_Boom.wav"


/*
   /\__/\
  (  ' v '  )
  (         )
   |   |   |
   (__)__)
*/

int key;
int day = 1;
int subscriber = 0;
int money = 50;
int fee = 0;
int profit = 0;
int equipLV = 0;

typedef struct {
    char name[21]; // �̸�
    int pay;        //�ϴ�
    int views;     //���� ��ȸ��
    int hired;      //��뿩��(0:���x, 1 : ���o)
}editor;

typedef struct v {
    int view;
    char name[50];
    int adv;//���� ����
}video;

typedef struct vl {
    int length;
    video VL[100];
}VideoList;

editor ed[2] = { { "�褷��",100,10000,0 },  { "�̤���",200,50000,0} };


#define LEFT 75
#define RIGHT 77 
#define ENTER 13
#define UP 72
#define DOWN 80


void gotoxy(int x, int y, const char* s) {
    COORD pos = { 2 * x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", s);
}

void title();
char Day1choice();

void DrawMain1(char major, VideoList* one);
void DrawMain2(char major, VideoList* one);
void DrawMain3(char major, VideoList* one);

void Upload(VideoList* x);
void ListofVideo(VideoList* x);
void BuyEquip();
void ListofVideo();

void Success1();//1�� �޼�
void Success2();//10�� �޼�
void Ending();

void Today(char major);


void Streaming(int subscriber, char major);
void Hire(int subscriber, char major);
void Together(int subscriber, char major);
void FanMeeting();
void Sponsor();
void event();

int main(void) {
    //title();
    PlaySound(TEXT(Cambo), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    VideoList* one = (VideoList*)malloc(sizeof(VideoList));
    one->length = 0;
    char major = 'a';//�ʱ�ȭ
    major = Day1choice();
    day++;
    system("cls");
    while (subscriber < 10000) { //stage 1
        DrawMain1(major, one);
        Today(major);
        day++;
    }
    system("cls");
    Success1();
    system("cls");
    while (subscriber < 100000) {//stage 2
        DrawMain2(major, one);
        Today(major);
        day++;
    }

    system("cls");
    Success2();
    system("cls");
    while (subscriber < 100000) {//stage 2
        DrawMain3(major, one);
        Today(major);
        day++;
    }

    system("cls");
    Ending();
    return 0;
}

void title() {
    gotoxy(10, 8, "������ �������� ������ �ʹ� �ɽ����� �����̴� ��Ʃ�긦 �����غ����� �Ѵ�!");
    Sleep(2000);
    gotoxy(13, 9, "������ �����̴� ��Ʃ�꿡 ���ؼ� �ƴ� ���� ���� ���٤Ф�");
    Sleep(1500);
    gotoxy(15, 10, "�����̸� ���ͼ� 100�� ��Ʃ���� �Ǿ� ����!");
    Sleep(1000);
    gotoxy(18, 12, "�����̸� �����ֽðڽ��ϱ�???");
    while (1) {
        int key = 0;
        if (_kbhit()) {
            key = _getch();
            if (key == ENTER)
                break;
        }
        gotoxy(23, 13, "YES");
        Sleep(400);
        gotoxy(23, 13, "   ");
        Sleep(400);
    }//end of while
    system("cls");
    gotoxy(10, 7, "   /\\__/\\");
    gotoxy(10, 8, "  ( ' v ' )");
    gotoxy(10, 9, "  (       )");
    gotoxy(10, 10, "  |   |   |");
    gotoxy(10, 11, "   (__)__)");
    Sleep(500);
    system("cls");
    gotoxy(12, 7, "   /\\__/\\");
    gotoxy(12, 8, "  ( ' v ' )");
    gotoxy(12, 9, "  (       )");
    gotoxy(12, 10, "  |   |   |");
    gotoxy(12, 11, "   (__)__)");
    Sleep(500);
    system("cls");
    gotoxy(14, 7, "   /\\__/\\");
    gotoxy(14, 8, "  ( ' v ' )");
    gotoxy(14, 9, "  (       )");
    gotoxy(14, 10, "  |   |   |");
    gotoxy(14, 11, "   (__)__)");
    gotoxy(0, 13, "---------------------------------------------------------------");
    gotoxy(0, 14, "���� �����༭ ����!!");
    Sleep(4000);
    system("cls");
}

void DrawMain1(char major, VideoList* one) {
    while (1) {
        gotoxy(0, 7, "   /\\__/\\");
        gotoxy(0, 8, "  ( ' v ' )");
        gotoxy(0, 9, "  (       )");
        gotoxy(0, 10, "  |   |   |");
        gotoxy(0, 11, "   (__)__)");
        gotoxy(20, 12, "������ ");
        printf("%d���� ", subscriber);
        switch (major) {
        case 'g':
            printf("���� ");
            break;
        case 'c':
            printf("�丮 ");
            break;
        case 'e':
            printf("�Թ� ");
            break;
        case 'v':
            printf("���̷α� ");
            break;
        }
        printf("��Ʃ��");
        gotoxy(0, 13, "---------------------------------------------------------------");
        gotoxy(0, 14, "������ ������ �ұ�??");
        gotoxy(25, 14, "$");
        printf("%d", money);
        gotoxy(30, 14, "DAY");
        printf("%d", day);

        gotoxy(0, 16, "����ø���");
        gotoxy(10, 16, "������ ����");
        gotoxy(20, 16, "������ ����");
        int choice = 1;
        int lastchoice = 0;
        while (1) {
            key = 100;
            if (_kbhit()) {
                do {
                    key = _getch();
                } while (key == 224);
            }
            switch (key) {
            case LEFT:
                if (choice == 1)
                    break;
                else {
                    choice--;
                    break;
                }
            case RIGHT:
                if (choice == 3)
                    break;
                else {
                    choice++;
                    break;
                }
            case ENTER: {
                lastchoice = choice;
                choice = 100;
                break;
            }
            default:
                break;
            }
            if (choice == 1) {
                gotoxy(0, 16, "           ");
                Sleep(400);
                gotoxy(0, 16, "���� �ø���");
                Sleep(400);
            }
            else if (choice == 2) {
                gotoxy(10, 16, "             ");
                Sleep(400);
                gotoxy(10, 16, "������ ����");
                Sleep(400);
            }
            else if (choice == 3) {
                gotoxy(20, 16, "             ");
                Sleep(400);
                gotoxy(20, 16, "������ ����");
                Sleep(400);
            }
            else
                break;//out of while
        }

        if (lastchoice == 1) {
            Upload(one);
            break;
        }
        else if (lastchoice == 2)
            BuyEquip();
        else if (lastchoice == 3) {
            ListofVideo(one);
        }
    }
}

void DrawMain2(char major, VideoList* one) {
    while (1) {
        switch (major) {
        case 'g':
            gotoxy(0, 7, "       /\\__/\\          G");
            gotoxy(0, 8, "  |   ( ' v ' )   |    A");
            gotoxy(0, 9, "  ����(       )����    M");
            gotoxy(0, 10, "     |   |   |         E");
            gotoxy(0, 11, "      (__)__)       ");
            gotoxy(20, 12, "������ ");
            printf("%d���� ", subscriber);
            printf("���� ��Ʃ�� ");
            break;
        case 'c':
            gotoxy(0, 7, "     /\\__/\\      C");
            gotoxy(0, 8, "    ( ' v ' )    O");
            gotoxy(0, 9, "  ��(       )/   O");
            gotoxy(0, 10, "    |   |   |    K");
            gotoxy(0, 11, "     (__)__)");
            gotoxy(20, 12, "������ ");
            printf("%d���� ", subscriber);
            printf("�丮 ��Ʃ�� ");
            break;
        case 'e':
            gotoxy(0, 7, "   /\\__/\\       E");
            gotoxy(0, 8, "  ( ' �� ' )    A");
            gotoxy(0, 9, "  (       )     T");
            gotoxy(0, 10, "  |   |   |");
            gotoxy(0, 11, "   (__)__)");
            gotoxy(20, 12, "������ ");
            printf("%d���� ", subscriber);
            printf("�Թ� ��Ʃ�� ");
            break;
        case 'v':
            gotoxy(0, 7, "   /\\__/\\      V");
            gotoxy(0, 8, "  ( > v < )    L");
            gotoxy(0, 9, "  (       )    O");
            gotoxy(0, 10, "  |   |   |    G");
            gotoxy(0, 11, "   (__)__)");
            gotoxy(20, 12, "������ ");
            printf("%d���� ", subscriber);
            printf("���̷α� ��Ʃ�� ");
            break;
        }
        gotoxy(0, 13, "---------------------------------------------------------------");
        gotoxy(0, 14, "������ ������ �ұ�??");
        gotoxy(13, 14, "����: $");
        printf("%d", money);   //���Կ� ���� ������ �ٲ���մϴ�.
        gotoxy(18, 14, "����: $");
        printf("%d", money);   //���⿡ ���� ������ �ٲ���մϴ�
        gotoxy(23, 14, "���� ��: $");
        printf("%d", money);  //���� ���� ���� ������ �ٲ���մϴ�.
        gotoxy(30, 14, "DAY");
        printf("%d", day);

        gotoxy(0, 16, "����ø���");
        gotoxy(10, 16, "������ ����");
        gotoxy(20, 16, "������ ����");
        gotoxy(0, 19, "�ǽð� ��Ʈ����");
        gotoxy(10, 19, "������ ���");
        gotoxy(20, 19, "���� ����ֱ�");
        gotoxy(0, 22, " �չ�");
        int choice = 1;
        int lastchoice = 0;
        while (1) {
            key = 100;
            if (_kbhit()) {
                do {
                    key = _getch();
                } while (key == 224);
            }
            switch (key) {
            case LEFT:
                if ((choice == 1) || (choice == 4) || (choice == 7))
                    break;
                else {
                    choice--;
                    break;
                }
            case RIGHT:
                if ((choice == 3) || (choice == 6) || (choice == 7))
                    break;
                else {
                    choice++;
                    break;
                }
            case UP:
                if ((choice == 1) || (choice == 2) || (choice == 3))
                    break;
                else {
                    choice -= 3;
                    break;
                }
            case DOWN:
                if ((choice == 5) || (choice == 6) || (choice == 7))
                    break;
                else {
                    choice += 3;
                    break;
                }
            case ENTER: {
                lastchoice = choice;
                choice = 100;
                break;
            }
            default:
                break;
            }
            if (choice == 1) {
                gotoxy(0, 16, "           ");
                Sleep(400);
                gotoxy(0, 16, "���� �ø���");
                Sleep(400);
            }
            else if (choice == 2) {
                gotoxy(10, 16, "             ");
                Sleep(400);
                gotoxy(10, 16, "������ ����");
                Sleep(400);
            }
            else if (choice == 3) {
                gotoxy(20, 16, "             ");
                Sleep(400);
                gotoxy(20, 16, "������ ����");
                Sleep(400);
            }
            else if (choice == 4) {
                gotoxy(30, 16, "               ");
                Sleep(400);
                gotoxy(30, 16, "�ǽð� ��Ʈ����");
                Sleep(400);
            }
            else if (choice == 5) {
                gotoxy(0, 19, "           ");
                Sleep(400);
                gotoxy(0, 19, "������ ���");
                Sleep(400);
            }
            else if (choice == 6) {
                gotoxy(10, 19, "               ");
                Sleep(400);
                gotoxy(10, 19, "���� ����ֱ�");
                Sleep(400);
            }
            else if (choice == 7) {
                gotoxy(20, 19, "    ");
                Sleep(400);
                gotoxy(20, 19, "�չ�");
                Sleep(400);
            }
            else
                break;//out of while
        }

        if (lastchoice == 1) {
            Upload(one);
            break;
        }
        else if (lastchoice == 2) {
            BuyEquip();
            break;
        }
        else if (lastchoice == 3) {
            ListofVideo(one);
            break;
        }
        else if (lastchoice == 4) {
            Streaming(subscriber, major);  //�ǽð� ��Ʈ���� �Լ�
            break;
        }
        else if (lastchoice == 5) {
            Hire(subscriber, major);    //������ ��� �Լ�
            break;
        }
        else if (lastchoice == 6) {
            break;
        }
        else if (lastchoice == 7) {
            Together(subscriber, major); //�չ� �Լ�
            break;
        }
    }
}

void DrawMain3(char major, VideoList* one) {
    while (1) {
        switch (major) {
        case 'g':
            gotoxy(0, 7, "       /\\__/\\          G");
            gotoxy(0, 8, "  |   ( ' v ' )   |    A");
            gotoxy(0, 9, "  ����(       )����    M");
            gotoxy(0, 10, "     |   |   |         E");
            gotoxy(0, 11, "      (__)__)       ");
            gotoxy(20, 12, "������ ");
            printf("%d���� ", subscriber);
            printf("���� ��Ʃ�� ");
            break;
        case 'c':
            gotoxy(0, 7, "     /\\__/\\      C");
            gotoxy(0, 8, "    ( ' v ' )    O");
            gotoxy(0, 9, "  ��(       )/   O");
            gotoxy(0, 10, "    |   |   |    K");
            gotoxy(0, 11, "     (__)__)");
            gotoxy(20, 12, "������ ");
            printf("%d���� ", subscriber);
            printf("�丮 ��Ʃ�� ");
            break;
        case 'e':
            gotoxy(0, 7, "   /\\__/\\       E");
            gotoxy(0, 8, "  ( ' �� ' )    A");
            gotoxy(0, 9, "  (       )     T");
            gotoxy(0, 10, "  |   |   |");
            gotoxy(0, 11, "   (__)__)");
            gotoxy(20, 12, "������ ");
            printf("%d���� ", subscriber);
            printf("�Թ� ��Ʃ�� ");
            break;
        case 'v':
            gotoxy(0, 7, "   /\\__/\\      V");
            gotoxy(0, 8, "  ( > v < )    L");
            gotoxy(0, 9, "  (       )    O");
            gotoxy(0, 10, "  |   |   |    G");
            gotoxy(0, 11, "   (__)__)");
            gotoxy(20, 12, "������ ");
            printf("%d���� ", subscriber);
            printf("���̷α� ��Ʃ�� ");
            break;
        }
        gotoxy(0, 13, "---------------------------------------------------------------");
        gotoxy(0, 14, "������ ������ �ұ�??");
        gotoxy(13, 14, "����: $");
        printf("%d", money);  //������ ��Ÿ���� ������ ���ľ���
        gotoxy(18, 14, "����: $");
        printf("%d", money);  //������ ��Ÿ���� ������ ���ľ���
        gotoxy(23, 14, "���� ��: $");
        printf("%d", money);  //���� ���� ��Ÿ���� ������ ���ľ���
        gotoxy(30, 14, "DAY");
        printf("%d", day);

        gotoxy(0, 16, "����ø���");
        gotoxy(10, 16, "������ ����");
        gotoxy(20, 16, "������ ����");
        gotoxy(0, 19, "�ǽð� ��Ʈ����");
        gotoxy(10, 19, "������ ���");
        gotoxy(20, 19, "���� ����ֱ�");
        gotoxy(0, 22, "�չ�");
        gotoxy(10, 22, "�ҹ���");
        gotoxy(20, 22, "�����ޱ�");

        int choice = 1;
        int lastchoice = 0;
        while (1) {
            key = 100;
            if (_kbhit()) {
                do {
                    key = _getch();
                } while (key == 224);
            }
            switch (key) {
            case LEFT:
                if ((choice == 1) || (choice == 4) || (choice == 7))
                    break;
                else {
                    choice--;
                    break;
                }
            case RIGHT:
                if ((choice == 3) || (choice == 6) || (choice == 9))
                    break;
                else {
                    choice++;
                    break;
                }
            case UP:
                if ((choice == 1) || (choice == 2) || (choice == 3))
                    break;
                else {
                    choice -= 3;
                    break;
                }
            case DOWN:
                if ((choice == 7) || (choice == 8) || (choice == 9))
                    break;
                else {
                    choice += 3;
                    break;
                }
            case ENTER: {
                lastchoice = choice;
                choice = 100;
                break;
            }
            default:
                break;
            }
            if (choice == 1) {
                gotoxy(0, 16, "           ");
                Sleep(400);
                gotoxy(0, 16, "���� �ø���");
                Sleep(400);
            }
            else if (choice == 2) {
                gotoxy(10, 16, "             ");
                Sleep(400);
                gotoxy(10, 16, "������ ����");
                Sleep(400);
            }
            else if (choice == 3) {
                gotoxy(20, 16, "             ");
                Sleep(400);
                gotoxy(20, 16, "������ ����");
                Sleep(400);
            }
            else if (choice == 4) {
                gotoxy(0, 19, "               ");
                Sleep(400);
                gotoxy(0, 19, "�ǽð� ��Ʈ����");
                Sleep(400);
            }
            else if (choice == 5) {
                gotoxy(10, 19, "           ");
                Sleep(400);
                gotoxy(10, 19, "������ ���");
                Sleep(400);
            }
            else if (choice == 6) {
                gotoxy(20, 19, "               ");
                Sleep(400);
                gotoxy(20, 19, "���� ����ֱ�");
                Sleep(400);
            }
            else if (choice == 7) {
                gotoxy(0, 22, "    ");
                Sleep(400);
                gotoxy(0, 22, "�չ�");
                Sleep(400);
            }
            else if (choice == 8) {
                gotoxy(10, 22, "      ");
                Sleep(400);
                gotoxy(10, 22, "�ҹ���");
                Sleep(400);
            }
            else if (choice == 9) {
                gotoxy(20, 22, "        ");
                Sleep(400);
                gotoxy(20, 22, "�����ޱ�");
                Sleep(400);
            }
            else
                break;//out of while
        }

        if (lastchoice == 1) {
            Upload(one);
            break;
        }
        else if (lastchoice == 2) {
            BuyEquip();
            break;
        }
        else if (lastchoice == 3) {
            ListofVideo(one);
            break;
        }
        else if (lastchoice == 4) {
            Streaming(subscriber, major);  //�ǽð� ��Ʈ���� �Լ�
            break;
        }
        else if (lastchoice == 5) {
            Hire(subscriber, major);    //������ ��� �Լ�
            break;
        }
        else if (lastchoice == 6) {
            //Ad(one); //���� ����ֱ� �Լ�
            break;
        }
        else if (lastchoice == 7) {
            Together(subscriber, major); //�չ� �Լ�
            break;
        }
        else if (lastchoice == 8) {
            FanMeeting();    //�ҹ��� �Լ�
            break;
        }
        else if (lastchoice == 9) {
            Sponsor();    //���� �Լ�
            break;
        }
    }
}

char Day1choice() {
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    gotoxy(20, 12, "������ ");
    printf("%d���� ", subscriber);
    printf("��Ʃ��");
    gotoxy(0, 13, "---------------------------------------------------------------");
    gotoxy(0, 14, "������ ù���̴ϱ� ���� �о߸� �����غ���!");
    gotoxy(25, 14, "DAY");
    printf("%d", day);
    gotoxy(0, 16, "����");
    gotoxy(10, 16, "�丮");
    gotoxy(20, 16, "�Թ�");
    gotoxy(30, 16, "���̷α�");
    int choice = 1;
    int lastchoice = 0;
    while (1) {
        key = 100;
        if (_kbhit()) {
            do {
                key = _getch();
            } while (key == 224);
        }
        switch (key) {
        case LEFT:
            if (choice == 1)
                break;
            else {
                choice--;
                break;
            }
        case RIGHT:
            if (choice == 4)
                break;
            else {
                choice++;
                break;
            }
        case ENTER: {
            lastchoice = choice;
            choice = 100;
            break;
        }
        default:
            break;
        }
        if (choice == 1) {
            gotoxy(0, 16, "     ");
            Sleep(400);
            gotoxy(0, 16, "����");
            Sleep(400);
        }
        else if (choice == 2) {
            gotoxy(10, 16, "     ");
            Sleep(400);
            gotoxy(10, 16, "�丮");
            Sleep(400);
        }
        else if (choice == 3) {
            gotoxy(20, 16, "      ");
            Sleep(400);
            gotoxy(20, 16, "�Թ�");
            Sleep(400);
        }
        else if (choice == 4) {
            gotoxy(30, 16, "         ");
            Sleep(400);
            gotoxy(30, 16, "���̷α�");
            Sleep(400);
        }
        else
            break;//out of while
    }

    if (lastchoice == 1)
        return 'g';//game
    else if (lastchoice == 2)
        return 'c';//cooking
    else if (lastchoice == 3)
        return 'e';//eating
    else if (lastchoice == 4)
        return 'v';//vlog

}

void Upload(VideoList* x) {
    system("cls");
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    gotoxy(0, 13, "---------------------------------------------------------------\n");
    char str[50];
    printf("����: ");
    getchar();
    scanf(" %s", str);
    strcpy(x->VL[x->length].name, str);
    srand(time(NULL));
    int num = rand() % 1000;
    subscriber += num + 1000;
    x->VL[x->length].view = See_Video();//������ ������ �����ּ���!
    printf("��ȸ��: %d", x->VL[x->length]);
    Sleep(500);
    x->length += 1;
}

void ListofVideo(VideoList* x) {
    printf("\n���� ���\n");
    for (int i = 0; i < (x->length); i++) {
        printf("����: %s  ��ȸ��: %d\n", x->VL[i].name, x->VL[i].view);
    }
}

/*
void Ad(VideoList* x)
{
    int adnum = 0;
    char Searchname[50];
    ListofVideo(x);

    for (int i = 0; i < (x->length); i++)
    {
        printf("To add an advertisement, type the specific name of a video\n");
        printf("If you do not want to add an advertisement, just press enter\n");
        scanf_s("%s", Searchname, sizeof(Searchname));
        if (Searchname == 'NULL')
            break;

        if (Searchname == x->VL[i].name)
        {
            x->VL[i].adv = 1;
        }
    }

    for (int i = 0; i < (x->length); i++)
    {
        if ((x->VL[i].adv) == 1)
            adnum++;
    }

    if (adnum > ((x->length) / 2))
    {
        subscriber *= 0.9;
    }

}*/

void BuyEquip() {
    char response1, response2;

    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    gotoxy(50, 7, "   /\\__/\\");
    gotoxy(50, 8, "  ( ' v ' )");
    gotoxy(50, 9, "  (       )");
    gotoxy(50, 10, "  |   |   |");
    gotoxy(50, 11, "   (__)__)");
    gotoxy(12, 6, "��� ��� ���� �Ǵ� ���׷��̵� �Ͻðڽ��ϱ�?  Y(y) / N(n)  ");
    scanf_s("%c", &response1);

    if ((response1 == 'N') || (response1 == 'n'))
    {
        return;
    }

    else
    {
        system("cls");
        gotoxy(0, 7, "   /\\__/\\");
        gotoxy(0, 8, "  ( ' v ' )");
        gotoxy(0, 9, "  (       )");
        gotoxy(0, 10, "  |   |   |");
        gotoxy(0, 11, "   (__)__)");
        gotoxy(50, 7, "   /\\__/\\");
        gotoxy(50, 8, "  ( ' v ' )");
        gotoxy(50, 9, "  (       )");
        gotoxy(50, 10, "  |   |   |");
        gotoxy(50, 11, "   (__)__)");
        if (equipLV == 0)
        {
            gotoxy(14, 6, "��� �����ϱ� ���ؼ��� $200�� �ʿ��մϴ�.\n");
            gotoxy(17, 10, "�׷��� �Ͻðڽ��ϱ�? Y(y) / N(n)  ");
            scanf_s("%c ", &response2);

            if ((response2 == 'N') || (response2 == 'n'))
            {
                return;
            }

            else
            {
                system("cls");
                if (money > 200)
                {
                    gotoxy(17, 6, "��� �����߽��ϴ� (��� LV 1)");
                    fee += 200;
                    printf("\n\n                                        ���� �ڱ� : %d\n\n", money);
                    equipLV++;
                    system("pause");
                    system("cls");
                }

                else
                {
                    gotoxy(20, 6, "�ڱ��� �����մϴ�!");
                    return;
                }
            }
        }

        else if (equipLV == 1)
        {
            gotoxy(14, 6, "��� �����ϱ� ���ؼ��� $600�� �ʿ��մϴ�.\n");
            gotoxy(17, 10, "�׷��� �Ͻðڽ��ϱ�? Y(y) / N(n)  ");
            scanf_s(" %c ", &response2);

            if ((response2 == 'N') || (response2 == 'n'))
            {
                return;
            }

            else
            {
                system("cls");
                if (money > 600)
                {
                    gotoxy(17, 6, "��� �����߽��ϴ� (��� LV 2)");
                    fee += 600;
                    printf("\n\n                                        ���� �ڱ� : %d\n\n", money);
                    equipLV++;
                    system("pause");
                }

                else
                {
                    gotoxy(20, 6, "�ڱ��� �����մϴ�!");
                    return;
                }
            }
        }

        else if (equipLV == 2)
        {
            gotoxy(14, 6, "��� �����ϱ� ���ؼ��� $1200�� �ʿ��մϴ�.\n");
            gotoxy(17, 10, "�׷��� �Ͻðڽ��ϱ�? Y(y) / N(n)  ");
            scanf_s("%c ", &response2);

            if ((response2 == 'N') || (response2 == 'n'))
            {
                return;
            }

            else
            {
                system("cls");
                if (money > 1200)
                {
                    gotoxy(17, 6, "��� �����߽��ϴ� (��� LV 3)");
                    fee += 1200;
                    printf("\n\n                                        ���� �ڱ� : %d\n\n", money);

                    equipLV++;
                    system("pause");
                }

                else
                {
                    gotoxy(20, 6, "�ڱ��� �����մϴ�!");
                    return;
                }
            }
        }
    }


}


void Success1() {
    system("cls");
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    Sleep(500);
    system("cls");
    gotoxy(0, 7, "      /\\__/\\");
    gotoxy(0, 8, "     / ' v ' /");
    gotoxy(0, 9, "    /       /");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    Sleep(500);
    system("cls");
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");

    gotoxy(0, 15, "�����մϴ�! �����ڼ� ������ �޼��߽��ϴ�.");
}

void Success2() {
    system("cls");
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, " o ( ' v ' ) o");
    gotoxy(0, 9, "  /(       )/");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    Sleep(500);
    system("cls");
    gotoxy(0, 7, "  -------------");
    gotoxy(0, 8, "  I            I");
    gotoxy(0, 9, "  I   YOUTUBE  I");
    gotoxy(0, 10, " I            I");
    gotoxy(0, 11, " ------------- ");
    Sleep(500);
    system("cls");
    gotoxy(0, 7, "         ");
    gotoxy(0, 8, "         ");
    gotoxy(0, 9, "      _  ");
    gotoxy(0, 10, "     V ");
    gotoxy(0, 11, "    /  ");
    Sleep(300);
    system("cls");
    gotoxy(0, 7, "          ");
    gotoxy(0, 8, "   *  / *  ");
    gotoxy(0, 9, "     *_   ");
    gotoxy(0, 10, "     V ");
    gotoxy(0, 11, "    /  ");
    Sleep(300);
    system("cls");
    gotoxy(0, 7, "  * O  o *  ");
    gotoxy(0, 8, "   *  / *  ");
    gotoxy(0, 9, "     *_   ");
    gotoxy(0, 10, "     V ");
    gotoxy(0, 11, "    /  ");
    Sleep(2000);
    system("cls");
    gotoxy(0, 8, "�����ڼ� 10������ �޼��߽��ϴ�!");
    Sleep(4000);
    system("cls");
}

void Ending() {
    system("cls");
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    Sleep(500);
    system("cls");
    gotoxy(0, 7, "      /\\__/\\");
    gotoxy(0, 8, "     / ' v ' /");
    gotoxy(0, 9, "    /       /");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    Sleep(500);
    system("cls");
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    Sleep(500);
    system("cls");
    gotoxy(0, 7, "/\\__/\\");
    gotoxy(0, 8, " / ' v ' /");
    gotoxy(0, 9, "  /       /");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    Sleep(500);
    system("cls");
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    Sleep(500);
    gotoxy(0, 15, "Mission Complete!");

}

void Today(char major) {//GI YONG
    while (1) {
        gotoxy(0, 7, "   /\\__/\\");
        gotoxy(0, 8, "  ( ' v ' )");
        gotoxy(0, 9, "  (       )");
        gotoxy(0, 10, "  |   |   |");
        gotoxy(0, 11, "   (__)__)");
        gotoxy(20, 12, "������ ");
        printf("%d���� ", subscriber);
        switch (major) {
        case 'g':
            printf("���� ");
            break;
        case 'c':
            printf("�丮 ");
            break;
        case 'e':
            printf("�Թ� ");
            break;
        case 'v':
            printf("���̷α� ");
            break;
        }
        printf("��Ʃ��");
        gotoxy(0, 13, "---------------------------------------------------------------");
        gotoxy(25, 14, "$");
        printf("%d", money);
        gotoxy(30, 14, "DAY");
        printf("%d", day);

        profit += See_Video() * 1;
        gotoxy(0, 16, "���� ���ǥ�Դϴ�!!!");
        gotoxy(0, 17, "������ ����: ");
        printf("%d��", profit);

        gotoxy(0, 18, "������ ����:");
        printf("$ %d", fee);
        //
        money += profit + fee;
        gotoxy(0, 20, "������ �հ�:");
        printf("$ %d", money);

        fee = 0;
        profit = 0;
        gotoxy(0, 22, "ENTER�� �����ø� �������� �Ѿ�ϴ�.");

        int choice = 1;
        int lastchoice = 0;
        while (1) {
            key = 100;
            if (_kbhit()) {
                do {
                    key = _getch();
                } while (key == 224);
            }
            switch (key) {
            case LEFT:
                if (choice == 1)
                    break;
                else {
                    choice--;
                    break;
                }
            case RIGHT:
                if (choice == 1)
                    break;
                else {
                    choice++;
                    break;
                }
            case ENTER: {
                Sleep(400);
                lastchoice = choice;
                choice = 100;
                break;
            }
            default:
                break;
            }
            if (choice == 1) {
                gotoxy(0, 22, "                                     ");
                Sleep(400);
                gotoxy(0, 22, "ENTER�� �����ø� �������� �Ѿ�ϴ�.");
                Sleep(400);
            }

            else
                break;//out of while
        }

        if (lastchoice == 1) {
            system("cls");
            return;
        }
    }
}




void Together(int subscriber, char major) {  //�չ�(������,�о�)
    char choice;
    int viewers;
    srand((unsigned int)time(NULL));
    if (subscriber < 10000)viewers = (int)(subscriber * 0.1 + rand() % 500 + 1);
    else if (subscriber < 100000)viewers = (int)(subscriber * 0.15 + rand() % 5000 + 1);
    else viewers = (int)(subscriber * 0.2 + rand() % 50000 + 1);
    switch (major) {  //������,�о߿� ���� ������ ������ �ٸ�
    case 'g':         //�չ��� ��û��, �չ� �� ������ ������ �� ���� ǥ��
        if (10000 < subscriber < 100000) {
            system("cls");
            gotoxy(10, 10, "���� ��Ʃ�� ��α� �Բ��� �չ� ���Ǹ� ���½��ϴ�!!");
            gotoxy(10, 11, "�չ��� �����Ͻðڽ��ϱ�?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "�չ��� �����մϴ�!");
                system("cls");
                gotoxy(10, 8, "������ /\\ _ /\\");
                gotoxy(10, 9, "��������' v ')");
                gotoxy(10, 10, "���� ������  \\");
                gotoxy(10, 11, "����/���� /��������/");
                gotoxy(10, 12, "__(__=��/     ��  /____");
                gotoxy(10, 13, "|���� ��/�ߣߣߣ�/��   |");
                gotoxy(10, 14, "|������                |");
                gotoxy(10, 15, "��û�� �� : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "�����ڰ� �����߽��ϴ�!! ���� ������ ��: ");
                subscriber += rand() % (subscriber / 10);
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "�չ��� �������� �ʾҽ��ϴ�.(���ңࡣ)");
            }
        }
        if (100000 < subscriber) {
            system("cls");
            gotoxy(10, 10, "���� ��Ʃ�� ����Ʈ �Բ��� �չ� ���Ǹ� ���½��ϴ�!!");
            gotoxy(10, 11, "�չ��� �����Ͻðڽ��ϱ�?");
            if (choice == 'Y') {
                gotoxy(10, 12, "�չ��� �����մϴ�!");
                system("cls");
                gotoxy(10, 8, "������ /\\ _ /\\");
                gotoxy(10, 9, "��������' v ')");
                gotoxy(10, 10, "���� ������  \\");
                gotoxy(10, 11, "����/���� /��������/");
                gotoxy(10, 12, "__(__=��/     ��  /____");
                gotoxy(10, 13, "|���� ��/�ߣߣߣ�/��   |");
                gotoxy(10, 14, "|������                |");
                gotoxy(10, 15, "��û�� �� : ");
                printf("%d\n", viewers);
                gotoxy(10, 16, "�����ڰ� �����߽��ϴ�!! ���� ������ ��: ");
                subscriber += rand() % (subscriber / 10);
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "�չ��� �������� �ʾҽ��ϴ�.(���ңࡣ)");
            }
        }
        break;
    case 'c':
        if (10000 < subscriber < 100000) {
            system("cls");
            gotoxy(10, 10, "�丮 ��Ʃ�� �¿� �ƺ� �Բ��� �չ� ���Ǹ� ���½��ϴ�!!");
            gotoxy(10, 11, "�չ��� �����Ͻðڽ��ϱ�?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "�չ��� �����մϴ�!");
                system("cls");
                gotoxy(10, 5, "        _....._");
                gotoxy(10, 6, "     .'   ^   '.");
                gotoxy(10, 7, "    /           \\");
                gotoxy(10, 8, "    |`'--...--'`|");
                gotoxy(10, 9, "     \\   ooo   /        /\\ _/\\");
                gotoxy(10, 10, "      '._____.'         (' v ')");
                gotoxy(10, 11, "        / | \\          �� ��_ `��");
                gotoxy(10, 12, "       /.-|-.\\         ~\\ �� )");
                gotoxy(10, 13, "      /'._|_.'\\          ) J J");
                gotoxy(10, 14, "     /    |    \\          �� ��");
                gotoxy(10, 15, "��û�� �� : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "�����ڰ� �����߽��ϴ�!! ���� ������ ��: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "�չ��� �������� �ʾҽ��ϴ�.(���ңࡣ)");
            }
        }
        if (100000 < subscriber) {
            system("cls");
            gotoxy(10, 10, "�丮 ��Ʃ�� SOF �Բ��� �չ� ���Ǹ� ���½��ϴ�!!");
            gotoxy(10, 11, "�չ��� �����Ͻðڽ��ϱ�?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "�չ��� �����մϴ�!");
                system("cls");
                gotoxy(10, 5, "        _....._");
                gotoxy(10, 6, "     .'   ^   '.");
                gotoxy(10, 7, "    /           \\");
                gotoxy(10, 8, "    |`'--...--'`|");
                gotoxy(10, 9, "     \\   ooo   /        /\\ _/\\");
                gotoxy(10, 10, "      '._____.'         (' v ')");
                gotoxy(10, 11, "        / | \\          �� ��_ `��");
                gotoxy(10, 12, "       /.-|-.\\         ~\\ �� )");
                gotoxy(10, 13, "      /'._|_.'\\          ) J J");
                gotoxy(10, 14, "     /    |    \\          �� ��");
                gotoxy(10, 15, "��û�� �� : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "�����ڰ� �����߽��ϴ�!! ���� ������ ��: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "�չ��� �������� �ʾҽ��ϴ�.(���ңࡣ)");
            }
        }
        break;
    case 'e':
        if (10000 < subscriber < 100000) {
            system("cls");
            gotoxy(10, 10, "�Թ� ��Ʃ�� ��� �Բ��� �չ� ���Ǹ� ���½��ϴ�!!");
            gotoxy(10, 11, "�չ��� �����Ͻðڽ��ϱ�?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "�չ��� �����մϴ�!");
                system("cls");
                gotoxy(10, 8, "����  /\\ _ /\\ ��");
                gotoxy(10, 9, "���� ��' v '����");
                gotoxy(10, 10, "���� /������ \\");
                gotoxy(10, 11, "����/���� 0oOo \\");
                gotoxy(10, 12, "��_(__=��(||||\\_\\_____");
                gotoxy(10, 13, "|����     ||||        |");
                gotoxy(10, 14, "|����     `\"\"'        |");
                gotoxy(10, 15, "��û�� �� : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "�����ڰ� �����߽��ϴ�!! ���� ������ ��: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "�չ��� �������� �ʾҽ��ϴ�.(���ңࡣ)");
            }
        }
        if (100000 < subscriber) {
            system("cls");
            gotoxy(10, 10, "�Թ� ��Ʃ�� ������ �Բ��� �չ� ���Ǹ� ���½��ϴ�!!");
            gotoxy(10, 11, "�չ��� �����Ͻðڽ��ϱ�?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "�չ��� �����մϴ�!");
                system("cls");
                gotoxy(10, 8, "����  /\\ _ /\\ ��");
                gotoxy(10, 9, "���� ��' v '����");
                gotoxy(10, 10, "���� /������ \\");
                gotoxy(10, 11, "����/���� 0oOo \\");
                gotoxy(10, 12, "��_(__=��(||||\\_\\_____");
                gotoxy(10, 13, "|����     ||||        |");
                gotoxy(10, 14, "|����     `\"\"'        |");
                gotoxy(10, 15, "��û�� �� : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "�����ڰ� �����߽��ϴ�!! ���� ������ ��: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "�չ��� �������� �ʾҽ��ϴ�.(���ңࡣ)");
            }
        }
        break;
    case'v':
        if (10000 < subscriber < 100000) {
            system("cls");
            gotoxy(10, 10, "���̷α� ��Ʃ�� ���� �Բ��� �չ� ���Ǹ� ���½��ϴ�!!");
            gotoxy(10, 11, "�չ��� �����Ͻðڽ��ϱ�?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "�չ��� �����մϴ�!");
                system("cls");
                gotoxy(10, 8, "��������  /\\_/\\");
                gotoxy(10, 9, "������ ��(' v ')��-,");
                gotoxy(10, 10, "���� ����/����/_/��|");
                gotoxy(10, 11, "���� L /��\\��L����|");
                gotoxy(10, 12, " ��������ө��������|");
                gotoxy(10, 13, " ���ߣߣߣߣߣߣ� ||");
                gotoxy(10, 14, "||����������-|");
                gotoxy(10, 15, "��û�� �� : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "�����ڰ� �����߽��ϴ�!! ���� ������ ��: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "�չ��� �������� �ʾҽ��ϴ�.(���ңࡣ)");
            }
        }
        if (100000 < subscriber) {
            system("cls");
            gotoxy(10, 10, "���̷α� ��Ʃ�� �µ� �Բ��� �չ� ���Ǹ� ���½��ϴ�!!");
            gotoxy(10, 11, "�չ��� �����Ͻðڽ��ϱ�?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "�չ��� �����մϴ�!");
                system("cls");
                gotoxy(10, 8, "��������  /\\_/\\");
                gotoxy(10, 9, "������ ��(' v ')��-,");
                gotoxy(10, 10, "���� ����/����/_/��|");
                gotoxy(10, 11, "���� L /��\\��L����|");
                gotoxy(10, 12, " ��������ө��������|");
                gotoxy(10, 13, " ���ߣߣߣߣߣߣ� ||");
                gotoxy(10, 14, "||����������-|");
                gotoxy(10, 15, "��û�� �� : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "�����ڰ� �����߽��ϴ�!! ���� ������ ��: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "�չ��� �������� �ʾҽ��ϴ�.(���ңࡣ)");
            }
            break;
        }
    }
}

void FanMeeting() {
    subscriber += 500;
    money -= 1000;
}

void Sponsor() {
    if ((subscriber > 100000) && (subscriber < 300000)) {
        profit += 100;
    }
    else if ((subscriber > 300000) && (subscriber < 500000)) {
        money += 150;
    }
    else if ((subscriber > 500000) && (subscriber < 700000)) {
        money += 200;
    }
    else if ((subscriber > 700000) && (subscriber < 1000000))
        money += 500;
}

void event() {
    srand((unsigned int)time(NULL));
    int percenta = rand() % 101;
    if (percenta < 2)
    {
        printf("����� �߻��ؼ� �����ڰ� �����Ͽ����ϴ�.\n");
        int reduce = rand() % subscriber / 10;
        subscriber -= reduce;
    }

    int percentc = rand() % 101;
    if (percentc < 15)
    {
        int famous;
        int yorn;
        printf("�ٸ� ��Ʃ���� �չ��� �����մϴ�.\n");
        printf("���Ǹ� �����Ϸ��� 1��, �����Ϸ��� 2���� ��������.\n");
        scanf_s("%d", &yorn);
        switch (yorn)
        {
        case 1:
            if (subscriber < 10000)
            {
                famous = rand() % 101;
                if (famous < 5)
                {
                    printf("1��� ��Ʃ������ ���ǰ� �Խ��ϴ�. �����ڰ� ���� �����մϴ�. \n");//������ ������ �����ؼ� �����
                    subscriber += subscriber / 10;
                }
                else if (famous < 20)
                {
                    printf("2��� ��Ʃ������ ���ǰ� �Խ��ϴ�. �����ڰ� ������� �����մϴ�. \n");
                    subscriber += subscriber / 20;
                }
                else if (famous < 50)
                {
                    printf("3��� ��Ʃ������ ���ǰ� �Խ��ϴ�. �����ڰ� ���� �����մϴ�. \n");
                    subscriber += subscriber / 30;
                }
                else
                {
                    printf("4��� ��Ʃ������ ���ǰ� �Խ��ϴ�. ��ſ� �ð��� ��������! \n");
                }
            }
            else if (subscriber < 100000)
            {
                famous = rand() % 101;
                if (famous < 20)
                {
                    printf("1��� ��Ʃ������ ���ǰ� �Խ��ϴ�. �����ڰ� ���� �����մϴ�. \n");//������ ������ �����ؼ� �����
                    subscriber += subscriber / 10;
                }
                else if (famous < 60)
                {
                    printf("2��� ��Ʃ������ ���ǰ� �Խ��ϴ�. �����ڰ� ������� �����մϴ�. \n");
                    subscriber += subscriber / 20;
                }
                else if (famous < 90)
                {
                    printf("3��� ��Ʃ������ ���ǰ� �Խ��ϴ�. �����ڰ� ���� �����մϴ�. \n");
                    subscriber += subscriber / 30;
                }
                else
                {
                    printf("4��� ��Ʃ������ ���ǰ� �Խ��ϴ�. ��ſ� �ð��� ��������! \n");
                }
            }
            else
            {
                famous = rand() % 101;
                if (famous < 50)
                {
                    printf("1��� ��Ʃ������ ���ǰ� �Խ��ϴ�. �����ڰ� ���� �����մϴ�. \n");//������ ������ �����ؼ� �����
                    subscriber += subscriber / 5;
                }
                else if (famous < 80)
                {
                    printf("2��� ��Ʃ������ ���ǰ� �Խ��ϴ�. �����ڰ� ������� �����մϴ�. \n");
                    subscriber += subscriber / 10;
                }
                else if (famous < 95)
                {
                    printf("3��� ��Ʃ������ ���ǰ� �Խ��ϴ�. �����ڰ� ���� �����մϴ�. \n");
                    subscriber += subscriber / 15;
                }
                else
                {
                    printf("4��� ��Ʃ������ ���ǰ� �Խ��ϴ�. ��ſ� �ð��� ��������! \n");
                }
            }
            break;

        default:
            printf("���Ǹ� �����Ͽ����ϴ�.\n");
        }


    }
}

void Streaming(int subscriber, char major) {  //������,�о�
    int viewers;
    srand((unsigned int)time(NULL));  //���� �Լ� �õ�
    if (subscriber < 10000)viewers = (int)(subscriber * 0.05 + rand() % 500 + 1);
    else if (subscriber < 100000)viewers = (int)(subscriber * 0.1 + rand() % 5000 + 1);
    else viewers = (int)(subscriber * 0.15 + rand() % 50000 + 1);  //�����ڿ� ���� ��û�ڼ��� �ٸ�
    switch (major) {
    case 'g':
        system("cls");
        gotoxy(10, 8, "������ /\\ _ /\\");
        gotoxy(10, 9, "��������' v ')");
        gotoxy(10, 10, "���� ������  \\");
        gotoxy(10, 11, "����/���� /��������/");
        gotoxy(10, 12, "__(__=��/     ��  /____");
        gotoxy(10, 13, "|���� ��/�ߣߣߣ�/��   |");
        gotoxy(10, 14, "|������                |");
        gotoxy(10, 15, "��û�� �� : ");
        printf("%d\n", viewers);
        break;
    case 'c':
        system("cls");
        gotoxy(10, 5, "        _....._");
        gotoxy(10, 6, "     .'   ^   '.");
        gotoxy(10, 7, "    /           \\");
        gotoxy(10, 8, "    |`'--...--'`|");
        gotoxy(10, 9, "     \\   ooo   /        /\\ _/\\");
        gotoxy(10, 10, "      '._____.'         (' v ')");
        gotoxy(10, 11, "        / | \\          �� ��_ `��");
        gotoxy(10, 12, "       /.-|-.\\         ~\\ �� )");
        gotoxy(10, 13, "      /'._|_.'\\          ) J J");
        gotoxy(10, 14, "     /    |    \\          �� ��");
        gotoxy(10, 15, "��û�� �� : ");
        printf("%d\n", viewers);
        break;
    case 'e':
        system("cls");
        gotoxy(10, 8, "����  /\\ _ /\\ ��");
        gotoxy(10, 9, "���� ��' v '����");
        gotoxy(10, 10, "���� /������ \\");
        gotoxy(10, 11, "����/���� 0oOo \\");
        gotoxy(10, 12, "��_(__=��(||||\\_\\_____");
        gotoxy(10, 13, "|����     ||||        |");
        gotoxy(10, 14, "|����     `\"\"'        |");
        gotoxy(10, 15, "��û�� �� : ");
        printf("%d\n", viewers);
        break;
    case 'v':
        gotoxy(10, 8, "��������  /\\_/\\");
        gotoxy(10, 9, "������ ��(' v ')��-,");
        gotoxy(10, 10, "���� ����/����/_/��|");
        gotoxy(10, 11, "���� L /��\\��L����|");
        gotoxy(10, 12, " ��������ө��������|");
        gotoxy(10, 13, " ���ߣߣߣߣߣߣ� ||");
        gotoxy(10, 14, "||����������-|");
        gotoxy(10, 15, "��û�� �� : ");
        printf("%d\n", viewers);
        break;
    }
}

void showinfo(editor* ptr) {
    //������ �����͸� �޾Ƽ� ������ ����ϴ� �Լ�
    gotoxy(10, 12, "�̸� : ");
    printf("%s", ptr->name);
    gotoxy(10, 13, "�ӱ� : $");
    printf("%d\n", ptr->pay);
    gotoxy(10, 14, "���� ��ȸ�� : ");
    printf("%d", ptr->views);
    printf(" ~ ");
    printf("%d", (ptr->views) * 2);
}

void Hire(int subscriber, char major) {  //�����ڸ� ����ϴ� �Լ�
    int key;
    system("cls");
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    gotoxy(20, 12, "������ ");
    printf("%d���� ", subscriber);
    switch (major) {
    case 'g':
        printf("���� ");
        break;
    case 'c':
        printf("�丮 ");
        break;
    case 'e':
        printf("�Թ� ");
        break;
    case 'v':
        printf("���̷α� ");
        break;
    }
    printf("��Ʃ��");
    gotoxy(0, 13, "---------------------------------------------------------------");
    gotoxy(0, 15, "�̸� : ");
    printf("%s", ed[0].name);
    gotoxy(0, 17, "�ӱ� : $");
    printf("%d\n", ed[0].pay);
    gotoxy(0, 19, "���� ��ȸ�� : ");
    printf("%d", ed[0].views);
    printf(" ~ ");
    printf("%d", (ed[0].views) * 2);

    gotoxy(0, 21, "�̸� : ");
    printf("%s", ed[1].name);
    gotoxy(0, 23, "�ӱ� : $");
    printf("%d\n", ed[1].pay);
    gotoxy(0, 25, "���� ��ȸ�� : ");
    printf("%d", ed[1].views);
    printf(" ~ ");
    printf("%d", (ed[1].views) * 2);
    int choice = 1;
    int lastchoice = 0;
    while (1) {
        key = 100;
        if (_kbhit()) {
            do {
                key = _getch();
            } while (key == 224);
        }
        switch (key) {
        case UP:
            if (choice == 1)
                break;
            else {
                choice--;
                break;
            }
        case DOWN:
            if (choice == 2)
                break;
            else {
                choice++;
                break;
            }
        case ENTER: {
            lastchoice = choice;
            choice = 100;
            break;
        }
        default:
            break;
        }
        if (choice == 1) {
            gotoxy(0, 16, "           ");
            gotoxy(0, 15, "�̸� : ");
            printf("%s", ed[0].name);
            gotoxy(0, 17, "�ӱ� : $");
            printf("%d\n", ed[0].pay);
            gotoxy(0, 19, "���� ��ȸ�� : ");
            printf("%d", ed[0].views);
            printf(" ~ ");
            printf("%d", (ed[0].views) * 2);
            Sleep(400);
        }
        else if (choice == 2) {
            gotoxy(0, 21, "�̸� : ");
            printf("%s", ed[1].name);
            gotoxy(0, 23, "�ӱ� : $");
            printf("%d\n", ed[1].pay);
            gotoxy(0, 25, "���� ��ȸ�� : ");
            printf("%d", ed[1].views);
            printf(" ~ ");
            printf("%d", (ed[1].views) * 2);
            Sleep(400);
        }
        if (lastchoice == 1) {
            if (ed[0].hired == 0)ed[0].hired = 1;
            else gotoxy(20, 19, "�̹� �����\n");
            system("cls");
            break;
        }
        else if (lastchoice == 2)
        {
            if (ed[1].hired == 0)ed[1].hired = 1;
            else gotoxy(20, 19, "�̹� �����\n");
            system("cls");
            break;
        }
    }
}

int See_Video() {
    //��ȸ�� : ������ ����o, ��� ��������, �����ڼ� ��
    int view;
    int total;
    for (int i = 0; i < 2; i++) {
        if (ed[i].hired == 0) {
            if (equipLV > 0) {
                total = subscriber * equipLV;
                if (subscriber < 10000) {
                    view = total;
                }
                else if (subscriber < 100000) {
                    view = total * 1.5;
                }
                else if (subscriber < 1000000) {
                    view = total * 2.0;
                }
            }
            else {
                total = subscriber;
                if (subscriber < 10000) {
                    view = total;
                }
                else if (subscriber < 100000) {
                    view = total * 1.5;
                }
                else if (subscriber < 1000000) {
                    view = total * 2;
                }
            }
        }
        else {
            total *= 2;
            view = total;
        }
    }
    return view;
}