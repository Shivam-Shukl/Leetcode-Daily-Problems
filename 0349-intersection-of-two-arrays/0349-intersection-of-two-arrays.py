class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        nums1.sort()
        nums2.sort()

        i = 0 
        j = 0
        ans= []
        n = len(nums1)
        m = len(nums2)

        while i< n and j<m: 
            if nums1[i] == nums2[j]:
                ans.append(nums1[i])
                val = nums1[i]
                while i < n and nums1[i] == val:
                    i+=1
                while j< m and nums2[j] == val:
                    j+=1
            elif nums1[i] > nums2[j]:
                j+=1
            else :
                i+=1
        
        return ans