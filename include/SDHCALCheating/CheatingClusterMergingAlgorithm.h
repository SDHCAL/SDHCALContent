/**
 *  @file   SDHCALContent/include/SDHCALCheating/CheatingClusterMergingAlgorithm.h
 * 
 *  @brief  Header file for the cheating cluster cleaning algorithm class.
 * 
 *  $Log: $
 */
#ifndef SDHCAL_CHEATING_CLUSTER_MERGING_ALGORITHM_H
#define SDHCAL_CHEATING_CLUSTER_MERGING_ALGORITHM_H 1

#include "Pandora/Algorithm.h"

namespace sdhcal_content
{

/**
 *  @brief CheatingClusterMergingAlgorithm class
 */
class CheatingClusterMergingAlgorithm : public pandora::Algorithm
{
public:
    /**
     *  @brief  Factory class for instantiating algorithm
     */
    class Factory : public pandora::AlgorithmFactory
    {
    public:
        pandora::Algorithm *CreateAlgorithm() const;
    };

private:
    pandora::StatusCode Run();
    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);
};

inline pandora::Algorithm *CheatingClusterMergingAlgorithm::Factory::CreateAlgorithm() const
{
    return new CheatingClusterMergingAlgorithm();
}

} // namespace SDHCAL_content

#endif
