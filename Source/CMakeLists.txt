# -----------------------------------------------------------------------------
# Add module directories
# -----------------------------------------------------------------------------
add_subdirectory(bmalloc)

add_subdirectory(WTF)

add_subdirectory(JavaScriptCore)

WEBKIT_INCLUDE_CONFIG_FILES_IF_EXISTS()

# -----------------------------------------------------------------------------
# Set compiler flags for all targets
# -----------------------------------------------------------------------------
WEBKIT_SET_EXTRA_COMPILER_FLAGS(bmalloc ${ADDITIONAL_COMPILER_FLAGS})
WEBKIT_SET_EXTRA_COMPILER_FLAGS(WTF ${ADDITIONAL_COMPILER_FLAGS})
WEBKIT_SET_EXTRA_COMPILER_FLAGS(JavaScriptCore ${ADDITIONAL_COMPILER_FLAGS})

# -----------------------------------------------------------------------------
# Create the configuration file
# -----------------------------------------------------------------------------
configure_file(cmakeconfig.h.cmake ${CMAKE_BINARY_DIR}/cmakeconfig.h @ONLY)
