class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        n1 = len(nums1)
        n2 = len(nums2)
        low = 0
        high = len(nums1)

        while low <= high:
            cut_1 = (low + high) // 2
            cut_2 = ((n1 + n2 + 1) // 2) - cut_1

            left_1 = 0
            left_2 = 0
            right_1 = 0
            right_2 = 0

            if cut_1 == 0:
                left_1 = float('-inf')
            else:
                left_1 = nums1[cut_1 - 1]
            if cut_2 == 0:
                left_2 = float('-inf')
            else:
                left_2 = nums2[cut_2 - 1]
            if cut_1 == n1:
                right_1 = float('inf')
            else:
                right_1 = nums1[cut_1]
            if cut_2 == n2:
                right_2 = float('inf')
            else:
                right_2 = nums2[cut_2]

            if left_1 <= right_2 and left_2 <= right_1:
                if (n1 + n2) % 2 == 0:
                    return (max(left_1, left_2) + min(right_1, right_2)) / 2.0
                else:
                    return max(left_1, left_2)
            elif left_1 > right_2:
                high = cut_1 - 1
            else:
                low = cut_1 + 1
        
        return 0.0
            
            
        