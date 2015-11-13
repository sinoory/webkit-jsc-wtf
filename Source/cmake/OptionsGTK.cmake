include(GNUInstallDirs)

set(PROJECT_VERSION_MAJOR 2)
set(PROJECT_VERSION_MINOR 8)
set(PROJECT_VERSION_MICRO 0)
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_MICRO})
set(WEBKITGTK_API_VERSION 4.0)

# Libtool library version, not to be confused with API version.
# See http://www.gnu.org/software/libtool/manual/html_node/Libtool-versioning.html

# IndexedDB support requires GCC 4.9, see https://bugs.webkit.org/show_bug.cgi?id=98932.
#if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9.0")
#        message(FATAL_ERROR "GCC 4.9.0 is required to build WebKitGTK+, use a newer GCC version or clang")
#`    endif ()
#endif ()

set(ENABLE_CREDENTIAL_STORAGE ON CACHE BOOL "Whether or not to enable support for credential storage using libsecret.")
set(ENABLE_GTKDOC OFF CACHE BOOL "Whether or not to use generate gtkdoc.")
set(ENABLE_X11_TARGET ON CACHE BOOL "Whether to enable support for the X11 windowing target.")
set(ENABLE_WAYLAND_TARGET OFF CACHE BOOL "Whether to enable support for the Wayland windowing target.")
set(ENABLE_INTROSPECTION ON CACHE BOOL "Whether to enable GObject introspection.")
set(ENABLE_GLES2 OFF CACHE BOOL "Whether to enable OpenGL ES 2.0.")

# These are shared variables, but we special case their definition so that we can use the
# CMAKE_INSTALL_* variables that are populated by the GNUInstallDirs macro.
set(LIB_INSTALL_DIR "${CMAKE_INSTALL_FULL_LIBDIR}" CACHE PATH "Absolute path to library installation directory")
set(EXEC_INSTALL_DIR "${CMAKE_INSTALL_FULL_BINDIR}" CACHE PATH "Absolute path to executable installation directory")
#set(LIBEXEC_INSTALL_DIR "${CMAKE_INSTALL_FULL_LIBEXECDIR}/webkit2gtk-${WEBKITGTK_API_VERSION}" CACHE PATH "Absolute path to install executables executed by the library")
set(LIBEXEC_INSTALL_DIR "${CMAKE_INSTALL_FULL_LIBEXECDIR}/${BROWSER_PROJECT_NAME}" CACHE PATH "Absolute path to install executables executed by the library")

set(DATA_BUILD_DIR "${CMAKE_BINARY_DIR}/share/${WebKit_OUTPUT_NAME}")
set(DATA_INSTALL_DIR "${CMAKE_INSTALL_DATADIR}/webkitgtk-${WEBKITGTK_API_VERSION}")
set(WEBKITGTK_HEADER_INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}/webkitgtk-${WEBKITGTK_API_VERSION}")
set(INTROSPECTION_INSTALL_GIRDIR "${CMAKE_INSTALL_FULL_DATADIR}/gir-1.0")
set(INTROSPECTION_INSTALL_TYPELIBDIR "${LIB_INSTALL_DIR}/girepository-1.0")

find_package(Cairo 1.10.2 REQUIRED)
find_package(Fontconfig 2.8.0 REQUIRED)
find_package(Freetype2 2.4.2 REQUIRED)
find_package(HarfBuzz 0.9.2 REQUIRED)
find_package(ICU REQUIRED)
find_package(JPEG REQUIRED)
#find_package(LibSoup 2.42.0 REQUIRED) ZRL
find_package(LibSoup 2.43.90 REQUIRED)
find_package(LibXml2 2.8.0 REQUIRED)
find_package(LibXslt 1.1.7 REQUIRED)
find_package(PNG REQUIRED)
find_package(Sqlite REQUIRED)
find_package(Threads REQUIRED)
find_package(ZLIB REQUIRED)
find_package(ATK REQUIRED)
find_package(WebP REQUIRED)
find_package(ATSPI 2.5.3)
find_package(GObjectIntrospection)
find_package(EGL)
find_package(GeoClue2 2.1.5)
find_package(GnuTLS 3.0.0)
find_package(LibNotify)

if (NOT GEOCLUE2_FOUND)
    find_package(GeoClue)
endif ()

