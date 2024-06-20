class Solution {
public:
    bool possible(vector<int>& bloomDay,int mid, int m, int k){
        int cut=0;
        int nb=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                cut++;
            }
            else{
               nb+=(cut/k);
               cut=0;
            }
        }
        nb+=(cut/k);
        if(nb>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=m*1LL*k*1LL;
        if(n<val){
            return -1;
        }
        
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        int mid;
        int ans;
        while(high>=low){
            mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;


    }
};