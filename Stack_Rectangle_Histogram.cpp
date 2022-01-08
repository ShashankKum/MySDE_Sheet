//We need to get the maximum area of rectangle
//For this we will take the leftmost index for each (index) till the current index is the least height and same for right,we will store all left 
  right points for each index in a vector which will be later used to calculate the area.
//This will be achived using stack by containing the elements of least heights in an order.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> s;  //left stack
        stack <int> s1; //right stack
        int l=heights.size(),i=0,m,ans=0;
        vector <int> left(l),right(l); //vector containing left and right position.
        bool flag;
        //creating the left vector containing the max left position having ht >= current ht
        while(i<l){
            flag=0;
            while(!s.empty()){
                if(heights[s.top()]>=heights[i]){
                    flag=1;
                    m=s.top();
                    s.pop();
                }
                else
                break;
            }
            if(flag==1)   left[i]=left[m];
            else if(s.empty()) left[i]=0;
            else  left[i]=i;
            s.push(i);
            i++;
        }
        //creating the right vector containing the max left position having ht >= current ht
        i=l-1;
        while(i>=0){
            flag=0;
            while(!s1.empty()){
                if(heights[s1.top()]>=heights[i]){
                    flag=1;
                    m=s1.top();
                    s1.pop();
                }
                else
                break;
            }
        if(flag==1)   right[i]=right[m]; //we dont need mth position but we need the last posititon till which mth index is the minimum,it can be considerded a dynamic approach
        else if(s1.empty()) right[i]=l-1;
        else  right[i]=i;
        s1.push(i);
        i--;
        }
        //calculating the area for each((right-left)*ht) and than storing the max.
        for(i=0;i<l;i++){
            m=(right[i]-left[i]+1)*heights[i];
            ans=max(ans,m);
        }
        return ans;
    }
};