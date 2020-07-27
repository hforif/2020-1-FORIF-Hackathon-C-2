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

#define Cambo "C:\\Users\\rjsgn\\Documents\\카카오톡 받은 파일\\Cambo-04-Heart_goes_Boom_Boom.wav"


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
    char name[21]; // 이름
    int pay;        //일당
    int views;     //예상 조회수
    int hired;      //고용여부(0:고용x, 1 : 고용o)
}editor;

typedef struct v {
    int view;
    char name[50];
    int adv;//광고 여부
}video;

typedef struct vl {
    int length;
    video VL[100];
}VideoList;

editor ed[2] = { { "김ㅇㅇ",100,10000,0 },  { "이ㅇㅇ",200,50000,0} };


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

void Success1();//1만 달성
void Success2();//10만 달성
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
    char major = 'a';//초기화
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
    gotoxy(10, 8, "종강후 집에서만 지내서 너무 심심해진 집순이는 유튜브를 시작해보려고 한다!");
    Sleep(2000);
    gotoxy(13, 9, "하지만 집순이는 유튜브에 대해서 아는 것이 별로 없다ㅠㅠ");
    Sleep(1500);
    gotoxy(15, 10, "집순이를 도와서 100만 유튜버가 되어 보자!");
    Sleep(1000);
    gotoxy(18, 12, "집순이를 도와주시겠습니까???");
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
    gotoxy(0, 14, "나를 도와줘서 고마워!!");
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
        gotoxy(20, 12, "구독자 ");
        printf("%d명의 ", subscriber);
        switch (major) {
        case 'g':
            printf("게임 ");
            break;
        case 'c':
            printf("요리 ");
            break;
        case 'e':
            printf("먹방 ");
            break;
        case 'v':
            printf("브이로그 ");
            break;
        }
        printf("유튜버");
        gotoxy(0, 13, "---------------------------------------------------------------");
        gotoxy(0, 14, "오늘은 무엇을 할까??");
        gotoxy(25, 14, "$");
        printf("%d", money);
        gotoxy(30, 14, "DAY");
        printf("%d", day);

        gotoxy(0, 16, "영상올리기");
        gotoxy(10, 16, "방송장비 구매");
        gotoxy(20, 16, "영상목록 관리");
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
                gotoxy(0, 16, "영상 올리기");
                Sleep(400);
            }
            else if (choice == 2) {
                gotoxy(10, 16, "             ");
                Sleep(400);
                gotoxy(10, 16, "방송장비 구매");
                Sleep(400);
            }
            else if (choice == 3) {
                gotoxy(20, 16, "             ");
                Sleep(400);
                gotoxy(20, 16, "영상목록 관리");
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
            gotoxy(0, 9, "  ㅇㅇ(       )ㅇㅇ    M");
            gotoxy(0, 10, "     |   |   |         E");
            gotoxy(0, 11, "      (__)__)       ");
            gotoxy(20, 12, "구독자 ");
            printf("%d명의 ", subscriber);
            printf("게임 유튜버 ");
            break;
        case 'c':
            gotoxy(0, 7, "     /\\__/\\      C");
            gotoxy(0, 8, "    ( ' v ' )    O");
            gotoxy(0, 9, "  ＼(       )/   O");
            gotoxy(0, 10, "    |   |   |    K");
            gotoxy(0, 11, "     (__)__)");
            gotoxy(20, 12, "구독자 ");
            printf("%d명의 ", subscriber);
            printf("요리 유튜버 ");
            break;
        case 'e':
            gotoxy(0, 7, "   /\\__/\\       E");
            gotoxy(0, 8, "  ( ' ㅇ ' )    A");
            gotoxy(0, 9, "  (       )     T");
            gotoxy(0, 10, "  |   |   |");
            gotoxy(0, 11, "   (__)__)");
            gotoxy(20, 12, "구독자 ");
            printf("%d명의 ", subscriber);
            printf("먹방 유튜버 ");
            break;
        case 'v':
            gotoxy(0, 7, "   /\\__/\\      V");
            gotoxy(0, 8, "  ( > v < )    L");
            gotoxy(0, 9, "  (       )    O");
            gotoxy(0, 10, "  |   |   |    G");
            gotoxy(0, 11, "   (__)__)");
            gotoxy(20, 12, "구독자 ");
            printf("%d명의 ", subscriber);
            printf("브이로그 유튜버 ");
            break;
        }
        gotoxy(0, 13, "---------------------------------------------------------------");
        gotoxy(0, 14, "오늘은 무엇을 할까??");
        gotoxy(13, 14, "수입: $");
        printf("%d", money);   //수입에 대한 변수로 바꿔야합니다.
        gotoxy(18, 14, "지출: $");
        printf("%d", money);   //지출에 대한 변수로 바꿔야합니다
        gotoxy(23, 14, "남은 돈: $");
        printf("%d", money);  //남은 돈에 대한 변수로 바꿔야합니다.
        gotoxy(30, 14, "DAY");
        printf("%d", day);

        gotoxy(0, 16, "영상올리기");
        gotoxy(10, 16, "방송장비 구매");
        gotoxy(20, 16, "영상목록 관리");
        gotoxy(0, 19, "실시간 스트리밍");
        gotoxy(10, 19, "편집자 고용");
        gotoxy(20, 19, "영상에 광고넣기");
        gotoxy(0, 22, " 합방");
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
                gotoxy(0, 16, "영상 올리기");
                Sleep(400);
            }
            else if (choice == 2) {
                gotoxy(10, 16, "             ");
                Sleep(400);
                gotoxy(10, 16, "방송장비 구매");
                Sleep(400);
            }
            else if (choice == 3) {
                gotoxy(20, 16, "             ");
                Sleep(400);
                gotoxy(20, 16, "영상목록 관리");
                Sleep(400);
            }
            else if (choice == 4) {
                gotoxy(30, 16, "               ");
                Sleep(400);
                gotoxy(30, 16, "실시간 스트리밍");
                Sleep(400);
            }
            else if (choice == 5) {
                gotoxy(0, 19, "           ");
                Sleep(400);
                gotoxy(0, 19, "편집자 고용");
                Sleep(400);
            }
            else if (choice == 6) {
                gotoxy(10, 19, "               ");
                Sleep(400);
                gotoxy(10, 19, "영상에 광고넣기");
                Sleep(400);
            }
            else if (choice == 7) {
                gotoxy(20, 19, "    ");
                Sleep(400);
                gotoxy(20, 19, "합방");
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
            Streaming(subscriber, major);  //실시간 스트리밍 함수
            break;
        }
        else if (lastchoice == 5) {
            Hire(subscriber, major);    //편집자 고용 함수
            break;
        }
        else if (lastchoice == 6) {
            break;
        }
        else if (lastchoice == 7) {
            Together(subscriber, major); //합방 함수
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
            gotoxy(0, 9, "  ㅇㅇ(       )ㅇㅇ    M");
            gotoxy(0, 10, "     |   |   |         E");
            gotoxy(0, 11, "      (__)__)       ");
            gotoxy(20, 12, "구독자 ");
            printf("%d명의 ", subscriber);
            printf("게임 유튜버 ");
            break;
        case 'c':
            gotoxy(0, 7, "     /\\__/\\      C");
            gotoxy(0, 8, "    ( ' v ' )    O");
            gotoxy(0, 9, "  ＼(       )/   O");
            gotoxy(0, 10, "    |   |   |    K");
            gotoxy(0, 11, "     (__)__)");
            gotoxy(20, 12, "구독자 ");
            printf("%d명의 ", subscriber);
            printf("요리 유튜버 ");
            break;
        case 'e':
            gotoxy(0, 7, "   /\\__/\\       E");
            gotoxy(0, 8, "  ( ' ㅇ ' )    A");
            gotoxy(0, 9, "  (       )     T");
            gotoxy(0, 10, "  |   |   |");
            gotoxy(0, 11, "   (__)__)");
            gotoxy(20, 12, "구독자 ");
            printf("%d명의 ", subscriber);
            printf("먹방 유튜버 ");
            break;
        case 'v':
            gotoxy(0, 7, "   /\\__/\\      V");
            gotoxy(0, 8, "  ( > v < )    L");
            gotoxy(0, 9, "  (       )    O");
            gotoxy(0, 10, "  |   |   |    G");
            gotoxy(0, 11, "   (__)__)");
            gotoxy(20, 12, "구독자 ");
            printf("%d명의 ", subscriber);
            printf("브이로그 유튜버 ");
            break;
        }
        gotoxy(0, 13, "---------------------------------------------------------------");
        gotoxy(0, 14, "오늘은 무엇을 할까??");
        gotoxy(13, 14, "수입: $");
        printf("%d", money);  //수입을 나타내는 변수로 고쳐야함
        gotoxy(18, 14, "지출: $");
        printf("%d", money);  //지출을 나타내는 변수로 고쳐야함
        gotoxy(23, 14, "남은 돈: $");
        printf("%d", money);  //남은 돈을 나타내는 변수로 고쳐야함
        gotoxy(30, 14, "DAY");
        printf("%d", day);

        gotoxy(0, 16, "영상올리기");
        gotoxy(10, 16, "방송장비 구매");
        gotoxy(20, 16, "영상목록 관리");
        gotoxy(0, 19, "실시간 스트리밍");
        gotoxy(10, 19, "편집자 고용");
        gotoxy(20, 19, "영상에 광고넣기");
        gotoxy(0, 22, "합방");
        gotoxy(10, 22, "팬미팅");
        gotoxy(20, 22, "협찬받기");

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
                gotoxy(0, 16, "영상 올리기");
                Sleep(400);
            }
            else if (choice == 2) {
                gotoxy(10, 16, "             ");
                Sleep(400);
                gotoxy(10, 16, "방송장비 구매");
                Sleep(400);
            }
            else if (choice == 3) {
                gotoxy(20, 16, "             ");
                Sleep(400);
                gotoxy(20, 16, "영상목록 관리");
                Sleep(400);
            }
            else if (choice == 4) {
                gotoxy(0, 19, "               ");
                Sleep(400);
                gotoxy(0, 19, "실시간 스트리밍");
                Sleep(400);
            }
            else if (choice == 5) {
                gotoxy(10, 19, "           ");
                Sleep(400);
                gotoxy(10, 19, "편집자 고용");
                Sleep(400);
            }
            else if (choice == 6) {
                gotoxy(20, 19, "               ");
                Sleep(400);
                gotoxy(20, 19, "영상에 광고넣기");
                Sleep(400);
            }
            else if (choice == 7) {
                gotoxy(0, 22, "    ");
                Sleep(400);
                gotoxy(0, 22, "합방");
                Sleep(400);
            }
            else if (choice == 8) {
                gotoxy(10, 22, "      ");
                Sleep(400);
                gotoxy(10, 22, "팬미팅");
                Sleep(400);
            }
            else if (choice == 9) {
                gotoxy(20, 22, "        ");
                Sleep(400);
                gotoxy(20, 22, "협찬받기");
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
            Streaming(subscriber, major);  //실시간 스트리밍 함수
            break;
        }
        else if (lastchoice == 5) {
            Hire(subscriber, major);    //편집자 고용 함수
            break;
        }
        else if (lastchoice == 6) {
            //Ad(one); //영상에 광고넣기 함수
            break;
        }
        else if (lastchoice == 7) {
            Together(subscriber, major); //합방 함수
            break;
        }
        else if (lastchoice == 8) {
            FanMeeting();    //팬미팅 함수
            break;
        }
        else if (lastchoice == 9) {
            Sponsor();    //협찬 함수
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
    gotoxy(20, 12, "구독자 ");
    printf("%d명의 ", subscriber);
    printf("유튜버");
    gotoxy(0, 13, "---------------------------------------------------------------");
    gotoxy(0, 14, "오늘은 첫날이니까 집중 분야를 선택해보자!");
    gotoxy(25, 14, "DAY");
    printf("%d", day);
    gotoxy(0, 16, "게임");
    gotoxy(10, 16, "요리");
    gotoxy(20, 16, "먹방");
    gotoxy(30, 16, "브이로그");
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
            gotoxy(0, 16, "게임");
            Sleep(400);
        }
        else if (choice == 2) {
            gotoxy(10, 16, "     ");
            Sleep(400);
            gotoxy(10, 16, "요리");
            Sleep(400);
        }
        else if (choice == 3) {
            gotoxy(20, 16, "      ");
            Sleep(400);
            gotoxy(20, 16, "먹방");
            Sleep(400);
        }
        else if (choice == 4) {
            gotoxy(30, 16, "         ");
            Sleep(400);
            gotoxy(30, 16, "브이로그");
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
    printf("제목: ");
    getchar();
    scanf(" %s", str);
    strcpy(x->VL[x->length].name, str);
    srand(time(NULL));
    int num = rand() % 1000;
    subscriber += num + 1000;
    x->VL[x->length].view = See_Video();//적당한 값으로 정해주세요!
    printf("조회수: %d", x->VL[x->length]);
    Sleep(500);
    x->length += 1;
}

