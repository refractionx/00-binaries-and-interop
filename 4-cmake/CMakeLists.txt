cmake_minimum_required(VERSION 3.16)

project(helloWorld C)

add_executable(helloWorld ../2-linking/helloWorld.c)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "-O2 -flto")
set(CMAKE_C_FLAGS_RELEASE "-O2 -flto -Wall -Wextra")

add_library(greetings STATIC IMPORTED)

if(MSYS OR MINGW)
  set_target_properties(greetings PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../1-libraries/static/win64/libgreetings-it-mingw64-msys2.a"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../1-libraries/include"
  )
elseif(CMAKE_GENERATOR MATCHES "Visual Studio")
  set(CMAKE_C_FLAGS "-D_DLLEXPORT /GL")
  set(CMAKE_C_FLAGS_DEBUG "")
  set(CMAKE_C_FLAGS_RELEASE "")
  set_target_properties(greetings PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../1-libraries/static/win64/libgreetings-it.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../1-libraries/include"
  )
else()
  set_target_properties(greetings PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../1-libraries/static/macOS/libgreetings-it.a"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../1-libraries/include"
  )
endif()


target_link_libraries(helloWorld greetings)