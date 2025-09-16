class Solution(object):
    def arithmeticTriplets(self, nums, diff):
        """
        :type nums: List[int]
        :type diff: int
        :rtype: int
        """
        dict = {}
        for ele in nums:
            dict[ele] = True

        cnt = 0
    
        for i in range(1,len(nums) -1):
            a = nums[i] - diff
            b = nums[i] + diff
            if a in dict and b in dict :
                cnt= cnt + 1
        
        return cnt