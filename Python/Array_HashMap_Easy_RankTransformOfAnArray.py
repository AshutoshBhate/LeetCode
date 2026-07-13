class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        order = sorted(arr)
        order_dict = {}
        curr = float('-inf')
        last_order = 0

        for i in range(0, len(order)):
            if curr != order[i]:
                order_dict[order[i]] = last_order + 1
                last_order += 1
                curr = order[i]
            else:
                order_dict[order[i]] = last_order
        
        answer = []

        for i in range(0, len(arr)):
            answer.append(order_dict[arr[i]])

        return answer
        