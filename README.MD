# DevWorkSpace

an super editor built from dev to devs.

### For Build using vs2022 terminal
C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2022\Visual Studio Tools\VC
%comspec% /k "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
### Build it using nmake
mkdir build
cd build
cmake -G "NMake Makefiles" -D CMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="/MT /O2 /Ob2 /D NDEBUG" -DCMAKE_C_FLAGS_RELEASE="/MT /O2 /Ob2 /D NDEBUG" ..
nmake all


##### Plugin System

