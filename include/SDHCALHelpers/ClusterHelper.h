  /// \file ClusterHelper.h
/*
 *
 * ClusterHelper.h header template automatically generated by a class generator
 * Creation date : ven. avr. 10 2015
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


#ifndef CLUSTERHELPER_H
#define CLUSTERHELPER_H

#include "Pandora/PandoraInternal.h"
#include "Pandora/PandoraInputTypes.h"
#include "SDHCALApi/SDHCALInputTypes.h"
#include "Helpers/ClusterFitHelper.h"

namespace sdhcal_content
{

/** 
 *  @brief  ClusterHelper class
 */ 
class ClusterHelper 
{
public:
	/**
	 *  @brief  Get the cluster centroid
	 *
	 *  @param  pCluster the cluster to evaluate the centroid
	 *  @param  centroid the centroid to receive
	 */
	static pandora::StatusCode GetCentroid(const pandora::Cluster *const pCluster, pandora::CartesianVector &centroid);
  
	static bool CanMergeCluster(const pandora::Pandora &pandora, const pandora::Cluster *const pCluster, const float minMipFraction, 
			const float maxAllHitsFitRms);
  
};


} 

#endif  //  CLUSTERHELPER_H
