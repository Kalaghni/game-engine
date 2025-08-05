add_library(platform
    PlatformStub.cpp
)

target_include_directories(platform
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(platform PUBLIC cxx_std_17)
