# build



不同平台生成命令可能不同。

一定要确保所有使用的工具(cmake/make/ninja/gcc等)都是同一环境下的

在windows下会优先使用msvc来编译，但如果使用的cmake是cygwin下的，则可能会选择其他工具。

```shell
cmake -B build
cmake -B build -G Ninja
cmake -B build -G "Unix Makefiles"
```




编译
```shell
cmake --build build
```