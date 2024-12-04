# @leet start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        sol, res = [], []

        def dfs(i):
            if i == n or sum(sol) > target:
                return
            elif sum(sol) == target:
                res.append(sol[:])
                return

            # Don't use candidates[i] (go to the next i)
            dfs(i + 1)

            # Use candidates[i] (Don't go to the next i)
            # We need to append it to the solution
            sol.append(candidates[i]) 
            dfs(i)

            # Pop it from the solution to backtrack
            sol.pop()

        dfs(0)
        return res

# @leet end
