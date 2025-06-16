												LEETCODE 

// 242. Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.


// SOLUTION ---


class Solution {
	public:
    		bool isAnagram(string s, string t) {
        		if (s.length() != t.length()) {
            			return false;
        }

        	unordered_map<char, int> counter;

        	for (char ch : s) {
            		counter[ch] = counter[ch] + 1;
        }

        	for (char ch : t) {
           		 if (counter.find(ch) == counter.end() || counter[ch] == 0) {
                		return false;
            }
           	 counter[ch] = counter[ch] - 1;
        }

       	 return true;        
    }
};

