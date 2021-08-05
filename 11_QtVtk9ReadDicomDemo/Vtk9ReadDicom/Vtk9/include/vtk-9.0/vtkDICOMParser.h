/*=========================================================================

  Program: DICOM for VTK

  Copyright (c) 2012-2019 David Gobbi
  All rights reserved.
  See Copyright.txt or http://dgobbi.github.io/bsd3.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtkDICOMParser_h
#define vtkDICOMParser_h

#include "vtkObject.h"
#include "vtkStdString.h" // For std::string
#include "vtkDICOMModule.h" // For export macro
#include "vtkDICOMConfig.h" // For configuration details
#include "vtkDICOMCharacterSet.h" // For character sets

class vtkDICOMFile;
class vtkDICOMItem;
class vtkDICOMMetaData;
class vtkUnsignedShortArray;
class vtkDICOMParserInternalFriendship;

//! A meta data reader for DICOM data.
/*!
 *  This class provides routines for parsing a DICOM file
 *  and creating a vtkDICOMMetaData object.  It stops parsing
 *  the file as soon as it finds the PixelData, and the byte
 *  offset of the PixelData within the file can be retrieved
 *  with GetFileOffset().
 */
class VTKDICOM_EXPORT vtkDICOMParser : public vtkObject
{
public:
  //! Create a new vtkDICOMParser instance.
  static vtkDICOMParser *New();

  //! VTK dynamic type information macro.
  vtkTypeMacro(vtkDICOMParser, vtkObject);

  //! Print a summary of the contents of this object.
  void PrintSelf(ostream& os, vtkIndent indent) VTK_DICOM_OVERRIDE;

  //@{
  //! Set the file name.
  vtkSetStringMacro(FileName);
  vtkGetStringMacro(FileName);
  //@}

  //@{
  //! Set the metadata object for storing the data elements.
  void SetMetaData(vtkDICOMMetaData *);
  vtkDICOMMetaData *GetMetaData() { return this->MetaData; }
  //@}

  //@{
  //! Set the instance index to use when storing metadata.
  vtkSetMacro(Index, int);
  int GetIndex() { return this->Index; }
  //@}

  //@{
  //! Set the character set to use if SpecificCharacterSet is missing.
  /*!
   *  Some DICOM files do not list a SpecificCharacterSet attribute, but
   *  nevertheless use a non-ASCII character encoding.  This method can be
   *  used to specify the character set in absence of SpecificCharacterSet.
   *  If SpecificCharacterSet is present, the default will not override it
   *  unless OverrideCharacterSet is true.
   */
  void SetDefaultCharacterSet(vtkDICOMCharacterSet cs);
  vtkDICOMCharacterSet GetDefaultCharacterSet() {
    return this->DefaultCharacterSet; }

  //! Override the value stored in SpecificCharacterSet.
  /*!
   *  This method can be used if the SpecificCharacterSet attribute of a
   *  file is incorrect.  It overrides the SpecificCharacterSet with the
   *  DefaultCharacterSet.
   */
  void SetOverrideCharacterSet(bool b);
  void OverrideCharacterSetOn() {
    this->SetOverrideCharacterSet(true); }
  void OverrideCharacterSetOff() {
    this->SetOverrideCharacterSet(false); }
  bool GetOverrideCharacterSet() {
    return this->OverrideCharacterSet; }
  //@}

  //@{
  //! Set a query. Only matching data will be retrieved.
  /*!
   *  This can be used to scan a file for data that matches a given
   *  query.  For more information on how matching is done, see the
   *  vtkDICOMValue::Matches() method.
   */
  void SetQuery(vtkDICOMMetaData *query);
  vtkDICOMMetaData *GetQuery() { return this->Query; }
  //@}

  //@{
  //! Set a query, using an item instead of vtkDICOMMetaData.
  /*!
   *  This can be used to scan a file for data that matches a given
   *  query.  For more information on how matching is done, see the
   *  vtkDICOMValue::Matches() method.  To clear the query, pass an
   *  empty item.
   */
  void SetQueryItem(const vtkDICOMItem& query);
  //@}

  //@{
  //! Set specific metadata groups to read (obsolete).
  /*!
   *  This method is obsolete, the SetQuery() method should be used instead.
   */
  void SetGroups(vtkUnsignedShortArray *groups);
  vtkUnsignedShortArray *GetGroups() { return this->Groups; }
  //@}

  //@{
  //! This is true only if the file matched the query.
  bool GetQueryMatched() { return this->QueryMatched; }

  //! This is true only if PixelData was found in the file.
  bool GetPixelDataFound() { return this->PixelDataFound; }

