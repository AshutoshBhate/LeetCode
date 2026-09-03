from collections import deque

'''
Definition for Node
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    def bottomView(self, root):
        answer = []
        
        if root is None:
            return answer
            
        map = {}
        queue = deque()
        
        curr_num = 0
        
        queue.append((root, curr_num))
        
        while queue:
            map[queue[0][1]] = queue[0][0].data
            
            if queue[0][0].left:
                queue.append((queue[0][0].left, queue[0][1] - 1))
            if queue[0][0].right:
                queue.append((queue[0][0].right, queue[0][1] + 1))
                
            queue.popleft()
            
        sorted_map = [map[i] for i in sorted(map.keys())]
        
        for num in sorted_map:
            answer.append(num)
            
        return answer
        