#include "core/DotfileManager.hpp"
#include "fs/FileSystem.hpp"
#include <iostream>

void DotfileManager::add(const Dotfile& dotfile)
{
    m_dotfiles.push_back(dotfile);
}

void DotfileManager::installAll() const
{
    for (const auto& df : m_dotfiles) {
        const auto& source = df.source();
        auto target = FileSystem::expandUser(df.target());

        try {
            if(FileSystem::exists(target) || FileSystem::isSymlink(target)) {
                // Case: correct symlink exists
                if (FileSystem::isSymlink(target) &&
                    FileSystem::readSymlink(target) == source)
                {
                    std::cout << "Already linked " << target << "\n";
                    continue;
                }
                
                // Otherwise backup
                std::cout << "Backing Up " << target << "\n";
                FileSystem::backup(target);
            }

            std::cout << "Linking "
                    << source << " -> "
                    << target << "\n";
            FileSystem::ensureParentDir(target);

            if(FileSystem::isDirectory(source)){
                FileSystem::createDirectorySymlink(source, target);
            } else {
                FileSystem::createSymlink(source, target);
            }
        }
        catch (const std::filesystem::filesystem_error& e){
            std::cerr << "Error Installing " 
                        << target << ": "
                        << e.what() << "\n";
        }
    }
}