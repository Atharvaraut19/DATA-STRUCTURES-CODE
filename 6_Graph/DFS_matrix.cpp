#include <iostream>
#include <stack>
using namespace std;

const int MAX = 100;

class Graph {
public:
    int V;
    int adj[MAX][MAX];

    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w) {
        adj[v][w] = 1;
        adj[w][v] = 1;
    }

    void DFS(int start) {
        bool visited[MAX] = {false};
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int u = s.top();
            s.pop();

            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";

                for (int v = 0; v < V; v++) {
                    if (adj[u][v] == 1 && !visited[v]) {
                        s.push(v);
                    }
                }
            }
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Depth First Traversal (starting from vertex 0): ";
    g.DFS(0);
    cout << endl;

    return 0;
}
