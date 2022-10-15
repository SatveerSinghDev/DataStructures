/* Program to find Minimum Spanning Tree of an undirected graph using Kruskal's Algorithm 
	Created by Nitish Arya
	Date of completion: 14th April, 2019
	Sources: cplusplus.com		github.com		geeksforgeeks.com
*/


#include <iostream>		//cout,cin
#include <vector>		//vector<> and related functions
#include <algorithm>	//sort()
#include <utility>		//pair<>

using namespace std;

#define FOR(i,x,y) for(int i = x; i<= y; ++i)

#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)		//iterate over a given data structure(vector in this program).

#define pb push_back			//push an element at the end of a vector.

#define II pair<int,int>		//for storing an edge with vertices u,v as pair<u,v>

#define mp make_pair			//given pair<int,int>; make_pair makes a pair. e.g pair<int,int> p; p = make_pair(5,6) makes a 5,6 pair.

#define F first					//points to first element of a pair<>. e.g pair<3,4>; pair.F would give 3.

#define S second				//points to second element of a pair<>. e.g pair<3,4>; pair.S would give 4. 

#define LL long long			//for storing a big value(used as ans for total weight of MST).


const int N = 100;				//Maximum number of vertices are N(i.e 100)

int pset[N], m, n;				/*pset[N] is the array of vertices used for finding a cycle in a given undirected graph using UNION-FIND algorithm.
									m,n -> total number of edges,vertices as enetered by the user during runtime */

vector< pair<int, II> > edge;		//stores edge of a graph with its weight. e.g  2----3[weight=4] is stored as vector< pair< 4, pair< 2, 3 > > >
vector< pair<int, II> > MSTedge;	//stores edges in the MST as found by KRUSKAL's algorithm

void init()						//Sets all vertices(pset[]) to their index values, means they point to themselves.
{
	FOR(i,1,n) pset[i] = i;
}

int findSet(int u)				//Finds the subset of input vertex and returns its parent.
{
	return pset[u] == u ? u : pset[u] = findSet(pset[u]);
}

int isSameSet(int u, int v)		//Checks if the given edge are in the same subset or not.
{
	return findSet(u) == findSet(v);
}

void unionSet(int u, int v)		//Adds u,v in the respective subset.(updates the parent vertex if needed)
{
	pset[findSet(u)] = findSet(v);
}
void autoInput()
{
	m=8;	n=6;
	edge.pb(mp(4,mp(1,2)));
	edge.pb(mp(2,mp(3,2)));
	edge.pb(mp(4,mp(1,3)));
	edge.pb(mp(2,mp(3,6)));
	edge.pb(mp(3,mp(5,6)));
	edge.pb(mp(3,mp(4,5)));
	edge.pb(mp(3,mp(3,4)));
	edge.pb(mp(4,mp(3,5)));
	
	cout<<"\n\t\tAuto input\n";
    FOR(i,0,31) cout<<"_";
    cout<<"\n\tEdge"<<"\t\t"<<"Weight"<<"\t|";
	forit(it, edge) 					//Output the auto input.
	{
        II e = it->S;
        
        cout<<"\n\t"<<e.F<<"-----"<<e.S<<"\t\t"<<it->F<<"\t|";
    }
    cout<<endl;
    FOR(i,0,31) cout<<"_";	cout<<"|";
}

void manualInput()
{
	cout<<"Enter total number of vertices in the graph: ";
		cin>>n;									//Total vertices input.
	cout<<"Enter total number of edges in the graph: ";
		cin>>m;									//Total edges input.
	cout<<"\n\t\tEnter graph:- "<<endl;
	
	FOR(i,1,m) 					//Graph input for m edges
	{
		int u,v,w;				//u,v are vertices joined by the edge with weight w.
	
		cout<<"\nEdge "<<i<<":"<<endl;
		cout<<"Vertex\t";
			cin>>u;
	
		cout<<"to\t";
	
			cin>>v;
	
		cout<<"Weight = ";
			cin>>w;
	
		edge.pb(mp(w,mp(u,v)));		//adding edges to the vector in the format defined above in the definition.
	}	//Input ends.
	
}
int main() {
	bool choice;
	cout<<"Choose an option: ";
	cout<<"\nPress 0 for auto input";
	cout<<"\nPress 1 for manual input"<<endl;
	cin>>choice;
	
	if(choice)	manualInput();
	else   autoInput();
	
	sort(edge.begin(), edge.end());		//Sorts the edges according to the first argument of the pair<>, i.e weight(as required by KRUSKAL's algorithm.
	
	init();								//Makes each vertex a disjoint set.(sets value as its own index)
	
	LL ans = 0;
    
    forit(it, edge) 					//KRUSKAL's algorithm implementation. Iterator it goes through every edge in the vector.
	{
        II e = it->S;					//	e points to second element of it, i.e vertices of the edge as a pair.
        
        if (isSameSet(e.F, e.S)) continue;		/*checks if the edge with vertices e.F(first element of pair e) and e.S(second element of pair e) 
													makes a cycle, if added to the MST, by checking their presence in same subset. Continue makes a jump to the next iteration
													without executing the below code  */
        
        unionSet(e.F, e.S);						//Add to subset if not a cycle making edge.
        
        MSTedge.pb(mp(it->F,mp(e.F,e.S)));		//Add to MST 
        
        ans += it->F;						//Adds corresponding weights of edges in the MST to final answer variable.
    }
        
    //Output MST
    cout<<"\n\n\n";
    FOR(i,0,31) cout<<"*";
    cout<<"\n\t\tMST\n";
    FOR(i,0,31) cout<<"_";
    cout<<"\n\tEdge"<<"\t\t"<<"Weight"<<"\t|";
    forit(it, MSTedge) 					
	{
        II e = it->S;
        
        cout<<"\n\t"<<e.F<<"-----"<<e.S<<"\t\t"<<it->F<<"\t|";
    }
    cout<<endl;
    FOR(i,0,31) cout<<"_";	cout<<"|";
    cout<<"\n   Total weight of MST is : "<<ans<<"\t|"<<endl;
	FOR(i,0,31) cout<<"_";	cout<<"|";
}
