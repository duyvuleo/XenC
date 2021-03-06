/**
 *  @file xenfile.cpp
 *  @brief Class providing some basic functions around files
 *  @author Anthony Rousseau
 *  @version 2.0.0
 *  @date 18 March 2016
 */

/*  This file is part of the cross-entropy tool for data selection (XenC)
 *  aimed at speech recognition and statistical machine translation.
 *
 *  Copyright 2013-2016, Anthony Rousseau, LIUM, University of Le Mans, France
 *
 *  Development of the XenC tool has been partially funded by the
 *  European Commission under the MateCat project.
 *
 *  The XenC tool is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License version 3 as
 *  published by the Free Software Foundation
 *
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library; if not, write to the Free Software Foundation,
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "../include/xenfile.h"

XenFile::XenFile() : fileName(""), dirName("") {

}

void XenFile::initialize(std::string name) {
    boost::filesystem::path p(name);
    boost::filesystem::path fn = p.filename();
    fileName = fn.string();
    dirName = p.parent_path().string();
    
    if (dirName.compare("") == 0) { dirName = boost::filesystem::initial_path().string(); }
}

XenFile::~XenFile() {
    
}

std::string XenFile::getFileName() const {
    return fileName;
}

std::string XenFile::getPrefix() {
    boost::regex e("(.*?)\\..*");
    std::string pre = boost::regex_replace(fileName, e, "\\1", boost::match_default | boost::format_sed);

    return pre;
}

std::string XenFile::getExt() {
    boost::regex e(".*?\\.(.*)");
    std::string ext = boost::regex_replace(fileName, e, "\\1", boost::match_default | boost::format_sed);
    
    return ext;
}

std::string XenFile::getDirName() const {
    return dirName;
}

std::string XenFile::getFullPath() const {
    return dirName + "/" + fileName;
}

bool XenFile::isGZ() const {
    std::FILE* file;
    file = std::fopen(getFullPath().c_str(), "rb");
    
    unsigned char magicNumber[2];
    size_t res = std::fread(&magicNumber, 2, 1, file);
    std::fclose(file);

    if((magicNumber[0] == 0x1f && magicNumber[1] == 0x8b) || (magicNumber[1] == 0x1f && magicNumber[0] == 0x8b))
        return true;
    else
        return false;
}
