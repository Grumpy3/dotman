#pragma once

#include <vector>
#include "Dotfile.hpp"

class DotfileManager
{
public:
    // add to internal list
    void add(const Dotfile& dotfile);

    //for now just iterate and show targets
    void installAll(bool dryRun) const;

private:
    std::vector<Dotfile> m_dotfiles;
};