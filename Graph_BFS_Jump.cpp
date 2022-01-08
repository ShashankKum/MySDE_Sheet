//it is a greedy BFS solution which will have a max time complexity of O(N).
//we can make a bfs graph of the nums array(all the nodes reachable in a single jump is in one level), ex -> [2,3,1,1,4] -> {(2),(3,1),(1,4)}
//each new level means a jump++.
//In this maxjump keeps track of the max position we could have reached till the current traversal
//currjump keeps track of the max jump possible till next level of bfs
//once we come to the end of a level, we equate curjump to maxjump.


class Solution {
public:
    int jump(vector<int>& nums) {
      int maxjump=0,curjump=0,n=nums.size(),i=0,jumps=0;
        if(n==1) return jumps;         //if only one index means only one level
        while(curjump<(n-1)){
            maxjump = max(maxjump,i+nums[i]);
            if(i==curjump){
                curjump=maxjump;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};