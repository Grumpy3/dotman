#include "core/Dotfile.hpp"
#include <cstdlib>

Dotfile::Dotfile(const std::filesystem::path source, const std::filesystem::path target)
    : m_source(std::move(source)), m_target(std::move(target))
{
}

const std::filesystem::path& Dotfile::source() const
{
    return m_source;
}

const std::filesystem::path& Dotfile::target() const
{
    return m_target;
}
