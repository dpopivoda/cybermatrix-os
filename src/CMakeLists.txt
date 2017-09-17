set("${PROJECT_NAME}_headers" "")
set("${PROJECT_NAME}_sources" "Main.cpp")

add_executable("${PROJECT_NAME}" "${${PROJECT_NAME}_headers}" "${${PROJECT_NAME}_sources}")

include_directories("${PROJECT_NAME}" "${CMAKE_SOURCE_DIR}/SFML/include")

target_link_libraries("${PROJECT_NAME}" "sfml-graphics" "sfml-window" "sfml-audio" "sfml-network" "sfml-system" "${FREETYPE_LIBRARY}" "${JPEG_LIBRARY}" "${OPENAL_LIBRARY}" "${FLAC_LIBRARY}" "${VORBISENC_LIBRARY}" "${VORBISFILE_LIBRARY}" "${VORBIS_LIBRARY}" "${OGG_LIBRARY}")
if(WIN32)
	if(MINGW OR MSVC)
		if(MSVC)
			set("CONFIG_BIN_SUBDIR" "$\(ConfigurationName\)")
		endif()
		target_link_libraries("${PROJECT_NAME}" "${OPENGL_gl_LIBRARY}" "winmm" "ws2_32")
	else()
		message(FATAL_ERROR "${CMAKE_GENERATOR} is currently not supported.")
	endif()
	add_custom_command(
		TARGET "${PROJECT_NAME}"
		POST_BUILD COMMAND
		${CMAKE_COMMAND} -E copy_if_different
		"${CMAKE_SOURCE_DIR}/SFML/extlibs/bin/${CONFIG_ARCH_TYPE}/openal32.dll"
		"${CMAKE_BINARY_DIR}/bin/${CONFIG_BIN_SUBDIR}/openal32.dll"
	)
	if(BUILD_SHARED_LIBS)
		set_target_properties(
			"sfml-graphics" "sfml-window" "sfml-audio" "sfml-network" "sfml-system" PROPERTIES
			RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
		)
	else()
		target_compile_definitions("${PROJECT_NAME}" PRIVATE "SFML_STATIC")
	endif()
else()
	message(FATAL_ERROR "${CMAKE_SYSTEM_NAME} is currently not supported.")
endif()

set_target_properties(
	"${PROJECT_NAME}" PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
