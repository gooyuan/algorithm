
#include "LongestPalindromicSubstring.h"
#include <iostream>

string LongestPalindromicSubstring::longestPalindrome(string s){
	if (s.empty()) return "";
	if (s.size() == 1) return s;
	int min_start = 0, max_len = 1;
	for (int i = 0; i < s.size();) {
		if (s.size() - i <= max_len / 2) break;
		int j = i, k = i;
		// Skip duplicate characters. 因为重复的字符肯定是属于palindrome string, 这里只是增加右边的值, 并更新下一次查找的位置
		while (k < s.size()-1 && s[k+1] == s[k]) ++k; 
		i = k+1;
		while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
		int new_len = k - j + 1;
		if (new_len > max_len) { min_start = j; max_len = new_len; }
	}
	return s.substr(min_start, max_len);
}

int main(void){
	LongestPalindromicSubstring l;
	cout << l.longestPalindrome("abbd") << endl;
    return 0;
}
