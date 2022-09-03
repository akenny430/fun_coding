#include <iostream> 


int main()
{
    int size; 
    std::cin >> size; 
    int first; 
    int second;
    int diff; 
    long long total_moves {0}; 
    std::cin >> first; 
    for (int k = 0; k < size - 1; ++k)
    {
        std::cin >> second; 
        diff = first - second; 
        if (diff > 0)
            total_moves += diff; 
        else 
            first = second; 
    }
    std::cout << total_moves; 
    return 0; 
}