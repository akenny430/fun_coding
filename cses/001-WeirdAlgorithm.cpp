#include <iostream> 

void collaz(long n) 
{
	std::cout << n << " "; 
	while(1)
	{
		if (n == 1) break; 
		n = n % 2 == 0 ? n/2 : 3*n + 1; 
		std::cout << n << " "; 
	}
}

int main()
{
	long n; 
	std::cin >> n; 
	collaz(n); 
	return 0; 
}
