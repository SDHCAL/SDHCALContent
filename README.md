# SDHCALContent
Plugins and tools for SDHCAL

To use it :

1. Make sure that you have mlpack, Armadillo and Boost installed
2. Clone the repository
3. cd SDHCALContent; mkdir build; cd build
4. cmake -C ${ILCSOFT}/ILCSoft.cmake -DPANDORA_MONITORING=ON .. -Dmlpack_DIR=${mlpack_DIR} -DBoost_INCLUDE_DIR=${boost_include} -DARMADILLO_INCLUDE_DIR=${armadillo_include}
5. make install

