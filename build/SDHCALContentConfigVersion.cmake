##############################################################################
# this file is parsed when FIND_PACKAGE is called with version argument
#
# @author Jan Engels, Desy IT
##############################################################################


SET( ${PACKAGE_FIND_NAME}_VERSION_MAJOR 01 )
SET( ${PACKAGE_FIND_NAME}_VERSION_MINOR 05 )
SET( ${PACKAGE_FIND_NAME}_VERSION_PATCH 01 )


INCLUDE( "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/cmakemodules/MacroCheckPackageVersion.cmake" )
CHECK_PACKAGE_VERSION( ${PACKAGE_FIND_NAME} 01.05.01 )

