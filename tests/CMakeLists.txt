add_executable(titan_tests
    EngineTests.cpp
    ECSTests.cpp
    ${PROJECT_SOURCE_DIR}/third_party/catch_amalgamated.cpp
)

# Include engine headers and third_party for Catch2
target_include_directories(titan_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/engine
        ${PROJECT_SOURCE_DIR}/platform
        ${PROJECT_SOURCE_DIR}/third_party
)

target_link_libraries(titan_tests PRIVATE engine)

add_test(NAME titan_tests COMMAND titan_tests)
