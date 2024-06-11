class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int c=n-1;
        int m=0;
        int mid;
        while(m!=c){
            mid=(m+c)/2;
            if(nums[mid]>=nums[c]){
                m=mid+1;
            }
            else
                c=mid;

        }
        return nums[m];
    }
};