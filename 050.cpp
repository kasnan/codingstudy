#include<iostream>
#include<vector>

using namespace std;

vector<int>parent;

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}
void findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    parent.resize(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if (!o) {// union연산
            unionParent(a, b);
        }
        else { //find연산
            findParent(a, b);
        }

    }

    return 0;
}