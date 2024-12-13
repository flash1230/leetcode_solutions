# https://leetcode.com/problems/find-center-of-star-graph/
# 1791. Find Center of Star Graph
# Easy
# Graph
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int: # type: ignore
        return edges[0][0] if (edges[0][0] == edges[1][0] or edges [0][0] == edges [1][1]) else edges [0][1]