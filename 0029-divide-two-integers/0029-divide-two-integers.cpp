class Solution {
public:
    long long divide(long long a,long long b){
    long long result=0,neg=-1;
   
    if((a<0 && b<0)||(a>0 && b>0)) neg=1;
    if(a==-2147483648 && b==-1) return 2147483647;
     a=abs(a);
    b=abs(b);
    while (b<=a)
    {
        long long temp=0;
        
    
    while (a-(b<<1<<temp)>=0)
    {
        temp++;
    }
    result=result+(1<<temp);
    a=a-(b<<temp);
    }
    return result*neg;
    }
};