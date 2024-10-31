cmake_minimum_required(VERSION 3.17)
project(BTD5-Decomp
	VERSION 4.5
	DESCRIPTION "A CMake build for the BloonsTD5 Decompilation"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 26)

if (WIN32)
set (NFW_PLATFORM_NAME "Win")
elseif (UNIX)
set(NFW_PLATFORM_NAME "Unix")
endif ()

set(GAME_TITLE "BloonsTD5")
set(GAME_TARGET ${GAME_TITLE}-${NFW_PLATFORM_NAME})

message("Platform: " ${NFW_PLATFORM_NAME})
message("Title: " ${GAME_TITLE})
message("Target: " ${GAME_TARGET})

add_subdirectory(Game)
add_subdirectory(Framework)
