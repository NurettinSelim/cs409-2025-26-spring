# ExprLab - CS409/509 Adv. C++ Programming
## Midterm Exam #1

**15 April 2026**

## Overview

It's an open-book exam, and the era is about leveraging the power of AI and blend your know-how into it, the exam's focus will be on how to get the best assistance from the AI. Your understanding about what is needed in the project, what are the metrics to optimize for is essential.

Moreover, to give you a clue from your future, your understanding of the resulting source code will also be very important for the 2nd midterm exam. I advise you to submit a human maintainable code (don't make AI overfit for a few more grades) to invest on your performance in 2nd midterm.

This exam asks you to build a small compile-time C++ expression library supporting exactly three runtime variables: `x`, `y`, and `z`.

You write math expressions using the placeholders `$x`, `$y`, and `$z`. Those expressions must then work on scalars and on containers with Python/Matlab-like behavior such as mapping, masking, picking, and slicing over the containers. You must carefully examine what the supplied `main()` function does before attempting solving the exam. Cross-checking the code in `main()` and its console output (provided) will make you understand how the system is expected to work.

- The exam provides questions to be fulfilled so that you earn grade.
- Some features come with a grade cost per usage. Check them out.
- Writing short code is enforced by semicolon count used in the header file you will submit. You can earn grade multipliers to boost your grade.
- There are also *FORBIDDEN* stuff that you must definitely obey. Check the relevant forbiddens table.

Checkout the `week10-mt1.cpp` file, and understand how ExprLibrary must be grammatically structured in the end.

## Open-book Policy

- You **may** use notes, internet resources, and AI tooling.
- You **may not** collaborate with another human being during the exam period.

## Grading - Question Breakdown

| Part | Topic | Points |
|------|-------|--------|
| **Q1** | **Expression construction and copy behavior** | **17** |
| Q1a | Build/evaluate with `$x`, `$y`, `$z` | 7 |
| Q1b | Preserve behavior under copying | 10 |
| **Q2** | **Runtime node checks** | **17** |
| Q2a | Report node kinds | 7 |
| Q2b | Evaluate nodes through the base interface | 10 |
| **Q3** | **Core `Vector<T>` behavior** | **30** |
| Q3a | Printing | 3 |
| Q3b | Masking | 5 |
| Q3c | Picking | 5 |
| Q3d | Mapping | 7 |
| Q3e | Negative indexing | 3 |
| Q3f | Tuple slicing | 7 |
| **Q4** | **Named and r-value slicing helpers** | **20** |
| Q4a | Named `mask` and `pick` | 7 |
| Q4b | Tuple-based named slicing | 7 |
| Q4c | Pair/brace-init slicing | 6 |
| **Q5** | **Applying expressions to tuple-like container items** | **16** |

## Feature Costs

Keyword costs are cumulative and counted **per usage**.

| Feature | Cost per use |
|---------|--------------|
| `struct` | 1.0 pt |
| `class` | 1.0 pt |
| `typename` | 1.0 pt |
| Comma operator (call-arg commas exempt) | 1.0 pt |
| Ternary `?:` | 1.0 pt |
| Method | 0.5 pt |
| Free function | 0.5 pt |
| Lambda | 0.5 pt |

**Comma operator note:** Only the comma *operator* is charged; commas that separate arguments in one function call do not count.

## Forbidden Rules

- You **cannot** use any `#define` macro in your submitted code.
- You **cannot** use multiple inheritance in your submitted code.
- You **may** use single inheritance **but** you may only inherit from **your custom written structs/classes**.

**Any violation of the above rules results in a zero grade.**

## Semicolon Multipliers

Semicolons are counted in the file `week10-mt1-impl.hpp` only.

| Semicolon count | Multiplier |
|-----------------|------------|
| <= 45 | 1.50x |
| 46-50 | 1.30x |
| 51-55 | 1.20x |
| 56-60 | 1.10x |
| 61-65 | 1.00x |
| 66-70 | 0.90x (penalty) |
| 71-75 | 0.80x (penalty) |
| > 75 | 0.00x (invalid) |

**Final formula:**

```
final = min(100, max(0, question_points - keyword_costs) * multiplier)
```

## Submission Layout

Supplied exam file is constructed to `#include` a header file. The `#include "week10-mt1-impl.hpp"` line is hard coded in the exam's main cpp file; your implementation goes in the header, subject to the rules above. You will only upload the header file as your solution to the LMS.

## Expected Console Output

The program must produce exactly below console output when correctly crafted:

```
Expression Lab

Q1a)
expr1(5, 10, 15) = 165

Q1b)
expr2(5, 10, 15) = 165

Q2a)
probe kinds: lit arg binop

Q2b)
probe evals: 7 8 8

Q3a)
v = 10 20 30 40 50

Q3b)
mask = v[$x > 25] = 0 0 1 1 1

Q3c)
v[mask] = 30 40 50

Q3d)
mapped with $x/10+$y = 1 3 5 7 9

Q3e)
tail = 50 40

Q3f)
sliced = v[1:-1] = 20 30 40 50

Q4a)
v.mask($x > 45) = 0 0 0 0 1
v.pick(vector<bool>{false, true, false, true, false}) = 20 40

Q4b)
v.slice(tuple{0, 5, 2}) = 10 30 50
v.slice(tuple{3, 5}) = 40 50

Q4c)
v.slice(pair{0, 2}) = 10 20
v.slice({1, 2}) = 20

Q5)
apply(x^2 + 2y^2 - z) -> 7.59 73.26 204.27
```

## Extra Clarification

Below are extra clarifications for `main()` in `week10-mt1.cpp`;

### Q1a

- **Formula:** `expr1(x, y, z) = (1.5 + z) * (x + y / 2.0)`
- **Input:** `(5, 10, 15)`
- **Expected output:** `165`

### Q1b

- **Task:** Copy `expr1` to `expr2`; preserve behavior.
- **Input:** `(5, 10, 15)`
- **Expected output:** `165`

### Q2a

- **Build:** Three runtime nodes:
  - `Literal(7)`
  - `Arg('y')`
  - `BinaryOp('+', Expr(5), $x)`
- **Task:** Print each node's `kind()` separated by spaces.
- **Expected:** `lit arg binop`

### Q2b

- **Task:** Evaluate each probe with `Args{3, 8, 13}` through the base `Node` interface.
- **Interpretation:**
  - `f(x, y, z) = 7` at `x=3, y=8, z=13` returns `7`
  - `f(x, y, z) = y` at `x=3, y=8, z=13` returns `8`
  - `f(x, y, z) = 5 + x` at `x=3, y=8, z=13` returns `8`
- **Expected:** `7 8 8`

### Q3a

- **Create:** `Vector<int>{10, 20, 30, 40, 50}`
- **Task:** Print the vector.
- **Expected:** `v = 10 20 30 40 50`

### Q3b

- **Task:** Compute a boolean vector via masking (`v[$x > 25]`).
- **Expected:** `mask = v[$x > 25] = 0 0 1 1 1`

### Q3c

- **Task:** Index `v` with a boolean mask; keep matching elements.
- **Expected:** `v[mask] = 30 40 50`

### Q3d

- **Task:** Map `$x/10 + $y` over `v`.
- **Note:** Treat `v`'s elements as 1D: only `$x` varies per element; `$y` or `$z` in the expression must be omitted by pluggin in value `0`.
- **Expected:** `mapped with $x/10+$y = 1 3 5 7 9`

### Q3e

- **Task:** Support negative subscripts (Python-style from the end).
- **Operations:** `v[-1]`, `v[-2]`
- **Expected:** `tail = 50 40`

### Q3f

- **Task:** Slice via `tuple<int, int>` (here `tuple{1, -1}`).
- **Note:** `[1:-1]` means start at index 1 through the last element (inclusive).
- **Expected:** `sliced = v[1:-1] = 20 30 40 50`

### Q4a

- **Task:** Provide r-value-compatible methods:
  - `.mask(predicate)` returns boolean vector
  - `.pick(vector<bool>)` returns values matching mask
- **Expected outputs:**
  - `v.mask($x > 45) = 0 0 0 0 1`
  - `v.pick(vector<bool>{false, true, false, true, false}) = 20 40`

### Q4b

- **Task:** Provide r-value-compatible `.slice()` for tuples:
  - `.slice(tuple{start, stop, step})` (3-element)
  - `.slice(tuple{start, stop})` (2-element)
- **Expected outputs:**
  - `v.slice(tuple{0, 5, 2}) = 10 30 50`
  - `v.slice(tuple{3, 5}) = 40 50`

### Q4c

- **Task:** Provide r-value-compatible `.slice()` for pairs and brace-init:
  - `.slice(pair{start, stop})`
  - `.slice({start, stop})`
- **Expected outputs:**
  - `v.slice(pair{0, 2}) = 10 20`
  - `v.slice({1, 2}) = 20`

### Q5

- **Task:** Apply `x^2 + 2y^2 - z` (as code: `$x*$x + 2*$y*$y - $z`) to each 3D tuple.
- **Data:** `Vector<tuple<double,double,double>>` with three rows:
  - `{1.1, 2.2, 3.3}`
  - `{4.4, 5.5, 6.6}`
  - `{7.7, 8.8, 9.9}`
- **Expected:** `apply(x^2 + 2y^2 - z) -> 7.59 73.26 204.27`

---

*End of exam sheet.*
