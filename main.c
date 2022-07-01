#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int n=0, ex=0, r=0, sr=0, usr=0, lr=0, legend=0, newlegend=0;

void load() //로드 함수
{
    FILE* fp;
    fp = fopen("cha.txt", "r");  // txt파일을 r(읽기) 모드로 열기

    fscanf(fp,"%d\n",&n);
    fscanf(fp,"%d\n",&ex);
    fscanf(fp,"%d\n",&r);
    fscanf(fp,"%d\n",&sr);
    fscanf(fp,"%d\n",&usr);
    fscanf(fp,"%d\n",&lr);
    fscanf(fp,"%d\n",&legend);
    fscanf(fp,"%d\n",&newlegend);

    fclose(fp); //파일 포인터 닫기
    return;
}

void selectcharacter()
{
    int a, b;

    a = rand() % 1000 + 1;

    if(a<=100) // 10%
    {
        b = rand() % n + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        printf("노말");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf(" : %d\n", b);
    }
    else if(a<=300) // 20%
    {
        b = rand() % ex + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        printf("EX");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf(" : %d\n", b);
    }
    else if(a<=600) // 30%
    {
        b = rand() % r + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        printf("레어");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf(" : %d\n", b);
    }
    else if(a<=800) // 20%
    {
        b = rand() % sr + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("슈퍼 레어");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf(" : %d\n", b);
    }
    else if(a<=950) // 15%
    {
        b = rand() % usr + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        printf("올트라 슈퍼 레어");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf(" : %d\n", b);
    }
    else if(a<=1000) // 5%
    {
        b = rand() % lr + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        printf("레전드 레어");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf(" : %d\n", b);
    }
}

void selectstage()
{
    int a, b, c, d;

    a = rand() % 1000 + 1;

    d = rand() % 1000 + 1;

    if(a<=700 || newlegend==0)
    {
        b = rand() % legend + 1;
        if(b<=20 || b==48) c = rand() % 8 + 1;
        else if(b==49) c = 1;
        else c = rand() % 6 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        printf("구레전드 ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("%d장 %d스테이지 %d성\n", b, c, d<=500?1:d<=800?2:3);
    }
    else
    {
        b = rand() % newlegend + 1;
        if(b==1) c = 1;
        else c = rand() % 6 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("신레전드 ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("%d장 %d스테이지 %d성\n", a%legend, b, c<=500?1:c<=800?2:3);
    }
}

int main()
{
    int key;
    srand(GetTickCount64());

    load();
    printf("냥코 랜덤 챌린지\n\n캐릭터를 뽑으실려면 c, 스테이지를 뽑을실려면 s를 입력하세요.\n(이외의 명령어는 무시되며, 동시 입력은 하지 마세요.)\n종료 하실때는 q를 입력 하세요.\n\n");

    while(1)
    {
        if(kbhit());
        {
            key=getch();
            if(key==99) selectcharacter();
            else if(key==115) selectstage();
            else if(key==113) return 0;
        }
    }
}
