#include<iostream>
#include<list>

using namespace std;

// Graph is represented as an adj. list representation
class Graph
{
private:
	int V;            // No. of vertices
	list<int> *adj;   // Pointer to an array of adj. lists
public:
	Graph(int V); // Constuctor
	void addEdge(int v, int w); // Function to add an edge to the graph
	void BFS(int s); 
};

// Constructor for the graph
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// Member Function : addEdge()
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add 'w' to v's list 
}

// Member Function : BFS(int s)
void Graph::BFS(int s)
{
	// First of all mark all the nodes as not visited
	bool *visited = new bool[V];
	for (int i=0; i<V; i++) {
		visited[i] = false;
	}

	// Create a queue for the BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// Take a list iterator to traverse the adjasency list
	list<int>::iterator itr;

	// Main while loop for traversing the the graph
	while (!queue.empty()) {
		// Dequeue the vertex from the queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all the adjecent vertices of the dequeued vertex s
		// If an adjacent vertex is not visited mark it as visited and
		// enqueue it
		for (itr = adj[s].begin(); itr != adj[s].end(); itr++) {
			if (!visited[*itr]) {
				visited[*itr] = true;
				queue.push_back(*itr);
			}		
		}
	}

}

// Driver Program
int main(void)
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is the Breadth First Traversal of the the graph starting at vertex 2 \n" ;
	g.BFS(0);

	return 0;
}
