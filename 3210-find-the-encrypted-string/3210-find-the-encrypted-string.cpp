class Solution {
public:
    string getEncryptedString(string s, int k) {
        string m="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if((i+k)>n-1){
                m+=s[(i+k)%n];
            }
            else{
                m+=s[i+k];
            }
        }
        return m;
    }
};