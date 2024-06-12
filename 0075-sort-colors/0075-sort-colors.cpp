class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;

        }
        vector<int>ans;
        for(auto it:mp){
            int c=it.second;
            while(c!=0){
                ans.push_back(it.first);
                c--;
            }
        }
        nums=ans;
    }
};