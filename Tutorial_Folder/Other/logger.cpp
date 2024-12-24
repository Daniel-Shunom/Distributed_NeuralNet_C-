#include <iostream>
#include "logger.h"

void Logger::SetLevel(int level) {
    m_Loglevel = level;
}

void Logger::Warn(const char* message) {
    if (Logger::m_Loglevel >= Logger::LogLevelWarning) {
        std::cout << "[WARNING]: " << message << std::endl;
    }
}

void Logger::Info(const char* message) {
    if (Logger::m_Loglevel >= Logger::LogLevelInfo) {
        std::cout << "[INFO]: " << message << std::endl;
    }
}

void Logger::Error(const char* message) {
    if (Logger::m_Loglevel >= Logger::LogLevelError) {
        std::cout << "[ERROR]: " << message << std::endl;
    }
}