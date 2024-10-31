add_subdirectory(Leaderboards)

target_sources(${GAME_TARGET} PRIVATE
	"${CMAKE_CURRENT_LIST_DIR}/GameProfile.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/PlayerProfileV1.cpp"
)