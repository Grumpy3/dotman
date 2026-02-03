#include "core/DotfileManager.hpp"
#include "core/Dotfile.hpp"
#include "fs/FileSystem.hpp"
#include "TestUtils.hpp"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>

void test_dry_run();
void test_install_creates_symlink();
void test_backup_existing_file();
void test_directory_install();

int main()
{
    test_dry_run();
    test_install_creates_symlink();

    std::cout << "All tests passed\n";
    return 0;
}

void test_dry_run()
{
    auto root = createTempDir();
    auto home = root / "home";
    auto dotfiles = root / "dotfiles";

    create_directories(home);
    create_directories(dotfiles);
    
    setHome(home);
    
    // create fake dotfile
    auto src = dotfiles / "bashrc";
    writeFile(src, "test");

    DotfileManager manager;
    manager.add(Dotfile(src, "~/.bashrc"));

    manager.installAll(true); // DRY RUN

    // Assert nothing was created
    assert(!exists(home / "./bashrc"));
}

void test_install_creates_symlink()
{
    auto root = createTempDir();
    auto home = root / "home";
    auto dotfiles = root / "dotfiles";

    create_directories(home);
    create_directories(dotfiles);
    
    setHome(home);
    
    auto src = dotfiles / "bashrc";
    writeFile(src, "test");

    DotfileManager manager;
    manager.add(Dotfile(src, "~/.bashrc"));

    manager.installAll(false);

    auto target = home / ".bashrc";

    assert(exists(target));
    assert(is_symlink(target));
    assert(read_symlink(target) == src);
}

void test_backup_existing_file()
{
    auto root = createTempDir();
    auto home = root / "home";
    auto dotfiles = root / "dotfiles";

    create_directories(home);
    create_directories(dotfiles);
    
    setHome(home);
    
    auto existing = dotfiles / "bashrc";
    writeFile(existing, "old");

    auto src = dotfiles / "bashrc";
    writeFile(src, "new");

    DotfileManager manager;
    manager.add(Dotfile(src, "~/.bashrc"));
    manager.installAll(false);

    assert(exists(home / ".bashrc.bak"));
    assert(is_symlink(home / ".bashrc"));
}

void test_directory_install()
{
    auto root = createTempDir();
    auto home = root / "home";
    auto dotfiles = root / "dotfiles";

    create_directories(home);
    create_directories(dotfiles);
    
    setHome(home);

    auto nvim = dotfiles / "nvim";
    create_directories(nvim);
    writeFile(nvim / "init.lua", "config");

    DotfileManager manager;
    manager.add(Dotfile(nvim, "~/.config/nvim"));
    manager.installAll(false);

    auto target = home / ".config/nvim";

    assert(is_symlink(target));
    assert(read_symlink(target) == nvim);
}