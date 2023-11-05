# DevWorkSpace

an super editor built from dev to devs.

### For Build using vs2022 terminal
```
C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2022\Visual Studio Tools\VC
%comspec% /k "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
```
### Build it using nmake

```
mkdir build
cd build
cmake -G "NMake Makefiles" -D CMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="/MT /O2 /Ob2 /D NDEBUG" -DCMAKE_C_FLAGS_RELEASE="/MT /O2 /Ob2 /D NDEBUG" ..
nmake all
```
#### Build Linux
```
mkdir build
cd build 
cmake ..
make
```

##### Editor 
this feature require that the application could work as single editor, you can edit text files in general, represented by ascii or UTF-x

##### Style System


#### Tabs


##### Plugin System

there is not definition of this yet.



##### Testing required ctest 

```
ctest --test-dir <BUILD_DIR> --output-on-failure -j12
```