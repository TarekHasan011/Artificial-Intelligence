#include<bits/stdc++.h>
using namespace std;

typedef pair< int , int > pii;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

char grid[57][57];
pii parent[57][57];

int n,m, pac_x, pac_y, food_x, food_y;
bool valid(int i , int j)
{
    return i>=0 && i<n && j>=0 && j<m && grid[i][j]!='%' && grid[i][j]!='#';
}
vector< pii > v;

void bfs()
{
    queue< pii > q;
    q.push(make_pair(pac_x,pac_y));
    grid[pac_x][pac_y]='#';
    parent[pac_x][pac_y]=make_pair(pac_x,pac_y);

    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        v.push_back(top);

        if(top.first==food_x && top.second==food_y)
            return;

        for(int it=0;it<4;it++)
        {
            if(valid(top.first+dx[it],top.second+dy[it]))
            {
                q.push(make_pair(top.first+dx[it],top.second+dy[it]));
                grid[top.first+dx[it]][top.second+dy[it]]='#';
                parent[top.first+dx[it]][top.second+dy[it]]=make_pair(top.first,top.second);
            }
        }
    }
    return;

}

void printPath(int i, int j, int counter)
{
    if(parent[i][j].first==i && parent[i][j].second==j)
    {
        cout << counter << endl;
        cout << i << " " << j << endl;
        return;
    }
    printPath(parent[i][j].first,parent[i][j].second,counter+1);
    cout << i << " " << j << endl;

}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    cin >> pac_x >> pac_y >> food_x >> food_y >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];
    bfs();
    cout << v.size() << endl;
    for(auto x : v)
        cout << x.first << " " << x.second << endl;
    printPath(food_x,food_y,0);
    return 0;
}
