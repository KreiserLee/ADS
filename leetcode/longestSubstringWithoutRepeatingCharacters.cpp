#include <iostream>
#include <vector>
#include <string>
#include <hash_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, max = 0;          
        map<char, int> charPoint;
      
        for (int i = 0; i < s.length(); ++i) {
            if (charPoint.find(s.at(i)) != charPoint.end()) {
                int point = charPoint[s.at(i)];
                if (point >= start)
                    start = point + 1;
            }
            end = i;
            charPoint[s.at(i)] = i;
            if (end-start+1 > max)
                max = end-start+1;
        }
        return max;
    }
};