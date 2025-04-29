
//#define ENABLE_LOG

#ifdef ENABLE_LOG
    const char* LogMessage(const char* message)
    {
        return message;
    }
#else
    const char* LogCommand(const char* command)
        {
            return command;
        }
#endif


