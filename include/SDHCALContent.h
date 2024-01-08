/// \file SDHCALContent.h
/*
 *
 * SDHCALContent.h header template automatically generated by a class generator
 * Creation date : ven. mars 20 2015
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

#ifndef SDHCAL_CONTENT_H
#define SDHCAL_CONTENT_H 1

// multi-threading option
#ifdef SDHCAL_PARALLEL
#include <omp.h>
#endif

#include "Api/PandoraApi.h"
#include "Pandora/PandoraInternal.h"
#include "SDHCALApi/SDHCALContentApi.h"
#include "SDHCALApi/ObjectFactories.h"

#include "SDHCALCheating/CheatingTrackToClusterMatching.h"
#include "SDHCALCheating/PerfectParticleFlowAlgorithm.h"
#include "SDHCALCheating/PerfectClusteringAlgorithm.h"
#include "SDHCALCheating/PerfectClusteringAlgorithmNew.h"
#include "SDHCALCheating/PerfectHitCorrectionAlgorithm.h"
#include "SDHCALCheating/PerfectFragmentRemovalAlgorithm.h"
#include "SDHCALCheating/PerfectIsoHitRemovalAlgorithm.h"
#include "SDHCALCheating/PerfectNeutralHitRecoveryAlgorithm.h"
#include "SDHCALCheating/PerfectChargedHitRecoveryAlgorithm.h"
#include "SDHCALCheating/PerfectChargedClusterSeparationAlgorithm.h"
#include "SDHCALCheating/PerfectPfoCreationAlgorithm.h"
#include "SDHCALCheating/SimplePfoTestAlgorithm.h"
#include "SDHCALCheating/SemiPerfectPfoCreationAlgorithm.h"
#include "SDHCALCheating/CheatingClusterCleaningAlgorithm.h"
#include "SDHCALCheating/CheatingClusterMergingAlgorithm.h"
#include "SDHCALCheating/CheatingClusterMergingNewAlgorithm.h"
#include "SDHCALCheating/CheatingHitRecoveryAlgorithm.h"
#include "SDHCALCheating/CheatingParticleIDAlgorithm.h"

#include "SDHCALClustering/SDHCALClusteringAlgorithm.h"
#include "SDHCALClustering/ClusteringParentAlgorithm.h"
#include "SDHCALClustering/SimpleRegionClusteringAlgorithm.h"
#include "SDHCALClustering/IsoHitRemovalAlgorithm.h"
#include "SDHCALClustering/IsoHitClusteringAlgorithm.h"
#include "SDHCALClustering/FragmentsFromIsoHitsMergingAlgorithm.h"

#include "SDHCALHelpers/CaloHitHelper.h"
#include "SDHCALHelpers/CaloHitRangeSearchHelper.h"
#include "SDHCALHelpers/CaloHitNeighborSearchHelper.h"
#include "SDHCALHelpers/ClusterHelper.h"
#include "SDHCALHelpers/ClusterPropertiesHelper.h"
#include "SDHCALHelpers/GeometryHelper.h"
#include "SDHCALHelpers/ReclusterHelper.h"
#include "SDHCALHelpers/SortingHelper.h"
#include "SDHCALHelpers/BDTBasedClusterIdHelper.h"
#include "SDHCALHelpers/ClusterPropertiesFillingHelper.h"
#include "SDHCALHelpers/ClusterTrackEnergyFillingHelper.h"

#include "SDHCALMonitoring/VisualMonitoringAlgorithm.h"
#include "SDHCALMonitoring/PerformanceMonitoringAlgorithm.h"
#include "SDHCALMonitoring/SingleParticleMonitoringAlgorithm.h"

#include "SDHCALPfoConstruction/PfoCreationAlgorithm.h"

#include "SDHCALParticleId/FinalParticleIdAlgorithm.h"
#include "SDHCALParticleId/PhotonReconstructionAlgorithm.h"
#include "SDHCALParticleId/SingleClusterIdAlgorithm.h"

#include "SDHCALPlugins/SDHCALBFieldPlugin.h"
#include "SDHCALPlugins/SDHCALPseudoLayerPlugin.h"
#include "SDHCALPlugins/EnergyCorrectionPlugins.h"
#include "SDHCALPlugins/ParticleIdPlugins.h"
#include "SDHCALPlugins/ShowerProfilePlugin.h"

#include "SDHCALReclustering/EnergyExcessReclusteringAlgorithm.h"
#include "SDHCALReclustering/MissingEnergyReclusteringAlgorithm.h"
#include "SDHCALReclustering/SplitTrackReclusteringAlgorithm.h"
#include "SDHCALReclustering/ForceSplitTrackAssociationsAlg.h"

#include "SDHCALTools/ConnectorCleaningTool.h"
#include "SDHCALTools/ConnectorSeedingTool.h"
#include "SDHCALTools/ConnectorPlusTool.h"
#include "SDHCALTools/NearbyHitsConnectingTool.h"
#include "SDHCALTools/ConnectorAlignmentTool.h"
#include "SDHCALTools/TrackDrivenSeedingTool.h"
#include "SDHCALTools/CaloHitMergingTool.h"

#include "SDHCALTopologicalAssociation/TopologicalAssociationParentAlgorithm.h"
#include "SDHCALTopologicalAssociation/PointingClusterAssociationAlgorithm.h"
#include "SDHCALTopologicalAssociation/PointingClusterAssociationNewAlgorithm.h"
#include "SDHCALTopologicalAssociation/ClustersMergingAlgorithm.h"
#include "SDHCALTopologicalAssociation/MatchTrackWithStartingClusterAlgorithm.h"
#include "SDHCALTopologicalAssociation/ClusterFromTrackMergingAlgorithm.h"
#include "SDHCALTopologicalAssociation/ClusterFromTrackMergingAlgorithm2.h"
#include "SDHCALTopologicalAssociation/ClusterFromTrackMergingAlgorithm3.h"
#include "SDHCALTopologicalAssociation/ChargedFragmentsMergingAlgorithm.h"
#include "SDHCALTopologicalAssociation/ChargedFragmentsMergingAlgorithm2.h"
#include "SDHCALTopologicalAssociation/ChargedFragmentsMergingAlgorithm3.h"
#include "SDHCALTopologicalAssociation/ClusterFromTrackMergingAlgorithm4.h"
#include "SDHCALTopologicalAssociation/ClusterFromTrackMergingAlgorithm5.h"
#include "SDHCALTopologicalAssociation/NeutralFragmentMergingAlgorithm.h"
#include "SDHCALTopologicalAssociation/NearbyFragmentsMergingAlgorithm.h"
#include "SDHCALTopologicalAssociation/ClosebySeedMergingAlgorithm.h"
#include "SDHCALTopologicalAssociation/ClusterFragmentMergingAlgorithm.h"
#include "SDHCALTopologicalAssociation/SurroundingHitsMergingAlgorithm.h"
#include "SDHCALTopologicalAssociation/NearbyTrackPhotonRemovalAlg.h"
#include "SDHCALTopologicalAssociation/MipFragmentMergingAlg.h"
#include "SDHCALTopologicalAssociation/FragmentRemovalAlgorithm.h"
#include "SDHCALTopologicalAssociation/FragmentsFindingAlgorithm.h"
#include "SDHCALTopologicalAssociation/PhotonCleanAlgorithm.h"
#include "SDHCALTopologicalAssociation/ConeBasedMergingAlgorithm.h"
#include "SDHCALTopologicalAssociation/MainFragmentRemovalAlgorithm.h"

#include "SDHCALTrackClusterAssociation/TrackClusterAssociationMVAAlgorithm.h"
#include "SDHCALTrackClusterAssociation/UnassociatedTrackRecoveryAlg.h"
#include "SDHCALTrackClusterAssociation/TrackClusterAssociationAlgorithm.h"
#include "SDHCALTrackClusterAssociation/LoopingTrackAssociationAlgorithm.h"
#include "SDHCALTrackClusterAssociation/TrackRecoveryAlgorithm.h"
#include "SDHCALTrackClusterAssociation/TrackRecoveryHelixAlgorithm.h"
#include "SDHCALTrackClusterAssociation/TrackRecoveryInteractionsAlgorithm.h"

#include "SDHCALUtility/AlgorithmConfiguration.h"
#include "SDHCALUtility/EventPreparationAlgorithm.h"
#include "SDHCALUtility/ClusterPreparationAlgorithm.h"
#include "SDHCALUtility/TrackPreparationAlgorithm.h"
#include "SDHCALUtility/ListChangingAlgorithm.h"
#include "SDHCALUtility/ListMergingAlgorithm.h"
#include "SDHCALUtility/CaloHitPreparationAlgorithm.h"
#include "SDHCALUtility/CaloHitTimingAlgorithm.h"
#include "SDHCALUtility/ClusterCheckAlgorithm.h"
#include "SDHCALUtility/ClusterPurityAlgorithm.h"
#include "SDHCALUtility/ClusterEfficiencyAlgorithm.h"
#include "SDHCALUtility/IsolatedHitClusteringAlgorithm.h"
#include "SDHCALUtility/LoadEMClusterAlgorithm.h"
#include "SDHCALUtility/NearbyHitRecoveryAlgorithm.h"

/** 
 * @brief  SDHCALContent class used to register sdhcal algorithms and plugins
 */ 
