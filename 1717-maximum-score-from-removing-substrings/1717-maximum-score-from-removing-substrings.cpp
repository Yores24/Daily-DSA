class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int l=s.length();

        string k="";
        string k2="";
        int count=0;
        if(x>y){
            for(int i=0;i<l;i++){
                if(k==""){
                    k+=s[i];
                    continue;
                }
                if(k.back()=='a' && s[i]=='b'){
                    count+=x;
                    k.pop_back();
                    continue;
                }
                k+=s[i];
            }
            int l2=k.length();
            for(int i=0;i<l2;i++){
                if(k2==""){
                    k2+=k[i];
                    continue;
                }
                if(k2.back()=='b' && k[i]=='a'){
                    count+=y;
                    k2.pop_back();
                    continue;
                }
                k2+=k[i];
            }

        }
        else{
                for(int i=0;i<l;i++){
                if(k==""){
                    k+=s[i];
                    continue;
                }
                if(k.back()=='b' && s[i]=='a'){
                    count+=y;
                    k.pop_back();
                    continue;
                }
                k+=s[i];
            }
            int l2=k.length();
            for(int i=0;i<l2;i++){
                if(k2==""){
                    k2+=k[i];
                    continue;
                }
                if(k2.back()=='a' && k[i]=='b'){
                    count+=x;
                    k2.pop_back();
                    continue;
                }
                k2+=k[i];
            }

        }
        return count;
    }
};