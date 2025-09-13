cmake_minimum_required(VERSION 3.12)
project(cabralcalc C)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
    -std=c2x \
    -Wall \
    -Wextra \
    -Werror \
    -Wconversion \
    -Wformat \
    -Wunreachable-code \
    -Wfloat-equal \
    -Wshadow \
    -Wpointer-arith \
    -Wstrict-prototypes \
    -Winit-self")

include_directories(include)
file(GLOB_RECURSE SRCS "src/*.c")


add_executable(cabralcalc ${SRCS})

target_compile_options(cabralcalc PRIVATE
    -g
    -fsanitize=address,undefined
)
target_link_options(cabralcalc PRIVATE
    -fsanitize=address,undefined
)

install(TARGETS cabralcalc DESTINATION bin)