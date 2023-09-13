# Cooking with Go

## Quick Start

Go to one of the folders and run:

```
cd [subfolder]
go run main.go
```

## General notes about this language and ecosystem

I first became interested in Go when reading this [post about Go's syntax](https://go.dev/blog/declaration-syntax). The way function pointer declaration is handled (syntactically) in Go seems to be cleaner than. These are some points that stood out to me, when learning the basics of Go that makes it interesting:

* **Coding conventions**
    * if a name is written with a capital letter, it is exported (can be used from outside a package)
* **Default linting through compiler**
    * For example, if there are unused modules, code won't compile
* **All-in-One ecosystem**
    * everything is handled by the `go` executable, no need for a separate CMake/Makefile-like system

Of course, Go is much more than it's function pointer declaration, but it is what caught my interest

### Packaging / Package Manager

A module is a collection of related Go packages that are versioned together as a single unit. Modules record precise dependency requirements and create reproducible builds.

TODO

### Build Systems

TODO

### Formatter + Linter

TODO

### Learning Resources

TODO

