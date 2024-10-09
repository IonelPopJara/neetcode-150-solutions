class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        s = list(s)
        # 0 ritations: abcde
        # 1 rotation:  bcdea
        # 2 rotations: cdeab
        # 3 rotations: deabc
        # 4 rotations: eabcd
        # 5 rotations: abcde
        # 0 rotations = 5, len(s) = 5, only up until len(s) - 1

        # Check all possible rotations
        for i in range(len(s)):
            # Rotate string 2
            tmp = s[0]
            for j in range(len(s) - 1):
                s[j] = s[j + 1]
            
            s[-1] = tmp
            tmpStr = "".join(s)
            print(s, tmpStr)
            if tmpStr == goal:
                return True
        
        return False


class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        # abcde + abcde
        # = abcdeabcde
        # goal = cdeab
        # the goal is contained in the sum

        return len(s) == len(goal) and goal in s + s