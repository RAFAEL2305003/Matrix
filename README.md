# MatrixLib
A Matrix library written in C++

## How to build

In the library directory, run:

```bash
$ cmake -DCMAKE_BUILD_TYPE=Release -B build
$ cmake --build build
```

Now, put the libMatrix.a file in your project directory and include it with:

```cpp
#include <matrix.h>
```
