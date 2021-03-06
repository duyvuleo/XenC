/**
 *  @file biXEntropy.h
 *  @brief Derived class to handle filtering mode 3: bilingual cross-entropy
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

#ifndef BIXENTROPY_H_
#define BIXENTROPY_H_

#include <boost/make_shared.hpp>

#include "../mode.h"       //!< Inherit boost::filesystem from here
#include "../utils/StaticData.h"    //!< Inherit boost::shared_ptr from here

using namespace boost;

/**
 *  @class BiXEntropy
 *  @brief Filtering mode 3: bilingual cross-entropy
 *
 *  This class derived from Mode handles the third filtering mode:
 *  bilingual cross-entropy
 */
class BiXEntropy : public Mode {
public:
    /**
     *  @fn BiXEntropy ()
     *  @brief Default constructor
     */
    BiXEntropy();
    
    /**
     *  @fn ~BiXEntropy ()
     *  @brief Default destructor
     */
    ~BiXEntropy();
    
    /**
     *  @fn int launch ()
     *  @brief Function in charge of launching the filtering mode
     *
     *  @return 0 if the filtering succeeds
     */
    int launch();
};

#endif
