#include<iostream>
#include<string>
#include<list>

using namespace std;

class Graph {
	// Private Members
	private:
		int V;
		list<int> *adj;
	// Public Member Functions
	public:
		// contructor 
		Graph(int V);
		// Destructor
		~Graph();
		// Member Function : addEdge
		void addEdge(int v, int w);
		// Util Method for the DFS
		void dfsUtil(int v, bool visited[], bool recStack[], bool& have_cycle);
		// Member function: DFS()
		void DFS(int v, bool& have_cycle);
		// Member Function: isCycle()
		bool isCycle(int v);
};

// Constructor Implementation
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// Destructor
Graph::~Graph()
{
	delete [] adj;
}

// Member Function: addEdge()
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

// Helper Function: dfsUtil()
void Graph::dfsUtil(int v, bool visited[], bool recStack[], bool& have_cycle)
{
	// First mark the node as visited
	if (!visited[v]) {
		// Print the node and then mark it as visited
		cout << v << " ";
		visited[v] = true;
		recStack[v] = true;
	}

	// Now iterate through the adj list of v and recursively call dfsUtil if not visited
	list<int>::iterator itr;
	for (itr = adj[v].begin(); itr != adj[v].end(); itr++) {
		if (!visited[*itr]) {
			dfsUtil(*itr, visited, recStack, have_cycle);
		} else {
			if (recStack[*itr]) {
				have_cycle = true;
				cout << "Cycle between" << v << "and" << *itr << endl;
			}
		}
	}
}

// Member Function: DFS()
void Graph::DFS(int v, bool& have_cycle)
{
	// First allocate a boolean array of the number of vertices in the graph
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	// First Initialize the entire graph with visited == false
	for (int i=0; i<V; i++) {
		visited[i] = false;
		recStack[i] = false;
	}
					
	// Call the utility function to recurse and find the DFS			
	dfsUtil(v, visited, recStack, have_cycle);

	// Delete the allocated memories and initialize back the pointers
	delete [] visited;
	delete [] recStack;
	visited = NULL;
	recStack = NULL;
}

bool Graph::isCycle(int v)
{
	// First have a new array called recStack[]
	bool have_cycle = false;
	// Now call the DFS() function
	DFS(v, have_cycle);
	if (have_cycle) {
		cout << "Graph contains cycle" << endl;
	} else {
		cout << "Graph does not contain any cycles" << endl;
	}
}

// Driver Function 
int main(void)
{
	Graph g(4);
	g.addEdge(0, 1);
//	g.addEdge(0, 2);
	g.addEdge(1, 2);
//	g.addEdge(2, 0);
	g.addEdge(2, 3);
//	g.addEdge(3, 3);

	cout << "Following is the depth first traversal starting at vertex 2 \n";
	g.isCycle(2);
	return 0;
}
