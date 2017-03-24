/* ============================================================
 *
 * This file is a part of RST-RT (CogIMon) project
 *
 * Copyright (C) 2016 by Jan Moringen <jmoringe@techfak.uni-bielefeld.de>
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

namespace rstrt {
namespace geometry {

class Rotation {
public:
	Rotation();
	Rotation(float qw, float qx, float qy, float qz);
	Rotation(float r, float p, float y);
	Rotation(float r, float p, float y, const std::string& fId);
	Rotation(float qw, float qx, float qy, float qz,
			const std::string& fId);
//private:
	Eigen::VectorXf rotation;
	std::string frameId;

	Eigen::Quaternionf euler2Quaternion(const float roll, const float pitch,
			const float yaw);
	Eigen::Vector3f quaternion2Euler(const Eigen::Quaternionf q);
};

std::ostream& operator<<(std::ostream& os, const Rotation& cd);
std::istream& operator>>(std::istream& is, Rotation& cd);

}
}
