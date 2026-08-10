class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:

        mapping_dict = defaultdict(int)
        stack = []
        answer = []

        for i in range(len(nums2) - 1, -1, -1):
            while stack and nums2[i] > stack[-1]:
                stack.pop()

            if not stack:
                mapping_dict[nums2[i]] = -1
                stack.append(nums2[i])
                continue
            mapping_dict[nums2[i]] = stack[-1]
            stack.append(nums2[i])

        for i in range(0, len(nums1)):
            answer.append(mapping_dict[nums1[i]])

        return answer