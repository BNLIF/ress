# Regression for Sparse Signal

A c++ package to implement various regression algorithms for sparse signal reconstruction.

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