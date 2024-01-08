  /// \file SplitTrackReclusteringAlgorithm.h
/*
 *
 * SplitTrackReclusteringAlgorithm.h header template automatically generated by a class generator
 * Creation date : mar. d�c. 8 2015
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


#ifndef SPLITTRACKRECLUSTERINGALGORITHM_H
#define SPLITTRACKRECLUSTERINGALGORITHM_H

#include "Pandora/Algorithm.h"
#include "Pandora/PandoraInternal.h"

namespace sdhcal_content
{

/** 
 *  @brief  SplitTrackReclusteringAlgorithm class
 */ 
class SplitTrackReclusteringAlgorithm : public pandora::Algorithm
{
public:
    typedef std::map<const pandora::Track *, const pandora::Cluster *> TrackToClusterMap;
    typedef std::map<const pandora::Track *, const pandora::Helix> TrackToHelixMap;
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

private:
	unsigned int                    m_minNTrackAssociation;
};

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::Algorithm *SplitTrackReclusteringAlgorithm::Factory::CreateAlgorithm() const
{
    return new SplitTrackReclusteringAlgorithm();
}

} 

#endif  //  SPLITTRACKRECLUSTERINGALGORITHM_H
