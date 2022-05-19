//Here time complexity becomes n*n*k since we are storing the results in 3d array.
//Here we make use of memoization technique.
//Since the events are mutually exclusive we simply add the probabilities.
//When k will be zero and knight is in the board we dont need to move anymore so the probability will be 1 for sure.
//Probability at each movement will be (sum of probabilities from all direction)/8.
//It is mutually exclusive since probability to stay at a position is independent of that of any previous position.


class Solution {
public:
    double helper(int N, int K, int r, int c, vector<vector<vector<double>>> & dp){
        if(r < 0 || c < 0 || r >= N || c >= N) return 0;     //it reaches out of boundry
        if(K == 0) return 1;                                 //when its all k moves ends but it still stays in the board
        if(dp[r][c][K] != -1) return dp[r][c][K];
        double sum = helper(N, K - 1, r - 2, c - 1, dp) +    //recur in all 8 possible directions
                     helper(N, K - 1, r - 1, c - 2, dp) +
                     helper(N, K - 1, r + 1, c - 2, dp) +
                     helper(N, K - 1, r + 2, c - 1, dp) +
                     helper(N, K - 1, r - 2, c + 1, dp) +
                     helper(N, K - 1, r - 1, c + 2, dp) +
                     helper(N, K - 1, r + 1, c + 2, dp) +
                     helper(N, K - 1, r + 2, c + 1, dp);
        sum = sum / 8;
        dp[r][c][K] = sum;
        return dp[r][c][K];
    }
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N + 1, vector<vector<double>> (N + 1, vector<double>(K + 1, -1)));
        return helper(N, K, r, c, dp);
    }
};