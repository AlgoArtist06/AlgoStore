#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <list>
#include <queue>

using namespace std;

class Graph
{
public:
    int vertices;
    vector<vector<int> > adjacencylist;
    Graph(int v)
    {
        this->vertices = v;
        adjacencylist.resize(v);
    }

    void addEdge(int src, int dest)
    {
        adjacencylist[src].push_back(dest);
        // for undirected graph
        adjacencylist[dest].push_back(src);
    }
};

void dfs(int start,Graph graph,vector<bool> &ch){
    ch[start]=true;
    cout<<start<<endl;
    int a=0;
    vector<int>neigh=graph.adjacencylist[start];
    for(int i=0;i<neigh.size();i++){
        if(ch[neigh[i]]==false){
            ch[neigh[i]]=true;
            dfs(neigh[i],graph,ch);
        }
        else{
            a++;
        }
    }
    if(a==neigh.size()){
        return;
    }
}

int main()
{
    Graph graph(8);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(0, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);
    graph.addEdge(4, 7);
    vector<bool> ch(graph.vertices,false);
    dfs(0, graph,ch);
}