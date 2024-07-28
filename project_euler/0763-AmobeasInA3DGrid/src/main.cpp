#include <cstdint>
#include <iostream>
#include <vector>

constexpr std::uint32_t ONE_BILLION { 1'000'000'000 };

class Cell
{
public:
    std::uint16_t x;
    std::uint16_t y;
    std::uint16_t z;

    Cell(std::uint16_t x, std::uint16_t y, std::uint16_t z)
    : x{ x }, y{ y }, z{ z }
    {}
};

int main()
{


    return 0;
}