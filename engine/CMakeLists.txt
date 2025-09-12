add_library(engine
    Engine.cpp
    EventBus.cpp
    SimulationMachine.cpp
)

target_include_directories(engine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${PROJECT_SOURCE_DIR}/platform
)

target_compile_features(engine PUBLIC cxx_std_17)
