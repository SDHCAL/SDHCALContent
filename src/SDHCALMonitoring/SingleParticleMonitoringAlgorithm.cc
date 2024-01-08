/// \file SingleParticleMonitoringAlgorithm.cc
/*
 *
 * SingleParticleMonitoringAlgorithm.cc source template automatically generated by a class generator
 * Creation date : jeu. oct. 6 2016
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


#include "SDHCALMonitoring/SingleParticleMonitoringAlgorithm.h"

#include "Pandora/AlgorithmHeaders.h"

#include "SDHCALHelpers/SortingHelper.h"
#include "SDHCALHelpers/CaloHitHelper.h"
#include "SDHCALHelpers/ReclusterHelper.h"
#include "SDHCALHelpers/ClusterHelper.h"

namespace sdhcal_content {

  SingleParticleMonitoringAlgorithm::~SingleParticleMonitoringAlgorithm()
  {
    PANDORA_MONITORING_API(SaveTree(this->GetPandora(), m_treeName, m_fileName, "RECREATE"));
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  pandora::StatusCode SingleParticleMonitoringAlgorithm::Run()
  {
#ifdef MONITORING
    // Extract the mc particle - this algorithm is intended to work only with single particle samples
    const pandora::MCParticleList *pMCParticleList = NULL;
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::GetCurrentList(*this, pMCParticleList));

    if (1 != pMCParticleList->size())
    {
      std::cout << "SingleParticleMonitoringAlgorithm - Algorithm works only with single particle samples, nParticles " << pMCParticleList->size() << std::endl;
      return pandora::STATUS_CODE_SUCCESS;
    }

    const pandora::MCParticle *const pMCParticle(*(pMCParticleList->begin()));

    // Extract the mc particle properties
    const float mcEnergy(pMCParticle->GetEnergy());
    const int mcPDGCode(pMCParticle->GetParticleId());

    const pandora::PfoList *pPfoList = NULL;
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::GetCurrentList(*this, pPfoList));

    std::vector<float> hitPositionX, hitPositionY, hitPositionZ;
    std::vector<float> hitExpectedDirX, hitExpectedDirY, hitExpectedDirZ;
    std::vector<float> hitCellNormaleX, hitCellNormaleY, hitCellNormaleZ;
    std::vector<float> hitCellSize0, hitCellSize1, hitCellThickness;
    std::vector<float> hitInputEnergy, hitEmEnergy, hitHadEnergy;
    std::vector<float> hitTime;
    std::vector<int>   hitType, hitRegion, hitGranularity;
    std::vector<int>   hitLayer, hitPseudoLayer;
    std::vector<int>   hitIsolated, hitNearGap;
    float              clusterFitDirX(0.f), clusterFitDirY(0.f), clusterFitDirZ(0.f);

    for (pandora::PfoList::const_iterator pfoIter = pPfoList->begin(); pfoIter != pPfoList->end(); ++pfoIter)
    {
      const pandora::ParticleFlowObject *const pPfo = *pfoIter;
      const pandora::ClusterList &clusterList(pPfo->GetClusterList());

      for (pandora::ClusterList::const_iterator clusterIter = clusterList.begin(); clusterIter != clusterList.end(); ++clusterIter)
      {
        const pandora::Cluster *const pCluster = *clusterIter;

        clusterFitDirX = pCluster->GetFitToAllHitsResult().GetDirection().GetX();
        clusterFitDirY = pCluster->GetFitToAllHitsResult().GetDirection().GetY();
        clusterFitDirZ = pCluster->GetFitToAllHitsResult().GetDirection().GetZ();

        pandora::CaloHitList clusterCaloHitList;
        pCluster->GetOrderedCaloHitList().FillCaloHitList(clusterCaloHitList);
        pandora::CaloHitList nearbyGapCaloHitList;

        ClusterHelper::GetCaloHitsNearDetectorGaps(this->GetPandora(), pCluster, m_gapDistanceFine,
            m_gapDistanceCoarse, nearbyGapCaloHitList, m_shouldUseIsolatedGapHits);

        for(pandora::CaloHitList::const_iterator hitIter = clusterCaloHitList.begin(), hitEndIter = clusterCaloHitList.end() ;
            hitEndIter != hitIter ; ++hitIter)
        {
          const pandora::CaloHit *const pCaloHit(*hitIter);

          hitPositionX.push_back(pCaloHit->GetPositionVector().GetX());
          hitPositionY.push_back(pCaloHit->GetPositionVector().GetY());
          hitPositionZ.push_back(pCaloHit->GetPositionVector().GetZ());

          hitExpectedDirX.push_back(pCaloHit->GetExpectedDirection().GetX());
          hitExpectedDirY.push_back(pCaloHit->GetExpectedDirection().GetY());
          hitExpectedDirZ.push_back(pCaloHit->GetExpectedDirection().GetZ());

          hitCellNormaleX.push_back(pCaloHit->GetCellNormalVector().GetX());
          hitCellNormaleY.push_back(pCaloHit->GetCellNormalVector().GetY());
          hitCellNormaleZ.push_back(pCaloHit->GetCellNormalVector().GetZ());

          hitCellSize0.push_back(pCaloHit->GetCellSize0());
          hitCellSize1.push_back(pCaloHit->GetCellSize1());
          hitCellThickness.push_back(pCaloHit->GetCellThickness());

          hitInputEnergy.push_back(pCaloHit->GetInputEnergy());
          hitEmEnergy.push_back(pCaloHit->GetElectromagneticEnergy());
          hitHadEnergy.push_back(pCaloHit->GetHadronicEnergy());

          hitTime.push_back(pCaloHit->GetTime());

          hitType.push_back(static_cast<int>(pCaloHit->GetHitType()));
          hitRegion.push_back(static_cast<int>(pCaloHit->GetHitRegion()));
          hitGranularity.push_back(PandoraContentApi::GetGeometry(*this)->GetHitTypeGranularity(pCaloHit->GetHitType()));

          hitLayer.push_back(pCaloHit->GetLayer());
          hitPseudoLayer.push_back(pCaloHit->GetPseudoLayer());

          hitIsolated.push_back(static_cast<int>(pCaloHit->IsIsolated()));

          bool nearGap(std::find(nearbyGapCaloHitList.begin(), nearbyGapCaloHitList.end(), pCaloHit) != nearbyGapCaloHitList.end());
          hitNearGap.push_back(static_cast<int>(nearGap));
        }
      }
    }

    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "mcEnergy",            mcEnergy));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "pdg",                 mcPDGCode));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "x",                  &hitPositionX));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "y",                  &hitPositionY));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "z",                  &hitPositionZ));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "xExpect",            &hitExpectedDirX));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "yExpect",            &hitExpectedDirY));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "zExpect",            &hitExpectedDirZ));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "xCell",              &hitCellNormaleX));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "yCell",              &hitCellNormaleY));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "zCell",              &hitCellNormaleZ));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "cell0",              &hitCellSize0));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "cell1",              &hitCellSize1));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "cellThick",          &hitCellThickness));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "Ein",                &hitInputEnergy));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "Eem",                &hitEmEnergy));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "Ehad",               &hitHadEnergy));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "time",               &hitTime));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "type",               &hitType));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "region",             &hitRegion));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "layer",              &hitLayer));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "pseudoLayer",        &hitPseudoLayer));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "isolated",           &hitIsolated));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "gap",                &hitNearGap));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "clusterFitX",         clusterFitDirX));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "clusterFitY",         clusterFitDirY));
    PANDORA_MONITORING_API(SetTreeVariable(this->GetPandora(), m_treeName, "clusterFitZ",         clusterFitDirZ));
    PANDORA_MONITORING_API(FillTree(this->GetPandora(), m_treeName));

#endif
    return pandora::STATUS_CODE_SUCCESS;
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  pandora::StatusCode SingleParticleMonitoringAlgorithm::ReadSettings(const pandora::TiXmlHandle xmlHandle)
  {
    m_treeName = "SingleParticleTree";
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "TreeName", m_treeName));

    m_fileName = "SDHCALPFASingleParticle.root";
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "FileName", m_fileName));

    m_gapDistanceFine = 10.f;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "GapDistanceFine", m_gapDistanceFine));

    m_gapDistanceCoarse = 20.f;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "GapDistanceCoarse", m_gapDistanceCoarse));

    m_shouldUseIsolatedGapHits = false;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "ShouldUseIsolatedGapHits", m_shouldUseIsolatedGapHits));

    return pandora::STATUS_CODE_SUCCESS;
  }
} 

