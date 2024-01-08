/*
 *
 * PerformanceMonitoringAlgorithm.cc source template automatically generated by a class generator
 * Creation date : jeu. mai 19 2016
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

#include "Pandora/AlgorithmHeaders.h"

#include "SDHCALMonitoring/PerformanceMonitoringAlgorithm.h"
#include "SDHCALHelpers/ReclusterHelper.h"
#include "SDHCALHelpers/ClusterHelper.h"
#include "SDHCALApi/SDHCALContentApi.h"

namespace sdhcal_content
{

  pandora::StatusCode PerformanceMonitoringAlgorithm::Run()
  {
    bool runVisualMonitoring(false);
    float pfoTotalEnergy(0.f);
    float pfoTotalNeutralEnergy(0.f);
    float pfoTotalChargedEnergy(0.f);
    float pfoTotalChi(0.f);

    const pandora::PfoList *pPfoList = NULL;
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::GetCurrentList(*this, pPfoList));

    if(pPfoList->empty())
      return pandora::STATUS_CODE_SUCCESS;

    for(pandora::PfoList::const_iterator pfoIter = pPfoList->begin(), pfoEndIter = pPfoList->end() ;
        pfoEndIter != pfoIter ; ++pfoIter)
    {
      const pandora::Pfo *const pPfo = *pfoIter;
      const int pdg(pPfo->GetParticleId());

      pfoTotalEnergy += pPfo->GetEnergy();

      if(pPfo->GetTrackList().empty())
      {
        pfoTotalNeutralEnergy += pPfo->GetEnergy();
      }
      else
      {
        pfoTotalChargedEnergy += pPfo->GetEnergy();

        const pandora::TrackList &trackList(pPfo->GetTrackList());
        const pandora::ClusterList &clusterList(pPfo->GetClusterList());
        float trackEnergySum(0.f);
        float clusterEnergySum(0.f);

        for(pandora::TrackList::const_iterator iter = trackList.begin(), endIter = trackList.end() ;
            endIter != iter ; ++iter)
          trackEnergySum += (*iter)->GetEnergyAtDca();

        for(pandora::ClusterList::const_iterator iter = clusterList.begin(), endIter = clusterList.end() ;
            endIter != iter ; ++iter)
        {
          // em showers
          if(pdg == pandora::PHOTON || std::abs(pdg) == pandora::E_MINUS)
          {
            const float clusterEnergy((*iter)->GetCorrectedElectromagneticEnergy(this->GetPandora()));
            clusterEnergySum += clusterEnergy;
          }
          // muon particle
          else if(std::abs(pdg) == pandora::MU_MINUS)
          {
            clusterEnergySum += trackEnergySum;
          }
          // hadronic shower
          else
          {
            const float clusterEnergy((*iter)->GetCorrectedHadronicEnergy(this->GetPandora()));
            clusterEnergySum += clusterEnergy;
          }
        }

        pfoTotalChi += ReclusterHelper::GetTrackClusterCompatibility(this->GetPandora(), clusterEnergySum, trackEnergySum);
      }
    }

    if(fabs(pfoTotalEnergy - m_expectedPfoTotalEnergy) > m_pfoTotalEnergyDeviation)
    {
      SDHCAL_LOG( "** Energy exceeded ! E = " << pfoTotalEnergy << " GeV, excepted = " << m_expectedPfoTotalEnergy << " GeV **" << std::endl );

      if(!m_visualMonitoringAlgorithmName.empty())
      {
        runVisualMonitoring = true;
      }
    }

    SDHCAL_LOG( "Total pfo energy = " << pfoTotalEnergy << " GeV" << std::endl );
    SDHCAL_LOG( "Neutral pfo energy = " << pfoTotalNeutralEnergy << " GeV" << std::endl );
    SDHCAL_LOG( "Charged pfo energy = " << pfoTotalChargedEnergy << " GeV" << std::endl );
    SDHCAL_LOG( "Total chi = " << pfoTotalChi << std::endl );

    if(runVisualMonitoring)
    {
      PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::RunDaughterAlgorithm(*this, m_visualMonitoringAlgorithmName));
    }

    return pandora::STATUS_CODE_SUCCESS;
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  pandora::StatusCode PerformanceMonitoringAlgorithm::ReadSettings(const pandora::TiXmlHandle xmlHandle)
  {
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "ExpectedPfoTotalEnergy", m_expectedPfoTotalEnergy));

    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "PfoTotalEnergyDeviation", m_pfoTotalEnergyDeviation));

    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ProcessAlgorithm(*this, xmlHandle,
        "VisualMonitoring", m_visualMonitoringAlgorithmName));

    return pandora::STATUS_CODE_SUCCESS;
  }

} 

