class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        adjacencyList = [[] for _ in range(n + 1)]
        flag = False

        for u, v in paths:
            adjacencyList[u].append(v)
            adjacencyList[v].append(u)

        res = [0] * (n+1)

        for i in range(1, n + 1):
            for k in range(1, 5):
                for j in adjacencyList[i]:
                
                    if res[j] == k:
                        flag = True
                        break
                if flag == True:
                    flag = False
                    continue
                res[i] = k
                break
                

        return res[1:]