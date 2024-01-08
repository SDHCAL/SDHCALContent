  /// \file SimpleRegionClusteringAlgorithm.h
/*
 *
 * SimpleRegionClusteringAlgorithm.h header template automatically generated by a class generator
 * Creation date : jeu. sept. 29 2016
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


#ifndef SIMPLEREGIONCLUSTERINGALGORITHM_H
#define SIMPLEREGIONCLUSTERINGALGORITHM_H

#include "Pandora/Algorithm.h"
#include "Pandora/PandoraInternal.h"
#include "Pandora/PandoraInputTypes.h"
#include "SDHCALApi/SDHCALInputTypes.h"

namespace sdhcal_content
{

/** 
 * @brief SimpleRegionClusteringAlgorithm class
 */ 
class SimpleRegionClusteringAlgorithm : public pandora::Algorithm
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

private:

  float             m_thetaAngle;
  float             m_phiAngle;
  float             m_distance;
};


//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::Algorithm *SimpleRegionClusteringAlgorithm::Factory::CreateAlgorithm() const
{
    return new SimpleRegionClusteringAlgorithm();
}

} 

#endif  //  SIMPLEREGIONCLUSTERINGALGORITHM_H
