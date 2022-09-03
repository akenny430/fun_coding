#include <iostream> 
#include <string>


int main()
{
    std::string sequence; 
    std::cin >> sequence; 
    int max_length {1}; 
    int current_length {1}; 
    for (int k = 1; k < sequence.size(); ++k)
    {
        if (sequence[k] == sequence[k - 1])
        {
            current_length += 1; 
        }
        else 
        {
            max_length = (current_length > max_length) ? current_length : max_length; 
            current_length = 1; 
        }
        max_length = (current_length > max_length) ? current_length : max_length; 
    }
    std::cout << max_length; 
    return 0; 
}