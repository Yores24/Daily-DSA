class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<int>st;
        
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(ans.length());
            else if(s[i]==')'){
                int m=st.top();
                st.pop();
                reverse(begin(ans)+m,end(ans));
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};