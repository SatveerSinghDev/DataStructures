//for testing of cycle assumption is made that there are no parallel edges
#include<iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int V;
    bool cycle;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);


    void BFS(int s);
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

void Graph::BFS(int s)
{
    cycle=false;
    bool *visited = new bool[V];
    vector<int> parent(V,-1);
    for(int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;


    visited[s] = true;
    queue.push_back(s);


    list<int>::iterator i;

    while(!queue.empty())
    {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        if(parent[s]==-1)
          parent[s]=s;
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                parent[*i]=s;
            }
            else if (parent[s] != *i)
            {
              cycle=true;
            }
        }
    }
    if(cycle)
      cout<<"\ngraph has cycle";
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
          // g.addEdge(j,i); //for parallel edges
          matrix[j][i]=matrix[i][j];
        }
      }
    }
    int src=0;
    cout<<"\nInput Source:";
    cin>>src;
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex "<<src<<") \n";
    g.BFS(src);

    return 0;
}
