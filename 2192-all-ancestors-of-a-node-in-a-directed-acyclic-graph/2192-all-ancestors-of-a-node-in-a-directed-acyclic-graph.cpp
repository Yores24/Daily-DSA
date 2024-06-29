
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Create a map to store the edges in reverse (child -> parents)
        map<int, vector<int>> mp;
        for (auto& it : edges) {
            mp[it[1]].push_back(it[0]);
        }

        // Vector to store the answer for each node
        vector<vector<int>> ans(n);

        // Process each node to find its ancestors
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            priority_queue<int, vector<int>, greater<int>> pq;
            queue<int> q;
            set<int> visited;

            // Start with the current node
            q.push(i);
            visited.insert(i);

            while (!q.empty()) {
                int t = q.front();
                q.pop();

                if (mp.find(t) != mp.end()) {
                    for (auto& parent : mp[t]) {
                        if (visited.find(parent) == visited.end()) {
                            q.push(parent);
                            pq.push(parent);
                            visited.insert(parent);
                        }
                    }
                }
            }

            // Extract elements from the priority queue to get sorted order
            while (!pq.empty()) {
                temp.push_back(pq.top());
                pq.pop();
            }

            ans[i] = temp;
        }

        return ans;
    }
};