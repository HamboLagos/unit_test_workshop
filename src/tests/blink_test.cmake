add_executable(
    blink_test
    ${PROJECT_SOURCE_DIR}/tests/blink_test.cpp
    ${PROJECT_SOURCE_DIR}/blink.c
)
target_link_libraries(blink_test ${GTEST_LIBRARIES})

add_test(NAME blink_test COMMAND blink_test)

