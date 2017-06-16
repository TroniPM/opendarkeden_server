# Packages:

Some packages not standard that you'll have to install (you may have to install more packages), at least i had to install these:
  - sudo apt install xutils-dev (because gccmakedep)
  - sudo apt install libmysqlclient-dev (because mysql.h)
  - sudo apt install liblua5.2-dev (because lua.hpp)
  - sudo apt install libcppunit-dev (because tests all over the server/gameserver folder)
  - sudo apt install libssl-dev

Every mention of cpsso LIB (this libs is a mess...), was commented. It was used to throw exception in these files:
  - src/Core/Cpackets/CLLogin.cpp
  - src/Core/Cpackets/GS/CLLogin.cpp
  - src/Core/Cpackets/LS/CLLogin.cpp
  - src/Core/Cpackets/SS/CLLogin.cpp

# For compiling:
cd src
make depall
make

# To generate source documentation:
cd src
doxygen