class SDHCALContent 
{
public:

#define SDHCAL_ALGORITHM_LIST(d) \
    d("PerfectParticleFlow",                 sdhcal_content::PerfectParticleFlowAlgorithm::Factory) \
    d("PerfectClustering",                   sdhcal_content::PerfectClusteringAlgorithm::Factory) \
    d("PerfectClusteringNew",                sdhcal_content::PerfectClusteringAlgorithmNew::Factory) \
    d("PerfectHitCorrection",                sdhcal_content::PerfectHitCorrectionAlgorithm::Factory) \
    d("PerfectFragmentRemoval",              sdhcal_content::PerfectFragmentRemovalAlgorithm::Factory) \
    d("PerfectIsoHitRemoval",                sdhcal_content::PerfectIsoHitRemovalAlgorithm::Factory) \
    d("IsoHitRemoval",                       sdhcal_content::IsoHitRemovalAlgorithm::Factory) \
    d("IsoHitClustering",                    sdhcal_content::IsoHitClusteringAlgorithm::Factory) \
    d("FragmentsFromIsoHitsMerging",         sdhcal_content::FragmentsFromIsoHitsMergingAlgorithm::Factory) \
    d("PerfectNeutralHitRecovery",           sdhcal_content::PerfectNeutralHitRecoveryAlgorithm::Factory) \
    d("PerfectChargedHitRecovery",           sdhcal_content::PerfectChargedHitRecoveryAlgorithm::Factory) \
    d("PerfectChargedClusterSeparation",     sdhcal_content::PerfectChargedClusterSeparationAlgorithm::Factory) \
    d("PerfectPfoCreation",                  sdhcal_content::PerfectPfoCreationAlgorithm::Factory) \
    d("SimplePfoTest",                       sdhcal_content::SimplePfoTestAlgorithm::Factory) \
    d("SemiPerfectPfoCreation",              sdhcal_content::SemiPerfectPfoCreationAlgorithm::Factory) \
    d("CheatingTrackToClusterMatching",      sdhcal_content::CheatingTrackToClusterMatching::Factory) \
    d("SDHCALClustering",                     sdhcal_content::SDHCALClusteringAlgorithm::Factory) \
    d("CheatingClusterCleaning",             sdhcal_content::CheatingClusterCleaningAlgorithm::Factory) \
    d("CheatingClusterMerging",              sdhcal_content::CheatingClusterMergingAlgorithm::Factory) \
    d("CheatingClusterMergingNew",           sdhcal_content::CheatingClusterMergingNewAlgorithm::Factory) \
    d("CheatingHitRecovery",                 sdhcal_content::CheatingHitRecoveryAlgorithm::Factory) \
    d("CheatingParticleID",                  sdhcal_content::CheatingParticleIDAlgorithm::Factory) \
    d("ClusteringParent",                    sdhcal_content::ClusteringParentAlgorithm::Factory) \
    d("SimpleRegionClustering",              sdhcal_content::SimpleRegionClusteringAlgorithm::Factory) \
    d("VisualMonitoring",                    sdhcal_content::VisualMonitoringAlgorithm::Factory) \
    d("PerformanceMonitoring",               sdhcal_content::PerformanceMonitoringAlgorithm::Factory) \
    d("SingleParticleMonitoring",            sdhcal_content::SingleParticleMonitoringAlgorithm::Factory) \
    d("FinalParticleId",                     sdhcal_content::FinalParticleIdAlgorithm::Factory) \
    d("PhotonReconstruction",                sdhcal_content::PhotonReconstructionAlgorithm::Factory) \
    d("SingleClusterId",                     sdhcal_content::SingleClusterIdAlgorithm::Factory) \
    d("PfoCreation",                         sdhcal_content::PfoCreationAlgorithm::Factory) \
    d("EnergyExcessReclustering",            sdhcal_content::EnergyExcessReclusteringAlgorithm::Factory) \
    d("MissingEnergyReclustering",           sdhcal_content::MissingEnergyReclusteringAlgorithm::Factory) \
    d("SplitTrackReclustering",              sdhcal_content::SplitTrackReclusteringAlgorithm::Factory) \
    d("ForceSplitTrackAssociations",         sdhcal_content::ForceSplitTrackAssociationsAlg::Factory) \
    d("TopologicalAssociationParent",        sdhcal_content::TopologicalAssociationParentAlgorithm::Factory) \
    d("PointingClusterAssociation",          sdhcal_content::PointingClusterAssociationAlgorithm::Factory) \
    d("PointingClusterAssociationNew",       sdhcal_content::PointingClusterAssociationNewAlgorithm::Factory) \
    d("ClustersMerging",                     sdhcal_content::ClustersMergingAlgorithm::Factory) \
    d("MatchTrackWithStartingCluster",       sdhcal_content::MatchTrackWithStartingClusterAlgorithm::Factory) \
    d("ClusterFromTrackMerging",             sdhcal_content::ClusterFromTrackMergingAlgorithm::Factory) \
    d("ClusterFromTrackMerging2",            sdhcal_content::ClusterFromTrackMergingAlgorithm2::Factory) \
    d("ClusterFromTrackMerging3",            sdhcal_content::ClusterFromTrackMergingAlgorithm3::Factory) \
    d("ChargedFragmentsMerging",             sdhcal_content::ChargedFragmentsMergingAlgorithm::Factory) \
    d("ChargedFragmentsMerging2",            sdhcal_content::ChargedFragmentsMergingAlgorithm2::Factory) \
    d("ChargedFragmentsMerging3",            sdhcal_content::ChargedFragmentsMergingAlgorithm3::Factory) \
    d("ClusterFromTrackMerging4",            sdhcal_content::ClusterFromTrackMergingAlgorithm4::Factory) \
    d("ClusterFromTrackMerging5",            sdhcal_content::ClusterFromTrackMergingAlgorithm5::Factory) \
    d("NeutralFragmentMerging",              sdhcal_content::NeutralFragmentMergingAlgorithm::Factory) \
    d("NearbyFragmentsMerging",              sdhcal_content::NearbyFragmentsMergingAlgorithm::Factory) \
    d("ClosebySeedMerging",                  sdhcal_content::ClosebySeedMergingAlgorithm::Factory) \
    d("ClusterFragmentMerging",              sdhcal_content::ClusterFragmentMergingAlgorithm::Factory) \
    d("SurroundingHitsMerging",              sdhcal_content::SurroundingHitsMergingAlgorithm::Factory) \
    d("NearbyTrackPhotonRemoval",            sdhcal_content::NearbyTrackPhotonRemovalAlg::Factory) \
    d("MipFragmentMerging",                  sdhcal_content::MipFragmentMergingAlg::Factory) \
    d("FragmentRemoval",                     sdhcal_content::FragmentRemovalAlgorithm::Factory) \
    d("FragmentsFinding",                    sdhcal_content::FragmentsFindingAlgorithm::Factory) \
    d("PhotonClean",                         sdhcal_content::PhotonCleanAlgorithm::Factory) \
    d("ConeBasedMerging",                    sdhcal_content::ConeBasedMergingAlgorithm::Factory) \
    d("MainFragmentRemoval",                 sdhcal_content::MainFragmentRemovalAlgorithm::Factory) \
    d("TrackClusterAssociationMVA",          sdhcal_content::TrackClusterAssociationMVAAlgorithm::Factory) \
    d("UnassociatedTrackRecovery",           sdhcal_content::UnassociatedTrackRecoveryAlg::Factory) \
    d("TrackClusterAssociation",             sdhcal_content::TrackClusterAssociationAlgorithm::Factory) \
    d("LoopingTrackAssociation",             sdhcal_content::LoopingTrackAssociationAlgorithm::Factory) \
    d("TrackRecovery",                       sdhcal_content::TrackRecoveryAlgorithm::Factory) \
    d("TrackRecoveryHelix",                  sdhcal_content::TrackRecoveryHelixAlgorithm::Factory) \
    d("TrackRecoveryInteractions",           sdhcal_content::TrackRecoveryInteractionsAlgorithm::Factory) \
    d("EventPreparation",                    sdhcal_content::EventPreparationAlgorithm::Factory) \
    d("ClusterPreparation",                  sdhcal_content::ClusterPreparationAlgorithm::Factory) \
    d("TrackPreparation",                    sdhcal_content::TrackPreparationAlgorithm::Factory) \
    d("CaloHitListMerging",                  sdhcal_content::InputObjectListMergingAlgorithm<pandora::CaloHitList>::Factory) \
    d("TrackListMerging",                    sdhcal_content::InputObjectListMergingAlgorithm<pandora::TrackList>::Factory) \
    d("MCParticleListMerging",               sdhcal_content::InputObjectListMergingAlgorithm<pandora::MCParticleList>::Factory) \
    d("PfoListMerging",                      sdhcal_content::AlgorithmObjectListMergingAlgorithm<pandora::ParticleFlowObject>::Factory) \
    d("ClusterListMerging",                  sdhcal_content::AlgorithmObjectListMergingAlgorithm<pandora::Cluster>::Factory) \
    d("VertexListMerging",                   sdhcal_content::AlgorithmObjectListMergingAlgorithm<pandora::Vertex>::Factory) \
    d("ListChanging",                        sdhcal_content::ListChangingAlgorithm::Factory) \
    d("AlgorithmConfiguration",              sdhcal_content::AlgorithmConfiguration::Factory) \
    d("CaloHitPreparation",                  sdhcal_content::CaloHitPreparationAlgorithm::Factory) \
    d("CaloHitTiming",                       sdhcal_content::CaloHitTimingAlgorithm::Factory) \
    d("ClusterCheck",                        sdhcal_content::ClusterCheckAlgorithm::Factory) \
    d("ClusterPurity",                       sdhcal_content::ClusterPurityAlgorithm::Factory) \
    d("ClusterEfficiency",                   sdhcal_content::ClusterEfficiencyAlgorithm::Factory) \
    d("IsolatedHitClustering",               sdhcal_content::IsolatedHitClusteringAlgorithm::Factory) \
    d("NearbyHitRecovery",                   sdhcal_content::NearbyHitRecoveryAlgorithm::Factory) \
    d("LoadEMCluster",                       sdhcal_content::LoadEMClusterAlgorithm::Factory)


#define SDHCAL_ALGORITHM_TOOL_LIST(d) \
    d("ConnectorCleaning",                   sdhcal_content::ConnectorCleaningTool::Factory) \
    d("ConnectorSeeding",                    sdhcal_content::ConnectorSeedingTool::Factory) \
    d("ConnectorPlus",                       sdhcal_content::ConnectorPlusTool::Factory) \
    d("NearbyHitsConnecting",                sdhcal_content::NearbyHitsConnectingTool::Factory) \
    d("TrackDrivenSeeding",                  sdhcal_content::TrackDrivenSeedingTool::Factory) \
    d("ConnectorAlignment",                  sdhcal_content::ConnectorAlignmentTool::Factory) \
    d("CaloHitMerging",                      sdhcal_content::CaloHitMergingTool::Factory)

#define SDHCAL_PARTICLE_ID_LIST(d) \
    d("SDHCALEmShowerId",                     sdhcal_content::SDHCALParticleIdPlugins::SDHCALEmShowerId) \
    d("SDHCALPhotonId",                       sdhcal_content::SDHCALParticleIdPlugins::SDHCALPhotonId) \
    d("SDHCALElectronId",                     sdhcal_content::SDHCALParticleIdPlugins::SDHCALElectronId) \
    d("SDHCALMuonId",                         sdhcal_content::SDHCALParticleIdPlugins::SDHCALMuonId)