if (ENABLE_GLES2)
    find_package(OpenGLES2 REQUIRED)
    if (OPENGLES2_FOUND AND NOT(EGL_FOUND))
        message(FATAL_ERROR "EGL is needed for OpenGL ES 2.0.")
    endif ()
else ()
    find_package(OpenGL)
endif ()

if (ENABLE_X11_TARGET)
    # With cmake 3.2.x we have to explicitly ask for X11 otherwise the X11_X11_LIB
    # variable won't be set thus the X11 linker flags won't be added and the build
    # will fail.
    find_package(X11 REQUIRED)
    if (OPENGL_FOUND)
        # We don't use find_package for GLX because it is part of -lGL, unlike EGL.
        check_include_files("GL/glx.h" GLX_FOUND)
    endif ()
endif ()

if (ENABLE_WAYLAND_TARGET)
    find_package(Wayland REQUIRED)
endif ()

if (LIBNOTIFY_FOUND)
    add_definitions(-DWTF_USE_LIBNOTIFY=1)
else ()
    add_definitions(-DWTF_USE_LIBNOTIFY=0)
endif ()

if (ENABLE_X11_TARGET)
    add_definitions(-DWTF_PLATFORM_X11=1)
    add_definitions(-DMOZ_X11=1)
    if (WTF_OS_UNIX)
        add_definitions(-DXP_UNIX)
    endif ()
endif ()

if (ENABLE_WAYLAND_TARGET)
    add_definitions(-DWTF_PLATFORM_WAYLAND=1)
endif ()

set(ENABLE_WEBCORE ON)
set(ENABLE_WEBKIT OFF)
set(ENABLE_WEBKIT2 ON)
set(ENABLE_PLUGIN_PROCESS ON)
set(ENABLE_SMOOTH_SCROLLING ON)

set(GDK_VERSION_MIN_REQUIRED GDK_VERSION_3_6)
set(GTK_API_VERSION 3.0)

#set(WTF_USE_SOUP 1)
#modified by zhangzc
if (${OPEN_LIBSOUP})
	set(WTF_USE_SOUP 1)
	set(WTF_USE_CURL 0)
endif ()
 
if (${OPEN_LIBCURL})
	set(WTF_USE_CURL 1)
	set(WTF_USE_SOUP 0)
endif ()
#end modified
set(WTF_USE_UDIS86 1)

set(WTF_LIBRARY_TYPE STATIC)
set(WTF_OUTPUT_NAME WTFGTK)
set(JavaScriptCore_OUTPUT_NAME javascriptcoregtk-${WEBKITGTK_API_VERSION})
set(WebCore_OUTPUT_NAME WebCoreGTK)
set(WebKit_OUTPUT_NAME webkitgtk-${WEBKITGTK_API_VERSION})
set(WebKit2_OUTPUT_NAME webkit2gtk-${WEBKITGTK_API_VERSION})
set(WebKit2_WebProcess_OUTPUT_NAME WebKitWebProcess)
set(WebKit2_NetworkProcess_OUTPUT_NAME WebKitNetworkProcess)
set(WebKit2_PluginProcess_OUTPUT_NAME WebKitPluginProcess)
set(WebKit2_DatabaseProcess_OUTPUT_NAME WebKitDatabaseProcess)

add_definitions(-DBUILDING_GTK__=1)
add_definitions(-DGETTEXT_PACKAGE="WebKit2GTK-${WEBKITGTK_API_VERSION}")
add_definitions(-DDATA_DIR="${CMAKE_INSTALL_DATADIR}")
add_definitions(-DUSER_AGENT_GTK_MAJOR_VERSION=601)
add_definitions(-DUSER_AGENT_GTK_MINOR_VERSION=1)
add_definitions(-DWEBKITGTK_API_VERSION_STRING="${WEBKITGTK_API_VERSION}")

if (INSTRUMENT_SWITCH)
add_definitions(-DANDROID_INSTRUMENT)
add_definitions(-DINSTRUMENT_LAYOUT_SCHEDULING)
add_definitions(-DAPP_LEVEL_TIME)
endif ()

if (DEVELOPER_MODE)
    add_definitions(-DDEVELOPMENT_BUILD=1)
endif ()

