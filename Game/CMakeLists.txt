add_executable(BTD5-Win)

add_subdirectory(Events)
add_subdirectory(Factories)
add_subdirectory(Managers)
add_subdirectory(Objects)
add_subdirectory(Screens)
add_subdirectory(Utilities)

target_sources(BTD5-Win PRIVATE
	"${CMAKE_CURRENT_LIST_DIR}/BloonsTD5.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/BTD5SpecialEvents.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/NewsFeed.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/SocialLeaderboard.cpp"
)