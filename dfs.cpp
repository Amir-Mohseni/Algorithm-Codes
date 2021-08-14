#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e5 + 5;

bool mark[N]; //marks visited vertices
vector <int> adj[N]; //keeps neighbors of each vertice

void dfs(int v) {
    mark[v] = true; //marks the unseen vertice as seen when we first encounter it.
    for (auto u : adj[v]) {
        if(!mark[u]) //checks if there is an adjacent vertice which is unseen
            dfs(u);
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
    int n, m, cnt_component = 0; // n: size of V m: size of E cnt_component: number of components in our graph G
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--; // there is an edge between v & u
        adj[v].push_back(u), adj[u].push_back(v);
    }
    for (int v = 0; v < n; v++) { //using dfs on every component
        if(!mark[v])
            dfs(v), cnt_component++;
    }
    cout << cnt_component << "\n";
}