class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>ind(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0)
            q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[t]){
                ind[it]--;
                if(ind[it]==0)
                    q.push(it);
            }
        }
        if(cnt==numCourses)
            return true;
        else return false;
    }
};