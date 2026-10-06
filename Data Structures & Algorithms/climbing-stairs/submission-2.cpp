class Solution {
public:
    // Memoization

    int recursion(int n, vector<int>& memo){
        // Base case
        if(n <= 2) return n;
        
        if(memo[n] != -1) return memo[n];

        memo[n] = recursion(n-1, memo) + recursion(n-2, memo);

        return memo[n];
    }

    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        
        return recursion(n, memo);
    }
};
