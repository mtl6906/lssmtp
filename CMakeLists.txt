project(smtp)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

aux_source_directory(src/ls/smtp SRC)
aux_source_directory(sample SRC_SAMPLE)

include_directories(src)

add_executable(testcase ${SRC} ${SRC_SAMPLE})

add_library(lssmtp SHARED ${SRC})

target_link_libraries(testcase lsconfig lsjson lsbase64 lsbuffer lsutil lsorderedmap)
