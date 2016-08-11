project( LinkedListUnitTesting )
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE RelWithDebInfo )
add_definitions ( -Wall )

add_executable ( runtests #name of executable
				 Node.h
				 LinkedList.h
				 unit_tests.cpp
				 main.cpp)

target_link_libraries ( runtests
						gtest
						pthread) #gtest and pthread order is important!

