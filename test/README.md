CDT Test
========
This is a standalone library that try to imitate [Jasmine](https://jasmine.github.io/)'s syntax for unit testing.

How does it work?
-----------------
Just write a new `main.cpp` (or any other name) and link it to your sources and/or library. 
After that you just have to use the simple syntax to write your tests.

Hello World!
------------
```c++
#include <cdt/test/test.hpp>

BEGIN_TEST

DESCRIBE("Hello World")
    IT("1==1")
        SHOULD(int, 1).BE(1);
    END_IT
END_DESCRIBE

END_TEST
```
Build then run. It will output:
```
================================= Hello World =================================
   1==1...................................................................OK
=================== Run: 1, Success: 1, Fail: 0, Disabled: 0 ==================

================================ Tests results ================================
        Total group run:      1                 Total unit run:       1
        Total group success:  1                 Total unit success:   1
        Total group fail:     0                 Total unit fail:      0
        Total group disabled: 0                 Total unit disabled:  0
```
