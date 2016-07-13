// MST implementation using Krushkal's MST

#include<iostream>
#include<string>
#include<list>
#include<vector>

using namespace std;

// Class declaration for the Union Find by Rank data struncture and member functions
class UnionFind {
	private:
		int *parent, *rank, cnt;

	public:
		// Constructor:
		UnionFind(int N);

		// Destructor
		~UnionFind();

		// Member Function: find()
		int find(int p);

		// Member Function: Union()
		void Union(int x, int y);

		// Member Function: isConnected()
		bool isConnected(int x, int y);

		// Member Function: Count()
		int Count();
};

// Class declaration for the Graph and it's member functions
class Graph {
	private:
		int V, E;  // Vertex and Egde of the graph
		vector< pair<int, pair<int, int> > > edges; // declaring the edges to accomodate cost and pair of vertices

	public:
		// Constructor:
		Graph(int V, int E);

		// Member function: addEdge()
		void addEdge(int u, int v, int w); // Add an edge of weight 'w' between 'u' and 'v' vertices

		// Member Function: KruskalsMST()
		void KruskalsMST();
};


/* Function Implementation for Graph */

// Constructor
Graph::Graph(int V, int E)
{
	this->V = V;
	this->E = E;
}

// Member Function : addEdge()
void Graph::addEdge(int u, int v, int w)
{
	edges.push_back({w, {u,v}});
	
}

// Member Function : KruskalsMST()
void Graph::KruskalsMST()
{

}
 
