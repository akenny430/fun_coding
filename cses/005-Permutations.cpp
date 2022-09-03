#include <iostream> 


/* Shitty original solution, keeping bc its interesting to look back on */
// void print_seq(int n)
// {
//     int temp; 
//     if (n == 1)
//     {
//         std::cout << 1; 
//         return; 
//     }
//     if (n < 4)
//     {
//         std::cout << "NO SOLUTION"; 
//         return; 
//     }
//     if (n == 4)
//     {
//         std::cout << "3 1 4 2"; 
//         return; 
//     }
//     else if (n == 5)
//     {
//         std::cout << "3 5 2 4 1";
//         return; 
//     }
//     else if (n % 2 == 0)
//     {
//         temp = n; 
//         while (temp >= 4)
//         {
//             std::cout << temp << ' '; 
//             temp -= 2; 
//         }
//         temp = 1; 
//         while (temp <= n - 1)
//         {
//             std::cout << temp << ' '; 
//             temp += 2; 
//         }
//         std::cout << 2; 
//     }
//     else 
//     {
//         temp = n; 
//         while (temp >= 3)
//         {
//             std::cout << temp << ' '; 
//             temp -= 2; 
//         }
//         temp = n - 1; 
//         while (temp >= 6)
//         {
//             std::cout << temp << ' '; 
//             temp -= 2; 
//         }
//         std::cout << "2 4 1"; 
//     }
// }

void print_seq(int n)
{
    if (n == 1)
    {
        std::cout << 1; 
        return; 
    }
    if (n < 4)
    {
        std::cout << "NO SOLUTION"; 
        return; 
    }
    int even_offset = n % 2 == 0 ? 0 : 1; 
    int odd_offset = 1 - even_offset; 
    for (int k = 2; k <= n - even_offset; k += 2)
    {
        std::cout << k << ' '; 
    }
    for (int k = 1; k <= n - odd_offset; k += 2)
    {
        std::cout << k << ' '; 
    }
}

int main()
{
    int n; 
    std::cin >> n; 
    print_seq(n); 
    return 0; 
}