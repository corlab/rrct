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

#include "IMU.hpp"

namespace rstrt {
namespace robot {

IMU::IMU() {
	this->linearAcceleration.fill(0);
	this->angularVelocity.fill(0);
	this->rotation.fill(0);
}

IMU::IMU(float ax, float ay, float az, float va, float vb, float vc, float qw,
		float qx, float qy, float qz) :
		linearAcceleration(ax, ay, az), angularVelocity(va, vb, vc), rotation(
				qw, qx, qy, qz) {
}

IMU::IMU(rstrt::geometry::LinearAcceleration linearAcceleration,
		rstrt::geometry::AngularVelocity angularVelocity,
		rstrt::geometry::Rotation rotation) :
		linearAcceleration(linearAcceleration.linearAcceleration), angularVelocity(
				angularVelocity.angularVelocity), rotation(rotation.rotation) {
}

std::ostream& operator<<(std::ostream& os, const IMU& cd) {
	os << cd.linearAcceleration << std::endl << cd.angularVelocity << std::endl
			<< cd.rotation;
	return os;
}

std::istream& operator>>(std::istream& is, IMU& cd) {
	return is;
}

}
}
