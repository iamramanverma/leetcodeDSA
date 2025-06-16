//  448. Find All Numbers Disappeared in an Array
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:

// Input: nums = [1,1]
// Output: [2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
 

// Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 1,095,018/1.8M
// Acceptance Rate
// 62.4%
// Topics
// icon
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (89)


// SOLUTION ------

// Solution with arrays------


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};



// Solution using hashMap --------------


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> arr(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(arr.find(i) == arr.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};