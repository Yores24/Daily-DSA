class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>ch;
        ch=heights;
        sort(ch.begin(),ch.end());
        int c=0;
        for(int i=0;i<ch.size();i++){
            if(ch[i]!=heights[i])
                c++;
        }
        return c;
    }
};