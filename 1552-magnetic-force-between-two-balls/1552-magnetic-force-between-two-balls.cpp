class Solution {
public:
    bool possible(int midf,vector<int>& position, int m){
        int count=1;
        int prev=position[0];

        for(int i=1;i<position.size();i++){
            int curr=position[i];
            if(curr-prev>=midf){
                prev=curr;
                count++;
            }
            if(count==m)
            break;
        }
        return count==m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int minf=1;
        int maxf=position[position.size()-1]-position[0];
        int midf;
        int ans;
        while(minf<=maxf){
            midf=(minf+maxf)/2;
            if(possible(midf,position,m)){
                ans=midf;
                minf=midf+1;
            }
            else{
                maxf=midf-1;
            }
        }
        return ans;
    }
};