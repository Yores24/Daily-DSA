class Solution {
public:
    vector<int> asteroidCollision(vector<int>& astro) {
        stack<int>s;
        for(auto i : astro){
            if(s.empty()){
                s.push(i);
            }
            else if(i>0){
                s.push(i);
            }
            else if(i<0){
                // while(!s.empty()){
                //     if(s.top()<=abs(i)){
                //         s.pop();
                //     }
                //     else{
                //         // s.push(i);
                //         break;
                //     }
                // }
                while(!s.empty()&&s.top()>0&&s.top()<abs(i)){
                    s.pop();
                }
                if(!s.empty()&&s.top()>0){
                    if(s.top()==abs(i)){
                        s.pop();
                    }
                }
                else{
                    s.push(i);
                }
            }
        }
        vector<int>ans;
        for(;!s.empty();){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};