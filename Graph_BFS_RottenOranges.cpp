//In this we use BFS to solve the problem, we first find out the co-ordinates of the rotten oranges and than put them in a queue
//than do a bfs to get all its adjacent fresh oranges with time time++, and than mark them as rotten, place them again in queue
//and repeat it till the queue becomes empty.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cntEmpty=0;
        queue<pair<pair<int,int>,int>> q;      //store (x,y), time
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({{i,j},0});
                if(grid[i][j]==0)
                    cntEmpty++;
            }
        }
        int dirX[] = {-1,1,0,0},dirY[] = {0,0,-1,1},new_X,new_Y;
        int rotten=0,x,y,time=0;
        pair<pair<int,int>,int> p;
        while(!q.empty()){        // traverse till the queue is empty(no rotten oranges left)
            p = q.front();       //get the first entered node from queue
            x=p.first.first;
            y=p.first.second;
            time=p.second;    //whatever is the time to reach current node, it will take time+1 to rotten its adjacent nodes
            q.pop();              //pop the node once visited
            rotten++;
            for(int i=0;i<4;i++){  //check all the adjacent directions to make the fresh oranges as rotten
                new_X = x+dirX[i];    //to generate adjacent co-ordinates
                new_Y = y+dirY[i];
                if(new_X>=0 && new_X<n && new_Y>=0 && new_Y<m && grid[new_X][new_Y]==1){  //check for valid pos and fresh orange
                    grid[new_X][new_Y]=2;   //once the pos is visited mark it as rotten
                    q.push({{new_X,new_Y},time+1}); //increment time by 1,as current node will take 1 more sec to rotten its adj
                }
            }
        }
        if((rotten+cntEmpty)!=n*m)
            return -1;
        return time;
    }
};