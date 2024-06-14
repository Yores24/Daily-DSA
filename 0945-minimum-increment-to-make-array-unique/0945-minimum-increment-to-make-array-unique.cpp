class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int c=0;
        for(auto it:mp){
            if(it.second>1){
                c+=it.second-1;
                mp[it.first]-=it.second-1;
                mp[it.first+1]+=it.second-1;
            }
        }
        return c;
    }
};