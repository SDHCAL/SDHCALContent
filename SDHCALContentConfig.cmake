##############################################################################
# cmake configuration file for SDHCALContent
#
# requires:
#   MacroCheckPackageLibs.cmake for checking package libraries
#
# returns following variables:
#
#   SDHCALContent_FOUND      : set to TRUE if SDHCALContent found
#       if FIND_PACKAGE called with REQUIRED and COMPONENTS arguments
#       SDHCALContent_FOUND is only set to TRUE if ALL components are also found
#       if REQUIRED is NOT set components may or may not be available
#
#   SDHCALContent_ROOT       : path to this SDHCALContent installation
#   SDHCALContent_VERSION    : package version
#   SDHCALContent_LIBRARIES  : list of SDHCALContent libraries (NOT including COMPONENTS)
#   SDHCALContent_INCLUDE_DIRS  : list of paths to be used with INCLUDE_DIRECTORIES
#   SDHCALContent_LIBRARY_DIRS  : list of paths to be used with LINK_DIRECTORIES
#   SDHCALContent_COMPONENT_LIBRARIES      : list of SDHCALContent component libraries
#   SDHCALContent_${COMPONENT}_FOUND       : set to TRUE or FALSE for each library
#   SDHCALContent_${COMPONENT}_LIBRARY     : path to individual libraries
#   SDHCALContent_${COMPONENT}_LIB_DEPENDS : individual library dependencies
#
# @author Jan Engels, Desy
##############################################################################

SET( SDHCALContent_ROOT "/gridgroup/ilc/pasquier/SDHCALContent" )
SET( SDHCALContent_VERSION "01.05.01" )


# ---------- include dirs -----------------------------------------------------
# do not store find results in cache
SET( SDHCALContent_INCLUDE_DIRS SDHCALContent_INCLUDE_DIRS-NOTFOUND )
MARK_AS_ADVANCED( SDHCALContent_INCLUDE_DIRS )

FIND_PATH( SDHCALContent_INCLUDE_DIRS
	NAMES SDHCALClustering/ClusteringParentAlgorithm.h
	PATHS ${SDHCALContent_ROOT}/include
	NO_DEFAULT_PATH
)



# ---------- libraries --------------------------------------------------------
INCLUDE( "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/cmakemodules/MacroCheckPackageLibs.cmake" )

# only standard libraries should be passed as arguments to CHECK_PACKAGE_LIBS
# additional components are set by cmake in variable PKG_FIND_COMPONENTS
# first argument should be the package name
CHECK_PACKAGE_LIBS( SDHCALContent SDHCALContent )




# ---------- libraries dependencies -------------------------------------------
# this sets SDHCALContent_${COMPONENT}_LIB_DEPENDS variables
INCLUDE( "${SDHCALContent_ROOT}/lib/cmake/SDHCALContentLibDeps.cmake" )
 



# ---------- final checking ---------------------------------------------------
INCLUDE( FindPackageHandleStandardArgs )
# set SDHCALContent_FOUND to TRUE if all listed variables are TRUE and not empty
# SDHCALContent_COMPONENT_VARIABLES will be set if FIND_PACKAGE is called with REQUIRED argument
FIND_PACKAGE_HANDLE_STANDARD_ARGS( SDHCALContent DEFAULT_MSG SDHCALContent_ROOT SDHCALContent_INCLUDE_DIRS SDHCALContent_LIBRARIES ${SDHCALContent_COMPONENT_VARIABLES} )

SET( SDHCALContent_FOUND ${SDHCALContent_FOUND} )

