#include <iostream>
#include <vector>
#include <string>

class Logger{
    public:
        static Logger& getInstance() {
            static Logger instance;
            return instance;
        }

        void log(const std::string& message) {
            std::cout << "Log: " << message << std::endl;
        }

    private:
        Logger() {}
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
};