class Solution {
public:
    string toLowerCase(string s) {
        int start = 0;
        int end = s.size() - 1;

        
    for(int i=start; i<=end;i++){
        if(s[i]>='A' && s[i]<='Z')
        s[i] = s[i]+32;
    }
     return s;

    }
};