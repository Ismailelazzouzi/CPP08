#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int max;
    public:
    class   AddFail : public std::exception
    {
        public :
        virtual const char* what() const throw();        
    };
    class   NotFound : public std::exception
    {
        public :
        virtual const char* what() const throw();        
    };
    Span(unsigned int N);
    void addNumber(int n);
    unsigned int longestSpan() const;
    unsigned int shortestSpan() const;
    template<typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end);
};

template<typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end)
{
    size_t dis = std::distance(begin, end);
    if (dis + numbers.size() > max)
        throw AddFail();
    for (InputIterator it = begin; it != end; ++it)
    {
        numbers.push_back(*it);
    }
}