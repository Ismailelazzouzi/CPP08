#include "easyfind.hpp"

int main()
{
    std::vector <int>V;
    for (size_t i = 0; i < 10; i++)
    {
        V.push_back(i * 25);
    }
    
    try
    {
        easyfind(V, 100);
        std::cout << "100 is inside V" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}