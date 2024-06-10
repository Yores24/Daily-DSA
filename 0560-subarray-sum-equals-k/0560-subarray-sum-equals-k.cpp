class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int psum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
            int remove=psum-k;
            cnt+=mp[remove];
            mp[psum]+=1;
        }
        return cnt;
        
    }
};