if (ENABLE_VIDEO OR ENABLE_WEB_AUDIO)
    set(GSTREAMER_COMPONENTS app pbutils)
    add_definitions(-DWTF_USE_GSTREAMER)
    if (ENABLE_VIDEO)
        list(APPEND GSTREAMER_COMPONENTS video mpegts tag)
    endif ()

    if (ENABLE_WEB_AUDIO)
        list(APPEND GSTREAMER_COMPONENTS audio fft)
        add_definitions(-DWTF_USE_WEBAUDIO_GSTREAMER)
    endif ()

    find_package(GStreamer 1.0.3 REQUIRED COMPONENTS ${GSTREAMER_COMPONENTS})

    if (PC_GSTREAMER_MPEGTS_FOUND)
        add_definitions(-DWTF_USE_GSTREAMER_MPEGTS)
        set(USE_GSTREAMER_MPEGTS TRUE)
    endif ()
endif ()

if (ENABLE_WAYLAND_TARGET)
    set(GTK3_REQUIRED_VERSION 3.12.0)
else ()
    set(GTK3_REQUIRED_VERSION 3.6.0)
endif ()

find_package(GTK3 ${GTK3_REQUIRED_VERSION} REQUIRED)
find_package(GDK3 ${GTK3_REQUIRED_VERSION} REQUIRED)
set(GTK_LIBRARIES ${GTK3_LIBRARIES})
set(GTK_INCLUDE_DIRS ${GTK3_INCLUDE_DIRS})
set(GDK_LIBRARIES ${GDK3_LIBRARIES})
set(GDK_INCLUDE_DIRS ${GDK3_INCLUDE_DIRS})

set(glib_components gio gobject gthread gmodule)
if (ENABLE_GAMEPAD_DEPRECATED OR ENABLE_GEOLOCATION)
    list(APPEND glib_components gio-unix)
endif ()
find_package(GLIB 2.33.2 REQUIRED COMPONENTS ${glib_components})

if (ENABLE_GEOLOCATION)
    if (GEOCLUE2_FOUND)
      set(WTF_USE_GEOCLUE2 1)
    else ()
      set(WTF_USE_GEOCLUE2 0)
    endif ()
endif ()

find_package(GTKUnixPrint)
if (GTK_UNIX_PRINT_FOUND)
    set(HAVE_GTK_UNIX_PRINTING 1)
endif ()

if (ENABLE_CREDENTIAL_STORAGE)
    find_package(Libsecret)
    set(ENABLE_CREDENTIAL_STORAGE 1)
endif ()

if (GTK_SUPPORTS_GESTURES)
    add_definitions(-DHAVE_GTK_GESTURES=1)
endif ()

# This part can be simplified once CMake 2.8.6 is required and
# CMakePushCheckState can be used. We need to have OPENGL_INCLUDE_DIR as part
# of the directories check_include_files() looks for in case OpenGL is
# installed into a non-standard location.
if (ENABLE_X11_TARGET)
    set(REQUIRED_INCLUDES_OLD ${CMAKE_REQUIRED_INCLUDES})
    set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} ${OPENGL_INCLUDE_DIR})
    set(CMAKE_REQUIRED_INCLUDES ${REQUIRED_INCLUDES_OLD})

    if (GLX_FOUND)
        set(WTF_USE_GLX 1)
    endif ()
endif ()

if (EGL_FOUND)
    set(WTF_USE_EGL 1)
endif ()

if (ENABLE_SPELLCHECK)
    find_package(Enchant REQUIRED)
endif ()

if ((OPENGL_FOUND OR OPENGLES2_FOUND) AND (GLX_FOUND OR EGL_FOUND))
    set(ENABLE_TEXTURE_MAPPER 1)
    set(WTF_USE_3D_GRAPHICS 1)

    add_definitions(-DWTF_USE_3D_GRAPHICS=1)
    add_definitions(-DWTF_USE_TEXTURE_MAPPER=1)
    add_definitions(-DWTF_USE_TEXTURE_MAPPER_GL=1)
    add_definitions(-DENABLE_3D_RENDERING=1)

    if (ENABLE_X11_TARGET AND USE_REDIRECTED_XCOMPOSITE_WINDOW)
        add_definitions(-DWTF_USE_REDIRECTED_XCOMPOSITE_WINDOW=1)
    endif ()

    if (OPENGLES2_FOUND)
        set(WTF_USE_OPENGL_ES_2 1)
        add_definitions(-DWTF_USE_OPENGL_ES_2=1)
    else ()
        set(WTF_USE_OPENGL 1)
        add_definitions(-DWTF_USE_OPENGL=1)
    endif ()

    if (EGL_FOUND)
        add_definitions(-DWTF_USE_EGL=1)
    endif ()

    if (GLX_FOUND)
        add_definitions(-DWTF_USE_GLX=1)
    endif ()

    if (ENABLE_THREADED_COMPOSITOR)
        add_definitions(-DWTF_USE_TILED_BACKING_STORE=1)
        add_definitions(-DWTF_USE_COORDINATED_GRAPHICS=1)
        add_definitions(-DWTF_USE_COORDINATED_GRAPHICS_THREADED=1)
    endif ()
