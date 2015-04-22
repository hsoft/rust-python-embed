#!/bin/sh

echo "Building the Rust library..."
cd rust
cargo clean
cargo build --release
mv target/release/libmyrustlib-*.a ../pymodule/libmyrustlib.a

echo "Building the Python module..."
cd ../pymodule
python3 setup.py
mv _myrustlib*.so ..
cd ..

echo "Building done! You can try _myrustlib by running try.py"

