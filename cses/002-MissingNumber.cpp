#include <iostream> 


int main()
{
    long n; 
    long temp; 
    long sum {0}; 
    std::cin >> n; 
    for (int k = 0; k < n - 1; ++k)
    {
        std::cin >> temp; 
        sum += temp; 
    }
    std::cout << ((n * (n + 1)) / 2) - sum; 
    return 0; 
}