#include "core/DotfileManager.hpp"
#include "fs/FileSystem.hpp"
#include <iostream>

void DotfileManager::add(const Dotfile& dotfile)
{
    m_dotfiles.push_back(dotfile);
}

void DotfileManager::installAll(bool dryRun) const
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
                
                std::cout << (dryRun ? "[dry-run] " : "")
                            << "Backing up " << target << "\n";
                if (!dryRun)
                    FileSystem::backup(target);
            }

            std::cout << (dryRun ? "[dry-run] " : "")
                    << source << " -> "
                    << target << "\n";

            if (!dryRun) {
                FileSystem::ensureParentDir(target);

                if(FileSystem::isDirectory(source)){
                    FileSystem::createDirectorySymlink(source, target);
                } else {
                    FileSystem::createSymlink(source, target);
                }
            }
        }
        catch (const std::filesystem::filesystem_error& e){
            std::cerr << "Error Installing " 
                        << target << ": "
                        << e.what() << "\n";
        }
    }
}