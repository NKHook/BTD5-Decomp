add_subdirectory(Graph)

target_sources(BTD5-Win PRIVATE
	"${CMAKE_CURRENT_LIST_DIR}/Path.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/PathManager.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/PathModifiedFactory.cpp"
)