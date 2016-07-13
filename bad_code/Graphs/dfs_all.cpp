// Version of DFS which will consider all the Vertex in the graph which can be disjoint as well
#include<iostream>
#include<list>

using namespace std;
// Define the class for the Graph for DFS
class Graph {
	private:
		int V;
		list<int> *adj;
		void dfsUtil(int v, bool visited[]);
	public:
		Graph(int V);
		void addEdge(int u, int v);
		void DFS();
};

// Constructor for the Graph
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// Member function : addEdge()
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add vertex w to v's adjacency list
}

// Internal function : dfsUtil()
void Graph::dfsUtil(int v, bool visited[])
{
	// Mark the Vertex as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Go through the adjacency list of v and then if not visited recur the Util
	list<int>::iterator itr;
	for (itr = adj[v].begin(); itr!=adj[v].end(); itr++) {
		if (!visited[*itr]) {
			dfsUtil(*itr, visited);
		}
	}
}

// Member Function : DFS()
void Graph::DFS()
{
	// First mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i=0; i < V; i++) {
		visited[i] = false;
	}

	// Now visit the vertex which are not in the connected set as well
	for (int i=0; i<V; i++) {
		if (!visited[i]) {
			dfsUtil(i, visited);
		}
	}
}

// Driver Function 
int main(void)
{
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 4);
	g.addEdge(4, 3);
	g.addEdge(3, 3);
	g.addEdge(5, 5);

	cout << "Following is the depth first traversal\n";
	g.DFS();

	return 0;
}
