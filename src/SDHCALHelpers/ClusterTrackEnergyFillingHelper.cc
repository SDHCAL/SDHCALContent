#include "SDHCALHelpers/ClusterTrackEnergyFillingHelper.h"
//#include "SDHCALHelpers/ClusterHelper.h"
//#include "SDHCALHelpers/ClusterPropertiesHelper.h"
//#include "SDHCALObjects/CaloHit.h"

TNtuple* sdhcal_content::ClusterTrackEnergyFillingHelper::m_ntuple = NULL;

float sdhcal_content::ClusterTrackEnergyFillingHelper::m_cluster = 0.;
float sdhcal_content::ClusterTrackEnergyFillingHelper::m_track   = 0.;

sdhcal_content::ClusterTrackEnergyFillingHelper::~ClusterTrackEnergyFillingHelper() 
{
	if(m_ntuple != NULL ) delete m_ntuple;
}

sdhcal_content::ClusterTrackEnergyFillingHelper::ClusterTrackEnergyFillingHelper() 
{   
   m_ntuple = new TNtuple("ClusterTrackEnergy","ClusterTrackEnergy", "cluster:track");
} 

pandora::StatusCode sdhcal_content::ClusterTrackEnergyFillingHelper::FillEnergy(float cluster, float track)
{ 
	static ClusterTrackEnergyFillingHelper filler;

	m_ntuple->Fill(cluster, track);

	//return pandora::STATUS_CODE_FAILURE;
	return pandora::STATUS_CODE_SUCCESS;
}
