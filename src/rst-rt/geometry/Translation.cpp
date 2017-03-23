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

#include "Translation.hpp"

namespace rstrt {
namespace geometry {

Translation::Translation() {
}

Translation::Translation(float x, float y, float z)
    : translation(3) {
	translation << x,y,z;
}

Translation::Translation(float x, float y, float z, const std::string& frameId)
    : translation(3), frameId(frameId) {
	translation << x,y,z;
}

std::ostream& operator<<(std::ostream& os, const Translation& cd) {
    os << cd.translation;
    if (!cd.frameId.empty()) {
        os << std::endl << "in frame " << cd.frameId;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Translation& cd) {
    return is;
}

}
}
