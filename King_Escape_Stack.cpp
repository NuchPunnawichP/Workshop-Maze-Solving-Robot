#include <iostream>
#include <stack>
using namespace std;

int n;

bool isInCheck[1000 + 10][1000 + 10];
bool visited[1000 + 10][1000 + 10];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

stack <pair <int, int>> st;

void flood_fill_queen(int x, int y, int k) {
    isInCheck[x][y] = true;
    st.push({x, y});
    while(!st.empty()) {
        pair <int, int> p = st.top();
        int x = p.first;
        int y = p.second;
        st.pop();
        int next_x = x + dx[k];
        int next_y = y + dy[k];
        if(next_x < 1 || next_x > n || next_y < 1 || next_y > n) {
            continue;
        }
        isInCheck[next_x][next_y] = true;
        st.push({next_x, next_y});
    }
}

int cx, cy;

void flood_fill_king(int x, int y) {
    isInCheck[x][y] = true;
    st.push({x, y});
    while(!st.empty()) {
        pair <int, int> p = st.top();
        int x = p.first;
        int y = p.second;
        st.pop();
        if(x == cx && y == cy) {
            cout << "YES" << '\n';
            exit(0);
        }
        visited[x][y] = true;
        for(int k = 0; k < 8; k++) {
            int next_x = x + dx[k];
            int next_y = y + dy[k];
            if(next_x < 1 || next_x > n || next_y < 1 || next_y > n) {
                continue;
            }
            if(isInCheck[next_x][next_y]) {
                continue;
            }
            if(visited[next_x][next_y]) {
                continue;
            }
            st.push({next_x, next_y});
        }
    }
}

int main() {
    int ax, ay;
    int bx, by;
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    for(int k = 0; k < 8; k++) {
        flood_fill_queen(ax, ay, k);
    }
    flood_fill_king(bx, by);
    cout << "NO" << '\n';
}