/* ============================================================
 *
 * This file is a part of RST-RT (CogIMon) project
 *
 * Copyright (C) 2017 by Dennis Leroy Wigand <dwigand@techfak.uni-bielefeld.de>
 *
 * This file may be licensed under the terms of the
 * GNU Lesser General Public License Version 3 (the ``LGPL''),
 * or (at your option) any later version.
 *
 * Software distributed under the License is distributed
 * on an ``AS IS'' basis, WITHOUT WARRANTY OF ANY KIND, either
 * express or implied. See the LGPL for the specific language
 * governing rights and limitations.
 *
 * You should have received a copy of the LGPL along with this
 * program. If not, go to http://www.gnu.org/licenses/lgpl.html
 * or write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The development of this software was supported by:
 *   CoR-Lab, Research Institute for Cognition and Robotics
 *     Bielefeld University
 *
 * ============================================================ */

#pragma once

#include <iostream>

#include <Eigen/Dense>

#include "Translation.hpp"
#include "Rotation.hpp"

namespace rstrt {
namespace geometry {

class Pose {
public:
    Pose();
    Pose(rstrt::geometry::Translation t, rstrt::geometry::Rotation r);
    Pose(float x, float y, float z, float qw, float qx, float qy, float qz);
    Pose(float x, float y, float z, const std::string& t_frameId, float qw, float qx, float qy, float qz, const std::string& r_frameId);
//private:
    rstrt::geometry::Translation translation;
    rstrt::geometry::Rotation rotation;
};

std::ostream& operator<<(std::ostream& os, const Pose& cd);
std::istream& operator>>(std::istream& is, Pose& cd);

}
}
