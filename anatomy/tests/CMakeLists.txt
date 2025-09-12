add_executable(anatomy_tests
  core_ids_tests.cpp
  graph_innervation_tests.cpp
)

target_link_libraries(anatomy_tests PRIVATE GTest::gtest_main anatomy)

include(GoogleTest)
gtest_discover_tests(anatomy_tests)
