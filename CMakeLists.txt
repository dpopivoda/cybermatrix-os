cmake_minimum_required(VERSION 3.9)
project("CybermatrixOS")

set("CONFIG_BIN_SUBDIR" ".")
if("${CMAKE_SIZEOF_VOID_P}" STREQUAL "4")
	set("CONFIG_ARCH_TYPE" "x86")
elseif("${CMAKE_SIZEOF_VOID_P}" STREQUAL "8")
	set("CONFIG_ARCH_TYPE" "x64")
else()
	message(FATAL_ERROR "Failed to determine computer architecture.")
endif()

add_subdirectory("SFML")
add_subdirectory("src")
