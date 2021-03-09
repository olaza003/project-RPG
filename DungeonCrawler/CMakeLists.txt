CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(exe
   main.cpp
   entities.cpp
   sequenceManager/seqMan.cpp
   items/protoITEMS/storage.cpp
   items/protoITEMS/protoITEMS.cpp
)
