//  Set Mismatch
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

// Example 1:

// Input: nums = [1,2,2,4]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1]
// Output: [1,2]
 

// Constraints:

// 2 <= nums.length <= 104
// 1 <= nums[i] <= 104


// SOLUTION ------


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        // a vector to store answer
        vector<int> v;
        // finding duplicate in given array
        int dup = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i]==nums[i+1]) {
                dup = nums[i];
                break;
            }
        }
        v.push_back(dup);
        // now finding the missing number by calculating the sum of n natural numbers with the sum we obtain from given array (excluding the repeating number);
        int actual_sum = (n*(n+1))/2;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
                sum += nums[i];
        }
        sum -= dup;
        int miss = actual_sum - sum;
        v.push_back(miss);
        return v;
    }
};