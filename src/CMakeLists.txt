# Set headers
set(header_path "${StatisticalDistributionsLib_SOURCE_DIR}/include/StatisticalDistributionsLib")
set(header ${header_path}/Bernoulli.h
           ${header_path}/Beta.h
           ${header_path}/BetaBinomial.h
           ${header_path}/ChiSquared.h
           ${header_path}/Empirical.h
           ${header_path}/Exponential.h
           ${header_path}/Gamma.h
           ${header_path}/GammaPoisson.h
           ${header_path}/Geometric.h
           ${header_path}/JohnsonSb.h
           ${header_path}/JohnsonSl.h
           ${header_path}/JohnsonSu.h
           ${header_path}/Lognormal.h
           ${header_path}/NegBinomial.h
           ${header_path}/Normal.h
           ${header_path}/Poisson.h
           ${header_path}/RNG.h
           ${header_path}/Triangular.h
           ${header_path}/Uniform.h
           ${header_path}/UniformDiscrete.h
           ${header_path}/Weibull.h)

# Require C++14 compilation
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set source files; not sure what to do with non-cpp files
set(src Bernoulli.cpp
        Beta.cpp
        BetaBinomial.cpp
        ChiSquared.cpp
        Empirical.cpp
        Exponential.cpp
        Gamma.cpp
        GammaPoisson.cpp
        Geometric.cpp
        JohnsonSb.cpp
        JohnsonSl.cpp
        JohnsonSu.cpp
        Lognormal.cpp
        NegBinomial.cpp
        Normal.cpp
        Poisson.cpp
        Triangular.cpp
        Uniform.cpp
        UniformDiscrete.cpp
        Weibull.cpp)

# Configure config.hpp.in
# configure_file("config.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp")

# Define library target
add_library(StatisticalDistributionsLib ${header} ${src})

target_include_directories(StatisticalDistributionsLib PUBLIC
  $<BUILD_INTERFACE:${StatisticalDistributionsLib_SOURCE_DIR}/include> # for headers when building
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for config_impl.hpp when building
  $<INSTALL_INTERFACE:${include_dest}> # for client in install mode
  $<INSTALL_INTERFACE:${lib_dest}>) # for config_impl.hpp in install mode

install(TARGETS StatisticalDistributionsLib EXPORT StatisticalDistributionsLib DESTINATION "${lib_dest}")
install(FILES ${header} DESTINATION "${include_dest}")
# install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp DESTINATION "${include_dest}")
