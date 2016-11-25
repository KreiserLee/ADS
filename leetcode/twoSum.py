class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # htarget means the another position of pair
        htarget = {}
        result = []
        for i in range(0, len(nums)):
            htarget[target-nums[i]] = i
        
        print htarget
        
        for i in range(0, len(nums)):
            if htarget.has_key(nums[i]):
                if htarget[nums[i]] != i:
                    result.append(i)
                    result.append(htarget[nums[i]])
                    break
        return result
        
s = Solution()
print s.twoSum([3,2,4], 6)
