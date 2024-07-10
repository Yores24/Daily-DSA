class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int x=0;
        for(auto i:logs){
            if(x==0 and i=="../")
                continue;
            if(i=="./")
                continue;
            
            if(i=="../")
                x--;
            
            else
                x++;
        }
        return x;
    }
};