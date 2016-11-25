class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        从s[0]开始，维护一个包含当前字符s[i]的最长无重复字符序列
        start为序列头，end为序列尾
        point维护字符的位置，如果遇到已存在字符，则在处理完序列之后，将
        point中该字符的位置维护至最新的
        longest保存截至当前遇到过的最长值
        """
        start = 0
        end = 0
        longest = 0
        point = {}
        for i in range(0, len(s)):
            nowPtr = point.get(s[i])
            if nowPtr == None:
                pass
            elif nowPtr >= start:
                start = nowPtr+1
            end = i
            point[s[i]] = i
            if longest < end-start+1:
                longest = end-start+1
        return longest