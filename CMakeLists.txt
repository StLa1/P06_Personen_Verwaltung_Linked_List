cmake_minimum_required(VERSION 3.28.0)
project(P06_Personen_Verwaltung_Linked_List VERSION 0.1.0 LANGUAGES C)


set(MAIN_SOURCES)
file(GLOB_RECURSE MAIN_SOURCES "src/*.c")


set(HEADERS)
file(GLOB_RECURSE HEADERS "include/*.h")
set(RECURSIVE_HEADER_DIRS "")
foreach(_headerFile ${HEADERS})
get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND RECURSIVE_HEADER_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES RECURSIVE_HEADER_DIRS)

include_directories(${RECURSIVE_HEADER_DIRS})
add_executable(P06_Personen_Verwaltung_Linked_List ${MAIN_SOURCES} ${HEADERS})

# include(CTest)
# enable_testing()

# set(TEST_SOURCES)
# file(GLOB_RECURSE TEST_SOURCES "tests/*.c")

# set(TEST_HEADERS)
# file(GLOB_RECURSE TEST_HEADERS "tests/*.h")
# set(RECURSIVE_TEST_HEADER_DIRS "")
# foreach(_headerFile ${TEST_HEADERS})
#     get_filename_component(_dir ${_headerFile} PATH)
#     list(APPEND RECURSIVE_TEST_HEADER_DIRS ${_dir})
# endforeach()
# list(REMOVE_DUPLICATES RECURSIVE_TEST_HEADER_DIRS)

# include_directories(${RECURSIVE_TEST_HEADER_DIRS})
# add_executable(tests ${TEST_SOURCES} ${TEST_HEADERS} ${HEADERS})
# add_test(NAME ${PROJECT_NAME}_tests COMMAND tests)
# set_target_properties(tests PROPERTIES LINKER_LANGUAGE C)
# target_link_options(tests PRIVATE -Wl,-subsystem,console)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)