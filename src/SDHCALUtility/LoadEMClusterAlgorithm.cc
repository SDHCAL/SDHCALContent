  /// \file LoadEMClusterAlgorithm.cc
/*
 *
 * LoadEMClusterAlgorithm.cc source template automatically generated by a class generator
 * Creation date : ven. d�c. 4 2015
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


#include "SDHCALUtility/LoadEMClusterAlgorithm.h"

#include "Pandora/AlgorithmHeaders.h"

namespace sdhcal_content
{

pandora::StatusCode LoadEMClusterAlgorithm::Run()
{
	const pandora::ClusterList *pClusterList = NULL;

	const std::string clusterListName("PandoraClusters");
    const pandora::StatusCode statusCode(PandoraContentApi::GetList(*this, clusterListName, pClusterList));

	if(pandora::STATUS_CODE_SUCCESS != statusCode) 
	{
		return statusCode;
	}

	if(pClusterList->empty())
		return pandora::STATUS_CODE_SUCCESS;

	for(pandora::ClusterList::const_iterator clusterIter = pClusterList->begin(); clusterIter != pClusterList->end() ; ++clusterIter)
	{
		std::cout << "cluster: " << (*clusterIter)->GetHadronicEnergy() << std::endl;
	}

#if 0
#endif

	return pandora::STATUS_CODE_SUCCESS;
}

//------------------------------------------------------------------------------------------------------------------------------------------

pandora::StatusCode LoadEMClusterAlgorithm::ReadSettings(const pandora::TiXmlHandle /*xmlHandle*/)
{
	return pandora::STATUS_CODE_SUCCESS;
}


} 

