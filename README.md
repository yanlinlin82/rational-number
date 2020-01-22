# Rational Number in C++

## Motivation

This library is for representing rational number precisely, in decimal or other positional system, such as binary form.

## Quick Start

This library is released as single C++ header: [rational.h](rational.h)

Here goes a very simple example:

```cpp
#include "rational.h"
using namespace std;  // for 'rational'
using namespace math; // for 'cout' & 'endl'

int main()
{
    rational x(3, 5);
    cout << x.to_fraction() << endl;   // in fraction format: 3/5
    cout << x.to_decimal() << endl;    // in decimal format: 0.6
    cout << x.to_decimal<2>() << endl; // in binary decimal format: 0.(1001)...
    return 0;
}
```

There are more examples in [demo.cpp](demo.cpp)
