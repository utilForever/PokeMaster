# Target name
set(target PokeMaster)

# Define
set(root_dir ${CMAKE_CURRENT_SOURCE_DIR}/../..)

# Includes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Sources
file(GLOB header_dir
    ${root_dir}/Includes)

file(GLOB_RECURSE headers
    ${header_dir}/*.hpp)

file(GLOB_RECURSE sources
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Custom-build event
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(poke_master_header_gen_py ${root_dir}/Scripts/header_gen.py)
    add_custom_command(
        COMMAND python ${poke_master_header_gen_py}
        DEPENDS ${headers}
        OUTPUT ${root_dir}/Includes/PokeMaster.hpp
    )
    add_custom_target(poke_master_header_gen_py ALL
        DEPENDS ${root_dir}/Includes/PokeMaster.hpp)
else ()
    set(poke_master_header_gen_py ${root_dir}/Scripts/header_gen.py)
    add_custom_command(
        COMMAND python3 ${poke_master_header_gen_py}
        DEPENDS ${headers}
        OUTPUT ${root_dir}/Includes/PokeMaster.hpp
    )
    add_custom_target(poke_master_header_gen_py ALL
        DEPENDS ${root_dir}/Includes/PokeMaster.hpp)
endif ()

# Build library
add_library(${target}
    ${sources})
add_dependencies(${target} poke_master_header_gen_py)

# Project options
set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
)

# Compile options
target_compile_options(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_COMPILE_OPTIONS}

    INTERFACE
)

target_compile_definitions(${target}
    PRIVATE
    RESOURCES_DIR="${POKEMASTER_ROOT}/Resources/"
)

target_link_libraries(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_LINKER_OPTIONS}
	${DEFAULT_LIBRARIES}

    INTERFACE
)

# Install
install(TARGETS ${target} DESTINATION lib)
install(DIRECTORY ${header_dir} DESTINATION include) 