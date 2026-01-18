#pragma once

#include <filesystem>

class Dotfile
{
public:
    Dotfile(std::filesystem::path source,
            std::filesystem::path target);

    const std::filesystem::path& source() const;
    const std::filesystem::path& target() const;

private:
    std::filesystem::path m_source;
    std::filesystem::path m_target;
};