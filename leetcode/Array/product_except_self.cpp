#include <bits/stdc++.h>

using namespace std;

void Out(vector<int>& arr) {
	cout << "[ ";
	for (int x : arr) cout << x << " ";
	cout << "]" << endl;
}

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> left(nums.size()), right(nums.size()), temp(nums.size());
	left[0] = 1;
	right[nums.size() - 1] = 1;
	for (int i = 1; i < left.size(); i++) left[i] = left[i - 1] * nums[i - 1];
	for (int i = right.size() - 2; i >= 0; i--) right[i] = right[i + 1] * nums[i + 1];
	for (int i = 0; i < temp.size(); i++) temp[i] = left[i] * right[i];
	return temp;
}

int main() {
	vector<int> a = {1, 2, 3, 4, 5};
	Out(a);
	vector<int> b = productExceptSelf(a);
	Out(b);
}
