#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void PrintPointer(int* ptr)
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    std::cout << "Value: " << *ptr << std::endl;
}

static int shareValue = 0;
void SharedValueIncrement()
{
    shareValue = shareValue + 1;
}

int main()
{
    int*** a2d = new int** [50];

    for (int i = 0; i < 50; i++)
    {
        a2d[i] = new int*[50];
    }

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; i < 50; i++)
        {
            a2d[i][j] = new int[50];
        }
    }

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; i < 50; i++)
        {
            for (int k = 0; i < 50; i++)
            {
                a2d[i][j][k] = i;
            }
        }
    }

    return 0;
}


//better peformance if we use one dimensonal array than other because memory allocated is continous 