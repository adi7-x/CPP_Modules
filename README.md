<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B_98-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
  <img src="https://img.shields.io/badge/42_Network-000000?style=for-the-badge&logo=42&logoColor=white" />
  <img src="https://img.shields.io/badge/Modules-00_to_09-blueviolet?style=for-the-badge" />
</p>

<h1 align="center">📘 CPP Modules</h1>

<p align="center">
  <i>From namespace basics to templated containers — the full C++ journey.</i>
  <br><br>
  10 progressive modules covering C++ fundamentals through advanced features,<br>
  constrained to the <b>C++98 standard</b>.
</p>

---

## 📋 Table of Contents

- [About](#-about)
- [Module Overview](#-module-overview)
- [Module Details](#-module-details)
- [Getting Started](#-getting-started)
- [Project Structure](#-project-structure)
- [Author](#-author)

---

## 💡 About

The **CPP Modules** are 42 School projects teaching Object-Oriented Programming in C++ incrementally. Each module builds on the last, introducing new language features and design patterns.

> All code compiles with `-Wall -Wextra -Werror -std=c++98`. No `auto`, no range-based loops, no smart pointers.

---

## 📊 Module Overview

| Module | Topic | Score | Key Concepts |
|:------:|:------|:-----:|:-------------|
| **00** | Namespaces, Classes, IO | **80** | Classes, member functions, stdio streams |
| **01** | Memory & References | **90** | `new`/`delete`, pointers vs references |
| **02** | Operator Overloading | **80** | Ad-hoc polymorphism, Orthodox Canonical Form |
| **03** | Inheritance | **80** | Class hierarchies, access specifiers |
| **04** | Polymorphism | **80** | Virtual functions, abstract classes |
| **05** | Exceptions | **100** | `try`/`catch`, custom exception classes |
| **06** | C++ Casts | **100** | `static_cast`, `dynamic_cast`, `reinterpret_cast` |
| **07** | Templates | **100** | Function templates, class templates |
| **08** | Templated Containers | **100** | STL containers, iterators, algorithms |
| **09** | STL | **100** | Advanced STL, real-world applications |

---

## 📈 Learning Progression

```
Module 00 → 01 → 02 → 03 → 04     (Foundations → OOP)
  Basics   Memory  Operators  Inherit  Polymorphism

Module 05 → 06 → 07 → 08 → 09     (Advanced → Mastery)
  Exceptions Casts  Templates  STL     Applications
```

---

## 📖 Module Details

### Module 00 — Namespaces, Classes, Member Functions

Exercises: Megaphone, PhoneBook, Account. First steps into C++ — `std::string`, `std::cin/cout`, class encapsulation, `public`/`private` access.

### Module 01 — Memory Allocation, References

`new`/`delete` vs `malloc`/`free`, references (`&`) as aliases, pointers to members, `switch` statement.

### Module 02 — Operator Overloading, Orthodox Canonical Form

Every proper C++ class needs: default constructor, copy constructor, copy assignment operator, destructor. Fixed-point number arithmetic via operator overloading.

### Module 03 — Inheritance

Class hierarchies with `public`/`protected`/`private` inheritance. ClapTrap → ScavTrap → FragTrap → DiamondTrap chain.

### Module 04 — Subtype Polymorphism, Abstract Classes

Virtual functions, pure virtual (`= 0`), abstract classes as interfaces. Runtime polymorphism via base class pointers. Always use virtual destructors.

### Module 05 — Exceptions

Custom exception classes inheriting from `std::exception`. `try`/`catch`/`throw` for graceful error handling. Bureaucrat grade validation.

### Module 06 — C++ Casts

| Cast | Purpose |
|:-----|:--------|
| `static_cast` | Implicit conversions, safe upcasts |
| `dynamic_cast` | Runtime-checked downcasts |
| `reinterpret_cast` | Low-level bit reinterpretation |
| `const_cast` | Add/remove `const` qualifier |

### Module 07 — Templates

Generic programming — write once, use with any type. Function templates and class templates.

### Module 08 — Templated Containers, Iterators

STL containers (`vector`, `list`, `stack`), iterator patterns, `std::find`, `std::sort`. MutantStack exercise.

### Module 09 — STL (Advanced)

Real-world STL applications: **BitcoinExchange** (`std::map`), **RPN Calculator** (`std::stack`), **PmergeMe** Ford-Johnson sort (`std::vector` vs `std::deque`).

---

## 🔑 Key Concepts

| Concept | Module | Description |
|:--------|:------:|:------------|
| RAII | 00+ | Resource Acquisition Is Initialization |
| OCF | 02+ | Orthodox Canonical Form (Rule of Three) |
| Polymorphism | 04 | Virtual dispatch, dynamic binding |
| Exception Safety | 05 | No resource leaks on throw |
| Type Safety | 06 | C++ casts vs C-style casts |
| Generic Programming | 07-08 | Templates for type-independent code |
| STL | 08-09 | Containers + Iterators + Algorithms |

---

## 🚀 Getting Started

```bash
# Navigate to a specific exercise
cd cpp05-09/cpp09/ex00

# Build and run
make
./btc input.txt

# Clean
make fclean
```

---

## 📁 Project Structure

```
CPP_Modules/
├── cpp00-04/
│   ├── cpp00/          # Megaphone, PhoneBook, Account
│   ├── cpp01/          # Memory, references
│   ├── cpp02/          # Fixed-point, operators
│   ├── cpp03/          # ClapTrap inheritance
│   └── cpp04/          # Animal polymorphism
├── cpp05-09/
│   ├── cpp05/          # Bureaucrat exceptions
│   ├── cpp06/          # Scalar conversion
│   ├── cpp07/          # Templates
│   ├── cpp08/          # Span, MutantStack
│   └── cpp09/          # Bitcoin, RPN, PmergeMe
└── README.md
```

---

## 👤 Author

**Adil Bourji** — [@adi7-x](https://github.com/adi7-x)

<p align="center">
  <a href="https://github.com/adi7-x"><img src="https://img.shields.io/badge/GitHub-adi7--x-181717?style=flat-square&logo=github" /></a>
  <a href="https://linkedin.com/in/adil-bourji"><img src="https://img.shields.io/badge/LinkedIn-Adil_Bourji-0A66C2?style=flat-square&logo=linkedin" /></a>
</p>

<p align="center"><sub>42 School · Common Core · C++ · OOP</sub></p>
