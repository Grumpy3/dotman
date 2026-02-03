#pragma once
#include <string>
#include <vector>

enum class CommandType
{
    Install,
    Help,
    Unknown
};

class ArgumentParser{
public:
    ArgumentParser(int argc, char** argv);
    bool dryRun() const;
    CommandType command() const;

private:
    int m_argc;
    char** m_argv;

    std::vector<std::string> m_args;
    CommandType m_command;
};