#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int> &Arr, int index, int N)
{
	// The child of current index are 2k and 2k+1, If k=3, then the childs are at 6 and 7 positions
	// Arr = [0,5,7,2,4,3,4,6] , index = 3, N=7
	// Case 1 : If current is smaller than both the childs, pick the elder valued child to swap
#if 0
	cout << endl;
	cout << "index=" << index;
	cout << "N =" << N;

#endif
	int largest;
	int left = 2*index;
	int right = 2*index+1;
	
	if (left <= N && Arr[index] < Arr[left]) {
		largest = left;	
	} else {
		largest = index;
	}
	if (right <= N && Arr[right] > Arr[largest]) {
		largest = right;
	}
	
	if (largest != index) {
		int temp = Arr[index];
		Arr[index] = Arr[largest];
		Arr[largest] = temp;
		heapify(Arr, largest, N);
	
	}

	return;
	
}


void build_heap(vector<int> &Arr)
{
	// Here to build the heap we need to traverse the Array from the position 
	// from N/2 until 1. We would start storing the values from position 1
	// of the array for convinience e.g. Arr = [0,5,7,2,4,3,4,6]
	int N = Arr.size() - 1;
	for (int i=N/2; i >0 ; i--) // i=3 to start with 
	{
		heapify(Arr, i, N);
	}
	return;

}

int main(void)
{
	int N;
	cin >> N;
	vector <int> Arr(N+1);

	Arr[0] = 0;
	for (int i=1; i < N+1; i++)
	{
		cin >> Arr[i];
	}
	// Array stored in the form [0,5,7,2,4,3,4,6]
	build_heap(Arr);
	// print the heap 
	cout << endl;
	for (int i=0; i < N+1; i++)
	{
		cout << Arr[i];
	}

	return 0;
}
