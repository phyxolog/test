/*
 * Copyright (C) 2018 Yura Zhivaga <yzhivaga@gmail.com>
 * 
 * This file is part of rz4.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

#include "boost/filesystem.hpp"
#include "boost/format.hpp"
#include <boost/program_options.hpp>

#include "scan.hpp"
#include "eject.hpp"
#include "util.hpp"

#define BUFFER_SIZE       262144
#define COMMAND_SCAN      "s"
#define COMMAND_COMPRESS  "c"
#define COMMAND_EXTRACT   "e"

static const std::string logo =
"----------------------------------------------------------\n"
"|                           rz4                          |\n"
"|                     multimedia packer                  |\n"
"|              https://github.com/phyxolog/rz4           |\n"
"----------------------------------------------------------\n";

static const std::string usage_message =
"Usage:\n"
"    rz4 <command> [options] <input_file>\n\n"
"    Commands:\n"
"      c - compress input file.\n"
"      s - scan only input file.\n"
"      e - extract found signatures from input file.\n\n"
"    Detect options:\n"
"      --wav=N          - enable RIFF WAVE detect (default: 1).\n\n"
"    Other options:\n"
"      --out=<filename> - path to output file name\n"
"      --outdir=<path>  - path to output folder (for extracted files)\n"
"      --bufsize=N      - set buffer size (default: 256kb).\n\n";