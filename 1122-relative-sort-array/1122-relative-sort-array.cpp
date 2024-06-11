class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        int n=arr1.size();
        for(int i=0;i<n;i++){
            mp[arr1[i]]++;
        }
        // int x=0;
        // mp[2]--;
        vector<int>ans;
        for(int i=0;i<arr2.size();){
            ans.push_back(arr2[i]);
            if(mp[arr2[i]]==1){
                mp.erase(arr2[i]);
                i++;
            }
            else
                mp[arr2[i]]--;
        }
        for(auto it:mp){
            if(it.second>0){
                int c=it.second;
                while(c!=0){
                ans.push_back(it.first);
                c--;
                }
            }
            // cout<<it.first<<endl;
            // cout<<it.second<<endl;
        }
        return ans;
    }
};