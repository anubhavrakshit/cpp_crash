#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
// Return the pivot index of a partioned array
int partition(vector<int> &nums, int left, int right) {
	cout << "left " << left << " right " << right << endl;

	int part_idx = -1;
	int pivot = nums[right];
	for (int i = left; i <= right; i++) {
		if (nums[i] < pivot) {
			part_idx++;
			swap(nums[i], nums[part_idx]);
		}
	}
	swap(nums[part_idx + 1], nums[right]);
	return part_idx + 1;
}
void helper(vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}

	int pivot_idx = partition(nums, left, right);
	assert(pivot_idx >= 0 and pivot_idx <= right);
	helper(nums, left, pivot_idx - 1);
	helper(nums, pivot_idx + 1, right);
}

void QuickSort(vector<int> &nums, int size) {
	// TODO: Write - Your - Code
	// Partition such that two arrays
	// array_left is less than pivot
	// array_right more than pivot
	helper(nums, 0, size - 1);
	return;
}

int main() {
    vector<int> test = {57, 189, 2, 33, 45, 900, 1239, 23, 567402, 901};
    QuickSort(test, test.size());
    for (auto n : test) {
        cout << n << ", ";
    }
    cout << endl;
    return 0;
}