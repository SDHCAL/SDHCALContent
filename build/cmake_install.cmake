# Install script for directory: /gridgroup/ilc/pasquier/SDHCALContent

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/gridgroup/ilc/pasquier/SDHCALContent")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.36.1-a9696/x86_64-centos7/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so.01.05.01"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so.01.05"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/gridgroup/ilc/pasquier/SDHCALContent/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/gridgroup/ilc/pasquier/SDHCALContent/build/lib/libSDHCALContent.so.01.05.01"
    "/gridgroup/ilc/pasquier/SDHCALContent/build/lib/libSDHCALContent.so.01.05"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so.01.05.01"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so.01.05"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib::::::::::::::::::::::::::::::::::::::::::"
           NEW_RPATH "/gridgroup/ilc/pasquier/SDHCALContent/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.36.1-a9696/x86_64-centos7/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so"
         RPATH "/gridgroup/ilc/pasquier/SDHCALContent/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/gridgroup/ilc/pasquier/SDHCALContent/build/lib/libSDHCALContent.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so"
         OLD_RPATH "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/gridgroup/ilc/pasquier/SDHCALContent/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.36.1-a9696/x86_64-centos7/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDHCALContent.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/gridgroup/ilc/pasquier/SDHCALContent/include/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/gridgroup/ilc/pasquier/SDHCALContent/docs/ChangeLog.txt")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/gridgroup/ilc/pasquier/SDHCALContent/docs" TYPE FILE OPTIONAL FILES "/gridgroup/ilc/pasquier/SDHCALContent/ChangeLog.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "/gridgroup/ilc/pasquier/SDHCALContent/build/SDHCALContentConfig.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "/gridgroup/ilc/pasquier/SDHCALContent/build/SDHCALContentConfigVersion.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/gridgroup/ilc/pasquier/SDHCALContent/build/SDHCALContentLibDeps.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/gridgroup/ilc/pasquier/SDHCALContent/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
