# SIMPL_libc

**SIMPL_libc** is a lightweight and optimized implementation of the standard C library, designed to replace common libc standards like `glibc` and `musl`. The philosophy of **SIMPL_libc** is to remain highly portable and written predominantly in **pure C**, with optimizations focused on delivering excellent performance across a wide range of platforms.

## Features

- **Pure C Implementation**: Most of the library is written in portable C, making it easy to use on a wide variety of architectures without modification.
- **Optimized for Performance**: Although primarily written in C, SIMPL_libc is carefully optimized for performance, leveraging low-level optimizations where appropriate.
- **Lightweight**: A minimalist approach ensures a smaller memory and binary footprint, ideal for systems where size and efficiency are critical.
- **Modular and Extendable**: The library is modular, allowing for easy extensions or replacements of specific functions with architecture-specific implementations if needed.
- **Open to Contributions**: While the project is in its early stages, we are open to community contributions and encourage involvement to expand and improve the library.

## Why SIMPL_libc?

Most standard C libraries are designed with broad compatibility in mind, which can introduce unnecessary complexity and performance overhead. **SIMPL_libc** focuses on:
- **Portability**: Written in pure C to ensure easy deployment on various platforms without the need for architecture-specific tweaks.
- **Efficiency**: Carefully optimized for performance while maintaining simplicity, making it ideal for embedded systems or projects where performance and minimalism are important.
- **Simplicity**: A small and clean codebase, making it easier to audit, extend, and integrate into projects without the bloat found in larger standard libraries.

## Available Functions

Currently, **SIMPL_libc** offers optimized versions of commonly used C library functions, including:
- String manipulation functions: `strlen`, `strcmp`, `strcpy`, etc.
- Memory operations: `memcpy`, `memset`, `memmove`, etc.
- Memory allocation: `malloc`, `aligned_alloc` and `posix_memalign` are currently on development...

As the project evolves, additional functions will be added to match the full scope of standard libc implementations.

## Development Status

SIMPL_libc is still in the **early stages** of development. While several core functions are implemented and optimized, the library is a work in progress. We encourage contributions from the community to help expand the function set and further optimize the library.

## Contributions

We welcome contributions from the community! If you’re interested in contributing:
- **Fork** the repository and create your branch from `main`.
- **Add new features** or improve existing functionality.
- **Submit pull requests** for review and integration.

### Contribution Guidelines
- Ensure your code is written in **pure C** unless architecture-specific optimizations are absolutely necessary.
- Maintain portability across platforms.
- Provide clear documentation and tests for any new functionality.

## License

**SIMPL_libc** is licensed under the GPL 2.0 License. See the [LICENSE](./LICENSE) file for details.

at0m741 and Bonsthie
