class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
       int n=arr.size();
       int j=0;
       for(int i=0;i<n;i++){
        if(j==3)
            return true;
        if(arr[i]%2){
            j++;
        }
        else{
            j=0;
        }
       }
        if(j==3) return true;
       return false;
    }
};