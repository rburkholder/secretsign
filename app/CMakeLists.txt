# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp
             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

add_library(
            sodium
            SHARED
            IMPORTED
            )

set(libsodium_DIR ${CMAKE_SOURCE_DIR}/src/main/cpp/libsodium)

set_target_properties(
                        sodium
                        PROPERTIES
                          IMPORTED_LOCATION ${libsodium_DIR}/lib/${ANDROID_ABI}/libsodium.so
                        )

include_directories(
                    ${libsodium_DIR}/lib/${ANDROID_ABI}/include
                   )

set(boost_DIR ${CMAKE_SOURCE_DIR}/src/main/cpp/boost)

add_library(
  date_time
  STATIC
  IMPORTED
  )

set_target_properties(
  date_time
  PROPERTIES
  IMPORTED_LOCATION ${boost_DIR}/lib/${ANDROID_ABI}/libboost_date_time.a
  )

include_directories(
  ${boost_DIR}/lib/${ANDROID_ABI}/include
  )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}

                       sodium
                       date_time
                       )