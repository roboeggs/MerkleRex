cmake_minimum_required(VERSION 3.10)
project(merklerex VERSION 0.1.0 LANGUAGES C CXX)

# Укажите путь к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/include)

# Найдите все файлы .cpp в каталоге src
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл
add_executable(merklerex ${SOURCES})

# add_executable(merklerex main.cpp)

include(CTest)
enable_testing()