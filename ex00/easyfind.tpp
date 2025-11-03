class   Not_found : public std::exception
{
    public :
        virtual const char* what() const throw();        
};

const char *Not_found::what() const throw()
{
    return "Item Not Found!!";
}

template<typename T> const typename T::iterator easyfind(T container, int item)
{
    typename T::iterator ret;

    ret = std::find(container.begin(), container.end(), item);
    if (ret == container.end())
        throw Not_found();
    return ret;
}