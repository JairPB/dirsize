# Dirsize

Dirsize is a command-line utility written in C that calculates and pretty-prints the total size of a specified directory on Linux.

## How It Works

1. **Directory Traversal**: The program uses the `nftw` (File Tree Walk) function from `<ftw.h>` to recursively traverse the directory path provided as a command-line argument.
2. **Size Accumulation**: For each file and directory traversed, the callback function `add_to_filesize` is invoked, adding the size (`sb->st_size` from `struct stat`) to a global variable `dirsize`.
3. **Pretty Printing**: Once the traversal is complete, `pretty_print_size` converts the accumulated size in bytes to a human-readable format (B, KB, MB, GB, or TB) using a divisor of 1000, and prints the result.

## Compilation

To compile the program, you need a C compiler like GCC. Run the following command in the project directory:

```bash
gcc -O2 dirsize.c -o dirsize
```

This generates an executable named `dirsize`.

## Usage

Run the executable by passing the target directory path as an argument:

```bash
./dirsize /path/to/directory
```

## Making It Globally Executable on Linux

To run `dirsize` from any directory without specifying its path, you can copy the compiled binary to a directory included in your system's `PATH`.

### Option 1: Install for all users (system-wide)

Copy the executable to `/usr/local/bin/` (requires administrator/sudo privileges):

```bash
sudo cp dirsize /usr/local/bin/
```

### Option 2: Install for the current user only

Copy the executable to `~/.local/bin/` (typically already in the user's path on modern Linux distributions):

```bash
mkdir -p ~/.local/bin
cp dirsize ~/.local/bin/
```

Ensure `~/.local/bin` is in your `PATH` by checking your shell configuration file (e.g., `.bashrc` or `.zshrc`). If it is not, add the following line to it:

```bash
export PATH="$HOME/.local/bin:$PATH"
```
