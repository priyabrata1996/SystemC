# SCBuilder version 0.1.6 Cmake file
# Invoke with cmake -G "MSYS Makefiles" ..

cmake_minimum_required(VERSION 3.2.2)
project("Time_project")

set(SYSTEMC_HOME "C:/SCBuilder//SystemC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories("C:/Users/Rocker/Desktop/Extra_study/SystemC/Time")
include_directories(${SYSTEMC_HOME}/include)

link_directories(${SYSTEMC_HOME}/lib-mingw)

add_executable(Time_project
	"C:/Users/Rocker/Desktop/Extra_study/SystemC/Time/tbtime.cpp"
	"C:/Users/Rocker/Desktop/Extra_study/SystemC/Time/timer.cpp"
	"C:/Users/Rocker/Desktop/Extra_study/SystemC/Time/up_counter.cpp")

target_link_libraries(Time_project systemc) 			#link the SystemC library
