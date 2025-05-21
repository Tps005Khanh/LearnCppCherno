#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{

    std::vector<int> vec = {3, 2, 5, 8, 6, 9};
    //std::sort(vec.begin(),vec.end(),std::greater<int>());
    std::sort(vec.begin(), vec.end(), [](int a, int b)
              { 
                if (a == 2)
                {
                    return true;
                }
                if (b == 2)
                {
                    return false;
                }
                return a > b; });
    for ( auto vecItem : vec)
    {
        std::cout << vecItem << std::endl;
    }
    
    return 0;
}