from typing import List

class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()  # Fixing the sorting method

        i = 0
        j = len(skill) - 1

        s = skill[i] + skill[j]  # Initialize s with the first and last element
        m = 0
        
        while i < j:
            if skill[i] + skill[j] == s:
                m += skill[i] * skill[j]
                i += 1
                j -= 1
            else:
                return -1
        
        return m
