cmake_minimum_required (VERSION 3.28)
project (MyBudget LANGUAGES CXX)

set (CMAKE_CXX_COMPILER clang++-18)
set (CMAKE_CXX_EXTENSIONS OFF)
set (FLAGS -Wall -Werror -Wextra -Wpedantic)

#For modules
set (CMAKE_CXX_SCAN_FOR_MODULES ON)
set (CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS "/usr/bin/clang-scan-deps-18")

#########################   GTEST   #########################
set (GMOCK_LIBRARIES        /usr/lib/libgmock.a /usr/lib/libgmock_main.a)
find_package(GTest REQUIRED)
#########################   GTEST   #########################

#########################   QT   #########################
find_package(Qt6 COMPONENTS Widgets Core Gui REQUIRED)

#Enable Qt automatic features (moc, uic, rcc)

set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)
set (CMAKE_AUTOUIC ON)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
#########################   QT   #########################

#########################   MODULES   #########################
set(ModuleInc        ${CMAKE_CURRENT_SOURCE_DIR}/Include/Category.cppm
                     ${CMAKE_CURRENT_SOURCE_DIR}/Include/Transaction.cppm
                     )

set(ModuleSrc        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Category.cpp
                     ${CMAKE_CURRENT_SOURCE_DIR}/Source/Transaction.cpp)

message(STATUS "ModuleInc = ${ModuleInc}")
message(STATUS "ModuleSrc = ${ModuleSrc}")
message(STATUS "ScanDeps = ${CLANG_SCAN_DEPS_EXECUTABLE}")

add_library (${PROJECT_NAME}-lib STATIC)
target_compile_features (${PROJECT_NAME}-lib PUBLIC cxx_std_20)

target_sources (${PROJECT_NAME}-lib
         PUBLIC
                FILE_SET modules TYPE CXX_MODULES FILES "${ModuleInc}"
         PRIVATE
                ${ModuleSrc}
)
#########################   MODULES   #########################

add_executable (${PROJECT_NAME} main.cpp)
add_executable (${PROJECT_NAME}-gt testRunner.cpp)

target_link_libraries(${PROJECT_NAME}-gt  PRIVATE       ${GTEST_LIBRARIES}
                                                        ${GMOCK_LIBRARIES}
                                                        ${PROJECT_NAME}-lib
                                                        )
target_link_libraries(${PROJECT_NAME}     PRIVATE       Qt6::Widgets Qt6::Core Qt6::Gui
                                                        ${PROJECT_NAME}-lib
                                                        )

target_compile_options (${PROJECT_NAME}-lib PRIVATE     ${FLAGS} -Og)
target_compile_options (${PROJECT_NAME}-gt  PRIVATE     ${FLAGS} -Og)
target_compile_options (${PROJECT_NAME}     PRIVATE     ${FLAGS} -Og)

set_target_properties (${PROJECT_NAME}-lib       PROPERTIES
                                                 CXX_STANDARD 20
                                                 CXX_STANDARD_REQUIRED ON)

set_target_properties (${PROJECT_NAME}-gt        PROPERTIES
                                                 CXX_STANDARD 20
                                                 CXX_STANDARD_REQUIRED ON)

set_target_properties (${PROJECT_NAME}           PROPERTIES
                                                 CXX_STANDARD 20
                                                 CXX_STANDARD_REQUIRED ON
                                                 AUTOMOC ON
                                                 AUTOUIC ON
                                                 AUTORCC ON)

set (CMAKE_VERBOSE_MAKEFILE ON)
