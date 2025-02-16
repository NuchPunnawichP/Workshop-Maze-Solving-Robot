#include <bits/stdc++.h>
using namespace std;

void fastC();

#define MAX 1010
char maze[MAX][MAX], path[MAX][MAX];
int ans[MAX][MAX];

void solved()
{
    // Solve the problem here
    int r, c;
    cin >> r >> c;

    for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<c ; j++)
        {
            cin >> maze[i][j];
            path[i][j] = '#';
        }

    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
    pair<int, int> start = {1, 1}, end = {r-2, c-2};
    maze[start.first][start.second] = '#';
    ans[start.first][start.second] = 1;

    queue<pair<int, int>> q;
    q.push(start);

    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(int k=0 ; k<4 ; k++)
        {
            int ii = i + di[k];
            int jj = j + dj[k];

            if(ii < 0 || jj < 0 || ii >= r || jj >= c)
                continue;
            
            if(maze[ii][jj] == '#')
                continue;
            
            if(ans[ii][jj] == 0)
                ans[ii][jj] = ans[i][j] + 1;
            else
                ans[ii][jj] = min(ans[i][j] + 1, ans[i][j]);
            
            q.push({ii, jj});
            maze[ii][jj] = '#';
        }
    }

    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << "\n";
    }
    
    stack<pair<int, int>> st;
    st.push(end);
    q.push(end);

    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(int k=0 ; k<4 ; k++)
        {
            int ii = i + di[k];
            int jj = j + dj[k];

            if(ii < 0 || jj < 0 || ii >= r || jj >= c)
                continue;
            
            if(ans[ii][jj] == ans[i][j] - 1 && ans[ii][jj] != 0)
            {
                st.push({ii, jj});
                q.push({ii,jj});
            }
        }
    }

    while(!st.empty())
    {
        int i = st.top().first;
        int j = st.top().second;
        st.pop();

        path[i][j] = '*';
    }
    
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            cout << path[i][j];
        }
        cout << "\n";
    }
}

int main(){
    fastC();
    solved();
    return 0;
}

void fastC()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
10 10
# # # # # # # # # # 
# * * * # * * * * # 
# * # * # * # # * # 
# * # * * * * # * # 
# * # # # # * # * # 
# * * * * # * # * # 
# # # # * # * # * # 
# * * # * * * * * # 
# * # # # # # # * # 
# # # # # # # # # #
*/