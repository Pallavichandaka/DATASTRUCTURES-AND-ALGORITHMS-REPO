class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        if (sLen == 0) return true;
        int i = 0, j = 0; 
        while (j < tLen && i < sLen) {
            if (s[i] == t[j]) {
                i++; 
                j++;
            }
            else{
                j++; 
            }
        }
      return i == sLen; 
    }
};
