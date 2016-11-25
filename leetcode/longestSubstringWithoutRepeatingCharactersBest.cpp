#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, max = 0;          
        int charPoint[256] = {-1};
        
        // 为了不和0位置冲突
        for (int i = 0; i < 256; ++i)
            charPoint[i] = -1;
        
        for (int i = 0; i < s.length(); ++i) {
            if (charPoint[s[i]] >= start)
                start = charPoint[s[i]] + 1;
            end = i;
            charPoint[s[i]] = i;
            if (end-start+1 > max)
                max = end-start+1;
        }
        return max;
    }
};