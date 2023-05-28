from typing import List 

class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        if income == 0: 
            return 0.0 
        paid: int = 0 
        prev_upper: int = 0 
        for upper, percent in brackets: 
            if upper > income: 
                paid += ( income - prev_upper ) * percent 
                break  
            paid += ( upper - prev_upper ) * percent
            prev_upper = upper 
        return float(paid) / 100.0