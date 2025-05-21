#include <iostream>
#include <cstdint>

struct Entity
{
    int x,y;
    //double z,d;
};


int main()
{
    int a = 50;
    double b = a;
    std::cout << b << std::endl;
    b = *(double*)&a;
    std::cout << b << std::endl;
    //Empty Struct or Class take at least one byte to allocate but class or stuct with variable just array 
    Entity e{5,8};
    int* position = (int*)&e;
    std::cout << position[0] << "\n" << position[1] << std::endl;

    int y = *(int*)((char*)&e+4);
    std::cout << y << std::endl;
}