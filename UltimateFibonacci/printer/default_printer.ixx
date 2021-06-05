module;
#include <iostream>

export module DefaultPrinter;

export struct DefaultPrinter
{
    void print_element(int e)
    {
        std::cout << e << " ";
    }

    void print_separator()
    {
        std::cout << ", ";
    }

    void print_eol()
    {
        std::cout << std::endl;
    }
};
