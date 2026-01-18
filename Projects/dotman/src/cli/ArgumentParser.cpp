#include "cli/ArgumentParser.hpp"

ArgumentParser::ArgumentParser(int argc, char** argv)
    : m_argc(argc), m_argv(argv), m_command(CommandType::Unknown)
{
    if (argc < 2) {
        m_command = CommandType::Help;
        return;
    }

    if (std::string(argv[1]) == "install")
        m_command = CommandType::Install;
    else
        m_command = CommandType::Unknown;
}

CommandType ArgumentParser::command() const
{
    return m_command;
}