/* ============================================================
 *
 * This file is a part of RST-RT (CogIMon) project
 *
 * Copyright (C) 2016 by Dennis Leroy Wigand <dwigand@techfak.uni-bielefeld.de>
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

#include "LinearVelocities.hpp"

namespace rstrt {
namespace kinematics {

LinearVelocities::LinearVelocities() : linearVelocities(3) {
	linearVelocities.fill(0);
}

LinearVelocities::LinearVelocities(float x, float y, float z)
    : linearVelocities(3) {
	linearVelocities << x, y, z;
}

std::ostream& operator<<(std::ostream& os, const LinearVelocities& cd) {
    os << cd.linearVelocities;
    return os;
}

std::istream& operator>>(std::istream& is, LinearVelocities& cd) {
    return is;
}

}
}
