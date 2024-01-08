/**
 *  @file   SDHCALContent/include/SDHCALCheating/CheatingClusterCleaningAlgorithm.h
 * 
 *  @brief  Header file for the cheating cluster cleaning algorithm class.
 * 
 *  $Log: $
 */
#ifndef SDHCAL_CHEATING_CLUSTER_CLEANING_ALGORITHM_H
#define SDHCAL_CHEATING_CLUSTER_CLEANING_ALGORITHM_H 1

#include "Pandora/Algorithm.h"

namespace sdhcal_content
{

/**
 *  @brief CheatingClusterCleaningAlgorithm class
 */
class CheatingClusterCleaningAlgorithm : public pandora::Algorithm
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

    bool m_isOnlyCleanPhoton;
};

inline pandora::Algorithm *CheatingClusterCleaningAlgorithm::Factory::CreateAlgorithm() const
{
    return new CheatingClusterCleaningAlgorithm();
}

} // namespace SDHCAL_content

#endif // #ifndef SDHCAL_CHEATING_CLUSTER_CLEANING_ALGORITHM_H
