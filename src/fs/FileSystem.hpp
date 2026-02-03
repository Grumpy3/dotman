#pragma once

#include <filesystem>

class FileSystem
{
public:
    static bool exists(const std::filesystem::path& path);

    static void ensureParentDir(const std::filesystem::path& path);

    static bool isSymlink(const std::filesystem::path& path);

    static bool isDirectory(const std::filesystem::path& path);

    static std::filesystem::path readSymlink(const std::filesystem::path& path);
    
    static std::filesystem::path expandUser(const std::filesystem::path& path);

    static void remove(const std::filesystem::path& path);
    
    static void createSymlink(
        const std::filesystem::path& source,
        const std::filesystem::path& target
    );

    static void createDirectorySymlink(
        const std::filesystem::path& source,
        const std::filesystem::path& target
    );

    static void backup(const std::filesystem::path& target);
};