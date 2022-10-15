#include<iostream>
#include<list>
#include <iterator>
using namespace std;

class Graph
{
    int V;

    list<int> *adj;

    void DFSUtil(int v, bool visited[]);
    bool isCyclic();
    bool isCyclicUtil(int v,bool visited[],bool *recStack);
public:
    Graph(int V);   // Constructor

    void addEdge(int v, int w);

    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{

    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic()
{

    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

void Graph::DFS(int v)
{

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
    if(isCyclic())
      cout<<"\nCycle is there in the graph";
    else
      cout<<"\nGraph doesn't have cycle";
}

int main()
{
  int nodes;
  cout<<"Enter no. of nodes: ";
  cin>>nodes;
  Graph g(nodes);
  int matrix[nodes][nodes];
  for(int i=0;i<nodes;i++)
  {
    for(int j=0;j<nodes;j++)
      matrix[i][j]=-1;
  }
  cout<<"Enter the connections into the Adjacency Matrix: ";
  for(int i=0; i<nodes; i++)
  {
    for(int j=i; j<nodes; j++)
    {
      cout<<endl<<i<<","<<j<<": ";
      if(i==j)
        matrix[i][j]=0;

      else if(matrix[i][j]==-1)
      {
        cin>>matrix[i][j];
        g.addEdge(i,j);
        // g.addEdge(j,i);  //for parallel edges 
        matrix[j][i]=matrix[i][j];
      }
    }
  }
  int src=0;
  cout<<"\nInput Source:";
  cin>>src;
  cout << "Following is Depth First Traversal "
       << "(starting from vertex "<<src<<") \n";
  g.DFS(src);

    return 0;
}
