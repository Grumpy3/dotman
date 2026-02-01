# dotman

A minimal, opinionated dotfile manager written in **C++**.

`dotman` manages your dotfiles by creating symlinks from a project-controlled `dotfiles/` directory into your `$HOME`, while safely backing up any existing configuration.

This project is intentionally small and focused, designed as both a practical tool and a clean systems-programming exercise.

---

# what dotman is

dotman is small, symlink-based dotfile manager written in C++

It manages configuration files by:
* keeping the source of truth in a project-controlled `dotfiles/` directory
* creating symlinks from those files/directories into `$HOME`
* safely backing up any existing configuration before replacing it
* ensuring installs are idempotent(safe to run multiple times)

Shortly:
**dotman installs your dotifles in predictable, reversible and repeatable way**

---

## what problem it solves

Manually managing dotfiles usually leads to one of these problems:
* configs copied instead of linked -> changes drift over time
* no backups when overwriting existing files
* hard to reproduce setups across machines
* shell scripts that are fragile and hard to reason about
`dotman` adresses this by:
* using symlinks instead of copies
* detecting and skipping already-correct links
* backing up existing files/directories automatically
* keeping logic explicit and visible in code (not magic)

---

## what dotman is not

It is not: 
* a full configuration framework
* a package manager
* a declarative system manager
* a replacement for XDG specs

It follows common conventions (like `~/.config`) but does not attempt to redefine them.

The goal is corectness, safety and clarity - not feature completeness.

---

## Who should use dotman

`dotman` is good for users who:
* want a simple, transparent dotfile manager
* prefer symlinks over copying
* like understanding what happens to their files
* are comfortable with a CLI tool
* want Linux-First solution without heavy dependencies

Its also useful as:
* reference for safe filesystem operations
* strong base to extend with your own custom workflows

---

## Prior art and context

There are many existing dotfile managers(e.g. GNU Stow, chezmoi, yadm) which are more feature-complete and battle-tested.

`dotman` does not try to compete with them directly.
Instead it focuses on:
* a small surface area
* explicit behavior
* clean object-oriented design

## ✨ Features

* Symlink-based dotfile management
* Supports **files and directories** (e.g. `~/.bashrc`, `~/.config/nvim`)
* Automatic backup of existing files/directories
* Idempotent installs (safe to run multiple times)
* Clean OOP-based architecture
* Built with modern C++ and `std::filesystem`

---

## 📁 Project Structure

```
dotman/
├── src/
│   ├── cli/        # CLI argument parsing
│   ├── core/       # Dotfile & DotfileManager logic
│   ├── fs/         # Filesystem abstraction
│   └── main.cpp
├── dotfiles/       # Your actual dotfiles live here
├── CMakeLists.txt
└── README.md
```

---

## 🚀 Usage

### 1. Put your configs into `dotfiles/`

Examples:

```bash
dotfiles/bashrc        -> ~/.bashrc
dotfiles/gitconfig     -> ~/.gitconfig
dotfiles/nvim/         -> ~/.config/nvim
```

### 2. Build

```bash
mkdir build
cd build
cmake ..
ninja   # or make
```

### 3. Install dotfiles

```bash
./dotman install
```

Existing files are automatically backed up before being replaced with symlinks.

---

## 🛡️ Safety

* Existing files/directories are backed up (e.g. `nvim` → `nvim.bak`)
* Correct symlinks are detected and skipped
* Re-running `install` is safe

---

## 📌 Status

**Work in progress**

Planned features:

* Dry-run mode (`--dry-run`)
* Automatic discovery of dotfiles
* Uninstall command
* Tests

---

## 🧠 Motivation

This project was built to:

* Learn more about C++ and OOP
* Practice writing in OOP
* Build my first project to post on github
