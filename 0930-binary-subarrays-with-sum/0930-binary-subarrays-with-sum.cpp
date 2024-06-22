class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
     int n=nums.size();
     map<int,int>mp;
     mp[0]=1;
     int s=0;
     int ans=0;
     for(auto i:nums){
        s+=i;
        ans+=mp[s-goal];
        mp[s]++;

     } 
     return ans;  
    }
};