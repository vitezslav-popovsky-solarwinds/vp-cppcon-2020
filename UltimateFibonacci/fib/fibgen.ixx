module;
#include <coroutine>

export module FibGenerator;
import FibCoroutines;

export fib gen_fib(int start, int len);
