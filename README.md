# dotman

A minimal, opinionated dotfile manager written in modern **C++**.

`dotman` manages your dotfiles by creating symlinks from a project-controlled `dotfiles/` directory into your `$HOME`, while safely backing up any existing configuration.

This project is intentionally small and focused, designed as both a practical tool and a clean systems-programming exercise.

---

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

---

## 🧠 Motivation

This project was built to:

* Learn more about C++ and OOP
* Practice writing in OOP
* Build my first project to post on github
