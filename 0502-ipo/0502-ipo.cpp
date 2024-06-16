class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vec;
        int n=capital.size();
        for(int i=0;i<n;i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });


    priority_queue<int>pq;
    int i=0;
    while(k){
        while(i<n && vec[i].first<=w)
            pq.push(vec[i++].second);
        if(!pq.empty()){
            w+=pq.top();
            pq.pop();
        }
        k--;
        
    }
        return w;
    }
};