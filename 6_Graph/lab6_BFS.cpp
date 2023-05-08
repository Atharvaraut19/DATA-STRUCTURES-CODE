#include <iostream>
#include<queue>
#include <map>
#include <list>
using namespace std;

class Graph{
public:
    map<int,list<int> > l;


void AddEdge(int x, int y)
{
    l[x].push_back(y);
    l[y].push_back(x);

}
void bfs(int src)
{
    map<int,bool> visited;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    cout << src << " ";
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(int nbr:l[node])
        {
            if(!visited[nbr])
            { 
                visited[nbr] = true;
                q.push(nbr);
                
                cout << nbr << " ";

            }
        }
    }
}

};
int main()
{
    Graph g;
    g.AddEdge(0,1);
    g.AddEdge(0,3);
    g.AddEdge(0,4);
    g.AddEdge(1,2);
    g.AddEdge(3,5);
    g.AddEdge(4,5);
    g.bfs(0);
    return 0;
}