cmake_minimum_required(VERSION 3.20)
project(proj1_csv_analytics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for tooling (clang-tidy, editors, etc.)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Warnings ----
function(enable_warnings target)
  if (MSVC)
    target_compile_options(${target} PRIVATE /W4 /permissive-)
  else()
    target_compile_options(${target} PRIVATE
      -Wall -Wextra -Wpedantic -Wconversion -Wshadow
    )
  endif()
endfunction()

# ---- Sanitizers (Debug) ----
function(enable_sanitizers target)
  if (NOT MSVC AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
  endif()
endfunction()

# ---- App ----
add_executable(csv_analytics
  src/main.cpp
)

enable_warnings(csv_analytics)
enable_sanitizers(csv_analytics)

# ---- Tests ----
enable_testing()

add_executable(tests
  src/tests/test_smoke.cpp
)

enable_warnings(tests)
enable_sanitizers(tests)

add_test(NAME smoke COMMAND tests)
