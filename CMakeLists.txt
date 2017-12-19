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

cmake_minimum_required(VERSION 2.8.3)

# Project information

project(rst-rt CXX)

if(NOT CMAKE_VERSION VERSION_LESS 3.1)
    set(CMAKE_CXX_STANDARD 11)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

string(TOUPPER "${CMAKE_PROJECT_NAME}" PROJECT_NAME_UPPER)

set(${PROJECT_NAME_UPPER}_VERSION_MAJOR 0)
set(${PROJECT_NAME_UPPER}_VERSION_MINOR 1)
set(${PROJECT_NAME_UPPER}_VERSION "${${PROJECT_NAME_UPPER}_VERSION_MAJOR}.${${PROJECT_NAME_UPPER}_VERSION_MINOR}")

set(INSTALL_SUFFIX "${${PROJECT_NAME_UPPER}_VERSION}")

set(LIBRARY_NAME "${CMAKE_PROJECT_NAME}${INSTALL_SUFFIX}")

# Dependencies
find_package(YCM QUIET)
find_package(Eigen3)

add_definitions(${EIGEN3_DEFINITIONS})
include_directories(${EIGEN3_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIRS})

# Sub-directories

add_subdirectory(src)

# Installation

configure_file("${CMAKE_PROJECT_NAME}-config.cmake.in"
               "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}-config.cmake"
               @ONLY)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}-config.cmake"
        DESTINATION "share/${CMAKE_PROJECT_NAME}-${INSTALL_SUFFIX}")
