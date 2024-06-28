class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>vec(n,0);
        for(int i=0;i<roads.size();i++){
            vec[roads[i][0]]++;
            vec[roads[i][1]]++;
        }
        sort(vec.begin(),vec.end());
        long long l=1;
        long long res=0;
        for(auto it:vec){
            res+=it*l;
            l++;
        }
        return res;

    }
};