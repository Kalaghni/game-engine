# Contributor Guidelines

## Code Style
- Use C++17 features and keep code portable across platforms.
- Separate engine, platform, and game code into their respective modules.
- Place external dependencies in `third_party/`.

## Testing
Run the following commands before submitting any changes:
```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

## Pull Requests
- Provide a summary of your changes.
- Mention which tests were executed and their results.
