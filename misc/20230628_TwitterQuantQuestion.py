import math 

p_up: float = 0.5 
g_up: float = 1.30 
p_down: float = 0.5 
g_down: float = 0.90 
n_years: int = 10 

threshold: float = 1.10**n_years 

prob_b_ge_a: float = 0.0 
for k in range(n_years + 1): 
    if (g_up**k) * (g_down**(n_years - k)) > threshold: 
        prob_b_ge_a += math.comb(n_years, k) * (p_up**k) * (p_down**(n_years - k))

print(f"{100 * prob_b_ge_a:.2f}% chance that B is greater than A") 