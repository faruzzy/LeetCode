// 667. Beautiful Arrangement II
// https://leetcode.com/problems/beautiful-arrangement-ii/

/*
Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement: 
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
Note:
The n and k are in the range 1 <= k < n <= 104.
*/

class Solution {
public:
	vector<int> constructArray(int n, int k) {
		if (k < 0 or k >= n) {
			return {};
		}
		vector<int> result;
		result.push_back(1);
		array<int, 2> A({2, n});
		for (int i = 1; i < k; ++i) {
			int id = i % 2;
			result.push_back(A[id]);
			if (i % 2) {
				--A[id];
			}
			else {
				++A[id];
			}
		}
		if (result.back() == A[0] - 1) {
			for (int i = A[0]; i <= A[1]; ++i) {
				result.push_back(i);
			}
		}
		else {
			for (int i = A[1]; i >= A[0]; --i) {
				result.push_back(i);
			}
		}
		return result;
	}
};