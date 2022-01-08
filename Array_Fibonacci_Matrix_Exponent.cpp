class Solution {
public:
    int my_fib(int a,int b,int n){
        if(n==1)
            return b;
        int c;
        c=a+b;
        n--;
        return my_fib(b,c,n);
    }
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return my_fib(0,1,n);
    }
};


//For matrix exponentiation method we basically find the nth fibonacci number in O(logN) time.
//In this nth fibonacci is same as F[0][0] of F[2][2]^(n-1), where  F[2][2]={{1,1},{1,0}}.
//It uses O(logN) time as everytime n is being divided by 2

class Solution {
public:
    void multiply(int F[2][2],int M[2][2]){  //it is a function used to multiply two matrices
        int a,b,c,d;
        a=F[0][0]*M[0][0]+F[0][1]*M[1][0];
        b=F[0][0]*M[1][0]+F[0][1]*M[1][1];
        c=F[1][0]*M[0][0]+F[1][1]*M[1][0];
        d=F[1][0]*M[1][0]+F[1][1]*M[1][1];
        //make F[][2] only as the new matrix,formed by multiplying F[][2] and M[][2]
        F[0][0]=a;
        F[0][1]=b;
        F[1][0]=c;
        F[1][1]=d;
    }
    void power(int F[2][2],int M[2][2],int n){  //Recursive function to calculate F[2][2]^(n-1)
        //Base case
        if(n==1)  
            return;
        power(F,M,n/2); //this step will keep on recurring till n becomes 1
        multiply(F,F); //each time F[2][2] will be updated as F[2][2]^2,(matrix is pass by refrence)
        if(n%2!=0)
            multiply(F,M); //if n is odd
    }
    int fib(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        int F[2][2]={{1,1},{1,0}}; 
        int M[2][2]={{1,1},{1,0}};
        power(F,M,n-1);  //we paas n-1 as we need F[2][2]^(n-1)
        return F[0][0]; 
    }
};