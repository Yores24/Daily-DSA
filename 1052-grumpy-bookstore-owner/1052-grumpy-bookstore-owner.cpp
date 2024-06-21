class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)
            ans+=customers[i];
        }
        int uns=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                uns+=customers[i];
            }
        }
        int m=uns;
        for(int i=minutes;i<n;i++){
            if(grumpy[i-minutes]==1){
                uns-=customers[i-minutes];
            }
            if(grumpy[i]==1)
            uns+=customers[i];
            m=max(uns,m);
        }
        return ans+m;
    }
};