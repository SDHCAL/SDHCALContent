  /// \file NeutralFragmentMergingAlgorithm.h
/*
 *
 * NeutralFragmentMergingAlgorithm.h header template automatically generated by a class generator
 * Creation date : jeu. avr. 9 2015
 *
 * This file is part of SDHCALContent libraries.
 * 
 * SDHCALContent is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * SDHCALContent is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with SDHCALContent.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#ifndef NEUTRALFRAGMENTMERGINGALGORITHM_H
#define NEUTRALFRAGMENTMERGINGALGORITHM_H

#include "Pandora/Algorithm.h"
#include "Pandora/PandoraInputTypes.h"
#include "SDHCALApi/SDHCALInputTypes.h"

#include "SDHCALHelpers/CaloHitRangeSearchHelper.h"
#include "SDHCALHelpers/CaloHitNeighborSearchHelper.h"

namespace pandora { class ClusterFitResult; }

namespace sdhcal_content
{

/** 
 * @brief NeutralFragmentMergingAlgorithm class
 */ 
class NeutralFragmentMergingAlgorithm : public pandora::Algorithm
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
  
    sdhcal_content::SDHCALCluster* GetMainCluster(const pandora::CaloHitVector& caloHitVector);
  
    void GetNearbyClusters(pandora::Cluster* cluster, const std::vector<sdhcal_content::SDHCALCluster*>& clusterVector, 
			std::vector<sdhcal_content::SDHCALCluster*>& clustersInRange);

    void SearchProperClusters(const pandora::Track* pTrack, SDHCALCluster* startingCluster);
		  

    pandora::StatusCode CleanClusterForMerging(std::vector<SDHCALCluster*>& clusterVector);

	/**
	 *  @brief  Get the eligible clusters for parent-daughter association
	 *
	 *  @param  clusterVector the cluster vector to receive
	 */
	pandora::StatusCode GetEligibleClusters(std::vector<SDHCALCluster*>& clusterVector) const;

private:
	float m_maxStartingClusterDistance;
	bool m_cleanClusterConnection;

	arma::mat m_clusterCentroidsMatrix;
	std::vector<SDHCALCluster*> m_clustersToMerge;
};

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::Algorithm *NeutralFragmentMergingAlgorithm::Factory::CreateAlgorithm() const
{
    return new NeutralFragmentMergingAlgorithm();
}

} 

#endif
