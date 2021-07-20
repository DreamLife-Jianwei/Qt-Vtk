/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef GDCMIMPLEMENTATIONUIDSUB_H
#define GDCMIMPLEMENTATIONUIDSUB_H

#include "gdcmTypes.h"

namespace gdcm
{

namespace network
{

/**
 * \brief ImplementationUIDSub
 * \details Table D.3-2
 * IMPLEMENTATION UID SUB-ITEM FIELDS (A-ASSOCIATE-AC)
 */
class GDCM_EXPORT ImplementationUIDSub
{
public:
  ImplementationUIDSub();
  const std::ostream &Write(std::ostream &os) const;
private:
  static const uint8_t ItemType;
  static const uint8_t Reserved2;
  uint16_t ItemLength;
  std::string ImplementationClassUID;
};

} // end namespace network

} // end namespace gdcm

#endif //GDCMMAXIMUMLENGTHSUB_H
