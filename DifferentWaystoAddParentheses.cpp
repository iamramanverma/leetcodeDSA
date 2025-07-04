// Different Ways to Add Parentheses
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

// Example 1:

// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:

// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
 

// Constraints:

// 1 <= expression.length <= 20
// expression consists of digits and the operator '+', '-', and '*'.
// All the integer values in the input expression are in the range [0, 99].
// The integer values in the input expression do not have a leading '-' or '+' denoting the sign.


// Solution 

C++ Recursive Solution | Using Expression Trees


☑️ The problem becomes easier when we think about these expressions as expression trees.

☑️ We can traverse over the experssion and whenever we encounter an operator, we recursively divide the expression into left and right part and evaluate them seperately until we reach a situation where our expression is purely a number and in this case we can simply return that number.

☑️ Since there can be multiple ways to evaluate an expression (depending on which operator you take first) we will get a list of reults from left and the right part.

☑️ Now that we have all the possible results from the left and the right part, we can use them to find out all the possible results for the current operator.


class Solution {
public:
    // function to get the result of the operation
    int perform(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    
    vector<int> diffWaysToCompute(string exp) {
        
        vector<int> results;
        bool isNumber = 1;
    
        for(int i = 0; i < exp.length(); i++) {
            // check if current character is an operator
            if(!isdigit(exp[i])) {
                
                // if current character is not a digit then
                // exp is not purely a number
                isNumber = 0;
                
                // list of first operands
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                
                // list of second operands
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));
                
                // performing operations
                for(int x : left) {
                    for(int y : right) {
                        int val = perform(x, y, exp[i]);
                        results.push_back(val);
                    }
                }
                
            }
        }
        
        if(isNumber == 1) results.push_back(stoi(exp));
        return results;
    }
};


