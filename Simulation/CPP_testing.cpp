#include <bits/stdc++.h>
using namespace std;

void fastC();

#define mr 1600
#define mc 1600
#define start 1

char maze[mr][mc], fmaze[mr][mc];

void solved()
{
    /*
        * = undefine
        # = wall
        . = path
    */ 
    int r, c;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            cin >> maze[i][j];
            fmaze[i][j] = '*';
        }
    }
    fmaze[start][start] = '.';

    queue<pair<int, int>> qu;
    qu.push({start, start});

    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};

    while(!qu.empty())
    {
        int i = qu.front().first;
        int j = qu.front().second;

        for(int k=0 ; k<4 ; k++)
        {
            int ii = i + di[k];
            int jj = j + dj[k];

            if(ii < 0 || jj < 0 || ii >= r || jj >= c)
                continue;
            
            if(maze[ii][jj] == '#')
            {
                fmaze[ii][jj] = '#';
                continue;
            }
            
            qu.push({ii, jj});
            fmaze[ii][jj] = '.';
        }
    }

    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            cout << fmaze[i][j];
        }
        cout << "\n";
    }
}

main(){
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
*/