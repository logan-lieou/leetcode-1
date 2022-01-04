#include <bits/stdc++.h>

using namespace std;

int maxProfit(const vector<int>& prices) {
	// brute force solution
	int maxProfit = 0;
	for (int i = 0; i < prices.size() - 1; i++) {
		for (int j = 1 ; j < prices.size() - i; j++) {
			maxProfit = max(maxProfit, prices[i + j] - prices[i]);
		}
	}
	return maxProfit;
}

int main() {
	vector<int> arr = {1, 3, 1, 4, 5, 9, 2, 8, 1};
	cout << maxProfit(arr) << endl;
}
