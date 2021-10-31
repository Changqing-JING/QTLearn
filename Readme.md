install on Ubuntu

sudo apt install qt5-default

install on windows:
https://download.qt.io/archive/qt/5.14/5.14.2/

>=5.15 must be installed with online installer
https://download.qt.io/official_releases/online_installers/

download and install

add {CMAKE_PREFIX_PATH, "C:\\Qt\\5.15.2\\msvc2019_64"} in system environment


install from source code:
    https://wiki.qt.io/Building_Qt_5_from_Git
    Make sure the python version must be 2.7 and NO space in python path
    install ruby and perl
    perl init-repository
    configure -prefix %CD%\qtbase -nomake tests
    choose open source
    After build, add ${QT_PROJECT_ROOT}\qtbase to CMAKE_PREFIX_PATH in Environment variables

clean configure:
    git submodule foreach --recursive "git clean -dfx"


Build on windows:
cmake -G "Visual Studio 16 2019" ..