  //! Get the VL for the PixelData, will be 0xffffffff if compressed.
  unsigned int GetPixelDataVL() { return this->PixelDataVL; }
  //@}

  //@{
  //! Get the byte offset to the end of the metadata.
  /*!
   *  After the metadata has been read, the file offset
   *  will be set to the position of the pixel data.
   */
  vtkTypeInt64 GetFileOffset() { return this->FileOffset; }

  //! Get the total file length (only valid after Update).
  vtkTypeInt64 GetFileSize() { return this->FileSize; }

  //@{
  //! Set the buffer size, the default is 8192 (8k).
  /*!
   *  A larger buffer size results in fewer IO calls.  The
   *  minimum buffer size is 256 bytes.
   */
  void SetBufferSize(int size);
  int GetBufferSize() { return this->BufferSize; }
  //@}

  //@{
  //! Read the metadata from the file.
  virtual void Update();

  //! Get the error code.
  unsigned long GetErrorCode() { return this->ErrorCode; }
  //@}

protected:
  vtkDICOMParser();
  ~vtkDICOMParser() VTK_DICOM_OVERRIDE;

  //! Internal method for filling the buffer.
  /*!
   *  This is an internal method that refills the buffer
   *  by reading data from the file.  The pointers cp and
   *  ep mark the region of the buffer that has not been
   *  parsed yet.  The call to FillBuffer will move this
   *  region to the beginning of the buffer, and will then
   *  fill the remainder of the buffer with new data from
   *  the file.  The values of cp and ep will be set to the
   *  beginning and end of the buffer.
   */
  virtual bool FillBuffer(
    const unsigned char* &cp, const unsigned char* &ep);

  //! Internal method to advance the buffer to a new file position.
  /*!
   *  This will move to a new position within the file.
   */
  virtual bool SeekBuffer(
    const unsigned char* &cp, const unsigned char* &ep, vtkTypeInt64 offset);

  //! Internal method for skipping over a value.
  /*!
   *  This is for skipping over bulk data (such as PixelData).
   *  If vl is 0xffffffff, then the value will be assumed to be
   *  delimited (e.g. encapsulated pixel data).
   */
  virtual bool SkipValue(
    const unsigned char* &cp, const unsigned char* &ep, unsigned int vl);

  //! Get the bytes remaining in the file.
  virtual vtkTypeInt64 GetBytesRemaining(
    const unsigned char *cp, const unsigned char *ep);

  //! Report an error while parsing the file.
  virtual void ParseError(
    const unsigned char *cp, const unsigned char *ep, const char *message);

  //! Set the error code.
  void SetErrorCode(unsigned long e) { this->ErrorCode = e; }

  //! Read the file into the provided metadata object.
  virtual bool ReadFile(vtkDICOMMetaData *data, int idx);

  //! Read just the meta header (group 0x0002).
  bool ReadMetaHeader(
    const unsigned char* &cp, const unsigned char* &ep,
    vtkDICOMMetaData *data, int idx);

  //! Read the meta data following the meta header.
  bool ReadMetaData(
    const unsigned char* &cp, const unsigned char* &ep,
    vtkDICOMMetaData *data, int idx);

  //! Compute the file offset to the current position.
  vtkTypeInt64 GetBytesProcessed(
    const unsigned char* cp, const unsigned char* ep);

  char *FileName;
  std::string TransferSyntax;
  vtkDICOMMetaData *MetaData;
  vtkDICOMMetaData *Query;
  vtkDICOMItem *QueryItem;
  vtkUnsignedShortArray *Groups;
  vtkDICOMFile *InputFile;
  vtkTypeInt64 BytesRead;
  vtkTypeInt64 FileOffset;
  vtkTypeInt64 FileSize;
  unsigned char *Buffer;
  int BufferSize;
  int ChunkSize;
  int Index;
  unsigned int PixelDataVL;
  bool PixelDataFound;
  bool QueryMatched;
  vtkDICOMCharacterSet DefaultCharacterSet;
  bool OverrideCharacterSet;
  unsigned long ErrorCode;

  // used to share FillBuffer with internal classes
  friend class vtkDICOMParserInternalFriendship;

private:
#ifdef VTK_DICOM_DELETE
  vtkDICOMParser(const vtkDICOMParser&) VTK_DICOM_DELETE;
  void operator=(const vtkDICOMParser&) VTK_DICOM_DELETE;
#else
  vtkDICOMParser(const vtkDICOMParser&) = delete;
  void operator=(const vtkDICOMParser&) = delete;
#endif
};

#endif /* vtkDICOMParser_h */
