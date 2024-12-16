#include <iostream>
#include <vector>
#include <utility>
using namespace std;

char a[20 + 10][20 + 10];
bool visited[20 + 10][20 + 10];

int r, c;

int sti, stj, eni, enj;

void dfs(int i, int j) {
    if(i < 1 || i > r || j < 1 || j > c) {
        return ;
    }
    if(visited[i][j]) {
        return ;
    }
    if(a[i][j] == '#') {
        return ;
    }
    visited[i][j] = true;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        cin >> r >> c;
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                cin >> a[i][j];
                visited[i][j] = false;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= r; i++) {
            if(a[i][1] == '.') {
                cnt++;
            }
            if(a[i][c] == '.' && c != 1) {
                cnt++;
            }
        }
        for(int j = 2; j <= c - 1; j++) {
            if(a[1][j] == '.') {
                cnt++;
            }
            if(a[r][j] == '.' && r != 1) {
                cnt++;
            }
        }
        if(cnt != 2) {
            cout << "invalid" << '\n';
            continue;
        }
        vector <pair <int, int>> points;
        for(int i = 1; i <= r; i++) {
            if(a[i][1] == '.') {
                points.push_back({i, 1});
            }
            if(a[i][c] == '.' && c != 1) {
                points.push_back({i, c});
            }
        }
        for(int j = 2; j <= c - 1; j++) {
            if(a[1][j] == '.') {
                points.push_back({1, j});
            }
            if(a[r][j] == '.' && r != 1) {
                points.push_back({r, j});
            }
        }
        sti = points[0].first;
        stj = points[0].second;
        eni = points[1].first;
        enj = points[1].second;
        dfs(sti, stj);
        cout << (visited[eni][enj] ? "valid" : "invalid") << '\n';
    }
    return 0;
}