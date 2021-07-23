set(ITKIOTIFF_LOADED 1)
set(ITKIOTIFF_ENABLE_SHARED "1")
set(ITKIOTIFF_DEPENDS "ITKIOImageBase;ITKTIFF")
set(ITKIOTIFF_PUBLIC_DEPENDS "ITKIOImageBase")
set(ITKIOTIFF_TRANSITIVE_DEPENDS "ITKIOImageBase")
set(ITKIOTIFF_PRIVATE_DEPENDS "ITKTIFF")
set(ITKIOTIFF_LIBRARIES "ITKIOTIFF")
set(ITKIOTIFF_INCLUDE_DIRS "${ITK_INSTALL_PREFIX}/include/ITK-5.2")
set(ITKIOTIFF_LIBRARY_DIRS "")
set(ITKIOTIFF_RUNTIME_LIBRARY_DIRS "${ITK_INSTALL_PREFIX}/bin")
set(ITKIOTIFF_TARGETS_FILE "")
set(ITKIOTIFF_FACTORY_NAMES "ImageIO::TIFF")
