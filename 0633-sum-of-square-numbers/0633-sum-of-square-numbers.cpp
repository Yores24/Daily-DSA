class Solution {
public:
    bool judgeSquareSum(int c) {
        int x=sqrt(c);
        if(c==0){
            return true;
        }
        while(x){
            int m=c-(x*x);
            
            int n=sqrt(m);
                if(n*n==m){
                    return true;
                }
                x--;
            }
            return false;
        }
};