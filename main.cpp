#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <tuple>

using namespace std;

int n, ex, r, sr, usr, lr, legend, newlegend;
int ranked = 0;

vector<pair<string,int>> A;
vector<pair<string,int>> B;

vector<pair<string,int>> characterpool;
vector<tuple<string, int, int, int>> mappool;

void load() //로드 함수
{
    FILE* fp;
    fp = fopen("cha.txt","r");  // txt파일을 r(읽기) 모드로 열기

    fscanf(fp,"%d\n", &n);
    fscanf(fp,"%d\n", &ex);
    fscanf(fp,"%d\n", &r);
    fscanf(fp,"%d\n", &sr);
    fscanf(fp,"%d\n", &usr);
    fscanf(fp,"%d\n", &lr);
    fscanf(fp,"%d\n", &legend);
    fscanf(fp,"%d\n", &newlegend);

    fclose(fp); //파일 포인터 닫기
    return;
}

void textcolor(int colorNum) {
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

int CharacterNumbering(int b)
{
    int c = rand() % 100 + 1;
    if(c<=3)
    {
        cout << " : ";
        textcolor(11);
        cout << "Choice! \n";
        textcolor(7);
    }
    else cout << " : " << b << '\n';

    return b;
}

void selectcharacter()
{
    int a, b;

    characterpool.clear();
    for(int i=0; i<3; i++)
    {
        a = rand() % 1000 + 1;

        if(a<=100) // 10%
        {
            b = rand() % n + 1;

            textcolor(8);
            cout << "노말";
            textcolor(7);
            int num = CharacterNumbering(b);
            characterpool.push_back(make_pair("노말", num));
        }
        else if(a<=350) // 25%
        {
            b = rand() % ex + 1;
            textcolor(13);
            cout << "EX";
            textcolor(7);
            int num = CharacterNumbering(b);
            characterpool.push_back(make_pair("EX", num));
        }
        else if(a<=650) // 30%
        {
            b = rand() % r + 1;
            textcolor(6);
            cout << "레어";
            textcolor(7);
            int num = CharacterNumbering(b);
            characterpool.push_back(make_pair("레어", num));
        }
        else if(a<=850) // 20%
        {
            b = rand() % sr + 1;
            textcolor(15);
            cout << "슈퍼 레어";
            textcolor(7);
            int num = CharacterNumbering(b);
            characterpool.push_back(make_pair("슈퍼 레어", num));
        }
        else if(a<=975) // 12.5%
        {
            b = rand() % usr + 1;
            textcolor(14);
            cout << "올트라 슈퍼 레어";
            textcolor(7);
            int num = CharacterNumbering(b);
            characterpool.push_back(make_pair("올트라 슈퍼 레어", num));
        }
        else if(a<=1000) // 2.5%
        {
            b = rand() % lr + 1;
            textcolor(9);
            cout << "레전드 레어";
            textcolor(7);
            int num = CharacterNumbering(b);
            characterpool.push_back(make_pair("레전드 레어", num));
        }
    }
}

void selectstage()
{
    int a, b, c, d, star;

    a = rand() % 1000 + 1;
    d = rand() % 1000 + 1;

    if(d<=500) star=1;
    else if(d<=800) star=2;
    else star=3;

    if(a<=850 || newlegend==0)
    {
        b = rand() % legend + 1;
        if(b<=20 || b==48) c = rand() % 8 + 1;
        else if(b==49) c = 1; // 49장은 스테이지가 1개이다.
        else c = rand() % 6 + 1; // 21~47장은 스테이지가 6개이다.
        textcolor(6);
        cout << "구레전드 ";
        textcolor(7);

        cout << b << "장 " << c << "스테이지" << star << "성\n"; // 50% 1성, 30% 20성, 20% 3성.

        if(ranked==1) mappool.push_back({"구레전드", b, c, star});
    }
    else
    {
        b = rand() % newlegend + 1;
        if(b==1 || b==39 || b==49) c = 1; // 1장, 39장, 49장은 스테이지가 1개이다.
        else if(b==48) c = rand() % 8 + 1; // 48장은 스테이지가 8개이다.
        else c = rand() % 6 + 1;
        textcolor(10);
        cout << "신레전드 ";
        textcolor(7);
        cout << b << "장 " << c << "스테이지" << star << "성\n"; // 50% 1성, 30% 20성, 20% 3성.
        if(ranked==1) mappool.push_back({"신레전드", b, c, star});
    }
}

void selectmission()
{
    int a, b;
    a = rand() % 1000 + 1;

    if(a<=200) // 20% (6.6, 6.6, 6.6)
    {
        b = rand() % 3 + 1;
        textcolor(4);
        cout << "Mission : "<< b << "단 진화 캐릭터만 사용\n";
        textcolor(7);
    }
    else if(a<=300) // 10%
    {
        textcolor(4);
        cout << "Mission : 모든 유닛을 1회 이상 소환하기(승리 조건)\n";
        textcolor(7);
    }
    else if(a<=400) // 10%
    {
        b = rand() % 10 +1;

        textcolor(4);
        cout << "Mission : " << b << "번째 슬롯에 꼬맹이 고양이(1진) 포함\n";
        textcolor(7);
    }
    else if(a<=450) // 5%
    {
        b = rand() % 5000 + 1;
        b+=500;
        textcolor(4);
        cout << "Mission : " << b << "원 이하의 캐릭터만 사용\n";
        textcolor(7);
    }
    else if(a<=500) // 5%
    {
        b = rand() % 2000 + 500;
        textcolor(4);
        cout << "Mission : " << b << "원 이상의 캐릭터만 사용\n";
        textcolor(7);
    }
    else if(a<=550) // 5%
    {
        b = rand() % 5 + 1;
        b+=1;
        textcolor(4);
        cout << "Mission : " << b << "개 슬롯 비우기\n";
        textcolor(7);
    }
    else if(a<=600) // 5%
    {
        b = rand() % 2 + 1;
        textcolor(4);
        cout << "Mission : "<< b << "페이지만 출진\n";
        textcolor(7);
    }
    else if(a<=700) // 10%
    {
        textcolor(4);
        cout << "Mission : 물총포 사용\n";
        textcolor(7);
    }
    else if(a<=750) // 5%
    {
        textcolor(4);
        cout << "Mission : 야옹컴 상시 사용\n";
        textcolor(7);
    }
    else if(a<=800) // 10%
    {
        b = rand() % 3 + 1;
        textcolor(4);
        cout << "Mission : 지갑 레벨 " << b << "레벨 이하 유지\n";
        textcolor(7);
    }
    else if(a<=900) // 10%
    {
        textcolor(4);
        printf("Mission : 제약 없음\n");
        textcolor(7);
    }
    else if(a<=999) // 4.9%
    {
        textcolor(4);
        printf("Mission : 미션 다중 수행(미션 2번 뽑기)\n");
        textcolor(7);
        if(ranked==1){selectmission();selectmission();}
    }
    else if(a==1000) // 0.1%
    {
        b = rand() % 2 + 1;
        char team;
        if(b==1) team = 'A';
        else team = 'B';

        textcolor(4);
        cout << "Mission : " << team << "팀 패배\n";
        textcolor(7);
    }
}

void rankedmatch()
{
    A.clear();
    B.clear();
    mappool.clear();

    int i, c=1, a=0, b=0;
    ranked = 1;
    system("cls");
        cout << "\n               -- Ranked Match --               \n\n";
        cout << "랭크 모드에 입장하였습니다. 선택 후에는 아무키나 눌러주세요.\n\n";

    for(i=0; i<5; i++)
    {
        cout << "3개중 1개를 선택하여 주세요. - A팀\n";
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        selectcharacter();
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n";
        while(1){
            int num=getch();
            if(num=='1'){A.push_back(make_pair(characterpool[0].first, characterpool[0].second)); break;}
            if(num=='2'){A.push_back(make_pair(characterpool[1].first, characterpool[1].second)); break;}
            if(num=='3'){A.push_back(make_pair(characterpool[2].first, characterpool[2].second)); break;}
        }
        cout << "3개중 1개를 선택하여 주세요. - B팀\n";
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        selectcharacter();
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n";
        while(1){
            int num=getch();
            if(num=='1'){B.push_back(make_pair(characterpool[0].first, characterpool[0].second)); break;}
            if(num=='2'){B.push_back(make_pair(characterpool[1].first, characterpool[1].second)); break;}
            if(num=='3'){B.push_back(make_pair(characterpool[2].first, characterpool[2].second)); break;}
        }
        cout << "3개중 1개를 선택하여 주세요. - B팀\n";
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        selectcharacter();
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n";
        while(1){
            int num=getch();
            if(num=='1'){B.push_back(make_pair(characterpool[0].first, characterpool[0].second)); break;}
            if(num=='2'){B.push_back(make_pair(characterpool[1].first, characterpool[1].second)); break;}
            if(num=='3'){B.push_back(make_pair(characterpool[2].first, characterpool[2].second)); break;}
        }
        cout << "3개중 1개를 선택하여 주세요. - A팀\n";
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        selectcharacter();
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n";
        while(1){
            int num=getch();
            if(num=='1'){A.push_back(make_pair(characterpool[0].first, characterpool[0].second)); break;}
            if(num=='2'){A.push_back(make_pair(characterpool[1].first, characterpool[1].second)); break;}
            if(num=='3'){A.push_back(make_pair(characterpool[2].first, characterpool[2].second)); break;}
        }
    }

    int ban;
    for(i=0; i<2; i++)
    {
        cout << "상대 팀의 캐릭터 중 1개를 선택하여 제거해 주세요.(슬롯 숫자 입력) - B팀\n";
        cin >> ban;
        A.erase(A.begin() + ban-1);
        cout << "상대 팀의 캐릭터 중 1개를 선택하여 제거해 주세요.(슬롯 숫자 입력) - A팀\n";
        cin >> ban;
        B.erase(B.begin() + ban-1);
        if(i==1) break;
        cout << "상대 팀의 캐릭터 중 1개를 선택하여 제거해 주세요.(슬롯 숫자 입력) - A팀\n";
        cin >> ban;
        B.erase(B.begin() + ban-1);
        cout << "상대 팀의 캐릭터 중 1개를 선택하여 제거해 주세요.(슬롯 숫자 입력) - B팀\n";
        cin >> ban;
        A.erase(A.begin() + ban-1);
    }

    for(i=0; i<2; i++)
    {
        cout << "3개중 1개를 선택하여 주세요. - A팀\n";
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        selectcharacter();
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n";
        while(1){
            int num=getch();
            if(num=='1'){A.push_back(make_pair(characterpool[0].first, characterpool[0].second)); break;}
            if(num=='2'){A.push_back(make_pair(characterpool[1].first, characterpool[1].second)); break;}
            if(num=='3'){A.push_back(make_pair(characterpool[2].first, characterpool[2].second)); break;}
        }
        cout << "3개중 1개를 선택하여 주세요. - B팀\n";
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        selectcharacter();
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n";
        while(1){
            int num=getch();
            if(num=='1'){B.push_back(make_pair(characterpool[0].first, characterpool[0].second)); break;}
            if(num=='2'){B.push_back(make_pair(characterpool[1].first, characterpool[1].second)); break;}
            if(num=='3'){B.push_back(make_pair(characterpool[2].first, characterpool[2].second)); break;}
        }
        if(i==1) break;
        cout << "3개중 1개를 선택하여 주세요. - B팀\n";
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        selectcharacter();
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n";
         while(1){
            int num=getch();
            if(num=='1'){B.push_back(make_pair(characterpool[0].first, characterpool[0].second)); break;}
            if(num=='2'){B.push_back(make_pair(characterpool[1].first, characterpool[1].second)); break;}
            if(num=='3'){B.push_back(make_pair(characterpool[2].first, characterpool[2].second)); break;}
        }
        cout << "3개중 1개를 선택하여 주세요. - A팀\n";
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        selectcharacter();
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n";
        while(1){
            int num=getch();
            if(num=='1'){A.push_back(make_pair(characterpool[0].first, characterpool[0].second)); break;}
            if(num=='2'){A.push_back(make_pair(characterpool[1].first, characterpool[1].second)); break;}
            if(num=='3'){A.push_back(make_pair(characterpool[2].first, characterpool[2].second)); break;}
        }
    }


    system("cls");
    cout << "\n               -- Ranked Match --               \n\n";
    cout << "          캐릭터가 모두 선정 되었습니다.          \n\n";
    Sleep(2000);

    for(int i=0; i<9; i++)
    {
        selectstage();
    }

    system("cls");
    for(int k=0; k<2; k++)
    {
        cout << "\n               -- Ranked Match --               \n\n";
        cout << "원하는 맵을 제거해 주세요. - A팀(숫자 입력)\n";
        for(int i=0; i<mappool.size(); i++)
        {
            cout << i+1 << ". " << get<0>(mappool[i]) << " " << get<1>(mappool[i]) << "장 " << get<2>(mappool[i]) << "스테이지 " << get<3>(mappool[i]) << "성" << "\n";
        }
        cin >> ban;
        mappool.erase(mappool.begin() + ban-1);
        system("cls");
        cout << "\n               -- Ranked Match --               \n\n";
        cout << "원하는 맵을 제거해 주세요. - B팀(숫자 입력)\n";
        for(int i=0; i<mappool.size(); i++)
        {
            cout << i+1 << ". " << get<0>(mappool[i]) << " " << get<1>(mappool[i]) << "장 " << get<2>(mappool[i]) << "스테이지 " << get<3>(mappool[i]) << "성" << "\n";
        }
        cin >> ban;
        mappool.erase(mappool.begin() + ban-1);
        system("cls");
    }

    cout << "\n               -- Ranked Match --               \n\n";
    cout << "              맵 벤픽이 완료되었습니다.             \n";
    cout << "                 대결을 시작합니다.                   ";
    Sleep(2000);

    while(1)
    {
        system("cls");

            cout << "\n               -- Ranked Match --               \n\n";

        if(a==3)
        {
            cout << "                   A팀 승리!                   \n\n";
            cout << "                  최종 스코어                    \n";
            cout << "                    "<< "A" << "   " << "B" << "   \n";
            cout << "                    "<< a << "   " << b << "       \n";
            while(!getch()){}
            return;
        }
        if(b==3)
        {
            cout << "                   B팀 승리!                   \n\n";
            cout << "                  최종 스코어                    \n";
            cout << "                    "<< "A" << "   " << "B" << "   \n";
            cout << "                    "<< a << "   " << b << "       \n";
            while(!getch()){}
            return;
        }

        int mapnum = rand() % mappool.size();

        showgame:
        cout << "                    ROUND " << c << "             \n\n";

        cout << "스테이지 : ";
        cout << get<0>(mappool[mapnum]) << " " << get<1>(mappool[mapnum]) << "장 " << get<2>(mappool[mapnum]) << "스테이지 " << get<3>(mappool[mapnum]) << "성" << "\n";

        selectmission();
        cout << "\n\n";
            cout << "                    스코어                       \n";
            cout << "                    "<< "A" << "   " << "B" << "   \n";
            cout << "                    "<< a << "   " << b << "       \n";

        while(1)
        {
            int key=getch();
            if(key=='a')
            {
                system("cls");
                cout << "\n               -- Ranked Match --               \n\n";
                cout << "                   A팀 득점!                       ";
                a++;
                while(!getch()){}
                break;
            }
            if(key=='b')
            {
                system("cls");
                cout << "\n               -- Ranked Match --               \n\n";
                cout << "                   B팀 득점!                       ";
                b++;
                while(!getch()){}
                break;
            }
            if(key=='1')
            {
                system("cls");
                cout << "A팀 라인업\n";
                for(int i=0; i<10; i++)
                {
                    cout << A[i].first << " " << A[i].second << "\n";
                }
                while(!getch()){}
                system("cls");
                goto showgame;
            }
            if(key=='2')
            {
                system("cls");
                cout << "B팀 라인업\n";
                for(int i=0; i<10; i++)
                {
                    cout << B[i].first << " " << B[i].second << "\n";
                }
                while(!getch()){}
                system("cls");
                goto showgame;
            }
        }
        mappool.erase(mappool.begin() + mapnum);
        c++;
    }
}

int main()
{
    int key;
    srand(GetTickCount());

    load();

    B:

    ranked=0;

    system("cls");
    cout << "냥코 랜덤 챌린지\n\n";
    cout << "캐릭터를 뽑으실려면 c(1개) 혹은 d(3개중 택1)를 누르세요.\n";
    cout << "스테이지를 뽑을실려면 s를 입력하세요\n";
    cout << "미션을 뽑으시려면 m을 입력하세요.\n";
    cout << "랭크모드는 r을 입력하세요.\n\n";
    cout << "(이외의 명령어는 무시되며, 동시 입력은 하지 마세요.)\n";
    cout << "창을 비우시려면 l을 입력하세요.\n종료 하실때는 q를 입력 하세요.\n\n";

    while(1)
    {
        if(kbhit());
        {
            key=getch();
            if(key=='c') selectcharacter();
            else if(key=='d')
            {
                cout << "3개중 1개를 선택하여 주세요.\n";
                cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
                selectcharacter();
                cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n";
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