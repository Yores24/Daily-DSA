class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long x=0;
        long long wt=0;
        for(auto i:customers){
            if(x<=i[0]){
                
                x=i[0]+i[1];
                wt+=x-i[0];
            }
            else{
                x+=i[1];
                wt+=x-i[0];
            }
            
        }
        int n=customers.size();
        cout<<wt;
        return wt/(n*1.0);
    }
};