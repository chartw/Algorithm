#include <iostream>
using namespace std;
int main()
{
    int cheese[9][9] = {
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int cheeseWithTrap[9][9] = {
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 2, 0},
        {1, 0, 2, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 2, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 1, 2, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // cheese[i][j] += max(cheese[i][j-1],cheese[i+1][j]);
    for (int i = 8; i >= 0; i--)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == 8 && j == 0) // 시작 위치에서는 skip
                continue;

            if (j == 0) // 좌측 엣지의 경우, 아래에서 올라오는 경우 밖에 없음
                cheese[i][j] += cheese[i + 1][j];

            else if (i == 8) //하단 엣지의 경우, 좌측에서 오는 경우 밖에 없음
                cheese[i][j] += cheese[i][j - 1];

            else // 좌측, 하단 엣지가 아닌경우, 좌측과 하단 값중 더 큰값을 더하여 갱신함
                cheese[i][j] += max(cheese[i][j - 1], cheese[i + 1][j]);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << cheese[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "cheese DP result : " << cheese[0][8] << "\n\n";

    // cheese[i][j]=(max(cheese[i][j-1],cheese[i+1][j]) + cheese[i][j]) || -1;
    for (int i = 8; i >= 0; i--)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == 8 && j == 0) // 시작 위치에서는 skip
                continue;

            if (cheeseWithTrap[i][j] == 2) // 현재 위치가 쥐덫일 경우, 값을 -1로 변경하여 패널티를 부여함
                cheeseWithTrap[i][j] = -1;
            else
            {
                if (j == 0) // 좌측 엣지의 경우, 아래에서 올라오는 경우 밖에 없음
                    cheeseWithTrap[i][j] += cheeseWithTrap[i + 1][j];

                else if (i == 8) //하단 엣지의 경우, 좌측에서 오는 경우 밖에 없음
                    cheeseWithTrap[i][j] += cheeseWithTrap[i][j - 1];

                else // 좌측, 하단 엣지가 아닌경우, 좌측과 하단 값중 더 큰값을 더하여 갱신함
                    cheeseWithTrap[i][j] += max(cheeseWithTrap[i][j - 1], cheeseWithTrap[i + 1][j]);
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << cheeseWithTrap[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "cheese with trap DP result : " << cheeseWithTrap[0][8]<<endl;
    cout<<"12161800 ChaTaeWoong"<<endl;

    return 0;
}