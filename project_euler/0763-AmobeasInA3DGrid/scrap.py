def count_valid_cells(N: int = 10_000) -> None:
    """
    Counts number of valid cells in triangular 3-d plane.
    What is this called?
    """
    if N > 100:
        print("You're an idiot for even writing this function!")
        return
    count: int = 0
    for i in range(N):
        for j in range(N):
            if i + j >= 10_000:
                continue
            for k in range(N):
                if i + j + k >= 10_000:
                    continue
                count += 1

    print(f"N = {N:,}, valid = {count:,}")


def test_keep_last_digits(n_digits: int = 9) -> None:
    """
    Making sure idea behind keeping last digits works fine.

    Works good.
    So to keep last k digits,
    can just mod results by 10^k.

    I only worry about how long this will take.
    And if there is maybe a faster way.
    Cross that bridge when we get to it.
    """
    modder: int = 10**n_digits

    x: int = 44254145432454
    y: int = 23257482758257
    z: int = 12247327234731

    num_sum: int = x + y
    sum_with_last_digits: int = num_sum % modder
    num_sum += z
    sum_with_last_digits += z % modder

    print(f"{num_sum:>20}")
    print(f"{sum_with_last_digits:>20}")


if __name__ == "__main__":
    # count_valid_cells(N=10_000)
    test_keep_last_digits(9)
