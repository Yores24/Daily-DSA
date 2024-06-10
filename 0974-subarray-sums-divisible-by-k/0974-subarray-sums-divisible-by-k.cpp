class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        mp[0]=1;
        int count=0;
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<n;i++){
           int rem=nums[i]%k;
           if(rem<0){
            mp[rem+k]++;
            if(mp[rem+k]>1){
                count+=mp[rem+k]-1;
            }
           }
           else{
            mp[rem]++;
            if(mp[rem]>1){
                count+=mp[rem]-1;
            }
           }
           
        }
        return count;
    }
};