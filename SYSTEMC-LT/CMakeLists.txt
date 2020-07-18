# SCBuilder version 0.1.6 Cmake file
# Invoke with cmake -G "MSYS Makefiles" ..

cmake_minimum_required(VERSION 3.2.2)
project("LC1")

set(SYSTEMC_HOME "C:/SCBuilder//SystemC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories("C:/Users/Rocker/Desktop/Extra_study/SystemC/time_loosly_coupled")
include_directories(${SYSTEMC_HOME}/include)

link_directories(${SYSTEMC_HOME}/lib-mingw)

add_executable(LC1
	"C:/Users/Rocker/Desktop/Extra_study/SystemC/time_loosly_coupled/tbtime.cpp"
	"C:/Users/Rocker/Desktop/Extra_study/SystemC/time_loosly_coupled/timer.cpp"
	"C:/Users/Rocker/Desktop/Extra_study/SystemC/time_loosly_coupled/up_counter.cpp")

target_link_libraries(LC1 systemc) 			#link the SystemC library
