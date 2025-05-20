#include <iostream>
#include <thread>
#include <chrono>

bool isFisnished{true};

void Print()
{
    while (isFisnished)
    {
        std::cout << "Thread is working..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
}

int main()
{
    std::thread t1(Print);
    std::cin.get();
    isFisnished = false;
    t1.join();
    return 0;
}

//Try with mutex and atomic