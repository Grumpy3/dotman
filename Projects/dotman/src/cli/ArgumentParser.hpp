#pragma once
#include <string>

enum class CommandType
{
    Install,
    Help,
    Unknown
};

class ArgumentParser{
public:
    ArgumentParser(int argc, char** argv);

    CommandType command() const;

private:
    int m_argc;
    char** m_argv;
    CommandType m_command;
};