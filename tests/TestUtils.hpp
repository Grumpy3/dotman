#pragma once
#include <filesystem>
#include <cstdlib>
#include <fstream>

inline std::filesystem::path createTempDir()
{
    auto base = std::filesystem::temp_directory_path();
    auto dir = base / "dotman-%%%%%";
    std::filesystem::create_directories(dir);
    return dir;
}

inline void setHome(const std::filesystem::path& path)
{
    setenv("HOME", path.c_str(), 1);
}

inline void writeFile(const std::filesystem::path& p, const std::string& content = "")
{
    std::ofstream ofs(p);
    ofs << content;
}