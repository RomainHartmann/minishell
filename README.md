# Minishell - UNIX Command Interpreter

<div align="center">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/OS-Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux"/>
  <img src="https://img.shields.io/badge/School-Epitech-0078D4?style=for-the-badge" alt="Epitech"/>
</div>

## 📋 Overview

**Minishell** is a custom implementation of a UNIX command interpreter based on TCSH. This project demonstrates deep understanding of system programming, process management, and UNIX shell architecture.

## ✨ Features

### 🎯 Core Features
- **Command Execution** - Full support for system commands via PATH
- **Process Management** - Fork, exec and child process handling
- **Error Handling** - Appropriate error messages and return codes
- **Interactive Prompt** - Clean and responsive user interface

### 🔧 Built-in Commands
- `cd` - Change directory navigation
- `env` - Display environment variables
- `setenv` - Set environment variables
- `unsetenv` - Remove environment variables
- `exit` - Clean shell exit

## 🚀 Installation & Usage

```bash
# Clone repository
git clone https://github.com/[your-username]/minishell.git
cd minishell

# Compile
make

# Run
./mysh
```

### 💡 Usage Examples

```bash
$> ls -la
$> cd /tmp
$> pwd
/tmp
$> setenv MY_VAR 42
$> env
[...]
MY_VAR=42
$> exit
```

## 🛠️ Technical Skills Demonstrated

- **System Programming** - Mastery of UNIX system calls (fork, execve, wait)
- **Memory Management** - Dynamic allocation and memory leak prevention
- **Parsing** - Command analysis and interpretation
- **Error Handling** - Robust implementation with comprehensive error cases
- **Software Architecture** - Modular and maintainable code

## 🎓 Academic Context

This project is part of the **Epitech** curriculum. It demonstrates:
- Deep understanding of UNIX mechanisms
- Ability to implement complex system features
- Rigorous approach to C development

## 📊 Performance & Quality

- ✅ **Zero memory leaks** (verified with Valgrind)
- ✅ **Complete error handling**
- ✅ **Commented and documented code**
- ✅ **Unit tests included**
- ✅ **Epitech coding standards compliant**

---

<div align="center">
  <i>Developed with passion by Romain Hartmann 🚀</i>
</div>
