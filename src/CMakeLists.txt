# Build the game executable
set(EXECUTABLE_NAME "square_interview")

add_executable(
    ${EXECUTABLE_NAME}
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    # ${PROJECT_SOURCE_DIR}/src/other_sources.cpp
)
