class Solution:

    def dfs_helper(self, n, node, adjList, visited_array, totalDegree, got_a_node):
        visited_array[node] = 1
        totalDegree += len(adjList[node])
        got_a_node += 1

        for it in adjList[node]:
            if not visited_array[it]:
                totalDegree, got_a_node = self.dfs_helper(n, it, adjList, visited_array, totalDegree, got_a_node)

        return totalDegree, got_a_node



    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        visited_array = [0] * n
        totalDegree = 0
        count = 0
        got_a_node = 0

        adjList = [[] for _ in range(0, n)]

        for u, v in edges:
            adjList[u].append(v)
            adjList[v].append(u)

        for i in range(0, n):
            if not visited_array[i]:
                node = i
                totalDegree = 0
                got_a_node = 0
                totalDegree, got_a_node = self.dfs_helper(n, i, adjList, visited_array, totalDegree, got_a_node)
                if totalDegree == got_a_node*(got_a_node - 1):
                    count += 1
        
        return count