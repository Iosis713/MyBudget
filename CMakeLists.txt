cmake_minimum_required (VERSION 3.28)
project (MyBudget)

set (FLAGS -Wall -Werror -Wextra -Wpedantic -fmodules)
set (CMAKE_CXX_COMPILER clang++-18)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

#For modules
set (CMAKE_CXX_SCAN_FOR_MODULES ON)
set (CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS "/usr/bin/clang-scan-deps-18")

#Enable Qt automatic features (moc, uic, rcc)
set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)
set (CMAKE_AUTOUIC ON)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
#Find Qt libraries
find_package(Qt6 COMPONENTS Widgets Core Gui REQUIRED)

set(SRC     Source/Category.cpp)
#add_library(${PROJECT_NAME}-lib STATIC)
#target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
#target_sources(
#    PUBLIC
#        FILE_SET modules TYPE CXX_MODULES FILES
#
#)


add_executable (${PROJECT_NAME} main.cpp ${SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)

target_compile_options (${PROJECT_NAME}     PRIVATE     ${FLAGS} -Og)
set_target_properties (${PROJECT_NAME}  PROPERTIES 
                                        CXX_STANDARD 20 
                                        CXX_STANDARD_REQUIRED ON
                                        AUTOMOC ON
                                        AUTOUIC ON
                                        AUTORCC ON)
