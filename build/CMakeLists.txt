cmake_minimum_required(VERSION 3.12)

project(wavCopy)

add_executable(wavCopy
	../../src/task1.c
	../../src/getopt.c
	../../src/printheader.c)

	#target_link_libraries(wavCopy PRIVATE GainLibrary)
target_include_directories(wavCopy PRIVATE ../include)