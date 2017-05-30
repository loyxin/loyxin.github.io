# geant4
## install
### require
gcc>= GCC 4.8.5+

CMake>= 3.3+

### cmake 
```shell
cmake [options...] ../geant4.10.03.p01
```
Important options:

```
-DCMAKE_INSTALL_PREFIX=...installation_path...
-DGEANT4_INSTALL_DATA=ON/OFF
-DGEANT4_BUILD_MULTITHREADED=ON/OFF
```
Further options:

```
-DGEANT4_USE_OPENGL_X11=ON/OFF
-DGEANT4_USE_QT=ON/OFF
-DCMAKE_BUILD_TYPE=Release/Debug/RelWithDebInfo
```
then 

```
make 
```
看到没有什么库， 补充什么库
 
And last:
 
```
make install
```

可能要权限

#### data

data 放在`share/Geant4-10.3.1/data`

## 编译例子
### 直接编译
在原目录下直接编译，要`source`

```shell
source PATH_TO_GEANTJ_INSTALL/share/geant4__/geant4make/geant4make.sh
```

### cmake
写`cmakefile` 框架：

![cmake](C://Users//loyxin//Pictures//first//cmake.png)

```
cmake -DGeant4_DIR=[directory containing the Geant4 libraries] [source_directory]
```

```
mkdir xx-build && cd xx-build
cmake  -DGeant4_DIR=/usr/local/geant4/geant4.10.03.p01-install/lib64/Geant4-10.3.1/ ~/_codes
make
```
or
包含 root 之类的扩展

```
cmake -DGeant4_DIR=/usr/local/geant4/geant4.10.03.p01-install/lib64/Geant4-10.3.1 -DCMAKE_MODULE_PATH=/usr/local/geant4/geant4.10.03.p01-install/lib64/Geant4-10.3.1/Modules/ [source_directory]
cmake  -DGeant4_DIR=/usr/local/geant4/geant4.10.03.p01-install/lib64/Geant4-10.3.1/ ~/_codes
make
```

## UI interactive
1. hard-coded application
 * no user interaction 
 * everything specified in the C++ source
 * re-compile needed to apply changes
2. batch session
 - commands in external macro file
3. interactive session
 - real-time command input by user
 - textual, graphical, (network-based)

A complete list of built-in commands is available inthe Geant4 Application Developers Guide, Chapter 7.1
(http://geant4.cern.ch/G4UsersDocuments/UsersGuides/ForApplicationDeveloper/html/Control/commands.html)

macro

```
 /run/initialize
 /vis/open OGLSQt \# This automatically opens a graphic window.
 /vis/drawVolume
 /vis/scene/add/trajectories smooth
 /vis/scene/endOfEventAction accumulate
 /run/beamOn 10

 /vis/viewer/pan -5 0 cm
 /vis/viewer/zoom 1.3

 ls /vis/viewer
 help /vis/viewer/PutHereTheCommandName
```
 
 #### 修改 qt 成 tcsh

```
export G4UI_USE_TCSH=1
unset G4UI_USE_QT
```