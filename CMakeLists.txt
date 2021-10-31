project(lssmtp)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

aux_source_directory(src/ls/smtp SRC)
aux_source_directory(sample SRC_SAMPLE)

include_directories(include)

add_executable(testcase ${SRC} ${SRC_SAMPLE})

link_directories(/user/local/lib)

add_library(lssmtp SHARED ${SRC})

target_link_libraries(testcase lsjson lsbuffer lsconfig lslogger lstime lsio lsnet lsitem lscopyableitem lsfile lsexception lscstring lsbase64)

install(TARGETS lssmtp DESTINATION lib)

install(DIRECTORY include/ls/smtp DESTINATION include/ls)
