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
set(WTF_CPU_X86_64 1)
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
set(DERIVED_SOURCES_JAVASCRIPTCORE_DIR "${CMAKE_BINARY_DIR}/DerivedSources/JavaScriptCore")
set(DERIVED_SOURCES_WEBINSPECTORUI_DIR "${CMAKE_BINARY_DIR}/DerivedSources/WebInspectorUI")

set(RUBY_EXECUTABLE "/usr/bin/ruby")
set(PYTHON_EXECUTABLE "/usr/bin/python")

macro(POPULATE_LIBRARY_VERSION library_name)
if (NOT DEFINED ${library_name}_VERSION_MAJOR)
    set(${library_name}_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
endif ()
if (NOT DEFINED ${library_name}_VERSION_MINOR)
    set(${library_name}_VERSION_MINOR ${PROJECT_VERSION_MINOR})
endif ()
if (NOT DEFINED ${library_name}_VERSION_MICRO)
    set(${library_name}_VERSION_MICRO ${PROJECT_VERSION_MICRO})
endif ()
if (NOT DEFINED ${library_name}_VERSION)
    set(${library_name}_VERSION ${PROJECT_VERSION})
endif ()
endmacro()

macro(INCLUDE_IF_EXISTS _file)
    if (EXISTS ${_file})
        message(STATUS "Using platform-specific CMakeLists: ${_file}")
        include(${_file})
    else ()
        message(STATUS "Platform-specific CMakeLists not found: ${_file}")
    endif ()
endmacro()

macro(WEBKIT_INCLUDE_CONFIG_FILES_IF_EXISTS)
    if (PORT_FALLBACK)
        INCLUDE_IF_EXISTS(${CMAKE_CURRENT_SOURCE_DIR}/Platform${PORT_FALLBACK}.cmake)
    endif ()
    INCLUDE_IF_EXISTS(${CMAKE_CURRENT_SOURCE_DIR}/Platform${PORT}.cmake)
endmacro()

macro(WEBKIT_SET_EXTRA_COMPILER_FLAGS _target)
    set(options ENABLE_WERROR IGNORECXX_WARNINGS)
    CMAKE_PARSE_ARGUMENTS("OPTION" "${options}" "" "" ${ARGN})
    if (CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        get_target_property(OLD_COMPILE_FLAGS ${_target} COMPILE_FLAGS)
        if (${OLD_COMPILE_FLAGS} STREQUAL "OLD_COMPILE_FLAGS-NOTFOUND")
            set(OLD_COMPILE_FLAGS "")
        endif ()

        get_target_property(TARGET_TYPE ${_target} TYPE)
        if (${TARGET_TYPE} STREQUAL "STATIC_LIBRARY") # -fPIC is automatically added to shared libraries
            set(OLD_COMPILE_FLAGS "-fPIC ${OLD_COMPILE_FLAGS}")
        endif ()

        # Enable warnings by default
        if (NOT ${OPTION_IGNORECXX_WARNINGS})
            set(OLD_COMPILE_FLAGS "-Wall -Wextra -Wcast-align -Wformat-security -Wmissing-format-attribute -Wpointer-arith -Wundef -Wwrite-strings ${OLD_COMPILE_FLAGS}")
        endif ()

        # Enable errors on warning
        if (OPTION_ENABLE_WERROR)
            set(OLD_COMPILE_FLAGS "-Werror -Wno-error=unused-parameter ${OLD_COMPILE_FLAGS}")
        endif ()

        set_target_properties(${_target} PROPERTIES
            COMPILE_FLAGS "${OLD_COMPILE_FLAGS}")

        unset(OLD_COMPILE_FLAGS)
    endif ()
endmacro()



# -----------------------------------------------------------------------------
# Port-specific options
# -----------------------------------------------------------------------------
include(Options${PORT})

# -----------------------------------------------------------------------------
# Add module directories
# -----------------------------------------------------------------------------
add_subdirectory(Source)


