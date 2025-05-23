#include <iostream>
#include <cstdlib>
#include <new> // std::bad_alloc
#include <sal.h>    // Visual Studio-specific annotations
#include <string_view>
static int s_AllocCount = 0;
_Ret_notnull_
void* operator new(std::size_t size) {
    s_AllocCount++;
    std::cout << "Allocating " << size << " byte(s)\n";

    if (void* ptr = std::malloc(size)) {
        return ptr;
    }

    throw std::bad_alloc();
}

void operator delete(void* ptr) noexcept {
    std::cout << "Freeing memory\n";
    std::free(ptr);
}


#define STRING_VIEW

#ifndef STRING_VIEW
void PrintName(const std::string& _rName)
{
	std::cout << _rName << std::endl;
}
#else
void PrintName(const std::string_view _rName)
{
    std::cout << _rName << std::endl;
}
#endif // 0


int main()
{
	std::string name = "Yane Cherno"; // use string can create memory allocate in heap memory 
    const char* constCharName = "Jesu Davies";

#ifndef STRING_VIEW
    std::string firstName = name.substr(0, 4);
    std::string lastName = name.substr(5, 11);
#else
    std::string_view firstName(name.c_str(),4); //c_str return const char*
    std::string_view lastName(name.c_str()+5,11);
    std::string_view firstCharName(constCharName, 4); //c_str return const char*
    std::string_view lastCharName(constCharName + 5, 11);
#endif // 0

    


    PrintName(name);
    PrintName(firstName);
    PrintName(lastName);
#ifdef STRING_VIEW
    PrintName(firstCharName);
    PrintName(lastCharName);
#endif // _STRING_VIEW_

    std::cout << s_AllocCount << std::endl;
}