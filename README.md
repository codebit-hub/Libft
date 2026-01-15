*This project has been created as part of the 42 curriculum by dporhomo.*

# Libft

![Score](https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42)
![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge)
![Completion Date](https://img.shields.io/badge/Completed-Nov%2024%2C%202025-orange?style=for-the-badge)

## 💡 About The Project

**Libft** is the first project of the 42 Core Curriculum. The goal is to create a custom C library named `libft.a` by rewriting standard C library functions and adding useful utility functions. This library will be used in almost all future 42 projects.

**Project Status:** ✅ Completed (125/100) - Mandatory & Bonus Parts.

## 📂 Function List

### Part 1: Libc Functions
Re-implementation of standard C library functions.

| Character | String | Memory | Numbers/Other |
| :--- | :--- | :--- | :--- |
| `ft_isalpha` | `ft_strlen` | `ft_memset` | `ft_atoi` |
| `ft_isdigit` | `ft_strlcpy` | `ft_bzero` | `ft_calloc` |
| `ft_isalnum` | `ft_strlcat` | `ft_memcpy` | `ft_tolower` |
| `ft_isascii` | `ft_strchr` | `ft_memmove` | `ft_toupper` |
| `ft_isprint` | `ft_strrchr` | `ft_memchr` | |
| | `ft_strncmp` | `ft_memcmp` | |
| | `ft_strnstr` | `ft_strdup` | |

### Part 2: Additional Functions
Useful string manipulation functions not present in standard libc.

| Function | Description |
| :--- | :--- |
| `ft_substr` | Allocates and returns a substring from the string 's'. |
| `ft_strjoin` | Allocates and returns a new string, result of 's1' + 's2'. |
| `ft_strtrim` | Trims characters specified in 'set' from start/end of 's1'. |
| `ft_split` | Splits a string using a delimiter and returns an array of strings. |
| `ft_itoa` | Converts an integer to a string (char *). |
| `ft_strmapi` | Applies a function to each character of a string (creates new string). |
| `ft_striteri` | Applies a function to each character of a string (in place). |
| `ft_putchar_fd`| Outputs a char to a file descriptor. |
| `ft_putstr_fd` | Outputs a string to a file descriptor. |
| `ft_putendl_fd`| Outputs a string followed by a newline to a FD. |
| `ft_putnbr_fd` | Outputs an integer to a file descriptor. |

### Part 3: Bonus Functions (Linked Lists)
Functions to manipulate `t_list` structures.

| Function | Description |
| :--- | :--- |
| `ft_lstnew` | Creates a new list node. |
| `ft_lstadd_front`| Adds a node to the beginning of a list. |
| `ft_lstsize` | Counts the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node to the end of a list. |
| `ft_lstdelone` | Deletes a node and frees its content. |
| `ft_lstclear` | Deletes and frees a node and all successors. |
| `ft_lstiter` | Applies a function to the content of every node. |
| `ft_lstmap` | Applies a function to a list and creates a new list with results. |

## 🛠️ Usage

### Requirements
* `gcc` or `clang` compiler.
* Standard C libraries.

### Compilation
To compile the library, run the following in the root directory:

```bash
make        # Compiles mandatory functions
make bonus  # Compiles mandatory + bonus functions
cc -Wall -Werror -Wextra main.c -L. -lft -lbsd -o test_prog
```