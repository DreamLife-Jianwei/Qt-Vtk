/*=========================================================================

  Program: DICOM for VTK

  Copyright (c) 2012-2019 David Gobbi
  All rights reserved.
  See Copyright.txt or http://dgobbi.github.io/bsd3.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtkDICOMSequence_h
#define vtkDICOMSequence_h

#include "vtkDICOMModule.h" // For export macro
#include "vtkDICOMValue.h"

class vtkDICOMItem;
class vtkDICOMTagPath;

//! A sequence of items according to the SQ representation.
/*!
 *  This class is for constructing and decoding sequences.
 *  There are two ways that sequences can be constructed:
 *  A fixed-size sequence can be created and then its items
 *  filled in with the SetItem() method, or, you can start
 *  with an empty sequence and use AddItem() to append items.
 */
class VTKDICOM_EXPORT vtkDICOMSequence
{
public:
  //@{
  //! Construct a growable sequence with no items.
  vtkDICOMSequence();

  //! Construct a sequence of fixed size.
  explicit vtkDICOMSequence(unsigned int n);
  //@}

  //@{
  //! Clear a sequence, remove its contents and make it empty.
  void Clear();
  //@}

  //@{
  //! Get a value from an item in the sequence.
  const vtkDICOMValue &Get(size_t i, vtkDICOMTag tag) const;
  const vtkDICOMValue &Get(size_t i, const vtkDICOMTagPath &p) const;
  const vtkDICOMValue &GetAttributeValue(
    size_t i, vtkDICOMTag tag) const {
    return this->Get(i, tag); }
  const vtkDICOMValue &GetAttributeValue(
    size_t i, const vtkDICOMTagPath &p) const {
    return this->Get(i, p); }
  //@}

  //@{
  //! Add an item to the sequence.
  /*!
   *  After calling this method, GetNumberOfItems() will report
   *  the number of items in the sequence, but GetVL() will return
   *  the special value 0xffffffff to indicate that this is a delimited
   *  sequence rather than a fixed-size sequence.
   */
  void AddItem(const vtkDICOMItem& item);

  //! Get the number of items in the sequence.
  size_t GetNumberOfItems() const {
    return this->V.GetNumberOfValues(); }
  //@}

  //@{
  //! Set an item in the sequence.
  /*!
   *  This method can only be used if space as been allocated within
   *  the sequence by specifying a size when calling the constructor.
   */
  void SetItem(size_t i, const vtkDICOMItem& item);

  //! Get an item from the sequence.
  const vtkDICOMItem& GetItem(size_t i) const;

  //! Get a pointer to the items in the sequence.
  const vtkDICOMItem *GetSequenceData() const {
    return this->V.GetSequenceData(); }
  //@}

  //@{
  //! Copy constructor.
  vtkDICOMSequence(const vtkDICOMSequence& o) : V(o.V) {}

  //! Conversion from value to sequence is type checked.
  vtkDICOMSequence(const vtkDICOMValue& o) : V(o) {
    if (o.GetVR() != vtkDICOMVR::SQ) { this->V.Clear(); } }

  //! Check that the sequence was constructed from a valid value.
  bool IsValid() const {
    return this->V.IsValid(); }
  //@}

  //@{
  //! Assignment operator.
  vtkDICOMSequence& operator=(const vtkDICOMSequence& o) {
    this->V = o.V; return *this; }

  //! Assignment from value to sequence is type checked.
  vtkDICOMSequence& operator=(const vtkDICOMValue& o) {
    if (o.GetVR() == vtkDICOMVR::SQ) { this->V = o; }
    else { this->V.Clear(); } return *this; }
  //@}

private:
  friend class vtkDICOMValue;

  vtkDICOMValue V;

  //! An invalid value, for when one is needed.
  static const vtkDICOMValue InvalidValue;
  //! An empty item, for when one is needed.
  static const vtkDICOMItem EmptyItem;
};

VTKDICOM_EXPORT ostream& operator<<(ostream& os, const vtkDICOMSequence& v);

#endif /* vtkDICOMSequence_h */
// VTK-HeaderTest-Exclude: vtkDICOMSequence.h
