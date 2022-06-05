cmake_minimum_required(VERSION 3.20)
project (BlackOS)
include_directories(Include)

################################################################################
# CORE
################################################################################
file(GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS "Include/BOS/Core/*.hpp")
file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "Source/BOS/Core/*.cpp")

add_library(Core ${CORE_HEADERS} ${CORE_SOURCES})


option(BUILD_CORE_TESTS "Build the unit and integration tests." ON)

if(BUILD_CORE_TESTS)
  add_subdirectory(Tests/Core)
endif()

################################################################################
# KERNEL
################################################################################
file(GLOB_RECURSE KERNEL_HEADERS CONFIGURE_DEPENDS "Include/BOS/Kernel/*.hpp")
file(GLOB_RECURSE KERNEL_SOURCES CONFIGURE_DEPENDS "Source/BOS/Kernel/*.cpp"
  "Source/BOS/Kernel/*.s")

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(BUILD_KERNEL_DEFAULT ON)
else()
  set(BUILD_KERNEL_DEFAULT OFF)
endif()

option(BUILD_KERNEL "Compile the kernel." ${BUILD_KERNEL_DEFAULT})

if(BUILD_KERNEL)
  set(KERNEL_LINK_SCRIPT "${CMAKE_SOURCE_DIR}/Linker/Kernel.ld")

  add_executable(Kernel ${KERNEL_SOURCES})

  # Make sure cmake rebuilds if the configuration script changes.
  set_target_properties(Kernel PROPERTIES LINK_DEPENDS ${KERNEL_LINK_SCRIPT})
  target_link_options(Kernel PRIVATE -T ${KERNEL_LINK_SCRIPT})
endif()

