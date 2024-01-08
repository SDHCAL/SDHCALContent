/// \file NearbyHitsConnectingTool.cc
/*
 *
 * NearbyHitsConnectingTool.cc source template automatically generated by a class generator
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


#include "SDHCALTools/NearbyHitsConnectingTool.h"

#include "Pandora/AlgorithmHeaders.h"

#include "SDHCALObjects/CaloHit.h"
#include "SDHCALObjects/Connector.h"
#include "SDHCALHelpers/CaloHitHelper.h"
#include "SDHCALHelpers/CaloHitRangeSearchHelper.h"
#include "SDHCALHelpers/CaloHitNeighborSearchHelper.h"
#include "SDHCALApi/SDHCALContentApi.h"

namespace sdhcal_content
{

  pandora::StatusCode NearbyHitsConnectingTool::Process(const pandora::Algorithm &algorithm, const pandora::CaloHitList *const /* pCaloHitList */)
  {
	//std::cout << " NearbyHitsConnectingTool : pCaloHitList " << pCaloHitList << ", size: " << pCaloHitList->size() << std::endl;
	
    // ordered calo hit list
    pandora::OrderedCaloHitList& orderedCaloHitList = *( CaloHitRangeSearchHelper::GetOrderedCaloHitList() );

	// seed hits
	pandora::CaloHitVector seedHits;

	// search hits which have no connector
    for(pandora::OrderedCaloHitList::const_iterator layerIter = orderedCaloHitList.begin();
			layerIter != orderedCaloHitList.end(); ++layerIter)
    {
      for(pandora::CaloHitList::const_iterator iterI = layerIter->second->begin(), endIterI = layerIter->second->end() ;
          endIterI != iterI ; ++iterI)
      {
        const sdhcal_content::CaloHit *const pCaloHitI = dynamic_cast<const sdhcal_content::CaloHit *const>(*iterI);

        if(NULL == pCaloHitI)
          continue;

        if( !SDHCALContentApi::GetConnectorList(pCaloHitI, BACKWARD_DIRECTION).empty() ||
			!SDHCALContentApi::GetConnectorList(pCaloHitI, FORWARD_DIRECTION).empty() ) 
		  continue;

        // check for availability
        if(m_connectOnlyAvailable && !PandoraContentApi::IsAvailable<pandora::CaloHit>(algorithm, pCaloHitI))
          continue;

        if(!m_shouldUseIsolatedHits && pCaloHitI->IsIsolated())
          continue;

		seedHits.push_back(pCaloHitI);
	  }
	}

	//std::cout << "# hits having no connector: " << seedHits.size() << std::endl;

	std::vector<pandora::CaloHitVector> hitsForCluster;

	if(m_metricType > 0)
	{
		//std::cout << "4D metric, eps: " << m_epsDBSCAN << ", minPoint: " << m_minpDBSCAN << std::endl;
		CaloHitNeighborSearchHelper::ClusteringByDBSCAN4D(seedHits, hitsForCluster, m_epsDBSCAN, m_minpDBSCAN);
	}
	else
	{
		//std::cout << "3D metric, eps: " << m_epsDBSCAN << ", minPoint: " << m_minpDBSCAN << std::endl;
		CaloHitNeighborSearchHelper::ClusteringByDBSCAN(seedHits, hitsForCluster, m_epsDBSCAN, m_minpDBSCAN);
	}

	for(int i = 0; i < hitsForCluster.size(); ++i)
	{
		const auto& caloHitVector = hitsForCluster.at(i);
		//std::cout << "hits for clustering: " << caloHitVector.size() << std::endl;

		if(caloHitVector.size() < 2) continue;

		// MakeConnectorsInHits(hitVector);
        CaloHitNeighborSearchHelper::BuildCaloNeighborSearch(caloHitVector);

		////////////////////////////////////////////////////////////////////////////////////
		// for test
		////////////////////////////////////////////////////////////////////////////////////
		{
            pandora::CaloHitList clusterCaloHitList;

            // create a cluster with this list
		    for(int iHit = 0; iHit < caloHitVector.size(); ++iHit)
		    {
		    	clusterCaloHitList.push_back(caloHitVector.at(iHit));
		    }

            const pandora::Cluster *pCluster = NULL;
	        object_creation::ClusterParameters clusterParameters;
            clusterParameters.m_caloHitList = clusterCaloHitList;

			// FIXME:: check if it is possible to create cluster ?
            PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, SDHCALContentApi::CreateSDHCALCluster(algorithm, clusterParameters, pCluster));

			//std::cout << "================ test hits from dbscan: " << caloHitVector.size() << std::endl;
			//std::cout << "================ create a test cluster: " << pCluster << ",  calo hit size: "
			//	<< pCluster->GetNCaloHits() << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////////

		// FIXME:: if cluster is made, hit is not available ...
		for(int iHit = 0; iHit < caloHitVector.size(); ++iHit)
		{
		    pandora::CaloHitList neighborHits;

			auto caloHit = caloHitVector.at(iHit);
            const sdhcal_content::CaloHit *const pCaloHitI = dynamic_cast<const sdhcal_content::CaloHit *const>(caloHit);
		    if(pCaloHitI == nullptr) continue;

            if(m_connectOnlyAvailable && !PandoraContentApi::IsAvailable<pandora::CaloHit>(algorithm, pCaloHitI))
              continue;

			auto caloHitPos = pCaloHitI->GetPositionVector();

		    //std::cout << "  --- calo hit: " << caloHitPos.GetX() << ", " << caloHitPos.GetY() << ", " << caloHitPos.GetZ() 
		    //	<< ", layer: " << caloHit->GetPseudoLayer() << std::endl;


		    std::vector<float> testPosition{caloHitPos.GetX(), caloHitPos.GetY(), caloHitPos.GetZ(), (float)pCaloHitI->GetPseudoLayer()};

			// get the neighbor hit
			CaloHitNeighborSearchHelper::SearchNeighbourHits4D(testPosition, 2, neighborHits);
			//std::cout << "   nb hits size: " << neighborHits.size() - 1 << std::endl;

		    auto neighborHititer = neighborHits.begin();
		    ++neighborHititer;

			auto neighborHit = *neighborHititer;

#if 0
		    auto neighborHitPos = neighborHit->GetPositionVector();

		    float distance = (neighborHitPos - caloHitPos).GetMagnitude();

		    std::cout << "    nb: " << neighborHitPos.GetX() << ", " << neighborHitPos.GetY() << ", " << neighborHitPos.GetZ() 
		    	<< ", layer: " << neighborHit->GetPseudoLayer()
		    	<< ", d = " << distance << std::endl;
#endif

            const sdhcal_content::CaloHit *const pCaloHitJ = dynamic_cast<const sdhcal_content::CaloHit *const>(neighborHit);

		    if(pCaloHitJ == nullptr) continue;
            
            //const pandora::CartesianVector &positionVectorI(pCaloHitI->GetPositionVector());
            //const pandora::CartesianVector &positionVectorJ(pCaloHitJ->GetPositionVector());
		    //const float difference = (positionVectorJ - positionVectorI).GetMagnitude();

            // check if already connected
            if(SDHCALContentApi::IsConnected(pCaloHitI, pCaloHitJ, FORWARD_DIRECTION) || 
			   SDHCALContentApi::IsConnected(pCaloHitI, pCaloHitJ, BACKWARD_DIRECTION) )
              continue;

            // check for availability
            if(m_connectOnlyAvailable && !PandoraContentApi::IsAvailable<pandora::CaloHit>(algorithm, pCaloHitJ))
              continue;

		    if(pCaloHitJ->GetPseudoLayer() == pCaloHitI->GetPseudoLayer())
		      continue;

            // connect !
            PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, SDHCALContentApi::Connect(pCaloHitI, pCaloHitJ, 
						pCaloHitI->GetPseudoLayer() < pCaloHitJ->GetPseudoLayer() ? FORWARD_DIRECTION : BACKWARD_DIRECTION));

		}
	}
	
    return pandora::STATUS_CODE_SUCCESS;
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  pandora::StatusCode NearbyHitsConnectingTool::ReadSettings(const pandora::TiXmlHandle xmlHandle)
  {
    m_metricType = 1; // > 0: 4D, = 0: 3D
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "MetricType", m_metricType));

    m_epsDBSCAN = 50.;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "EpsDBSCAN", m_epsDBSCAN));

    m_minpDBSCAN = 5;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "MinPointDBSCAN", m_minpDBSCAN));

    m_connectOnlyAvailable = true;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "ConnectOnlyAvailable", m_connectOnlyAvailable));

    m_shouldUseIsolatedHits = false;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "ShouldUseIsolatedHits", m_shouldUseIsolatedHits));

    m_maxTransverseDistanceFine = 20.f;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "MaxTransverseDistanceFine", m_maxTransverseDistanceFine));

    m_maxTransverseDistanceCoarse = 65.f;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "MaxTransverseDistanceCoarse", m_maxTransverseDistanceCoarse));

    m_shouldDiscriminateConnectedHits = false;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "ShouldDiscriminateConnectedHits", m_shouldDiscriminateConnectedHits));

    return pandora::STATUS_CODE_SUCCESS;
  }

} 

