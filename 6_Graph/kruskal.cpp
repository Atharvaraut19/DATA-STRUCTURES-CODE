#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool comp(Edge a, Edge b) {
    return a.w < b.w;
}

int findParent(int u, int parent[]) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = findParent(parent[u], parent);
}

void unionNodes(int u, int v, int parent[], int rank[]) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    int N, m;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> m;
    
    vector<Edge> edges(m);

    cout << "Enter edges (source, destination, weight):\n";
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    sort(edges.begin(), edges.end(), comp);

    int parent[N], rank[N];

    for (int i = 0; i < N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<pair<int,int>> mst;
    int ansWeight = 0;

    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (findParent(u, parent) != findParent(v, parent)) {
            unionNodes(u, v, parent, rank);
            mst.push_back({u, v});
            ansWeight += w;
        }
    }

    for (auto edge : mst) {
        cout << edge.first << " - " << edge.second << "\n";
    }
    cout << "Total weight of the MST: " << ansWeight << "\n";

    return 0;
}
