cmake_minimum_required(VERSION 3.20)
project(my_game VERSION 1.0.0 LANGUAGES CXX)

# Require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Library: game_core ----
add_library(game_core
 src/core/Game.cpp
 src/core/Level.cpp
 src/levels/LevelManager.cpp
 src/entities/Player.cpp
)
target_include_directories(game_core PUBLIC include)

# ---- Executable: my_game ----
add_executable(my_game apps/main.cpp)
target_link_libraries(my_game PRIVATE game_core)

# ---- Tests(optional) ----
option(BUILD_TESTS "Build unit tests" OFF)
"tok-kw">if(BUILD_TESTS)
 add_subdirectory(tests)
endif()
