  /// \file ConnectorAlignmentTool.h
/*
 *
 * ConnectorAlignmentTool.h header template automatically generated by a class generator
 * Creation date : lun. juin 27 2016
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


#ifndef CONNECTORALIGNMENTTOOL_H
#define CONNECTORALIGNMENTTOOL_H

#include "SDHCALTools/ConnectorAlgorithmTool.h"
#include "SDHCALApi/SDHCALInputTypes.h"

namespace sdhcal_content
{

/** 
 * @brief ConnectorAlignmentTool class
 */ 
class ConnectorAlignmentTool : public ConnectorAlgorithmTool
{
public:
    /**
     *  @brief  Factory class for instantiating algorithm tool
     */
    class Factory : public pandora::AlgorithmToolFactory
    {
    public:
        pandora::AlgorithmTool *CreateAlgorithmTool() const;
    };

	/**
	 *  @brief  Seed connectors from the calo hit list
	 *
	 *  @param  algorithm the parent algorithm to access pandora content
	 *  @param  pCaloHitList the calo hit list to process
	 */
	pandora::StatusCode Process(const pandora::Algorithm &algorithm, const pandora::CaloHitList *const pCaloHitList = nullptr);

	/**
	 *  @brief  Read settings from the xml handle
	 *
	 *  @param  xmlHandle the xml handle to settings
	 */
	pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

private:
	/**
	 *  @brief  Get the ordered calo hit list. Filter on availability in specified
	 *
	 *  @param  pCaloHitList the input calo hit list
	 *  @param  orderedCaloHitList the ordered calo hit list to receive
	 */
	pandora::StatusCode GetOrderedCaloHitList(const pandora::Algorithm &algorithm, const pandora::CaloHitList *const pCaloHitList, pandora::OrderedCaloHitList &orderedCaloHitList) const;

	/**
	 *  @brief  Get the connector list to align
	 *
	 *  @param  orderedCaloHitList the input ordered calo hit list
	 *  @param  connectorList the connector list to receive
	 */
	pandora::StatusCode GetConnectorList(const pandora::OrderedCaloHitList &orderedCaloHitList, ConnectorList &connectorList) const;

	/**
	 *  @brief  Create new connection in the forward direction of the target connector
	 *
	 *  @param  orderedCaloHitList the input ordered calo hit list
	 *  @param  pConnector the target connector
	 */
	pandora::StatusCode ConnectBackward(const pandora::OrderedCaloHitList &orderedCaloHitList, const Connector *const pConnector) const;

	/**
	 *  @brief  Create new connection in the backward direction of the target connector
	 *
	 *  @param  orderedCaloHitList the input ordered calo hit list
	 *  @param  pConnector the target connector
	 */
	pandora::StatusCode ConnectForward(const pandora::OrderedCaloHitList &orderedCaloHitList, const Connector *const pConnector) const;

private:
	bool                               m_connectOnlyAvailable;            ///< Whether to connect only available hits
	bool                               m_shouldUseIsolatedHits;           ///< Whether to use isolated hits
	bool                               m_shouldConnectOnlySameHitType;    ///< Whether to connect only hits with same type
	unsigned int                       m_maxPseudoLayerConnection;        ///< The maximum pseudo layer for a suitable connection
	float                              m_maxConnectionAngleFine;          ///< The maximum angle (fine granularity) for a suitable connection
	float                              m_maxConnectionAngleCoarse;        ///< The maximum angle (coarse granularity) for a suitable connection
	float                              m_maxConnectionDistanceFine;       ///< The maximum distance between hits (fine granularity) for a suitable connection
	float                              m_maxConnectionDistanceCoarse;     ///< The maximum distance between hits (coarse granularity) for a suitable connection
}; 

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::AlgorithmTool *ConnectorAlignmentTool::Factory::CreateAlgorithmTool() const
{
	return new ConnectorAlignmentTool();
}

} 

#endif  //  CONNECTORALIGNMENTTOOL_H
