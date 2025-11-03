#include "Span.hpp"

Span::Span(unsigned int N) : max(N)
{
}

void    Span::addNumber(int n)
{
    if (numbers.size() >= max)
        throw AddFail();
    numbers.push_back(n);
}

unsigned int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw NotFound();
    std::vector<int> V = numbers;
    std::vector<int>::iterator minresult = std::min_element(V.begin(), V.end());
    std::vector<int>::iterator maxresult = std::max_element(V.begin(), V.end());
    return (*maxresult - *minresult);
}

unsigned int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw NotFound();
    std::vector<int> V = numbers;
    std::sort(V.begin(), V.end());
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 0; i < V.size(); i++)
    {
        if (i + 1 < V.size())
        {
            if ((unsigned int)(V[i + 1] - V[i]) < minSpan)
                minSpan = V[i + 1] - V[i];
        }
    }
    return minSpan;
}

const char *Span::AddFail::what() const throw()
{
    return "Failed To add Number, Can't take more than N integers";
}

const char *Span::NotFound::what() const throw()
{
    return "Span Not Found!";
}