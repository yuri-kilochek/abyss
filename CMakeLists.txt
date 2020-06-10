cmake_minimum_required(VERSION 3.11)

include(GNUInstallDirs)

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS VERSION)
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" PROJECT_VERSION)
project(abyss VERSION ${PROJECT_VERSION})


add_library(abyss)

set_target_properties(abyss PROPERTIES VERSION ${PROJECT_VERSION})
if("${BUILD_SHARED_LIBS}")
    set_target_properties(abyss PROPERTIES C_VISIBILITY_PRESET hidden)
    target_compile_definitions(abyss
        PRIVATE ABYSS_IMPL_BUILD_DYNAMIC=1
        INTERFACE ABYSS_IMPL_USE_DYNAMIC=1
    )
endif()

set(VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(VERSION_PATCH ${PROJECT_VERSION_PATCH})
configure_file("include/abyss/version.h.in" 
               "include/abyss/version.h")

target_include_directories(abyss PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

target_sources(abyss PRIVATE
    src/version.c
    src/error.c
    src/std_allocator.c
)


target_include_directories(abyss PUBLIC
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
              "${CMAKE_CURRENT_BINARY_DIR}/include/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    PATTERN "abyss/priv.h" EXCLUDE
    PATTERN "abyss/priv"   EXCLUDE
    PATTERN "abyss/priv/*" EXCLUDE
    PATTERN "*.in" EXCLUDE
)
install(TARGETS abyss EXPORT abyss
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)
install(EXPORT abyss
    DESTINATION "${CMAKE_INSTALL_DATADIR}/abyss"
    NAMESPACE abyss::
    FILE abyss-config.cmake
)
export(EXPORT abyss
    NAMESPACE abyss::
    FILE abyss-config.cmake
)
