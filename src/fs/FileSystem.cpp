#include "fs/FileSystem.hpp"
#include <filesystem>
#include <string>

bool FileSystem::exists(const std::filesystem::path&  path)
{
    return std::filesystem::exists(path);
}

bool FileSystem::isSymlink(const std::filesystem::path& path)
{
    return std::filesystem::is_symlink(path);
}

bool FileSystem::isDirectory(const std::filesystem::path& path)
{
    return std::filesystem::is_directory(path);
}

std::filesystem::path FileSystem::readSymlink(const std::filesystem::path& path)
{
    return std::filesystem::read_symlink(path);
}

std::filesystem::path FileSystem::expandUser(const std::filesystem::path& path)
{
    std::string s = path.string();

    if (s == "~") {
        const char* home = std::getenv("HOME");
        if (!home) {
            throw std::runtime_error("HOME not set");
        }
        return std::filesystem::path(home);
    }

    if (s.rfind("~/", 0) == 0) { //starts with "~/""
        const char* home = std::getenv("HOME");
        if(!home) {
            throw std::runtime_error("HOME not set");
        }
        return std::filesystem::path(home) / s.substr(2);
    }

    return path;
}

void FileSystem::remove(const std::filesystem::path& path)
{
    std::filesystem::remove(path);
}

void FileSystem::ensureParentDir(const std::filesystem::path& path)
{
    auto parent = path.parent_path();
    if(!parent.empty() && !std::filesystem::exists(parent)){
        std::filesystem::create_directories(parent);
    }
}

void FileSystem::createSymlink(
        const std::filesystem::path& source,
        const std::filesystem::path& target
)
{
    ensureParentDir(target);
    std::filesystem::create_symlink(source, target);
}

void FileSystem::createDirectorySymlink(
    const std::filesystem::path& source,
    const std::filesystem::path& target
)
{
    std::filesystem::create_directory_symlink(source, target);
}

void FileSystem::backup(const std::filesystem::path& target)
{
    std::filesystem::path backupPath = target;
    backupPath += ".bak";

    if(std::filesystem::exists(backupPath)){
        std::filesystem::remove_all(backupPath);
    }

    std::filesystem::rename(target, backupPath);
}
