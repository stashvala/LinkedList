project( testFib )
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE RelWithDebInfo )
add_definitions ( -Wall )

add_executable ( unittest #name of executable 
                 fib.cpp
		 fib.h
		 main.cpp
	         test.cpp)

target_link_libraries ( unittest
                        gtest
			pthread) #pthread more biti na koncu

