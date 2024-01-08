  /// \file SDHCALPseudoLayerPlugin.h
/*
 *
 * SDHCALPseudoLayerPlugin.h header template automatically generated by a class generator
 * Creation date : sam. mars 21 2015
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
 * @author John Marshall
 */


#ifndef SDHCALPSEUDOLAYERPLUGIN_H
#define SDHCALPSEUDOLAYERPLUGIN_H 1

#include "Pandora/PandoraInputTypes.h"

#include "Plugins/PseudoLayerPlugin.h"

namespace sdhcal_content
{

/**
 *  @brief  SDHCALPseudoLayerPlugin class
 */
class SDHCALPseudoLayerPlugin : public pandora::PseudoLayerPlugin
{
public:
    /**
     *  @brief  Default constructor
     */
    SDHCALPseudoLayerPlugin();

private:
    pandora::StatusCode Initialize();
public:
    unsigned int GetPseudoLayer(const pandora::CartesianVector &positionVector) const;
    unsigned int GetPseudoLayerAtIp() const;
private:
    /**
     *  @brief  Get the appropriate pseudolayer for a specified parameters
     * 
     *  @param  rCoordinate the radial coordinate
     *  @param  zCoordinate the z coordinate
     *  @param  rCorrection the barrel/endcap overlap r correction
     *  @param  zCorrection the barrel/endcap overlap z correction
     *  @param  barrelInnerR the barrel inner r coordinate
     *  @param  endCapInnerZ the endcap inner z coordinate
     *  @param  pseudoLayer to receive the appropriate pseudolayer
     */
    pandora::StatusCode GetPseudoLayer(const float rCoordinate, const float zCoordinate, const float rCorrection, const float zCorrection, 
        const float barrelInnerR, const float endCapInnerZ, unsigned int &pseudoLayer) const;

    typedef std::vector<float> LayerPositionList;

    /**
     *  @brief  Find the layer number corresponding to a specified position, via reference to a specified layer position list
     * 
     *  @param  position the specified position
     *  @param  layerPositionList the specified layer position list
     *  @param  layer to receive the layer number
     */
    pandora::StatusCode FindMatchingLayer(const float position, const LayerPositionList &layerPositionList, unsigned int &layer) const;

    /**
     *  @brief  Store all revelevant barrel and endcap layer positions upon initialization
     */
    void StoreLayerPositions();

    /**
     *  @brief  Store subdetector layer positions upon initialization
     * 
     *  @param  subDetector the sub detector
     *  @param  layerParametersList the layer parameters list
     */
    void StoreLayerPositions(const pandora::SubDetector &subDetector, LayerPositionList &LayerPositionList);

    /**
     *  @brief  Store positions of barrel and endcap outer edges upon initialization
     */
    void StoreDetectorOuterEdge();

    /**
     *  @brief  Store sine and cosine of angles used to project hit positions onto polygonal calorimeter surfaces upon initialization
     */
    void StorePolygonAngles();

    /**
     *  @brief  Store all details revelevant to barrel/endcap overlap corrections upon initialization
     */
    void StoreOverlapCorrectionDetails();

    typedef std::vector< std::pair<float, float> > AngleVector;

    /**
     *  @brief  Get the maximum polygon radius, with reference to cached sine/cosine values for relevant polygon angles
     * 
     *  @param  angleVector vector containing cached sine/cosine values
     *  @param  x the cartesian x coordinate
     *  @param  y the cartesian y coordinate
     * 
     *  @return the maximum radius
     */
    float GetMaximumRadius(const AngleVector &angleVector, const float x, const float y) const;

    /**
     *  @brief  Fill a vector with sine/cosine values for relevant polygon angles
     * 
     *  @param  symmetryOrder the polygon symmetry order
     *  @param  phi0 the polygon cylindrical polar phi coordinate
     *  @param  angleVector the vector to fill with sine/cosine values for relevant polygon angles
     */
    void FillAngleVector(const unsigned int symmetryOrder, const float phi0, AngleVector &angleVector) const;

    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

private:
    LayerPositionList   m_barrelLayerPositions;     ///< List of barrel layer positions
    LayerPositionList   m_endCapLayerPositions;     ///< List of endcap layer positions
    AngleVector         m_eCalBarrelAngleVector;    ///< The ecal barrel angle vector
    AngleVector         m_muonBarrelAngleVector;    ///< The muon barrel angle vector

    float               m_barrelInnerR;             ///< Barrel inner radius
    float               m_endCapInnerZ;             ///< Endcap inner z position
    float               m_barrelInnerRMuon;         ///< Muon barrel inner radius
    float               m_endCapInnerZMuon;         ///< Muon endcap inner z position

    float               m_rCorrection;              ///< Barrel/endcap overlap r correction
    float               m_zCorrection;              ///< Barrel/endcap overlap z correction
    float               m_rCorrectionMuon;          ///< Muon barrel/endcap overlap r correction
    float               m_zCorrectionMuon;          ///< Muon barrel/endcap overlap z correction

    float               m_barrelEdgeR;              ///< Extremal barrel r coordinate
    float               m_endCapEdgeZ;              ///< Extremal endcap z coordinate

    bool                m_useCoordinateCorrections; ///< Whether to use coordinate correction in intermediate regions
};

//------------------------------------------------------------------------------------------------------------------------------------------

inline unsigned int SDHCALPseudoLayerPlugin::GetPseudoLayerAtIp() const
{
    const unsigned int pseudoLayerAtIp(this->GetPseudoLayer(pandora::CartesianVector(0.f, 0.f, 0.f)));
    return pseudoLayerAtIp;
}

} // namespace lc_content

#endif // #ifndef LC_PSEUDO_LAYER_PLUGIN_H