  /**
   *  @brief  Register all the sdhcal algorithms with pandora
   *
   *  @param  pandora the pandora instance with which to register content
   */
  static pandora::StatusCode RegisterAlgorithms(const pandora::Pandora &pandora);

  /**
   *  @brief  Register pseudo layer plugin with pandora
   *
   *  @param  pandora the pandora instance with which to register content
   */
  static pandora::StatusCode RegisterSDHCALPseudoLayerPlugin(const pandora::Pandora &pandora);
  static pandora::StatusCode RegisterSDHCALShowerProfilePlugin(const pandora::Pandora &pandora);

  /**
   *  @brief  Register the b field plugin (note user side configuration) with pandora
   *
   *  @param  pandora the pandora instance with which to register content
   *  @param  innerBField the bfield in the main tracker, ecal and hcal, units Tesla
   *  @param  muonBarrelBField the bfield in the muon barrel, units Tesla
   *  @param  muonEndCapBField the bfield in the muon endcap, units Tesla
   */
  static pandora::StatusCode RegisterBFieldPlugin(const pandora::Pandora &pandora, const float innerBField, const float muonBarrelBField,
      const float muonEndCapBField);

  /**
   *  @brief  Register the energy corrections with pandora
   *
   *  @param  pandora the pandora instance with which to register content
   */
  static pandora::StatusCode RegisterEnergyCorrections(const pandora::Pandora &pandora);

