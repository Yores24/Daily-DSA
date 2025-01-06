from typing import List

class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        result = [0] * n
        # Forward pass
        balls = 0  # Number of balls encountered so far
        moves = 0  # Cumulative moves so far
        for i in range(n):
            result[i] += moves
            if boxes[i] == '1':
                balls += 1
            moves += balls

        # Backward pass
        balls = 0
        moves = 0
        for i in range(n - 1, -1, -1):
            result[i] += moves
            if boxes[i] == '1':
                balls += 1
            moves += balls

        return result
