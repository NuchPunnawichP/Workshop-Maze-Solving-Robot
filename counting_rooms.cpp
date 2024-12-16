#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char a[1000 + 10][1000 + 10];

int main() {
    int r, c;
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    int di[4] = {-1, 0, 1, 0}; // NESW
    int dj[4] = {0, 1, 0, -1};
    for(int sti = 1; sti <= r; sti++) {
        for(int stj = 1; stj <= c; stj++) {
            if(a[sti][stj] == '.') {
                ans++;
                a[sti][stj] = '#';
                queue <pair <int, int>> qu;
                qu.push({sti, stj});
                while(!qu.empty()) {
                    int i = qu.front().first;
                    int j = qu.front().second;
                    qu.pop();
                    for(int k = 0; k < 4; k++) {
                        int next_i = i + di[k];
                        int next_j = j + dj[k];
                        if(next_i < 1 || next_i > r || next_j < 1 || next_j > c) {
                            continue;
                        }
                        if(a[next_i][next_j] == '#') {
                            continue;
                        }
                        a[next_i][next_j] = '#';
                        qu.push({next_i, next_j});
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}