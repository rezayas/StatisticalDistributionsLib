cmake_minimum_required(VERSION 3.3)
project (StatisticalDistributionsLib)

# Require C++14 compilation
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define library version
set(StatisticalDistributionsLib_VERSION_MAJOR 0 CACHE STRING "major version" FORCE)
set(StatisticalDistributionsLib_VERSION_MINOR 2 CACHE STRING "minor version" FORCE)
set(StatisticalDistributionsLib_VERSION ${StatisticalDistributionsLib_VERSION_MAJOR}.${StatisticalDistributionsLib_VERSION_MINOR} CACHE STRING "version" FORCE)

# Define install destinations
set(include_dest "include/StatisticalDistributionsLib-${StatisticalDistributionsLib_VERSION}")
set(main_lib_dest "lib/StatisticalDistributionsLib-${StatisticalDistributionsLib_VERSION}")
set(lib_dest ${main_lib_dest}/${CMAKE_BUILD_TYPE})

# Define options here

# Add subdirectories
add_subdirectory(src)
# add_subdirectory(tests)

install(FILES StatisticalDistributionsLibConfig.cmake DESTINATION ${main_lib_dest})
install(EXPORT StatisticalDistributionsLib DESTINATION ${lib_dest})
