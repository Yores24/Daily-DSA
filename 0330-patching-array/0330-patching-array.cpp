class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long s = 0; // Current maximum sum we can achieve with patches
        int i = 0;       // Current index in nums
        int c = 0;       // Number of patches added

        while (s < n) {
            // If the current sum `s` plus 1 is less than or equal to the next number in `nums`,
            // we can safely use that number to extend our sum range.
            if (i < nums.size() && nums[i] <= s + 1) {
                s += nums[i];
                i++;
            } else {
                // Otherwise, we need to patch (add) the number `s + 1` to cover this gap.
                s += s + 1;
                c++;
            }
        }

        return c;
    }
};
