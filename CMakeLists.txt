cmake_minimum_required(VERSION 2.8.8)
project(WebKit)



# -----------------------------------------------------------------------------
# Default library type
# -----------------------------------------------------------------------------
set(BMALLOC_DIR "${CMAKE_SOURCE_DIR}/Source/bmalloc")
set(WTF_DIR "${CMAKE_SOURCE_DIR}/Source/WTF")
set(JAVASCRIPTCORE_DIR "${CMAKE_SOURCE_DIR}/Source/JavaScriptCore")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Source/cmake")

# Do not create transitive library dependencies by default
set(CMAKE_LINK_INTERFACE_LIBRARIES "")

set (PORT GTK)
# -----------------------------------------------------------------------------
# Determine which port will be built
# -----------------------------------------------------------------------------
set(ALL_PORTS Efl WinCE GTK AppleWin WinCairo Mac)
set(PORT "NOPORT" CACHE STRING "choose which WebKit port to build (one of ${ALL_PORTS})")

list(FIND ALL_PORTS ${PORT} RET)
if (${RET} EQUAL -1)
    message(FATAL_ERROR "Please choose which WebKit port to build (one of ${ALL_PORTS})")
endif ()

# -----------------------------------------------------------------------------
# Determine the operating system
# -----------------------------------------------------------------------------
if (UNIX)
    if (APPLE)
        set(WTF_OS_MAC_OS_X 1)
    else ()
        set(WTF_OS_UNIX 1)
    endif ()
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(WTF_OS_WINDOWS 1)
else ()
    message(FATAL_ERROR "Unknown OS '${CMAKE_SYSTEM_NAME}'")
endif ()

# -----------------------------------------------------------------------------
# Default library types
# -----------------------------------------------------------------------------
option(SHARED_CORE "build JavaScriptCore and WebCore as shared libraries")

if (SHARED_CORE)
    set(JavaScriptCore_LIBRARY_TYPE SHARED)
    set(WebCore_LIBRARY_TYPE SHARED)
else ()
    if (${PORT} STREQUAL GTK AND NOT DEFINED INSTRUMENT_SWITCH)
        set(JavaScriptCore_LIBRARY_TYPE SHARED)
    else ()
        set(JavaScriptCore_LIBRARY_TYPE STATIC)
    endif ()
    set(WebCore_LIBRARY_TYPE STATIC)
endif ()

# -----------------------------------------------------------------------------
# Install JavaScript shell
# -----------------------------------------------------------------------------
option(SHOULD_INSTALL_JS_SHELL "generate an installation rule to install the built JavaScript shell")

# -----------------------------------------------------------------------------
# Common options
#------------------------------------------------------------------------------
include(OptionsCommon)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# -----------------------------------------------------------------------------
# Port-specific options
# -----------------------------------------------------------------------------
include(Options${PORT})

# -----------------------------------------------------------------------------
# Add module directories
# -----------------------------------------------------------------------------
add_subdirectory(Source)


