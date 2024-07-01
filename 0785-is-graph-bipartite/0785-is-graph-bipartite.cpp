class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>c(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(c[i]) continue;
            c[i]=1;
            q.push(i);

            while(!q.empty()){
                int temp=q.front();
                q.pop();
                for(auto it:graph[temp]){
                    if(!c[it]){
                        c[it]=-c[temp];
                        q.push(it);
                    }
                    else if(c[it]==c[temp])
                    return false;
                }

            }

        }
        return true;
    }
};