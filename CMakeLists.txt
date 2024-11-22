cmake_minimum_required(VERSION 3.10)
project(merklerex VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

# Укажите путь к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/include)

# Найдите все файлы .cpp в каталоге src
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл
add_executable(merklerex ${SOURCES})

set_target_properties(${PROJECT_NAME}
PROPERTIES
 RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
 RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
 RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
 RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

# Copy the assets folder info the build directory.

# add_custom_target(copy_assets
#     COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/assets
# )

message("Source directory: ${CMAKE_CURRENT_SOURCE_DIR}/assets")
message("Target directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets")
add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)

add_dependencies(${PROJECT_NAME} copy_assets)

include(CTest)
enable_testing()