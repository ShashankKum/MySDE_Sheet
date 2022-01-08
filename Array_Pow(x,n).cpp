 class Solution {
 public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long int m=n;  //if n was negative converting it to +ve might lead to overflow as -ve int limit is higher than +ve
        if(m<0) m=m*-1;
        while(m>0){ 
            if(m%2==0){  //relate with ex: 2^10=(2*2)^5
                x=x*x; //ans will be same just x will change
                m/=2;  //m will be half
            }
            else{ 
                ans=ans*x; //ans will be muitiplied by x and x will be same for further looping
                m=m-1;  //power will decrement by 1...you can relate with the example (4^5)=(4)*(4^4)
            }
        }
        if(n<0) //if power was negative .. x^n=1/x^(-n)
            ans=(double)(1.0)/(double)(ans);
        return ans;
    }
 };