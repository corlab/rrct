# This file is a part of RST-RT (CogIMon) project
#
# Copyright (C) 2016 Jan Moringen <jmoringe@techfak.uni-bielefeld.de>
#
# This file may be licensed under the terms of the
# GNU Lesser General Public License Version 3 (the ``LGPL''),
# or (at your option) any later version.
#
# Software distributed under the License is distributed
# on an ``AS IS'' basis, WITHOUT WARRANTY OF ANY KIND, either
# express or implied. See the LGPL for the specific language
# governing rights and limitations.
#
# You should have received a copy of the LGPL along with this
# program. If not, go to http://www.gnu.org/licenses/lgpl.html
# or write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#
# The development of this software was supported by:
#   CoR-Lab, Research Institute for Cognition and Robotics
#     Bielefeld University

# Sources

set(SOURCES ${CMAKE_PROJECT_NAME}/geometry/Translation.cpp
            ${CMAKE_PROJECT_NAME}/geometry/Rotation.cpp
            ${CMAKE_PROJECT_NAME}/geometry/LinearAcceleration.cpp
            ${CMAKE_PROJECT_NAME}/geometry/AngularVelocity.cpp

            ${CMAKE_PROJECT_NAME}/kinematics/JointAngles.cpp
            ${CMAKE_PROJECT_NAME}/kinematics/JointVelocities.cpp
            ${CMAKE_PROJECT_NAME}/kinematics/JointAccelerations.cpp
            ${CMAKE_PROJECT_NAME}/kinematics/JointJerks.cpp

            ${CMAKE_PROJECT_NAME}/dynamics/JointTorques.cpp
            ${CMAKE_PROJECT_NAME}/dynamics/JointImpedance.cpp
            ${CMAKE_PROJECT_NAME}/dynamics/Forces.cpp
            ${CMAKE_PROJECT_NAME}/dynamics/Torques.cpp
            ${CMAKE_PROJECT_NAME}/dynamics/Wrench.cpp
            
            ${CMAKE_PROJECT_NAME}/robot/JointState.cpp
            ${CMAKE_PROJECT_NAME}/robot/Weights.cpp
            ${CMAKE_PROJECT_NAME}/robot/IMU.cpp
)

set(HEADERS ${CMAKE_PROJECT_NAME}/geometry/Translation.hpp
            ${CMAKE_PROJECT_NAME}/geometry/Rotation.hpp
            ${CMAKE_PROJECT_NAME}/geometry/LinearAcceleration.hpp
            ${CMAKE_PROJECT_NAME}/geometry/AngularVelocity.hpp

            ${CMAKE_PROJECT_NAME}/kinematics/JointAngles.hpp
            ${CMAKE_PROJECT_NAME}/kinematics/JointVelocities.hpp
            ${CMAKE_PROJECT_NAME}/kinematics/JointAccelerations.hpp
            ${CMAKE_PROJECT_NAME}/kinematics/JointJerks.hpp

            ${CMAKE_PROJECT_NAME}/dynamics/JointTorques.hpp
            ${CMAKE_PROJECT_NAME}/dynamics/JointImpedance.hpp
            ${CMAKE_PROJECT_NAME}/dynamics/Forces.hpp
            ${CMAKE_PROJECT_NAME}/dynamics/Torques.hpp
            ${CMAKE_PROJECT_NAME}/dynamics/Wrench.hpp
            
            ${CMAKE_PROJECT_NAME}/robot/JointState.hpp
            ${CMAKE_PROJECT_NAME}/robot/Weights.hpp
            ${CMAKE_PROJECT_NAME}/robot/IMU.hpp
)

# Shared object

add_library(${LIBRARY_NAME} SHARED
            ${SOURCES})

# Install

install(TARGETS ${LIBRARY_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY ${CMAKE_PROJECT_NAME}
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include/${CMAKE_PROJECT_NAME}${INSTALL_SUFFIX}")
