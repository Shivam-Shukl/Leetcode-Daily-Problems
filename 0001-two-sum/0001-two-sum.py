class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        my_dict = {}
        for i in range(len(nums)):
            key = nums[i]
            value = i
            my_dict[key] = value
        
        ans = []

        for i in range(len(nums)):
            key1 = nums[i]
            key2 = target - key1
            if key2 in my_dict and my_dict[key2] != i:
                ans.append(i)
                ans.append(my_dict[key2])  # ✅ fixed this line
                break
        return ans
