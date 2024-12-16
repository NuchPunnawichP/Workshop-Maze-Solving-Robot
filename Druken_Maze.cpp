#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector <string> a(r + 10);
    int sti, stj, eni, enj;
    for(int i = 1; i <= r; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
        for(int j = 1; j <= c; j++) {
            if(a[i][j] == 'S') {
                sti = i;
                stj = j;
            }
            else if(a[i][j] == 'T') {
                eni = i;
                enj = j;
            }
        }
    }
    int dis[r + 10][c + 10][4][4];
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            for(int dir = 0; dir < 4; dir++) { 
                // Which direction you're facing
                // 0: up, 1: right, 2: down, 3: left
                for(int state = 0; state <= 3; state++) {
                    // how many steps you've taken in the same direction
                    dis[i][j][dir][state] = -1;
                }
            }
        }
    }
    int di[4] = {-1, 0, 1, 0}; // NESW
    int dj[4] = {0, 1, 0, -1};
    queue <pair <pair <int, int>, pair <int, int>>> qu;
    for(int k = 0; k < 4; k++) {
        dis[sti][stj][k][0] = 0;
        qu.push({{sti, stj}, {k, 0}});
    }
    while(!qu.empty()) {
        pair <pair <int, int>, pair <int, int>> p = qu.front();
        qu.pop();
        int i = p.first.first;
        int j = p.first.second;
        int dir = p.second.first;
        int state = p.second.second;
        if(i == eni && j == enj) {
            cout << dis[i][j][dir][state] << '\n';
            return 0;
        }
        for(int k = 0; k < 4; k++) {
            int next_i = i + di[k];
            int next_j = j + dj[k];
            int next_dir = k;
            int next_state;
            if(k == dir) {
                next_state = state + 1;
            }
            else {
                next_state = 1;
            }
            if(next_i < 1 || next_i > r || next_j < 1 || next_j > c) {
                continue;
            }
            if(a[next_i][next_j] == '#') {
                continue;
            }
            if(next_state > 3) {
                continue;
            }
            if(dis[next_i][next_j][next_dir][next_state] != -1) {
                continue;
            }
            dis[next_i][next_j][next_dir][next_state] = dis[i][j][dir][state] + 1;
            qu.push({{next_i, next_j}, {next_dir, next_state}});
        }
    }
    cout << -1 << '\n';
    return 0;
}