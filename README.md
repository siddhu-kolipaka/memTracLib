# 🧠 Custom Memory Tracker in C Using a Static Library

This project provides a simple memory tracking utility in C that helps you detect dynamically allocated memory that hasn't been freed. It demonstrates how to encapsulate the tracking logic in a **static library**, and use it in other C programs.

---

## 📦 Features

- Tracks allocations using `my_malloc()` and deallocations with `my_free()`
- Provides `report()` to display memory still in use
- Shows line numbers of unfreed memory allocations
- Modularized via a static library (`libsidlib.a`)

---

## 📁 File Structure

├── memtrac.c  ---> Memory tracking implementation

├── memtrac.h ---> Function declarations

├── mainprog.c ---> Test program using the tracker


---

## 🛠️ Build and Run

### 🔨 1. Compile `memtrac.c` to an object file

```bash
gcc -c memtrac.c -o memtrac.o
```

### 📚 2. Create the static library libsidlib.a

```bash
ar rcs libsidlib.a memtrac.o
```
### 🧵 3. Compile mainprog.c and link with the static library
```bash
gcc -o mainprog mainprog.c -L. -lsidlib
```
### ▶️ 4. Run the Program
```bash
./mainprog
```
---

## 🖥️ Sample Output
```bash
Memory not freed: 2 bytes at line 7
Memory not freed: 4 bytes at line 8
Memory not freed: 2 bytes at line 7

```






