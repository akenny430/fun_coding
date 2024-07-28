#include <stdlib.h>
#include <stdio.h>

#include "messages.hpp"
#include "miller_rabin.hpp"

int main()
{
    int testNum; 
    int yes_no;

    printf("Enter 0 to terminate program\nEnter some numbers:\n");
    while (scanf("%d", &testNum) > 0)
    {
        // if you enter 0 or a negative number, it ends the program
        if (testNum < 1)
        {
            break;
        }

        // testing and printing whether the numbers are prime or not
        yes_no = is_prime(testNum);
        print_message(testNum, yes_no);
    }

    return 0;
}