cmake_minimum_required(VERSION 3.10)
project(MySQLExample)

set(CMAKE_CXX_STANDARD 11)

# Find MySQL client libraries and include directories manually
find_path(MYSQL_INCLUDE_DIR NAMES mysql.h PATHS /usr/include/mysql)
find_library(MYSQL_LIBRARY NAMES mysqlclient PATHS /usr/lib /usr/lib/x86_64-linux-gnu)

if (MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)
    message(STATUS "Found MySQL include at ${MYSQL_INCLUDE_DIR}")
    message(STATUS "Found MySQL library at ${MYSQL_LIBRARY}")
else()
    message(FATAL_ERROR "Could not find MySQL include or library")
endif()

include_directories(${MYSQL_INCLUDE_DIR})
link_directories(${MYSQL_LIBRARY})

add_executable(MySQLExample sql.cpp)
target_link_libraries(MySQLExample ${MYSQL_LIBRARY})
