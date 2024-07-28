#include <stdio.h>

#include "messages.hpp"

/**
 * @brief
 * Prints "prime" in green text.
 * 
 * @param input number to print.
*/
void print_prime(int input)
{
    printf("%10d : \033[32mprime\033[0m\n", input);
}

/**
 * @brief
 * Prints "not prime" in orange text.
 * 
 * @param input number to print.
*/
void print_composite(int input)
{
    printf("%10d : \033[38;5;208mnot prime\033[0m\n", input);
}

/**
 * @brief
 * Implements print_message.
*/
void print_message(int input, bool is_prime)
{
    if (is_prime)
    {
        print_prime(input);
    }
    else 
    {
        print_composite(input);
    }
}
