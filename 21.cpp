#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int calculateLCS(string& w1, string& w2, int i, int j, vector<vector<int>>& memo) {
        if (i == 0 || j == 0) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        if (w1[i - 1] == w2[j - 1]) {
            return memo[i][j] = 1 + calculateLCS(w1, w2, i - 1, j - 1, memo);
        }
        
        return memo[i][j] = max(calculateLCS(w1, w2, i - 1, j, memo), 
                                calculateLCS(w1, w2, i, j - 1, memo));
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        int lcs = calculateLCS(word1, word2, m, n, memo);
        
        return m + n - 2 * lcs;
    }
};

int main() {
    Solution solver;
    
    string word1_1 = "sea";
    string word2_1 = "eat";
    cout << "Test Case 1: " << solver.minDistance(word1_1, word2_1) << endl;

    string word1_2 = "leetcode";
    string word2_2 = "etco";
    cout << "Test Case 2: " << solver.minDistance(word1_2, word2_2) << endl;

    return 0;
}
