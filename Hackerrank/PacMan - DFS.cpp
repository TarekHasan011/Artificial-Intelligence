#include<bits/stdc++.h>
using namespace std;
int pac_i, pac_j, food_i, food_j, n, m;
char arr[50][50];
int dx[4]= {-1,0,0,1};
int dy[4]= {0,-1,1,0};
pair< int, int > parent[50][50];
bool visited[50][50];
bool valid(int i, int j)
{
    return i>=0 && i<n && j>=0 && j<m && arr[i][j]!='%' && !visited[i][j];
}
vector< pair< int , int > > v;
void dfs(int i, int j)
{
    stack< pair< int, int > > st;
    parent[i][j] = make_pair(i,j);
    st.push(make_pair(i,j));
    visited[i][j] = true;

    while(!st.empty())
    {
        pair< int, int > top = st.top();
        v.push_back(top);
        st.pop();
        if(top.first==food_i && top.second==food_j)
            return;
        for(int it=0; it<4; it++)
        {
            if(valid(top.first+dx[it],top.second+dy[it]))
            {
                st.push(make_pair(top.first+dx[it],top.second+dy[it]));
                parent[top.first+dx[it]][top.second+dy[it]].first = top.first;
                parent[top.first+dx[it]][top.second+dy[it]].second = top.second;
                visited[top.first+dx[it]][top.second+dy[it]] = true;
            }
        }
    }
    return;
}
void Print_Path(int i, int j, int c)
{
    if(parent[i][j].first==i && parent[i][j].second==j)
    {
        cout << c << endl;
        cout << i << " " << j << endl;
        return;
    }

    Print_Path(parent[i][j].first,parent[i][j].second,c+1);
    cout << i << " " << j << endl;

}
int main()
{
#ifdef TarekHasan
    freopen("input.txt","r",stdin);
#endif // TarekHasan
    cin >> pac_i >> pac_j;
    cin >> food_i >> food_j;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    memset(visited,false,sizeof(visited));
    dfs(pac_i,pac_j);
    cout << v.size() << endl;
    for(auto x : v)
        cout << x.first << " " << x.second << endl;
    Print_Path(food_i, food_j, 0);
    return 0;
}

