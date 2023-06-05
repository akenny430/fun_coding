m: int # goes from 1 to 9 
n: int # goes from 1 to 9 

with open(file="../data/hook_combos/combos.txt", mode='w') as hc: 
    print("H(1, 1)") 
    hc.write("1,1\n")
    n_combos: int = 1
    for m in range(1, 10): 
        for n in range(2, 10): # not considering 1 
            if n <= 2 * m - 1: 
                print(f"H({m}, {n})")
                hc.write(f"{m},{n}\n")
                n_combos += 1 
    print(f"{n_combos} valid combos") 
    # 53 valid combinations 