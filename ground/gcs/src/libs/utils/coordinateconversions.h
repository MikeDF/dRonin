/**
 ******************************************************************************
 *
 * @file       coordinateconversions.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 *             Parts by Nokia Corporation (qt-info@nokia.com) Copyright (C) 2009.
 * @brief
 * @see        The GNU Public License (GPL) Version 3
 * @defgroup
 * @{
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */

#ifndef COORDINATECONVERSIONS_H
#define COORDINATECONVERSIONS_H

#include "utils_global.h"
#include "math.h"

namespace Utils {

class QTCREATOR_UTILS_EXPORT CoordinateConversions
{
public:
    CoordinateConversions();
    int NED2LLA_HomeECEF(double BaseECEF[3], double NED[3], double LLA[3]);
    int NED2LLA_HomeLLA(double homeLLA[3], double NED[3], double LLA[3]);
    void LLA2Rne(double LLA[3], double Rne[3][3]);
    void LLA2ECEF(double LLA[3], double ECEF[3]);
    int ECEF2LLA(double ECEF[3], double LLA[3]);
    void LLA2NED_HomeECEF(double LLA[3], double homeECEF[3], double Rne[3][3], double NED[3]);
    void LLA2NED_HomeLLA(double LLA[3], double homeLLA[3], double NED[3]);
    void Quaternion2RPY(const float q[4], float rpy[3]);
    void RPY2Quaternion(const float rpy[3], float q[4]);
    void Quaternion2R(const float q[4], float Rbe[3][3]);
    void R2Quaternion(float const Rbe[3][3], float q[4]);
private:
    //WGS84 parameters
    static const double R_EQUATOR;           // Equatorial Radius
    static const double ECCENTRICITY;        // Eccentricity
};

}

#endif /* COORDINATECONVERSIONS_H */
