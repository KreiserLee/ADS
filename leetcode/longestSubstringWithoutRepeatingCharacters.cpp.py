class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        ��s[0]��ʼ��ά��һ��������ǰ�ַ�s[i]������ظ��ַ�����
        startΪ����ͷ��endΪ����β
        pointά���ַ���λ�ã���������Ѵ����ַ������ڴ���������֮�󣬽�
        point�и��ַ���λ��ά�������µ�
        longest���������ǰ���������ֵ
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