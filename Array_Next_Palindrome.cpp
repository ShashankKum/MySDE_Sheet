//for next smallest palindrome first check if just reversing the left in right will do it will be our answer, or else add one to the left half and than copy it 
  to right,keep in mind right will have same no of elements as in actual right...specially keep in mind cases(9,999,9999).

string Solution::solve(string A) {
    int n=A.size();
    if(n==1){ //for one digit numbers
        if(A=="9") return "11";
        else return to_string(stoi(A)+1);
    }
    string l,r,ans;
        l=A.substr(0,n/2);
        r=l;
        reverse(r.begin(),r.end());
        ans="";
        ans+=l+r;
        if(ans>A) return ans;  //if taking reverse of left half in right will do so return the same
        else{
            int car,a,i;
            if(n%2==0) i=n/2-1;
            else i=n/2;
            l="";
             a=(A[i]-'0')+1; //to get integer value of char+1
             car=a/10;
             a=a%10;
             l+=(char)(a+'0');  //type conversion of integer to char
             i--; 
            while(i>=0){
               a=(A[i]-'0')+car;
               car=a/10;
               a=a%10;
               l+=(char)(a+'0');
               i--;
            }
            if(car!=0) l+=(char)(car+'0'); //if carry is still 1..99->100
            reverse(l.begin(),l.end());  //to get the left half reverse it
            r=l.substr(0,n/2);  //right will have digits equal to actual right half
            reverse(r.begin(),r.end()); //since palindrome so copy left and reverse it
            ans="";
            ans+=l+r; //it will be combo of left and right halves
            return ans; //return the next palindrome
        }
}
