add_subdirectory(Generic)
add_subdirectory(Tablet)

target_sources(BTD5-Win PRIVATE
	"${CMAKE_CURRENT_LIST_DIR}/Screens.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/ScriptedScreen.cpp"
)