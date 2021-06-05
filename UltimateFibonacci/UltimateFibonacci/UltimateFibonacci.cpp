// UltimateFibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <coroutine>
#include <concepts>
#include "printer_concepts.h"

import FibCoroutines;
import FibGenerator;
import DefaultPrinter;
import BetterPrinter;

struct DefaultFormatter
{
    template<is_series S, is_printer T>
    void format(T t, S s)
    {
        while (!s.done())
        {
            t.print_element(s.next());
            t.print_separator();
        }
        t.print_eol();
    }
};

struct BetterFormatter
{
    template<is_series S, is_printer T>
    void format(T t, S s)
    {
        if (!s.done())
            t.print_element(s.next());
        while (!s.done())
        {
            t.print_separator();
            t.print_element(s.next());
        }
        t.print_eol();
    }
};


template<
    typename S,
    typename T = DefaultPrinter,
    typename F = DefaultFormatter>
    requires is_series_printer<T, S, F>
    void print(S& s)
{
    F{}.format(T{}, s);
}

int main()
{
    int len = 6;
    fib f1 = gen_fib(1, len);
    print(f1);

    len = 6;
    fib f2 = gen_fib(10, len);
    print<fib, Printer, BetterFormatter>(f2);
}
