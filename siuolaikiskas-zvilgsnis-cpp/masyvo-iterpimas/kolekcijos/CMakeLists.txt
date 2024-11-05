add_executable(szcpp-kolekcijos kolekcijos.cpp
        ../../paieska-nesutvarkytame-sarase/ledai/ledai.cpp)
set_target_properties(szcpp-kolekcijos PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)