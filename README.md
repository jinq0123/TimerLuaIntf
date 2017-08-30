# TimerLuaIntf
Timer calls between C++ and Lua with LuaIntf.

Just a test.

## Conclusion
* Lua is fast.
* LuaIntf is good.

## Build
1. Install [conan](http://docs.conan.io/en/latest/installation.html).
1. `conan remote add remote_bintray_jinq0123 https://api.bintray.com/conan/jinq0123/test`
1. `conan install --build missing`
```
PROJECT: Generator visual_studio created conanbuildinfo.props
PROJECT: Generated conaninfo.txt
```
1. Use sln to build

## Output
```
C++ calls lua add() many times:
 2.759473s wall, 2.761218s user + 0.000000s system = 2.761218s CPU (100.1%)
C++ calls lua add_times() once:
 0.436400s wall, 0.436803s user + 0.000000s system = 0.436803s CPU (100.1%)
Lua calls C++ add() many times:
 0.535802s wall, 0.530403s user + 0.000000s system = 0.530403s CPU (99.0%)
Lua calls C++ add_times() once:
 0.000005s wall, 0.000000s user + 0.000000s system = 0.000000s CPU (n/a%)
```

## Reference
* http://www.cnblogs.com/archy_yu/p/3185608.html
