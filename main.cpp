#include "main.h"

int main()
{

#ifdef ENABLE_LOG
    LogMessage("Cherno");
#else
    LogCommand("Cherno");
#endif
    
    return 0;
}   