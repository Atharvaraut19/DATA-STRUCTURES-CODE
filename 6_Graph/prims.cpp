#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, m;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> m;
    
    vector<pair<int,int> > adj[N]; 

    cout << "Enter edges (source, destination, weight):\n";
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int parent[N];
    int key[N]; 
    bool mstSet[N]; 

    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    { 

        int mini = INT_MAX, u; 

        for (int v = 0; v < N; v++) 
        {
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
        }
        mstSet[u] = true; 

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }

    } 


    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    return 0;
}
