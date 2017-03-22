# Regression for Sparse Signal

A c++ package to implement various regression algorithms for sparse signal reconstruction.

## Prerequisite
The only depedent library is [Eigen](http://eigen.tuxfamily.org).
Sicne `Eigen` is a header-only library, one only need to create a syumlink in `/usr/local/include` that points to the `Eigen` folder of the source code. Alternatively, one can specify `-I /path/to/eigen` in the compiler.

## Compile
```
make
```

## Clean up
```
make clean
```

## Make Test
```
make test
```
Then, the test program can be found in `bin/test_ress`

## Run test

The `LD_LIBRARY_PATH` need to be set for the test program to run
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/lib
```