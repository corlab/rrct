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

#include "CallTraceSample.hpp"

namespace rstrt {
namespace monitoring {

CallTraceSample::CallTraceSample() : call_type(CALL_UNIVERSAL) {
}

CallTraceSample::CallTraceSample(const std::string& callName, const std::string& containerName, const uint_least64_t callTime, const int callType) {
	this->call_name = callName;
	this->container_name = containerName;
	this->call_time = callTime;
	this->call_type = callType;
}

const CallTraceSample::CallSampleType CallTraceSample::convertCallTypeFromInt2Enum(const int& type) {
	switch(type) {
	case 0:
		return CallTraceSample::CALL_UNIVERSAL;
	case 1:
		return CallTraceSample::CALL_START;
	case 2:
		return CallTraceSample::CALL_END;
	case 3:
		return CallTraceSample::CALL_INSTANTANEOUS;
	case 4:
		return CallTraceSample::CALL_PORT_WRITE;
	case 5:
		return CallTraceSample::CALL_PORT_READ_NODATA;
	case 6:
		return CallTraceSample::CALL_PORT_READ_NEWDATA;
	case 7:
		return CallTraceSample::CALL_PORT_READ_OLDDATA;
	default:
		// should actually not happen!
		return CallTraceSample::CALL_UNIVERSAL;
	}
}

const int CallTraceSample::convertCallTypeFromEnum2Int(const CallTraceSample::CallSampleType& type) {
	switch(type) {
	case CallTraceSample::CALL_UNIVERSAL:
		return 0;
	case CallTraceSample::CALL_START:
		return 1;
	case CallTraceSample::CALL_END:
		return 2;
	case CallTraceSample::CALL_INSTANTANEOUS:
		return 3;
	case CallTraceSample::CALL_PORT_WRITE:
		return 4;
	case CallTraceSample::CALL_PORT_READ_NODATA:
		return 5;
	case CallTraceSample::CALL_PORT_READ_NEWDATA:
		return 6;
	case CallTraceSample::CALL_PORT_READ_OLDDATA:
		return 7;
	default:
		// should actually not happen!
		return -1;
	}
}

const std::string CallTraceSample::convertCallTypeFromEnum2String(const CallTraceSample::CallSampleType& type) {
	switch(type) {
	case CallTraceSample::CALL_UNIVERSAL:
		return "CALL_UNIVERSAL";
	case CallTraceSample::CALL_START:
		return "CALL_START";
	case CallTraceSample::CALL_END:
		return "CALL_END";
	case CallTraceSample::CALL_INSTANTANEOUS:
		return "CALL_INSTANTANEOUS";
	case CallTraceSample::CALL_PORT_WRITE:
		return "CALL_PORT_WRITE";
	case CallTraceSample::CALL_PORT_READ_NODATA:
		return "CALL_PORT_READ_NODATA";
	case CallTraceSample::CALL_PORT_READ_NEWDATA:
		return "CALL_PORT_READ_NEWDATA";
	case CallTraceSample::CALL_PORT_READ_OLDDATA:
		return "CALL_PORT_READ_OLDDATA";
	default:
		// should actually not happen!
		return "";
	}
}

const std::string CallTraceSample::convertCallTypeFromInt2String(const int& type) {
	switch(type) {
	case 0:
		return "CALL_UNIVERSAL";
	case 1:
		return "CALL_START";
	case 2:
		return "CALL_END";
	case 3:
		return "CALL_INSTANTANEOUS";
	case 4:
		return "CALL_PORT_WRITE";
	case 5:
		return "CALL_PORT_READ_NODATA";
	case 6:
		return "CALL_PORT_READ_NEWDATA";
	case 7:
		return "CALL_PORT_READ_OLDDATA";
	default:
		// should actually not happen!
		return "UNKNOWN CALL TYPE";
	}
}

std::ostream& operator<<(std::ostream& os, const CallTraceSample& cd) {
	os << std::endl << "call name: " << cd.call_name;
	os << std::endl << "container name: " << cd.container_name;
	os << std::endl << "call time: " << cd.call_time;
	os << std::endl << "call type:" << CallTraceSample::convertCallTypeFromInt2String(cd.call_type);
	return os;
}

std::istream& operator>>(std::istream& is, CallTraceSample& cd) {
	return is;
}

}
}
