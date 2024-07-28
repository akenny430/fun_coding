#include <stdlib.h>
#include <stdio.h>

#include "messages.hpp"
#include "miller_rabin.hpp"

int main()
{
    int test_num;
    int yes_no;

    printf("Enter 0 to terminate program\nEnter some numbers:\n");
    while (scanf("%d", &test_num) > 0)
    {
        // if you enter 0 or a negative number, it ends the program
        if (test_num < 1)
        {
            break;
        }

        // testing and printing whether the numbers are prime or not
        yes_no = is_prime(test_num);
        print_message(test_num, yes_no);
    }

    return 0;
}