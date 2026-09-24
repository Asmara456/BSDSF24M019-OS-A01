# REPORT: OS Assignment 01 (Feature-2: Multi-file Build)

## Q1. Explain the linking rule `$(TARGET): $(OBJECTS)`. How does it differ from a rule that links against a library?

In this Makefile, `$(TARGET)` is the executable `../bin/client` and `$(OBJECTS)` is the list of object files (`main.o`, `mystrfunctions.o`, `myfilefunctions.o`). The rule says the executable depends on all of the object files. If any `.o` file is newer than the executable, make runs the recipe `$(CC) $(OBJECTS) -o $@`, which links every object file together into one executable. `$@` stands for the target name.

A rule that links against a library is different. The library functions are not compiled into the program's own object files. Only `main.o` is linked directly, and the other functions come from a library file such as `libmyutils.a` (static) or `libmyutils.so` (dynamic). The link command then uses `-L../lib -lmyutils` (and `-I` for headers at compile time). With a static library, the needed code is copied into the executable at link time. With a dynamic library, the executable only records the dependency, and the code is loaded at run time.

## Q2. What is a git tag and why is it useful? What is the difference between a simple tag and an annotated tag?

A git tag is a fixed, human-readable name that points to one specific commit. Unlike a branch, it does not move when new commits are made. Tags are useful for marking stable points such as releases (for example `v1.0-multifile`), so anyone can return to exactly that version of the code, and GitHub Releases are built on top of tags.

A simple (lightweight) tag is just a name pointing to a commit and stores no extra information. An annotated tag (created with `git tag -a`) is a full git object that stores the tagger's name, email, date and a message, and it can be signed. Annotated tags are recommended for releases because they record who made the tag, when, and why.

## Q3. What is the purpose of creating a Release on GitHub? Why attach binaries?

A GitHub Release packages a specific tag into an official, downloadable version of the project, with a title, release notes and attached files. It gives users a clear list of stable versions and lets them download one without cloning the repository or looking through commits.

Attaching the compiled binary (`client`) means users can download and run the program directly without needing a compiler or having to run `make`. It also keeps the compiled file out of the git repository (build outputs are ignored in `.gitignore`), while still keeping a copy of the exact build for each version.
