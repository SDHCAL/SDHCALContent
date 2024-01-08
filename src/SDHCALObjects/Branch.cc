/// \file Branch.cc
/*
 *
 * Branch.cc source template automatically generated by a class generator
 * Creation date : lun. mai 4 2015
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

#include "SDHCALApi/SDHCALContentApi.h"
#include "SDHCALObjects/CaloHit.h"
#include "SDHCALObjects/Connector.h"
#include "SDHCALObjects/Branch.h"

namespace sdhcal_content
{

  Branch::Branch(const_iterator first, const_iterator last) :
    m_caloHitList(first, last)
  {
    if(!IsValid())
    {
      this->clear();
      throw pandora::StatusCodeException(pandora::STATUS_CODE_FAILURE);
    }
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  Branch::Branch(const Branch &branch)
  {
    *this = branch;

    if(!IsValid())
    {
      clear();
      throw pandora::StatusCodeException(pandora::STATUS_CODE_FAILURE);
    }
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  pandora::StatusCode Branch::BuildFromCaloHit(const CaloHit *const pCaloHit)
  {
    if(NULL == pCaloHit)
      return pandora::STATUS_CODE_INVALID_PARAMETER;

    clear();

    const CaloHit *pCurrentCaloHit = pCaloHit;
    m_caloHitList.push_back(pCurrentCaloHit);

    while(pCurrentCaloHit)
    {
      const ConnectorList &backwardConnectorList(SDHCALContentApi::GetConnectorList(pCurrentCaloHit, BACKWARD_DIRECTION));

      if(backwardConnectorList.empty())
        return pandora::STATUS_CODE_SUCCESS;

      if(backwardConnectorList.size() != 1)
      {
        clear();
        return pandora::STATUS_CODE_FAILURE;
      }

      const Connector *const pConnector(*backwardConnectorList.begin());
      pCurrentCaloHit = pConnector->GetFrom();
      m_caloHitList.insert(m_caloHitList.begin(), pCurrentCaloHit);
    }

    return pandora::STATUS_CODE_SUCCESS;
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  pandora::StatusCode Branch::push_back(const CaloHit *const pCaloHit)
  {
    if(NULL == pCaloHit)
      return pandora::STATUS_CODE_INVALID_PARAMETER;

    if(m_caloHitList.empty())
    {
      m_caloHitList.push_back(pCaloHit);
    }
    else
    {
      const CaloHit *const pOuterCaloHit(m_caloHitList.back());

      if(!SDHCALContentApi::IsConnected(pCaloHit, pOuterCaloHit, BACKWARD_DIRECTION))
        return pandora::STATUS_CODE_FAILURE;

      m_caloHitList.push_back(pCaloHit);
    }

    return pandora::STATUS_CODE_SUCCESS;
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  pandora::StatusCode Branch::push_front(const CaloHit *const pCaloHit)
  {
    if(NULL == pCaloHit)
      return pandora::STATUS_CODE_INVALID_PARAMETER;

    if(m_caloHitList.empty())
    {
      m_caloHitList.push_back(pCaloHit);
    }
    else
    {
      const CaloHit *const pInnerCaloHit(m_caloHitList.front());

      if(!SDHCALContentApi::IsConnected(pCaloHit, pInnerCaloHit, FORWARD_DIRECTION))
        return pandora::STATUS_CODE_FAILURE;

      m_caloHitList.insert(m_caloHitList.begin(), pCaloHit);
    }

    return pandora::STATUS_CODE_SUCCESS;
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  pandora::StatusCode Branch::Cut(iterator position, bool keepForwardPart)
  {
    if(m_caloHitList.end() == position || m_caloHitList.end() == position+1)
      return pandora::STATUS_CODE_SUCCESS;

    if(keepForwardPart)
    {
      m_caloHitList.erase(m_caloHitList.begin(), position);
    }
    else
    {
      m_caloHitList.erase(position+1, m_caloHitList.end());
    }

    return pandora::STATUS_CODE_SUCCESS;
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  bool Branch::IsValid() const
  {
    if(m_caloHitList.size() <= 1)
      return true;

    for(const_iterator iter = this->begin(), endIter = this->end() ; endIter != iter ; ++iter)
    {
      const CaloHit *const pCaloHit = *iter;

      if(iter+1 == this->end())
        break;

      const CaloHit*const pNextCaloHit = *(iter+1);

      if(!SDHCALContentApi::IsConnected(pCaloHit, pNextCaloHit, FORWARD_DIRECTION))
        return false;
    }

    return true;
  }

  //------------------------------------------------------------------------------------------------------------------------------------------

  Branch &Branch::operator =(const Branch &branch)
  {
    m_caloHitList.insert(m_caloHitList.begin(), branch.m_caloHitList.begin(), branch.m_caloHitList.end());

    return *this;
  }

} 