endif ()

if (ENABLE_GAMEPAD_DEPRECATED)
    find_package(GUdev)
endif ()

if (ENABLE_FTL_JIT)
    find_package(LLVM REQUIRED)
    set(HAVE_LLVM ON)
endif ()

set(CPACK_SOURCE_GENERATOR TBZ2)

set(FORWARDING_HEADERS_DIR ${DERIVED_SOURCES_DIR}/ForwardingHeaders)
set(FORWARDING_HEADERS_WEBKIT2GTK_DIR ${FORWARDING_HEADERS_DIR}/webkit2gtk)
set(FORWARDING_HEADERS_WEBKIT2GTK_EXTENSION_DIR ${FORWARDING_HEADERS_DIR}/webkit2gtk-webextension)

set(WebKit_PKGCONFIG_FILE ${CMAKE_BINARY_DIR}/Source/WebKit/gtk/webkitgtk-${WEBKITGTK_API_VERSION}.pc)
set(WebKit2_PKGCONFIG_FILE ${CMAKE_BINARY_DIR}/Source/WebKit2/webkit2gtk-${WEBKITGTK_API_VERSION}.pc)
set(WebKit2WebExtension_PKGCONFIG_FILE ${CMAKE_BINARY_DIR}/Source/WebKit2/webkit2gtk-web-extension-${WEBKITGTK_API_VERSION}.pc)

set(SHOULD_INSTALL_JS_SHELL OFF) # ZRL disable this.

# Add a typelib file to the list of all typelib dependencies. This makes it easy to
# expose a 'gir' target with all gobject-introspection files.
macro(ADD_TYPELIB typelib)
    if (ENABLE_INTROSPECTION)
        get_filename_component(target_name ${typelib} NAME_WE)
        add_custom_target(${target_name}-gir ALL DEPENDS ${typelib})
        list(APPEND GObjectIntrospectionTargets ${target_name}-gir)
        set(GObjectIntrospectionTargets ${GObjectIntrospectionTargets} PARENT_SCOPE)
    endif ()
endmacro()

# CMake does not automatically add --whole-archive when building shared objects from
# a list of convenience libraries. This can lead to missing symbols in the final output.
# We add --whole-archive to all libraries manually to prevent the linker from trimming
# symbols that we actually need later.
macro(ADD_WHOLE_ARCHIVE_TO_LIBRARIES _list_name)
    foreach (library IN LISTS ${_list_name})
      list(APPEND ${_list_name}_TMP -Wl,--whole-archive ${library} -Wl,--no-whole-archive)
    endforeach ()
    set(${_list_name} "${${_list_name}_TMP}")
endmacro()

if (CMAKE_MAJOR_VERSION LESS 3)
    # Before CMake 3 it was necessary to use a build script instead of using cmake --build directly
    # to preserve colors and pretty-printing.

    build_command(COMMAND_LINE_TO_BUILD)
    # build_command unconditionally adds -i (ignore errors) for make, and there's
    # no reasonable way to turn that off, so we just replace it with -k, which has
    # the same effect, except that the return code will indicate that an error occurred.
    # See: http://www.cmake.org/cmake/help/v3.0/command/build_command.html
    string(REPLACE " -i" " -k" COMMAND_LINE_TO_BUILD ${COMMAND_LINE_TO_BUILD})
    file(WRITE
        ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/build.sh
        "#!/bin/sh\n"
        "${COMMAND_LINE_TO_BUILD} $@"
    )
    file(COPY ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/build.sh
        DESTINATION ${CMAKE_BINARY_DIR}
        FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE
    )
endif ()
