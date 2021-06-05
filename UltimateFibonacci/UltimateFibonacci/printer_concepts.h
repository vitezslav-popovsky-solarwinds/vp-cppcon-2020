#pragma once

template<typename T>
concept is_series = requires(T t, int i)
{
    t.done() == true;
    i = t.next();
};

template<typename T>
concept is_printer = requires(T t, int i)
{
    t.print_element(i);
    t.print_separator();
    t.print_eol();
};

template<typename Printer, typename Series, typename Formatter>
concept is_series_printer = requires(Printer t, Series u, Formatter f, int i) {
    f.format(t, u);
    { t } -> is_printer;
    { u } -> is_series;
};
