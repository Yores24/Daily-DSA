import math

class Solution:
    def fractionAddition(self, expression: str) -> str:
        def lcm(a, b):
            return abs(a * b) // math.gcd(a, b)

        def reduce_fraction(numerator, denominator):
            gcd = math.gcd(numerator, denominator)
            reduced_numerator = numerator // gcd
            reduced_denominator = denominator // gcd
            return reduced_numerator, reduced_denominator

        # Initialization
        n = len(expression)
        denominators = []
        numerators = []
        num = 0
        den = 0
        i = 0
        sign = 1
        
        # Parse the expression
        while i < n:
            if expression[i] in "+-":
                sign = -1 if expression[i] == '-' else 1
                i += 1
            numerator = 0
            while i < n and expression[i].isdigit():
                numerator = numerator * 10 + int(expression[i])
                i += 1
            numerator *= sign
            i += 1  # Skip '/'
            denominator = 0
            while i < n and expression[i].isdigit():
                denominator = denominator * 10 + int(expression[i])
                i += 1
            numerators.append(numerator)
            denominators.append(denominator)
        
        # Calculate the LCM of all denominators
        lcm_result = denominators[0]
        for den in denominators[1:]:
            lcm_result = lcm(lcm_result, den)
        
        # Convert fractions to have a common denominator and sum them
        total_numerator = 0
        for i in range(len(numerators)):
            total_numerator += numerators[i] * (lcm_result // denominators[i])
        
        # Reduce the resulting fraction
        final_numerator, final_denominator = reduce_fraction(total_numerator, lcm_result)
        
        return f"{final_numerator}/{final_denominator}"

