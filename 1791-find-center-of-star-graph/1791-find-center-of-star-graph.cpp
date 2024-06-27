class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto it=edges[0];
        auto it2=edges[1];
        if(edges[0][0]==edges[1][1]){
            return edges[0][0];
        }
        else if(edges[0][0]==edges[1][0]){
            return edges[0][0];
        }
        else if(edges[0][1]==edges[1][0]){
            return edges[0][1];
        }
        else if(edges[0][1]==edges[1][1]){
            return edges[0][1];
        }
        else{
            return -1;
        }
    }
};