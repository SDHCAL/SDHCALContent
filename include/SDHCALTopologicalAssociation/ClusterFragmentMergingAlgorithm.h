/*
 *
 * ClusterFragmentMergingAlgorithm.h header template automatically generated by a class generator
 * Creation date : mer. nov. 18 2015
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


#ifndef CLUSTERFRAGMENTMERGINGALGORITHM_H
#define CLUSTERFRAGMENTMERGINGALGORITHM_H

#include "Pandora/Algorithm.h"
#include "Pandora/PandoraInputTypes.h"

namespace sdhcal_content
{

/** 
 *  @brief  ClusterFragmentMergingAlgorithm class
 */ 
class ClusterFragmentMergingAlgorithm : public pandora::Algorithm
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

	/**
	 *  @brief  Whether the cluster can be merged
	 *
	 *  @param pCluster the considered cluster pointer
	 */
	bool CanMergeCluster(const pandora::Cluster *const pCluster) const;

private:
	unsigned int                m_minNCaloHits;
	unsigned int                m_maxNCaloHits;
	unsigned int                m_minNPseudoLayers;
	unsigned int                m_maxNPseudoLayers;
	float                        m_minNHitPerLayer;
	unsigned int                m_maxFirstPseudoLayerFit;
	float                        m_maxClusterDistance;
	unsigned int                m_maxFitPseudoLayer;
	float                        m_maxClusterFitAngle;
	float                        m_maxClusterFitAngle2;
	float                        m_maxEnergyChi2;
};

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::Algorithm *ClusterFragmentMergingAlgorithm::Factory::CreateAlgorithm() const
{
    return new ClusterFragmentMergingAlgorithm();
}

} 

#endif  //  CLUSTERFRAGMENTMERGINGALGORITHM_H
