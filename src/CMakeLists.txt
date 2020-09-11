set(CMAKE_CXX_STANDARD 14 CACHE STRING "")

if(NOT LLVM_ENABLE_RTTI)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

add_library(FeatureExtractor SHARED Pass.cpp)

target_link_libraries(FeatureExtractor
    "$<$<PLATFORM_ID:Darwin>:-undefined dynamic_lookup>")

