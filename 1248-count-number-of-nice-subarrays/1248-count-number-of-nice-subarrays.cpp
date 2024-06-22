#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 0;  // Total number of subarrays
        for (int i = 0; i < n; i++) {
            // Convert nums to a binary representation where 1 means odd and 0 means even
            if (nums[i] % 2) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }

        int i = 0, j = 0;
        int cz = 0;  // Number of consecutive zeros
        int sum = 0; // Sum of current window

        while (j < n) {
            sum += nums[j];
            while (i < j && (nums[i] == 0 || sum > k)) {
                if (nums[i] == 0) {
                    cz++;
                } else {
                    cz = 0;
                }
                sum -= nums[i];
                i++;
            }
            if (sum == k) {
                s += 1 + cz;
            }
            j++;
        }
        return s;
    }
};
