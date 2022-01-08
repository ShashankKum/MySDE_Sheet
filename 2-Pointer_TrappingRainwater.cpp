//we keep on checking what amount of water can be added at each index.
//amount of water that can be added at a particular index is: (min(leftmax,rightmax)-a[i])
//Time taken will be O(N) and space will be O(N)
//We can further optimise it using 2 pointer approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),ans=0;
        if(n==0 || n==1) return 0;
        int suf[n],pref[n];
        suf[n-1]=height[n-1];
       for(int i=n-2;i>=0;i--){  //we create suffix array which will have the right max for each index
           if(height[i]>suf[i+1])
               suf[i]=height[i];
           else
               suf[i]=suf[i+1];
       } 
        pref[0]=height[0];
        for(int i=1;i<n;i++){     //we create a prefix array which will have the left max value for each particular index
            if(height[i]>pref[i-1])
                pref[i]=height[i];
            else
                pref[i]=pref[i-1];
        }
        for(int i=0;i<n;i++){
            ans+=(min(pref[i],suf[i]))-height[i];
        }
        return ans;
    }
};

//2-pointer
//Here l and r are left and right pointers respectively and lmax and rmax are maximum left and right ht for a current index.
//whenever a bigger ht than height[r] comes in left side we make r-- by keeping l as it is, so that whenever (height[l]<=height[r]) //comes it means that we already have a height >= leftmax, vice versa for the reverse case when we do l++ and r as it is.
//Time taken is O(N) and space is O(1).


class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),ans=0;
        if(n==0 || n==1) return 0;
        int l=0,r=n-1,lmax=0,rmax=0;
        while(l<r){
          if(height[l]<=height[r]){  //in this we are confirmed that in right there is atleast one which is bigger or equal to lmax
                if(height[l]>lmax)   //lmax is updated
                    lmax=height[l];
                else
                    ans+=(lmax-height[l]);  //we only see for lmax as we know at right rmax is surely greater than equal to lmax
                l++;
            }
            else{                   //same cases applied in vice versa manner here
                if(height[r]>rmax)
                    rmax=height[r];
                else
                    ans+=(rmax-height[r]);
                r--;
            }
        }
        return ans;
    }
};