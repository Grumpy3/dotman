#include "cli/ArgumentParser.hpp"
#include <algorithm>

ArgumentParser::ArgumentParser(int argc, char** argv)
    : m_argc(argc), m_argv(argv), m_command(CommandType::Unknown)
{
    for (int i = 1; i < argc; i++){
        m_args.emplace_back(argv[i]);
    }

    if (m_args.empty()){
        m_command = CommandType::Help;
        return;
    }

    if (m_args[0] == "install")
        m_command = CommandType::Install;
    else
        m_command = CommandType::Unknown;
}

CommandType ArgumentParser::command() const
{
    return m_command;
}

bool ArgumentParser::dryRun() const
{
    return std::find(m_args.begin(), m_args.end(), "--dry-run") != m_args.end();
}