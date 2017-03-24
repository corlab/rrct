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

#include "Rotation.hpp"

namespace rstrt {
namespace geometry {

Rotation::Rotation() : rotation(4) {
	rotation.fill(0);
}

Rotation::Rotation(float qw, float qx, float qy, float qz) :
		rotation(4) {
	rotation << qw, qx, qy, qz;
}

Rotation::Rotation(float qw, float qx, float qy, float qz,
		const std::string& fId) :
		rotation(4), frameId(fId) {
	rotation << qw, qx, qy, qz;
}

Rotation::Rotation(float r, float p, float y) : rotation(4) {
	Eigen::Quaternionf q = euler2Quaternion(r, p, y);
	rotation << q.w(), q.x(), q.y(), q.z();
}

Rotation::Rotation(float r, float p, float y, const std::string& fId) : rotation(4) {
	Eigen::Quaternionf q = euler2Quaternion(r, p, y);
	rotation << q.w(), q.x(), q.y(), q.z();
	frameId = fId;
}

std::ostream& operator<<(std::ostream& os, const Rotation& cd) {
	os << cd.rotation;
	if (!cd.frameId.empty()) {
		os << std::endl << "in frame " << cd.frameId;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Rotation& cd) {
	return is;
}

Eigen::Quaternionf Rotation::euler2Quaternion(const float roll,
		const float pitch, const float yaw) {
	// TODO 1 xyz order: If there is a problem check all the other 24 combinations of euler angles -.-
	// TODO 2 Don't know it this has a bad influence on real-time?
	Eigen::AngleAxisf rollAngle((roll * M_PI) / 180, Eigen::Vector3f::UnitX());
	Eigen::AngleAxisf yawAngle((yaw * M_PI) / 180, Eigen::Vector3f::UnitZ());
	Eigen::AngleAxisf pitchAngle((pitch * M_PI) / 180,
			Eigen::Vector3f::UnitY());

	return rollAngle * pitchAngle * yawAngle;
}

Eigen::Vector3f Rotation::quaternion2Euler(const Eigen::Quaternionf q) {
	return q.toRotationMatrix().eulerAngles(0, 1, 2);
}

}
}
