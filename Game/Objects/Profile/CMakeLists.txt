add_subdirectory(Leaderboards)

target_sources(BTD5-Win PRIVATE
	"${CMAKE_CURRENT_LIST_DIR}/GameProfile.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/PlayerProfileV1.cpp"
)