  /**
   *  @brief  Register sdhcal particle id functions
   *
   *  @param  pandora the pandora instance with which to register content
   */
  static pandora::StatusCode RegisterParticleIds(const pandora::Pandora &pandora);
};

//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::StatusCode SDHCALContent::RegisterAlgorithms(const pandora::Pandora &pandora)
{
  SDHCAL_ALGORITHM_LIST(PANDORA_REGISTER_ALGORITHM);
  SDHCAL_ALGORITHM_TOOL_LIST(PANDORA_REGISTER_ALGORITHM_TOOL);

  return pandora::STATUS_CODE_SUCCESS;
}

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::StatusCode SDHCALContent::RegisterSDHCALPseudoLayerPlugin(const pandora::Pandora &pandora)
{
  return PandoraApi::SetPseudoLayerPlugin(pandora, new sdhcal_content::SDHCALPseudoLayerPlugin());
}

inline pandora::StatusCode SDHCALContent::RegisterSDHCALShowerProfilePlugin(const pandora::Pandora &pandora)
{
  return PandoraApi::SetShowerProfilePlugin(pandora, new sdhcal_content::SDHCALShowerProfilePlugin());
}

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::StatusCode SDHCALContent::RegisterBFieldPlugin(const pandora::Pandora &pandora, const float innerBField,
    const float muonBarrelBField, const float muonEndCapBField)
{
  return PandoraApi::SetBFieldPlugin(pandora, new sdhcal_content::SDHCALBFieldPlugin(innerBField, muonBarrelBField, muonEndCapBField));
}

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::StatusCode SDHCALContent::RegisterEnergyCorrections(const pandora::Pandora &pandora)
{
  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "SdhcalQuadraticEnergyFunction", pandora::HADRONIC, new sdhcal_content::SdhcalQuadraticEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "SdhcalQuadraticEnergyFunction", pandora::ELECTROMAGNETIC, new sdhcal_content::SdhcalQuadraticEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "AnalogicEnergyFunction", pandora::HADRONIC, new sdhcal_content::AnalogicEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "AnalogicEnergyFunction", pandora::ELECTROMAGNETIC, new sdhcal_content::AnalogicEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "BarrelGapEnergyFunction", pandora::HADRONIC, new sdhcal_content::BarrelGapEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "ThetaEnergyFunction", pandora::HADRONIC, new sdhcal_content::ThetaEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "ThetaNHitFunction", pandora::HADRONIC, new sdhcal_content::ThetaNHitFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "PhiNHitFunction", pandora::HADRONIC, new sdhcal_content::PhiNHitFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "CleanClusters", pandora::HADRONIC, new sdhcal_content::CleanCluster()));

  return pandora::STATUS_CODE_SUCCESS;
}

//------------------------------------------------------------------------------------------------------------------------------------------

pandora::StatusCode SDHCALContent::RegisterParticleIds(const pandora::Pandora &pandora)
{
  SDHCAL_PARTICLE_ID_LIST(PANDORA_REGISTER_PARTICLE_ID);

  return pandora::STATUS_CODE_SUCCESS;
}


#endif  //  SDHCAL_CONTENT_H
