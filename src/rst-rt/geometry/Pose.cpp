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

#include "Pose.hpp"

namespace rstrt {
namespace geometry {

Pose::Pose() {
}

Pose::Pose(rstrt::geometry::Translation t, rstrt::geometry::Rotation r) :
		translation(t), rotation(r) {

}

Pose::Pose(float x, float y, float z, float qw, float qx, float qy, float qz) :
		translation(x, y, z), rotation(qw, qx, qy, qz) {

}

Pose::Pose(float x, float y, float z, const std::string& t_frameId, float qw,
		float qx, float qy, float qz, const std::string& r_frameId) :
		translation(x, y, z, t_frameId), rotation(qw, qx, qy, qz, r_frameId) {

}

std::ostream& operator<<(std::ostream& os, const Pose& cd) {
	os << cd.translation << std::endl << cd.rotation;
	return os;
}

std::istream& operator>>(std::istream& is, Pose& cd) {
	return is;
}

}
}
