# anatomy
A C++20 library modeling structural and cross-cutting relations of human anatomy.

## Build
```bash
cmake -S . -B build && cmake --build build -j && ctest --test-dir build
```

## Docs
```bash
cmake --build build --target anatomy_docs
```
