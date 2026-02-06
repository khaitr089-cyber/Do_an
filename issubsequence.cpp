class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;  // for t
        int j = 0;  // for s
        int n = t.size();
        int m = s.size();

        if( n==0 && m==0 ){
            return true;
        }

        for( int i = 0; i<n; i++ ){
            if( t[i] == s[j] ){
                j++;
            }
            if( j == m ){
                return true;
            }
        }
        return false;
    }
};