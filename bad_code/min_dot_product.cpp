#include<algorithm>
#include<iostream>
#include<vector>

// Greedy  //

using namespace std;

long long calc_min_product(vector<int> A, vector<int> B)
{
	long long prod = 0;
	// Appy the greedy logic here that the first array is sorted in ascending
	// and the second array is sorted in descending order.
	sort (A.begin(), A.end());
	sort (B.begin(), B.end(), greater<int>());
#if 0
	cout << endl;
	for (int i=0; i < A.size(); i++) {
		cout << A[i];
	}
	cout << endl;
	for (int i=0; i < B.size(); i++) {
		cout << B[i];
	}
	cout << endl;
#endif
	for (int i=0; i < A.size(); i++) {
		prod = prod + A[i]*B[i];
	}
	return prod;
}


int main(void)
{
	int N;
	cin >> N;

	vector <int> A(N);
	vector <int> B(N);
	for (int i=0; i<N ; i++) {
		cin >> A[i]; 
	}
	for (int i=0; i<N ; i++) {
		cin >> B[i]; 
	}

	long long min_prod = calc_min_product(A,B);
	cout << min_prod;
	return 0;
}
