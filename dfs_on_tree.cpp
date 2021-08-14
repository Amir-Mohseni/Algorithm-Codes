#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

//in this problem the root of our tree is v = 0(zero based)
//each vertice in this problem is colored either in red or in white
//we try to find the number of red/white vertices in a random vertice's subtree

int col[N], sz[N], red[N]; //col[v] shows the color of v (col[v] == 0 => red col[v] == 1 => white   sz: shows the number of vertices in one's subtree
vector <int> adj[N]; //adj[v] shows the list of v's neighbors

 // in our dfs we keep the parent of v in par which in order to show that for v = 0 there is no parent, its default value is -1
void dfs(int v, int par = -1) {
    sz[v] = 1, red[v] = (col[v] == 0);
    for (auto u : adj[v]) {
        if(u == par)
            continue; //in order to only see v's subtree
        dfs(u, v); //goes into one of its children
        sz[v] += sz[u];
        red[v] += red[u];
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
    int n; // n : size of V
    cin >> n;
    //size of E in a n vertice tree is n - 1
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        cin >> col[i]; //either 0 or 1
    }
    dfs(0);
    int q; // number of queries we need to answer
    cin >> q;
    while(q--) {
        int v, color;
        cin >> v >> color;
        v--;
        if(!color) { // find the number of red vertices
            cout << red[v] << "\n";
        }
        else { // find the number of white vertices
            //the number of white vertices is equal to (number of vertices in the subtree - number of red vertices in the subtree)
            cout << sz[v] - red[v] << "\n";
        }
    }
}