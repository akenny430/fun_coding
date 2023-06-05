#include <iostream> 
#include <thread> 

auto gcd(int m0, int n0) -> int
{
    int m { m0 }; 
    int n { n0 }; 
    while ( m != n )
    {
        if ( m > n ) { m -= n; }
        else { n -= m; }
    }
    return m; 
}