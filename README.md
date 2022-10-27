#

## Files

1. `binary.obj`: Notes about the contents of the binary generated by the compiler and how we are going to patch it to make it slower.
2. `binary_generator.cpp`: The C++ source code that generates the binary that we are patching.
3. `bed.cmd`: The command that we used (using `bed`) to patch the binary.
4. `temp.txt`: The file that the binary program `stat`s (We needed to write code that did *something*, after all).
5. `artifacts/binary`: The binary that we are going to patch.
6. `artifacts/binary-patched`: The patched binary (recreatable with `source bed.cmd`).