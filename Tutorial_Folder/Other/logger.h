#ifndef LOGGER
#define LOGGER

class Logger 
{
private:
    int m_Loglevel = LogLevelInfo;

public: 
    const int LogLevelWarning = 1;
    const int LogLevelError = 0;
    const int LogLevelInfo = 2;

public:
    void SetLevel(int level);
    void Warn(const char* message);
    void Info(const char* message);
    void Error(const char* message);
};

#endif