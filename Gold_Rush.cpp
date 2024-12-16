#include <iostream>
using namespace std;

bool dfs(int n, int m) {
    if(n == m) {
        return true;
    }
    if(n % 3 != 0) {
        return false;
    }
    if(n < m) {
        return false;
    }
    if(dfs(n / 3, m)) {
        return true;
    }
    if(dfs(n / 3 * 2, m)) {
        return true;
    }
    return false;
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n, m;
        cin >> n >> m;
        cout << (dfs(n, m) ? "YES" : "NO") << '\n';
    }
}
