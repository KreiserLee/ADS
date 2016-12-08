#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        string maxStr = "";
        for (int i = 0; i < s.length(); ++i) {
            // 奇数回文
            int len = 1;
            int j = 1;
            while(i-j >= 0 && i+j <= s.length()-1) {
                if (s[i-j] != s[i+j])
                    break;
                ++j;
                len += 2;
            }
            if (len > max) {
                max = len;
                maxStr = s.substr(i-j+1, (j-1)*2 + 1);
            }
            // 偶数回文
            if (i+1 < s.length() && s[i] == s[i+1]) {
                len = 2;
                int j = 1;
                while(i-j >= 0 && i+j+1 <= s.length()-1) {
                    if (s[i-j] != s[i+j+1])
                        break;
                    ++j;
                    len += 2;
                }
                if (len > max) {
                    max = len;
                    maxStr = s.substr(i-j+1, (j-1)*2 + 2);
                }
            }
        }
        return maxStr;
    }
};

int main()
{
    string s = "cccccccccc";
    Solution Ss = Solution();
    cout << Ss.longestPalindrome(s) << endl;
    
    return 0;
}