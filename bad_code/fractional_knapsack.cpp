#include <iostream>
#include <vector>
#include <unistd.h>

using std::vector;
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  	double value = 0.0;
	double max_frac = 0.0;
	int pos_val = -1;
	int W = capacity;
	
	int n = weights.size();
		
	int prev_pos = -1;

	while (W)
	{
		for (int i=0; i<n; i++)
		{
			if (i == pos_val){
				continue;
			}
			if (max_frac < (double)values[i]/weights[i]) {
				max_frac = (double)values[i]/weights[i];
				pos_val = i;
			}
		}

		if (W > weights[pos_val])
		{
			value = value + (double)max_frac*weights[pos_val];
			W = W - weights[pos_val];
			// Zero the values of pos_val so that it is not considered in the next round
			values[pos_val] = 0;
			max_frac = 0.0;
		} else {
			value = value + (double)max_frac*W;
			W = 0;
			// No need to zero the pos as we are already done
		}
	}
	return value;
}

int main() {
		int n;
		int capacity;
		cin >> n; 
		cin >> capacity;
		
		vector<int> values(n);
		vector<int> weights(n);
		
		for (int i = 0; i < n; i++) {
				cin >> values[i] ;
				cin >> weights[i];
		}
		
		double optimal_value = get_optimal_value(capacity, weights, values);
		std::cout.precision(7);
		std::cout << optimal_value << std::endl;
		return 0;
}
