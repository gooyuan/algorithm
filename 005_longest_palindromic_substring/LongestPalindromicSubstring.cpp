
#include <stdio.h>

string LongestPalindromicSubstring::longestPalindrome(string s){
        if(s.empty()) return "";
        if(s.size() <3) return s;
        int len = s.size(), start=0, curLen = len;
        bool find = false;
        while(curLen > 1){
            for(start = 0; start + curLen < len; start++){
                int i=start, j=start+curLen;
                while(i<j){
                    if(s[i] == s[j]){
                        i++;
                        j--;
                    }else{
                        break;
                    }
                }
                if(i >= j){
                    find = true;
                    break;
                }
            }
            if(find) break;
            curLen--;
        }
        return s.substr(start,start + curLen);
}

int main(string args){
    return 0;
}
