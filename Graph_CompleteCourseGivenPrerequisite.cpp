//We need to check if it is possible to complete all the courses or not given condition that [a,b], b needs to be completed for a to be done
//In this we first need to convert the pairs in a graph format.
//if [a,b] -> for a to happen one needs to first finish b, so we will have a edge from b to a.
//In this it is similar to topological sort.
//So for the vertices to be in topological order one needs to check if there is a cycle in the directed graph or not.
//Since if cycle exists one can not be sure to complete one work before other, there will be ambiguity.


class Solution {
public:
    bool cycle(vector<vector<int>>& graph,bool b1[],bool b2[],int i){
        b1[i]=true;  b2[i]=true;
        for(auto val:graph[i]){
            if(!b1[val]){
                if(!cycle(graph,b1,b2,val))  return false; }    //once cycle is encountered recursively return false
            else if(b2[val])      //when both b1 and b2 are marked it means we have a cycle so return false
                return false;
        }
        b2[i]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses+1);
        //create a graph first from the given pairs
        for(auto v:prerequisites){
            graph[v[1]].push_back(v[0]);
        }
        bool b1[numCourses+1],b2[numCourses+1];
        memset(b1,false,sizeof(b1));      //general boolean to mark the visited vertices
        memset(b2,false,sizeof(b2));      //it marks the vertices in the current loop cycle
        for(int i=0;i<numCourses;i++){    //loop for all the unmarked vertices 
            if(!b1[i])
                if(!cycle(graph,b1,b2,i))   return false;
        }
        return true;
    }
};