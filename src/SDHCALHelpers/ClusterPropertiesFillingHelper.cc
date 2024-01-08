#include "SDHCALHelpers/ClusterPropertiesFillingHelper.h"
#include "SDHCALHelpers/ClusterHelper.h"
#include "SDHCALHelpers/ClusterPropertiesHelper.h"
#include "SDHCALObjects/CaloHit.h"

TNtuple* sdhcal_content::ClusterPropertiesFillingHelper::m_ntuple = NULL;

float sdhcal_content::ClusterPropertiesFillingHelper::m_minHitLayer          = 0.;
float sdhcal_content::ClusterPropertiesFillingHelper::m_clusterVol           = 0.;
float sdhcal_content::ClusterPropertiesFillingHelper::m_energyRatio          = 0.;
float sdhcal_content::ClusterPropertiesFillingHelper::m_hitOutsideRatio      = 0.;
float sdhcal_content::ClusterPropertiesFillingHelper::m_axisLengthRatio      = 0.;
float sdhcal_content::ClusterPropertiesFillingHelper::m_shortAxisLengthRatio = 0.;

sdhcal_content::ClusterPropertiesFillingHelper::~ClusterPropertiesFillingHelper() 
{
	if(m_ntuple != NULL ) delete m_ntuple;
}

sdhcal_content::ClusterPropertiesFillingHelper::ClusterPropertiesFillingHelper() 
{   
   m_ntuple = new TNtuple("Cluster","SDHCALCluster", 
		                  "MinHitLayer:ClusterVol:EnergyRatio:HitOutsideRatio:AxisLengthRatio:ShortAxisLengthRatio");
} 

pandora::StatusCode sdhcal_content::ClusterPropertiesFillingHelper::FillProperties(const pandora::Cluster* cluster)
{ 
	static ClusterPropertiesFillingHelper filler;

	ClusterPropertiesHelper::GetClusterProperties(cluster, m_minHitLayer, m_clusterVol, m_energyRatio, 
		                 m_hitOutsideRatio, m_axisLengthRatio, m_shortAxisLengthRatio);

	m_ntuple->Fill(m_minHitLayer, m_clusterVol, m_energyRatio, m_hitOutsideRatio, m_axisLengthRatio, m_shortAxisLengthRatio);

	//return pandora::STATUS_CODE_FAILURE;
	return pandora::STATUS_CODE_SUCCESS;
}
