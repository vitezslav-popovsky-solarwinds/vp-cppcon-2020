module;
#include <fmt/color.h>
#include <iostream>

export module BetterPrinter;

export struct Printer
{
    void print_element(int e)
    {
        fmt::print(fg(fmt::color::crimson) |
            fmt::emphasis::bold, "[{}]", e);
    }

    void print_separator()
    {
        fmt::print(bg(fmt::color::yellow), ", ");
    }

    void print_eol()
    {
        std::cout << std::endl;
    }
};
