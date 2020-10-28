#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
typedef pair< int , pair<int, int> > pii;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

int pac_x, pac_y, food_x, food_y, n, m;
char grid[57][57];
int dist[57][57];
pair< int , int > parent[57][57];

bool valid(int i, int j)
{
    return i>=0 && i<n && j>=0 && j<m && grid[i][j]!='%';
}

int heuristic(int i, int j)
{
    return abs(food_x-i)+abs(food_y-j);
}

void AStar()
{
    priority_queue< pii, vector< pii >, greater<pii> > pq;
    pq.push(make_pair(0,make_pair(pac_x,pac_y)));
    memset(dist,INF,sizeof(dist));
    dist[pac_x][pac_y]=0;
    parent[pac_x][pac_y] = make_pair(pac_x,pac_y);

    while(!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        if(top.second.first==food_x && top.second.second==food_y)
            return;
        for(int it=0;it<4;it++)
        {
            int temp_x = top.second.first + dx[it];
            int temp_y = top.second.second + dy[it];

            if(valid(temp_x,temp_y))
            {
                int h = heuristic(temp_x,temp_y);
                int n_dist = grid[temp_x][temp_y]=='.' ? 0 : 1;
                if(dist[temp_x][temp_y]>dist[top.second.first][top.second.second]+n_dist)
                {
                    dist[temp_x][temp_y]=dist[top.second.first][top.second.second]+n_dist;
                    parent[temp_x][temp_y] = make_pair(top.second.first,top.second.second);
                    pq.push(make_pair(dist[temp_x][temp_y]+h,make_pair(temp_x,temp_y)));
                }
            }
        }
    }

    return;

}

void PathPrint(int i, int j, int counter)
{
    if(parent[i][j].first==i && parent[i][j].second==j)
    {
        cout << counter << endl;
        cout << i << " " << j << endl;
        return;
    }
    PathPrint(parent[i][j].first,parent[i][j].second,counter+1);
    cout << i << " " << j << endl;
}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    cin >> pac_x >> pac_y >> food_x >> food_y >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> grid[i][j];
    AStar();
    PathPrint(food_x,food_y,0);
    return 0;
}

