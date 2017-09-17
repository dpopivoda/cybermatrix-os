set("${PROJECT_NAME}_headers", "")
set("${PROJECT_NAME}_sources", "Main.cpp")

add_executable("${PROJECT_NAME}" "${${PROJECT_NAME}_headers}" "${${PROJECT_NAME}_sources}")

set_target_properties(
	"${PROJECT_NAME}" PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