void ListofVideo(VideoList* x) {
    printf("\n영상 목록\n");
    for (int i = 0; i < (x->length); i++) {
        printf("제목: %s  조회수: %d\n", x->VL[i].name, x->VL[i].view);
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
    gotoxy(12, 6, "방송 장비를 구입 또는 업그레이드 하시겠습니까?  Y(y) / N(n)  ");
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
            gotoxy(14, 6, "장비를 구입하기 위해서는 $200이 필요합니다.\n");
            gotoxy(17, 10, "그래도 하시겠습니까? Y(y) / N(n)  ");
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
                    gotoxy(17, 6, "장비를 구입했습니다 (장비 LV 1)");
                    fee += 200;
                    printf("\n\n                                        남은 자금 : %d\n\n", money);
                    equipLV++;
                    system("pause");
                    system("cls");
                }

                else
                {
                    gotoxy(20, 6, "자금이 부족합니다!");
                    return;
                }
            }
        }

        else if (equipLV == 1)
        {
            gotoxy(14, 6, "장비를 구입하기 위해서는 $600이 필요합니다.\n");
            gotoxy(17, 10, "그래도 하시겠습니까? Y(y) / N(n)  ");
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
                    gotoxy(17, 6, "장비를 구입했습니다 (장비 LV 2)");
                    fee += 600;
                    printf("\n\n                                        남은 자금 : %d\n\n", money);
                    equipLV++;
                    system("pause");
                }

                else
                {
                    gotoxy(20, 6, "자금이 부족합니다!");
                    return;
                }
            }
        }

        else if (equipLV == 2)
        {
            gotoxy(14, 6, "장비를 구입하기 위해서는 $1200가 필요합니다.\n");
            gotoxy(17, 10, "그래도 하시겠습니까? Y(y) / N(n)  ");
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
                    gotoxy(17, 6, "장비를 구입했습니다 (장비 LV 3)");
                    fee += 1200;
                    printf("\n\n                                        남은 자금 : %d\n\n", money);

                    equipLV++;
                    system("pause");
                }

                else
                {
                    gotoxy(20, 6, "자금이 부족합니다!");
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

    gotoxy(0, 15, "감사합니다! 구독자수 만명을 달성했습니다.");
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
    gotoxy(0, 8, "구독자수 10만명을 달성했습니다!");
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
        gotoxy(20, 12, "구독자 ");
        printf("%d명의 ", subscriber);
        switch (major) {
        case 'g':
            printf("게임 ");
            break;
        case 'c':
            printf("요리 ");
            break;
        case 'e':
            printf("먹방 ");
            break;
        case 'v':
            printf("브이로그 ");
            break;
        }
        printf("유튜버");
        gotoxy(0, 13, "---------------------------------------------------------------");
        gotoxy(25, 14, "$");
        printf("%d", money);
        gotoxy(30, 14, "DAY");
        printf("%d", day);

        profit += See_Video() * 1;
        gotoxy(0, 16, "정산 통계표입니다!!!");
        gotoxy(0, 17, "오늘의 수입: ");
        printf("%d원", profit);

        gotoxy(0, 18, "오늘의 지출:");
        printf("$ %d", fee);
        //
        money += profit + fee;
        gotoxy(0, 20, "오늘의 합계:");
        printf("$ %d", money);

        fee = 0;
        profit = 0;
        gotoxy(0, 22, "ENTER를 누르시면 다음날로 넘어갑니다.");

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
                gotoxy(0, 22, "ENTER를 누르시면 다음날로 넘어갑니다.");
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




void Together(int subscriber, char major) {  //합방(구독자,분야)
    char choice;
    int viewers;
    srand((unsigned int)time(NULL));
    if (subscriber < 10000)viewers = (int)(subscriber * 0.1 + rand() % 500 + 1);
    else if (subscriber < 100000)viewers = (int)(subscriber * 0.15 + rand() % 5000 + 1);
    else viewers = (int)(subscriber * 0.2 + rand() % 50000 + 1);
    switch (major) {  //구독자,분야에 따라서 들어오는 제안이 다름
    case 'g':         //합방중 시청자, 합방 후 증가한 구독자 수 까지 표시
        if (10000 < subscriber < 100000) {
            system("cls");
            gotoxy(10, 10, "게임 유튜버 우왁굳 님께서 합방 제의를 보냈습니다!!");
            gotoxy(10, 11, "합방을 진행하시겠습니까?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "합방을 진행합니다!");
                system("cls");
                gotoxy(10, 8, "　　　 /\\ _ /\\");
                gotoxy(10, 9, "　　　（' v ')");
                gotoxy(10, 10, "　　 ／　　  \\");
                gotoxy(10, 11, "　　/　　 /￣￣￣￣/");
                gotoxy(10, 12, "__(__=つ/     　  /____");
                gotoxy(10, 13, "|　　 ＼/＿＿＿＿/　   |");
                gotoxy(10, 14, "|　　　                |");
                gotoxy(10, 15, "시청자 수 : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "구독자가 증가했습니다!! 현재 구독자 수: ");
                subscriber += rand() % (subscriber / 10);
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "합방을 진행하지 않았습니다.(´⌒｀。)");
            }
        }
        if (100000 < subscriber) {
            system("cls");
            gotoxy(10, 10, "게임 유튜버 감스트 님께서 합방 제의를 보냈습니다!!");
            gotoxy(10, 11, "합방을 진행하시겠습니까?");
            if (choice == 'Y') {
                gotoxy(10, 12, "합방을 진행합니다!");
                system("cls");
                gotoxy(10, 8, "　　　 /\\ _ /\\");
                gotoxy(10, 9, "　　　（' v ')");
                gotoxy(10, 10, "　　 ／　　  \\");
                gotoxy(10, 11, "　　/　　 /￣￣￣￣/");
                gotoxy(10, 12, "__(__=つ/     　  /____");
                gotoxy(10, 13, "|　　 ＼/＿＿＿＿/　   |");
                gotoxy(10, 14, "|　　　                |");
                gotoxy(10, 15, "시청자 수 : ");
                printf("%d\n", viewers);
                gotoxy(10, 16, "구독자가 증가했습니다!! 현재 구독자 수: ");
                subscriber += rand() % (subscriber / 10);
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "합방을 진행하지 않았습니다.(´⌒｀。)");
            }
        }
        break;
    case 'c':
        if (10000 < subscriber < 100000) {
            system("cls");
            gotoxy(10, 10, "요리 유튜버 승우 아빠 님께서 합방 제의를 보냈습니다!!");
            gotoxy(10, 11, "합방을 진행하시겠습니까?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "합방을 진행합니다!");
                system("cls");
                gotoxy(10, 5, "        _....._");
                gotoxy(10, 6, "     .'   ^   '.");
                gotoxy(10, 7, "    /           \\");
                gotoxy(10, 8, "    |`'--...--'`|");
                gotoxy(10, 9, "     \\   ooo   /        /\\ _/\\");
                gotoxy(10, 10, "      '._____.'         (' v ')");
                gotoxy(10, 11, "        / | \\          （ つ_ `つ");
                gotoxy(10, 12, "       /.-|-.\\         ~\\ 　 )");
                gotoxy(10, 13, "      /'._|_.'\\          ) J J");
                gotoxy(10, 14, "     /    |    \\          ∪ ∪");
                gotoxy(10, 15, "시청자 수 : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "구독자가 증가했습니다!! 현재 구독자 수: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "합방을 진행하지 않았습니다.(´⌒｀。)");
            }
        }
        if (100000 < subscriber) {
            system("cls");
            gotoxy(10, 10, "요리 유튜버 SOF 님께서 합방 제의를 보냈습니다!!");
            gotoxy(10, 11, "합방을 진행하시겠습니까?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "합방을 진행합니다!");
                system("cls");
                gotoxy(10, 5, "        _....._");
                gotoxy(10, 6, "     .'   ^   '.");
                gotoxy(10, 7, "    /           \\");
                gotoxy(10, 8, "    |`'--...--'`|");
                gotoxy(10, 9, "     \\   ooo   /        /\\ _/\\");
                gotoxy(10, 10, "      '._____.'         (' v ')");
                gotoxy(10, 11, "        / | \\          （ つ_ `つ");
                gotoxy(10, 12, "       /.-|-.\\         ~\\ 　 )");
                gotoxy(10, 13, "      /'._|_.'\\          ) J J");
                gotoxy(10, 14, "     /    |    \\          ∪ ∪");
                gotoxy(10, 15, "시청자 수 : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "구독자가 증가했습니다!! 현재 구독자 수: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "합방을 진행하지 않았습니다.(´⌒｀。)");
            }
        }
        break;
    case 'e':
        if (10000 < subscriber < 100000) {
            system("cls");
            gotoxy(10, 10, "먹방 유튜버 쯔양 님께서 합방 제의를 보냈습니다!!");
            gotoxy(10, 11, "합방을 진행하시겠습니까?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "합방을 진행합니다!");
                system("cls");
                gotoxy(10, 8, "　　  /\\ _ /\\ 　");
                gotoxy(10, 9, "　　 （' v '）　");
                gotoxy(10, 10, "　　 /　　　 \\");
                gotoxy(10, 11, "　　/　　 0oOo \\");
                gotoxy(10, 12, "＿_(__=つ(||||\\_\\_____");
                gotoxy(10, 13, "|　　     ||||        |");
                gotoxy(10, 14, "|　　     `\"\"'        |");
                gotoxy(10, 15, "시청자 수 : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "구독자가 증가했습니다!! 현재 구독자 수: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "합방을 진행하지 않았습니다.(´⌒｀。)");
            }
        }
        if (100000 < subscriber) {
            system("cls");
            gotoxy(10, 10, "먹방 유튜버 문복희 님께서 합방 제의를 보냈습니다!!");
            gotoxy(10, 11, "합방을 진행하시겠습니까?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "합방을 진행합니다!");
                system("cls");
                gotoxy(10, 8, "　　  /\\ _ /\\ 　");
                gotoxy(10, 9, "　　 （' v '）　");
                gotoxy(10, 10, "　　 /　　　 \\");
                gotoxy(10, 11, "　　/　　 0oOo \\");
                gotoxy(10, 12, "＿_(__=つ(||||\\_\\_____");
                gotoxy(10, 13, "|　　     ||||        |");
                gotoxy(10, 14, "|　　     `\"\"'        |");
                gotoxy(10, 15, "시청자 수 : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "구독자가 증가했습니다!! 현재 구독자 수: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "합방을 진행하지 않았습니다.(´⌒｀。)");
            }
        }
        break;
    case'v':
        if (10000 < subscriber < 100000) {
            system("cls");
            gotoxy(10, 10, "브이로그 유튜버 오눅 님께서 합방 제의를 보냈습니다!!");
            gotoxy(10, 11, "합방을 진행하시겠습니까?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "합방을 진행합니다!");
                system("cls");
                gotoxy(10, 8, "　　　　  /\\_/\\");
                gotoxy(10, 9, "　　　 ⊂(' v ')つ-,");
                gotoxy(10, 10, "　　 ／／/　　/_/　|");
                gotoxy(10, 11, "　　 L /⊂\\ノL｜／|");
                gotoxy(10, 12, " 　／￣￣旦￣￣￣／|");
                gotoxy(10, 13, " ／＿＿＿＿＿＿／ ||");
                gotoxy(10, 14, "||―――――-|");
                gotoxy(10, 15, "시청자 수 : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "구독자가 증가했습니다!! 현재 구독자 수: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "합방을 진행하지 않았습니다.(´⌒｀。)");
            }
        }
        if (100000 < subscriber) {
            system("cls");
            gotoxy(10, 10, "브이로그 유튜버 온도 님께서 합방 제의를 보냈습니다!!");
            gotoxy(10, 11, "합방을 진행하시겠습니까?");
            scanf("%c", &choice);
            if (choice == 'Y') {
                gotoxy(10, 12, "합방을 진행합니다!");
                system("cls");
                gotoxy(10, 8, "　　　　  /\\_/\\");
                gotoxy(10, 9, "　　　 ⊂(' v ')つ-,");
                gotoxy(10, 10, "　　 ／／/　　/_/　|");
                gotoxy(10, 11, "　　 L /⊂\\ノL｜／|");
                gotoxy(10, 12, " 　／￣￣旦￣￣￣／|");
                gotoxy(10, 13, " ／＿＿＿＿＿＿／ ||");
                gotoxy(10, 14, "||―――――-|");
                gotoxy(10, 15, "시청자 수 : ");
                printf("%d\n", viewers);
                subscriber += rand() % (subscriber / 10);
                gotoxy(10, 16, "구독자가 증가했습니다!! 현재 구독자 수: ");
                printf("%d\n", subscriber);
            }
            if (choice == 'N') {
                gotoxy(10, 12, "합방을 진행하지 않았습니다.(´⌒｀。)");
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
        printf("논란이 발생해서 구독자가 감소하였습니다.\n");
        int reduce = rand() % subscriber / 10;
        subscriber -= reduce;
    }

    int percentc = rand() % 101;
    if (percentc < 15)
    {
        int famous;
        int yorn;
        printf("다른 유튜버가 합방을 제의합니다.\n");
        printf("제의를 수락하려면 1번, 거절하려면 2번을 누르세요.\n");
        scanf_s("%d", &yorn);
        switch (yorn)
        {
        case 1:
            if (subscriber < 10000)
            {
                famous = rand() % 101;
                if (famous < 5)
                {
                    printf("1등급 유튜버에게 제의가 왔습니다. 구독자가 많이 증가합니다. \n");//구독자 증가폭 생각해서 써야함
                    subscriber += subscriber / 10;
                }
                else if (famous < 20)
                {
                    printf("2등급 유튜버에게 제의가 왔습니다. 구독자가 어느정도 증가합니다. \n");
                    subscriber += subscriber / 20;
                }
                else if (famous < 50)
                {
                    printf("3등급 유튜버에게 제의가 왔습니다. 구독자가 조금 증가합니다. \n");
                    subscriber += subscriber / 30;
                }
                else
                {
                    printf("4등급 유튜버에게 제의가 왔습니다. 즐거운 시간을 보내세요! \n");
                }
            }
            else if (subscriber < 100000)
            {
                famous = rand() % 101;
                if (famous < 20)
                {
                    printf("1등급 유튜버에게 제의가 왔습니다. 구독자가 많이 증가합니다. \n");//구독자 증가폭 생각해서 써야함
                    subscriber += subscriber / 10;
                }
                else if (famous < 60)
                {
                    printf("2등급 유튜버에게 제의가 왔습니다. 구독자가 어느정도 증가합니다. \n");
                    subscriber += subscriber / 20;
                }
                else if (famous < 90)
                {
                    printf("3등급 유튜버에게 제의가 왔습니다. 구독자가 조금 증가합니다. \n");
                    subscriber += subscriber / 30;
                }
                else
                {
                    printf("4등급 유튜버에게 제의가 왔습니다. 즐거운 시간을 보내세요! \n");
                }
            }
            else
            {
                famous = rand() % 101;
                if (famous < 50)
                {
                    printf("1등급 유튜버에게 제의가 왔습니다. 구독자가 많이 증가합니다. \n");//구독자 증가폭 생각해서 써야함
                    subscriber += subscriber / 5;
                }
                else if (famous < 80)
                {
                    printf("2등급 유튜버에게 제의가 왔습니다. 구독자가 어느정도 증가합니다. \n");
                    subscriber += subscriber / 10;
                }
                else if (famous < 95)
                {
                    printf("3등급 유튜버에게 제의가 왔습니다. 구독자가 조금 증가합니다. \n");
                    subscriber += subscriber / 15;
                }
                else
                {
                    printf("4등급 유튜버에게 제의가 왔습니다. 즐거운 시간을 보내세요! \n");
                }
            }
            break;

        default:
            printf("제의를 거절하였습니다.\n");
        }


    }
}

void Streaming(int subscriber, char major) {  //구독자,분야
    int viewers;
    srand((unsigned int)time(NULL));  //랜덤 함수 시드
    if (subscriber < 10000)viewers = (int)(subscriber * 0.05 + rand() % 500 + 1);
    else if (subscriber < 100000)viewers = (int)(subscriber * 0.1 + rand() % 5000 + 1);
    else viewers = (int)(subscriber * 0.15 + rand() % 50000 + 1);  //구독자에 따라 시청자수가 다름
    switch (major) {
    case 'g':
        system("cls");
        gotoxy(10, 8, "　　　 /\\ _ /\\");
        gotoxy(10, 9, "　　　（' v ')");
        gotoxy(10, 10, "　　 ／　　  \\");
        gotoxy(10, 11, "　　/　　 /￣￣￣￣/");
        gotoxy(10, 12, "__(__=つ/     　  /____");
        gotoxy(10, 13, "|　　 ＼/＿＿＿＿/　   |");
        gotoxy(10, 14, "|　　　                |");
        gotoxy(10, 15, "시청자 수 : ");
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
        gotoxy(10, 11, "        / | \\          （ つ_ `つ");
        gotoxy(10, 12, "       /.-|-.\\         ~\\ 　 )");
        gotoxy(10, 13, "      /'._|_.'\\          ) J J");
        gotoxy(10, 14, "     /    |    \\          ∪ ∪");
        gotoxy(10, 15, "시청자 수 : ");
        printf("%d\n", viewers);
        break;
    case 'e':
        system("cls");
        gotoxy(10, 8, "　　  /\\ _ /\\ 　");
        gotoxy(10, 9, "　　 （' v '）　");
        gotoxy(10, 10, "　　 /　　　 \\");
        gotoxy(10, 11, "　　/　　 0oOo \\");
        gotoxy(10, 12, "＿_(__=つ(||||\\_\\_____");
        gotoxy(10, 13, "|　　     ||||        |");
        gotoxy(10, 14, "|　　     `\"\"'        |");
        gotoxy(10, 15, "시청자 수 : ");
        printf("%d\n", viewers);
        break;
    case 'v':
        gotoxy(10, 8, "　　　　  /\\_/\\");
        gotoxy(10, 9, "　　　 ⊂(' v ')つ-,");
        gotoxy(10, 10, "　　 ／／/　　/_/　|");
        gotoxy(10, 11, "　　 L /⊂\\ノL｜／|");
        gotoxy(10, 12, " 　／￣￣旦￣￣￣／|");
        gotoxy(10, 13, " ／＿＿＿＿＿＿／ ||");
        gotoxy(10, 14, "||―――――-|");
        gotoxy(10, 15, "시청자 수 : ");
        printf("%d\n", viewers);
        break;
    }
}

void showinfo(editor* ptr) {
    //편집자 포인터를 받아서 정보를 출력하는 함수
    gotoxy(10, 12, "이름 : ");
    printf("%s", ptr->name);
    gotoxy(10, 13, "임금 : $");
    printf("%d\n", ptr->pay);
    gotoxy(10, 14, "예상 조회수 : ");
    printf("%d", ptr->views);
    printf(" ~ ");
    printf("%d", (ptr->views) * 2);
}

void Hire(int subscriber, char major) {  //편집자를 고용하는 함수
    int key;
    system("cls");
    gotoxy(0, 7, "   /\\__/\\");
    gotoxy(0, 8, "  ( ' v ' )");
    gotoxy(0, 9, "  (       )");
    gotoxy(0, 10, "  |   |   |");
    gotoxy(0, 11, "   (__)__)");
    gotoxy(20, 12, "구독자 ");
    printf("%d명의 ", subscriber);
    switch (major) {
    case 'g':
        printf("게임 ");
        break;
    case 'c':
        printf("요리 ");
        break;
    case 'e':
        printf("먹방 ");
        break;
    case 'v':
        printf("브이로그 ");
        break;
    }
    printf("유튜버");
    gotoxy(0, 13, "---------------------------------------------------------------");
    gotoxy(0, 15, "이름 : ");
    printf("%s", ed[0].name);
    gotoxy(0, 17, "임금 : $");
    printf("%d\n", ed[0].pay);
    gotoxy(0, 19, "예상 조회수 : ");
    printf("%d", ed[0].views);
    printf(" ~ ");
    printf("%d", (ed[0].views) * 2);

    gotoxy(0, 21, "이름 : ");
    printf("%s", ed[1].name);
    gotoxy(0, 23, "임금 : $");
    printf("%d\n", ed[1].pay);
    gotoxy(0, 25, "예상 조회수 : ");
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
            gotoxy(0, 15, "이름 : ");
            printf("%s", ed[0].name);
            gotoxy(0, 17, "임금 : $");
            printf("%d\n", ed[0].pay);
            gotoxy(0, 19, "예상 조회수 : ");
            printf("%d", ed[0].views);
            printf(" ~ ");
            printf("%d", (ed[0].views) * 2);
            Sleep(400);
        }
        else if (choice == 2) {
            gotoxy(0, 21, "이름 : ");
            printf("%s", ed[1].name);
            gotoxy(0, 23, "임금 : $");
            printf("%d\n", ed[1].pay);
            gotoxy(0, 25, "예상 조회수 : ");
            printf("%d", ed[1].views);
            printf(" ~ ");
            printf("%d", (ed[1].views) * 2);
            Sleep(400);
        }
        if (lastchoice == 1) {
            if (ed[0].hired == 0)ed[0].hired = 1;
            else gotoxy(20, 19, "이미 고용함\n");
            system("cls");
            break;
        }
        else if (lastchoice == 2)
        {
            if (ed[1].hired == 0)ed[1].hired = 1;
            else gotoxy(20, 19, "이미 고용함\n");
            system("cls");
            break;
        }
    }
}

int See_Video() {
    //조회수 : 편집자 참여o, 장비가 좋아지고, 구독자수 업
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