cmake_minimum_required(VERSION 3.4.1)
add_library(bitmap-util SHARED src/main/cpp/bitmap-util.cpp )
# 链接 jnigraphics 库
target_link_libraries(bitmap-util jnigraphics)