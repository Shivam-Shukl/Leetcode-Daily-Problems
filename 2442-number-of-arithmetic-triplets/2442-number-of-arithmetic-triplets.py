class Solution(object):
    def arithmeticTriplets(self, nums, diff):
       
        s = set(nums)   # automatically handles uniqueness
        cnt = 0
        for i in range(1, len(nums) - 1):
            if (nums[i] - diff) in s and (nums[i] + diff) in s:
                cnt += 1
        return cnt
