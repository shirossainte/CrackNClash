# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CrackNClash_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CrackNClash_autogen.dir\\ParseCache.txt"
  "CrackNClash_autogen"
  )
endif()
