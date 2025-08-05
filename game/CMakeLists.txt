add_executable(titan_game
    main.cpp
)

target_link_libraries(titan_game
    PRIVATE engine platform
)

target_compile_features(titan_game PUBLIC cxx_std_17)
