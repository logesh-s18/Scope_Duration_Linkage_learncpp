# LearnCpp.com — Notes

## Chapter: Scope, Duration, and Linkage  
### 7.6 – Internal Linkage

---

## New things I learned

- `extern` variables and function forward declarations have the **same conceptual behavior**:
  both are **declarations without definitions**.  
  The difference is only **syntax**, not linkage.

- A **non-const global variable written without `extern` is NOT a declaration**.
  It is a **definition**, even if no value is assigned.

- Global `static` variables and global `const` variables behave **similarly with respect to linkage and copies**:
  - both have **internal linkage**
  - both create **separate copies per translation unit**
  - they differ only in **mutability and intent**

---

## Examples / Code I tried

- Available in GitHub commits for this chapter

---

## Things that confused me

- The difference between **internal linkage** and **external linkage**
- How `static`, `extern`, and `const` affect visibility across multiple `.cpp` files

---

## Important notes / rules

- Functions, namespaces, and **non-const global variables** have **external linkage by default**
- `const` global variables and `static` global variables have **internal linkage by default**
- Variables:
  - `extern int x;` → declaration
  - `int x;` (global scope) → definition
- Functions:
  - `void foo();` → declaration
  - `void foo() {}` → definition
- **One Definition Rule (ODR)**:
  - A variable or function must have **exactly one definition**
  - Declarations can appear multiple times

---

## Quick summary (in my own words)

- `extern` for variables works like forward declarations for functions
- `static` and `const` isolate symbols to a single translation unit
- Header files should usually contain **declarations**, not definitions
