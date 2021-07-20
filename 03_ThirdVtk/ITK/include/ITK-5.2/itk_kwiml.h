/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itk_kwiml_h
#define itk_kwiml_h

/* Use the KWIML library configured for ITK.  */
/* #undef ITK_USE_SYSTEM_KWIML */
#ifdef ITK_USE_SYSTEM_KWIML
# include <kwiml/abi.h>
# include <kwiml/int.h>
#else
# include "itkkwiml/abi.h"
# include "itkkwiml/int.h"
#endif

#endif
