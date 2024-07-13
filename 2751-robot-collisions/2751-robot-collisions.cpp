#include <vector>
#include <map>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int, pair<int, char>> mp;
        int n = healths.size();

        for (int i = 0; i < n; i++) {
            mp[positions[i]] = {healths[i], directions[i]};
        }

        stack<int> st;
        vector<int> toErase; // To keep track of positions to erase
        int i=0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int pos = it->first;
            int health = it->second.first;
            char dir = it->second.second;

            while (!st.empty() && mp[st.top()].second == 'R' && dir == 'L') {
                cout<<i<<"asd";
                int topPos = st.top();
                int topHealth = mp[topPos].first;

                if (topHealth > health) {
                    mp[topPos].first--;
                    toErase.push_back(pos);
                    break;
                } else if (topHealth < health) {
                    cout<<"called";
                    mp[pos].first--;
                    health--;
                    
                    toErase.push_back(topPos);
                    st.pop();
                } else {
                    cout<<"abc";
                    toErase.push_back(topPos);
                    toErase.push_back(pos);
                    st.pop();
                    break;
                }
            }

            if (dir == 'R' || (dir == 'L' && st.empty()) || (dir == 'L' && mp[st.top()].second == 'L')) {
                cout<<i<<" ";
                i++;
                st.push(pos);
            }
        }

        // Erase marked positions
        for (int pos : toErase) {
            mp.erase(pos);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mp.find(positions[i]) != mp.end()) {
                ans.push_back(mp[positions[i]].first);
            }
        }

        return ans;
    }
};
