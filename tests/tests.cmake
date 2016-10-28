set(TEST_NAME "tests")

add_executable(
    ${TEST_NAME}
    ${TEST_NAME}.cpp
    # ${CMAKE_SOURCE_DIR}/src/other_sources.cpp
)
target_link_libraries(${TEST_NAME} ${GTEST_LIBRARIES})

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
