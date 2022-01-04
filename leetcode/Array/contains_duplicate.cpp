#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
	// O(nlogn)
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++) if (nums[i] == nums[i + 1]) return true;
	return false;
}

int main() {
	vector<int> arr = {1, 2, 1};
	cout << (containsDuplicate(arr) == 0 ? "false" : "true") << endl;
}
