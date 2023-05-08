#include <iostream>
#include <stack>
#include <list>
#include <map>
using namespace std;


class Graph{
public:
    map<int, list<int> > l;

 
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs(int src)
    {
        stack<int> st;
        map<int,bool> visited;
        for(auto p:l)
        {
            int node = p.first;
            visited[node] = false;
        }
        st.push(src);
        visited[src] = true;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            cout<<node<<" ";
            
            for(auto nbr : l[node])
            {
            {if(visited[nbr]==false)
            {
                st.push(nbr);
                visited[nbr] = true;
                
            }
            }
        }
        }

    }
};
int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    g.dfs(0);
    cout << endl;
}