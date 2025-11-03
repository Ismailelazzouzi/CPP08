#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try
    {
        std::vector<int> vec;
        for (int i = 0; i < 10001; i++)
        vec.push_back(i);

        Span sp(10000);
        sp.addNumbers(vec.begin(), vec.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}