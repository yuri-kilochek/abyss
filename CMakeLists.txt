cmake_minimum_required(VERSION 3.11)

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS VERSION)
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" PROJECT_VERSION)
project(abyss VERSION ${PROJECT_VERSION} LANGUAGES C)

include(GNUInstallDirs)


add_library(abyss)

set_target_properties(abyss PROPERTIES VERSION ${PROJECT_VERSION})
if("${BUILD_SHARED_LIBS}")
    set_target_properties(abyss PROPERTIES C_VISIBILITY_PRESET hidden)
    target_compile_definitions(abyss
        PRIVATE ABYSS_SHARED_EXPORT=1
        INTERFACE ABYSS_SHARED_IMPORT=1
    )
endif()

target_include_directories(abyss PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

target_sources(abyss PRIVATE
    src/lay_out.c
    src/error.c
    src/platform.c
    src/malloc_free_allocator.c
)


target_include_directories(abyss PUBLIC
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)
install(TARGETS abyss EXPORT abyss)
install(EXPORT abyss
    DESTINATION "${CMAKE_INSTALL_DATADIR}/abyss"
    NAMESPACE abyss::
    FILE abyss-config.cmake
)
export(EXPORT abyss
    NAMESPACE abyss::
    FILE abyss-config.cmake
)
