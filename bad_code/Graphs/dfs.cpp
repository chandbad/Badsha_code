// Normal Depth First Search with only connected nodes

#include<iostream>
#include<list>

using namespace std;
// Graph Class
class Graph {
		private:
				int V;	// No. of Vertex int the graph
				list<int> *adj; // Adjacency list for each vsertex in the graph
				void dfsUtil(int v, bool visited[]); // Utility function to be used by the DFS
		public:
				Graph(int V); // Constructor
				void addEdge(int v, int w); // Member function to add an edge between v and w
				void DFS(int v); // Work horse function for the DFS
};

// Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// Member Function : addEdge()
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Push the vertex w to the v's adjacency list
}

// Internal Function to be used for recursion
void Graph::dfsUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Now recur the vertex adjacent to this vertex
	list<int>::iterator itr;
	for (itr=adj[v].begin() ; itr!=adj[v].end(); itr++) {
		if (!visited[*itr]) {
			dfsUtil(*itr, visited);
		}
	}
}

// Member function : DFS()
void Graph::DFS(int v)
{
	// First start with marking all the vertices as not visited
	bool *visited = new bool[V]; // This is the dynamic array which will hold all the state iof the vertices
	for (int i=0; i<V; i++) {
		visited[i] = false;
	}

	// Call the recursive helper function 
	dfsUtil(v, visited);
}

// Driver Method 
int main(void)
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is the depth first traversal starting at vertex 2 \n";
	g.DFS(2);
	return 0;
}
