#!/bin/sh

echo "Building the Rust library..."
cd rust
cargo clean
cargo build --release
mv target/release/libmyrustlib-*.a ../pymodule/libmyrustlib.a

echo "Building the Python module..."
cd ../pymodule
python3 setup.py

echo "Testing the newly built module"
python3 -c "import _myrustlib; print(_myrustlib.triple(42))"

