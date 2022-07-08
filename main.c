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

    if(a<=850 || newlegend==0)
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
        printf("%d장 %d스테이지 %d성\n", b%newlegend+1, c, d<=500?1:d<=800?2:3);
    }
}

void selectmission()
{
    int a, b;
    a = rand() % 1000 + 1;

    if(a<=200) // 20% (6.6, 6.6, 6.6)
    {
        b = rand() % 3 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : %d단 진화 캐릭터만 사용\n", b);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=300) // 10%
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : 모든 유닛을 1회 이상 소환하기(클리어 조건)\n", b+500);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=400) // 10%
    {
        b = rand() % 2 +1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : %d번째 슬롯에 꼬맹이 고양이(1진) 포함\n", b==1?3:8);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=450) // 5%
    {
        b = rand() % 5000 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : %d원 이하의 캐릭터만 사용\n", b+500);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=500) // 5%
    {
        b = rand() % 2000 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : %d원 이상의 캐릭터만 사용\n", b);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=550) // 5%
    {
        b = rand() % 5 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : %d개 슬롯 비우기\n", b+3);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=600) // 5%
    {
        b = rand() % 2 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : %d페이지만 출진\n", b);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=700) // 10%
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : 물총포 사용\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=750) // 5%
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : 야옹컴 상시 사용\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=850) // 10%
    {
        b = rand() % 3 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : 지갑 레벨 %d레벨 이하 유지\n", b);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=950) // 10%
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : 제약 없음\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a<=999) // 4.9%
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : 미션 다중 수행(미션 2번 뽑기)\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(a==1000) // 0.1%
    {
        b = rand() % 2 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Mission : %c팀 패배\n", b==1?'A':'B');
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

void rankedmatch()
{
    int i, c=1, a=0, b=0;
    system("cls");
    printf("\n     -- Ranked Match -- \n\n");
    printf("랭크 모드에 입장하였습니다. 선택 후에는 아무키나 눌러주세요.\n\n");

    for(i=0; i<5; i++)
    {
        printf("3개중 1개를 선택하여 주세요. - A팀\n");
        printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
        for(int i=0; i<3; i++) selectcharacter();
        printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
        while(!getch()){}
        printf("3개중 1개를 선택하여 주세요. - B팀\n");
        printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
        for(int i=0; i<3; i++) selectcharacter();
        printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
        while(!getch()){}
        printf("3개중 1개를 선택하여 주세요. - B팀\n");
        printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
        for(int i=0; i<3; i++) selectcharacter();
        printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
        while(!getch()){}
        printf("3개중 1개를 선택하여 주세요. - A팀\n");
        printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
        for(int i=0; i<3; i++) selectcharacter();
        printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
        while(!getch()){}
    }

    system("cls");
    printf("\n     -- Ranked Match -- \n\n");
    printf("캐릭터가 모두 선정 되었습니다.\n\n");
    Sleep(1500);
    printf("대결을 시작합니다.");
    Sleep(2000);

    while(1)
    {
        system("cls");
        printf("\n     -- Ranked Match -- \n\n");

        if(a==2)
        {
            printf("          A팀 승리!");
            printf("\n\n         최종 스코어\n            A   B\n            %d   %d", a, b);
            while(!getch()){}
            return;
        }
        if(b==2)
        {
            printf("          B팀 승리!");
            printf("\n\n         최종 스코어\n            A   B\n            %d   %d", a, b);
            while(!getch()){}
            return;
        }
        printf("           ROUND %d\n\n",c);

        printf("스테이지 : ");
        selectstage();
        printf("\n");
        selectmission();
        printf("\n\n            스코어\n            A   B\n            %d   %d", a, b);

        while(1)
        {
            int key=getch();
            if(key=='a')
            {
                system("cls");
                printf("\n     -- Ranked Match -- \n\n");
                printf("         A팀 득점!");
                a++;
                while(!getch()){}
                break;
            }
            if(key=='b')
            {
                system("cls");
                printf("\n     -- Ranked Match -- \n\n");
                printf("         B팀 득점!");
                b++;
                while(!getch()){}
                break;
            }
            if(key=='=')
            {
                system("cls");
                printf("\n     -- Ranked Match -- \n\n");
                printf("           무승부!");
                while(!getch()){}
                break;
            }
        }
        c++;
    }
}

int main()
{
    int key;
    srand(GetTickCount64());

    load();

    B:

    system("cls");
    printf("냥코 랜덤 챌린지\n\n캐릭터를 뽑으실려면 c(1개) 혹은 d(3개중 택1)를 누르세요.\n스테이지를 뽑을실려면 s를 입력하세요.\n미션을 뽑으시려면 m을 입력하세요.\n랭크모드는 r을 입력하세요.\n\n(이외의 명령어는 무시되며, 동시 입력은 하지 마세요.)\n창을 비우시려면 l을 입력하세요.\n종료 하실때는 q를 입력 하세요.\n\n");

    while(1)
    {
        if(kbhit());
        {
            key=getch();
            if(key=='c') selectcharacter();
            else if(key=='d')
            {
                printf("3개중 1개를 선택하여 주세요.\n");
                printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
                for(int i=0; i<3; i++) selectcharacter();
                printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
            }
            else if(key=='s') selectstage();
            else if(key=='m') selectmission();
            else if(key=='r')
            {
                rankedmatch();
                goto B;
            }
            else if(key=='q') return 0;
            else if(key=='l') goto B;
        }
    }
}
