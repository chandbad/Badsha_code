#include<iostream>
#include<string>
#include<list>

using namespace std;
class UnionFind {
	private:
		int *parent, *rank, cnt;
	public:
		// Constructor: Create an empty union find data structure with N isolated sets
		// the constructor will work as the function makeSet()
		UnionFind(int N) {
			cnt = N;
			parent = new int[N];
			rank = new int[N];

			// Initialize the arrays. To start with the rank should be 0 as all the nodes are the leaf nodes
			for (int i=0; i < N; i++) {
				parent[i] = i;
				rank[i] = 0;
			}
		}

		// Destructor
		~UnionFind () {
			delete [] parent;
			delete [] rank;
		}

		// Member Function: find(): Return the parent of the component corresponding to the object p.
		int find(int p) 
		{
			int root = p;
			while (root != parent[root]) {
				root = parent[root];
			}

			// Path compression is happening here in order to simplify the lookup
			while (p != root) {
				int newp = parent[p];
				parent[p] = root;
				p = newp;
			}
			return root;
		}

		void Union(int x, int y) 
		{
			int i = find(x);
			int j = find(y);

			// If the parent for the both are same return
			if (i == j) {
				return;
			}

			// Now take a decision to hang based on the rank. Make the smaller 
			// root hang from the bigger
			if (rank[i] > rank[j]) {
				// Hang subtree with j as root under subtree with i as root
				parent[j] = i;
				rank[i] += rank[j];
			} else {
				parent[i] = j;
				rank[j] += rank[i];
			}
			// Decrement the count
			cnt--;
		}

		// member function: is_connected
		bool is_connected(int x, int y) {
			return (find(x) == find(y));
		}

		// member function : Return the number of disjoint sets
		int count () {
			return cnt;
		}
};

// Driver Function to test the implementation for the union find DS
int main()
{	
		UnionFind U(5);
		for (int i=0; i<5; i++) {
				cout << U.find(i) << " ";
		}
		U.Union(0,1);
		U.Union(2,3);
		U.Union(3,4);
		U.Union(1,4);
		cout << "\n";
		for (int i=0; i<5; i++) {
				cout << U.find(i) << " ";
		}
		cout << "\nCount is :" << U.count();
		return 0;

}
