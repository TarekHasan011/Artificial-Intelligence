#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;
    int bot_x, bot_y; cin >> bot_x >> bot_y;
    int queen_x, queen_y;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char temp; cin >> temp;
            if(temp=='p')
            {
                queen_x = i;
                queen_y = j;
            }
        }
    }
    if(queen_x!=bot_x)
    {
        if(queen_x>bot_x)
            cout << "DOWN\n";
        else
            cout << "UP\n";
    }
    else
    {
        if(queen_y>bot_y)
            cout << "RIGHT\n";
        else
            cout << "LEFT\n";
    }
    return 0;

}
