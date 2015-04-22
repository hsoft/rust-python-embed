# rust-python-embed

This is a playground repo where I experiment with embedding rust in Python.

The `rust` folder contains a simple rust library with C exports as well as C header files. It
builds with Cargo.

The `pymodule` folder contains a python C extension that links to the `rust` library.

The end result is a `_myrustlib` module that is callable from Python 3.3+.

## Features

* Direct Python modules (no `cffi` or `ctypes`)
* `int` argument passing and returning
* Global static variables in Rust, controlled with locks

## Requirements

* Python 3.3+
* Rust 1.0

## How to build

    ./build.sh

The resulting `_myrustlib.so` file will be in the root folder. You can test that it works well
by running:

    python3 try.py

