# TestU01 - Docker Wrapper

This wrapper allows run TestU01 tests for any generator on any language.

## Install

`docker build -t testu01 .`

## Use

It reads 4-byte sequences from stdin.<br>
To make things happy pipe desired generator with it.

For test purposes use PCG32 generator from Crystal Lang placed in example folder:

1. `docker build -t generator-test example`
2. `docker run --rm --name gen-test generator-test | docker run --rm -i testu01 SmallCrush > result.log`
3. Generator container does not stop automatically. Stop it manually: `docker stop gen-test`

There are 3 types of tests that should be sent to the arguments: SmallCrush, Crush, BigCrush.<br>
For explicit reasons there is no default value.
