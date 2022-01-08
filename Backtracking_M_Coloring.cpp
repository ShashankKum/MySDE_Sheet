//In this we have to allocate color to each node such that no two adjacent nodes have the same color.
//In this we use the concept of backtacking(do,recur,undo) in which we first start from first node try out a color and mark the node, than we move to 
  i+1 node check for it, if for a particular node no such color fits we bactrack we undo the current color and change the color of the previous node,
  and than try recursion for the same.
//There are total O(m^V) combination of colors. So time complexity is O(m^V),this is same for both backtracking and naive approach.
  The upperbound time complexity remains the same but the average time taken will be less for backtracking.
//Space complexity will be O(V).  

class m_color{
public:
int b[21];

bool isSafe(bool graph[101][101],int i,int col,int v){  //it will check if any adjacent vertex is of the same color,if yes than it will return false
    for(int j=0;j<v;j++){  
        if(graph[i-1][j]==1){
            if(b[j+1]==col)
            return false;
        }
    }
    return true;
}
bool color(bool graph[101][101],int i,int m,int v){
    if(i==(v+1))  //it means all vertices have been travelled
    return true;
    for(int c=1;c<=m;c++){  //used for choosing the right color for the node
        if(isSafe(graph,i,c,v)){
        //do
        b[i]=c;
        //recur
        if(color(graph,i+1,m,v))  //if one true is returned repetedly all true will be returned
        return true;
        //undo
        b[i]=-1;  //if nothing will work we have to try with different color
        }
    }
    return false; //if no color is safe for the position
}
bool graphColoring(bool graph[101][101], int m, int V) {
    memset(b,-1,sizeof(b));
    return color(graph,1,m,V);
}
};