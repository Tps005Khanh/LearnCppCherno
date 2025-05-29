#include <iostream>

void foo(int a, int b) {
    std::cout << a << " " << b << "\nSum of all: " << a+b << std::endl;
}

int f1() { std::cout << "f1\n"; return 0; }
int f2() { std::cout << "f2\n"; return 0; }

int main() {
    int x = 0;
    int a = ++x;
    int b = ++x;
    foo(++x, ++x); // undefined behavior
    foo(f1(), f2()); // undefined behavior
    foo(a,b);// Should use
}
/*
Case: Calling foo(++x, ++x)

== Possible outcomes ==

Evaluation Order       | ++x (1st) | ++x (2nd) | Output | Final x
---------------------- | ----------| ----------|--------|---------
Left to right          |    3      |    4      | 3 4    |   4
Right to left          |    4      |    3      | 4 3    |   4
Both increments use final value | 4 |    4      | 4 4    |   4
Compiler-dependent     |   ???     |   ???     | ???    | Undefined

❗ Note:
- Before C++17: The evaluation order of function arguments is **unspecified**, leading to **undefined behavior**.
- From C++17 onward: Arguments are evaluated **left to right**, but modifying the same variable multiple times in a single expression is still unsafe.

✅ To ensure correct and predictable behavior, avoid writing foo(++x, ++x);
*/
