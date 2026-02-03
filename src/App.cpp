#include "App.hpp"
#include "cli/ArgumentParser.hpp"
#include "core/Dotfile.hpp"
#include "core/DotfileManager.hpp"
#include <iostream>

int App::run(int argc, char** argv)
{
    ArgumentParser parser(argc, argv);
    DotfileManager manager;

    if (parser.command() == CommandType::Install) {
        //for now add one example
        manager.add(Dotfile("dotfiles/bashrc", "~/.bashrc"));
        manager.add(Dotfile("dotfiles/gitconfig", "~/.gitconfig"));
        manager.add(Dotfile("dotfiles/nvim", "~/.config/nvim"));

        manager.installAll(parser.dryRun());
    } else {
        std::cout << "Usage: dotman install\n";
    }
    
    
    return 0;
}