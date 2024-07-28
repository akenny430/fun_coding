#include "messages.hpp"
#include <stdio.h>

// auxiliary function to print out a number being prime
void print_prime(int input)
{
    printf("%10d is \033[32mprime\033[0m\n", input);
}

// auxiliary function to print out that the number is not prime
void print_composite(int input)
{
    printf("%10d is \033[38;5;208mnot prime\033[0m\n", input);
}

// function to print out whether number is prime or not
void print_message(int input, int is_prime)
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
