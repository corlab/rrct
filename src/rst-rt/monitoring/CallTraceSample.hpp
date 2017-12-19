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

namespace rstrt {
namespace monitoring {

class CallTraceSample {
public:
	
    /**
     * Call Sample Types.
     */
	enum CallSampleType {
		// Use CALL_UNIVERSAL if you are not sure.
        CALL_UNIVERSAL = 0,
        // Use to indicate a call start sample.
        CALL_START = 1,
        // Use to indicate a call end sample.
        CALL_END = 2,
        // Use to indicate an instantaneous call sample.
        CALL_INSTANTANEOUS = 3,

        /** Specific Types use with caution only */
        // Use to indicate a port write call sample.
        CALL_PORT_WRITE = 4,
        // Use to indicate a port read call sample that returned NoData.
        CALL_PORT_READ_NODATA = 5,
        // Use to indicate a port read call sample that returned NewData.
        CALL_PORT_READ_NEWDATA = 6,
        // Use to indicate a port read call sample that returned OldData.
        CALL_PORT_READ_OLDDATA = 7
	};
    
	CallTraceSample();
	CallTraceSample(const std::string& callName, const std::string& containerName, const double callTime, const int callType = 0);

    static const CallSampleType convertCallTypeFromInt2Enum(const int& type);
    static const int convertCallTypeFromEnum2Int(const CallSampleType& type);
    static const std::string convertCallTypeFromEnum2String(const CallSampleType& type);
    static const std::string convertCallTypeFromInt2String(const int& type);

//private:
	std::string call_name;

	std::string container_name;

	double call_time;

    int call_type;              // optional
};

std::ostream& operator<<(std::ostream& os, const CallTraceSample& cd);
std::istream& operator>>(std::istream& is, CallTraceSample& cd);

}
}
