
# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project (openCV_course)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
# add_subdirectory (Hello)
# add_subdirectory (Demo)



# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
# add_library (First main.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
# target_include_directories (First PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})



# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (chapter0 src/chapter0.cpp)
add_executable (chapter1 src/chapter1.cpp)
add_executable (chapter2 src/chapter2.cpp)
add_executable (chapter3 src/chapter3.cpp)
add_executable (chapter4 src/chapter4.cpp)
add_executable (chapter5 src/chapter5.cpp)
add_executable (chapter6 src/chapter6.cpp)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
# target_link_libraries (main LINK_PUBLIC First)
target_link_libraries( chapter0 ${OpenCV_LIBS} )
target_link_libraries( chapter1 ${OpenCV_LIBS} )
target_link_libraries( chapter2 ${OpenCV_LIBS} )
target_link_libraries( chapter3 ${OpenCV_LIBS} )
target_link_libraries( chapter4 ${OpenCV_LIBS} )
target_link_libraries( chapter5 ${OpenCV_LIBS} )
target_link_libraries( chapter6 ${OpenCV_LIBS} )
