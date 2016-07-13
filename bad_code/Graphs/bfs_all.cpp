#include <iostream>
#include <list>

using namespace std;
// Define the class for the Breadth First Search
class Graph {
	private:
		int V;
		list<int> *adj;
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void BFS();
};

// Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// Member function : addEdge()
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v's adjacency list
}

// Member Function : BFS()
void Graph::BFS()
{
	int v;
	// First mark all the nodes are not visited
	bool *visited = new bool[V];
	for (int i=0; i<V; i++) {
		visited[i] = false;
	}

	// Create queue for the BFS

	// Now the actual logic
	// First go through the list and see which all nodes are visited, if not 
	// visited then first print it and then go through the asjacency list 
	// of the node and print 

	for (int i=0; i<V; i++) {
		list<int> queue;
		// check if the Vertex is already traversed
		if (!visited[i]) {
			// Mark it visited and enqueue
			visited[i] = true;
			queue.push_back(i);
		}
		while (!queue.empty()) {
				// Pop from the front and print the value
				v = queue.front();
				cout << v << " ";
				queue.pop_front();
				// Go through the adjasency list 

				list<int>::iterator itr;
				for (itr=adj[v].begin(); itr!=adj[v].end(); itr++) {
						if (!visited[*itr]) {
								// Mark visited
								visited[*itr] = true;
								queue.push_back(*itr);
						}
				}
		}
	}
}

int main(void)
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following are the breadth first traversal";
	g.BFS();

	return 0;
}
