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

#include "Odometry.hpp"

namespace rstrt {
namespace robot {

Odometry::Odometry() {
}

Odometry::Odometry(rstrt::geometry::Pose p, rstrt::kinematics::Twist t) :
		pose(p), twist(t) {

}

Odometry::Odometry(float px, float py, float pz, float pqw, float pqx,
		float pqy, float pqz, float lx, float ly, float lz, float aa, float ab,
		float ac) :
		pose(px, py, pz, pqw, pqx, pqy, pqz), twist(lx, ly, lz, aa, ab, ac) {

}

std::ostream& operator<<(std::ostream& os, const Odometry& cd) {
	os << cd.pose << std::endl << cd.twist;
	return os;
}

std::istream& operator>>(std::istream& is, Odometry& cd) {
	return is;
}

}
}
