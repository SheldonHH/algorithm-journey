# https://youtu.be/XQlxCCx2vI4
import heapq
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
            R, C = len(heights), len(heights[0])
            mH = [[0, 0, 0]] # [diff, r, c]
            visit = set()
            d = [[0,1], [0,-1], [1,0], [-1,0]]
            while mH:
                diff, r, c = heapq.heappop(mH)
                if (r, c) in visit: continue
                visit.add((r, c))
                if (r, c) == (R-1, C-1): return diff # reach the end
                for dr, dc in d:
                    nR, nC = r + dr, c + dc
                    if (nR < 0 or nR >= R or nC < 0 or nC >= C or (nR, nC) in visit): continue
                    
                    heapq.heappush(mH, [max(diff, abs(heights[r][c] - heights[nR][nC])), nR, nC])