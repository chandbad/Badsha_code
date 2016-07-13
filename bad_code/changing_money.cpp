/*
Problem:  Changing Money

Problem Introduction :
In this problem, you will design an algorithm for changing money optimally.

Problem Description :
The goal in this problem is to  nd the minimum number of coins needed to change the input value
(an integer) into coins with denominations 1, 5, and 10.

Input Format :
The input consists of a single integer
m

Constraints.
1 <= m <= 10^3

Output Format.
Output the minimum number of coins with denominations 1, 5, 10 that changes m
*/


#include <iostream>

using namespace std;

int computeMinChange(unsigned int m)
{
	int count = 0;
	// We have denominations 10, 5 and 1

	while (m)
	{
		if (m/10 == 0 && m%10 == m) 
		{
			if (m/5 == 0 && m%5 == m)
			{
				// Here we know that m < 5
				count = count + m;
				m = 0;
			} else {
				count = count+(m/5);
				m = m%5;
			}
		} else {
			count = count+(m/10);
			m = m%10;
		}
	}
	return count;
}


int main(void)
{
	unsigned int m;
	cin >> m;
	unsigned int count = computeMinChange(m);
	cout << count;
	return 0;
}
