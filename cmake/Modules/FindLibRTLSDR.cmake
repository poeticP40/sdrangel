if(NOT LIBRTLSDR_FOUND)

  pkg_check_modules (LIBRTLSDR_PKG librtlsdr)
  
  find_path(LIBRTLSDR_INCLUDE_DIR 
    NAMES rtl-sdr.h
	PATHS ${RTLSDR_DIR}/include
	      ${LIBRTLSDR_PKG_INCLUDE_DIRS}
	      /usr/include
	      /usr/local/include
  )

  find_library(LIBRTLSDR_LIBRARIES 
    NAMES rtlsdr
	PATHS ${RTLSDR_DIR}/lib
	      ${LIBRTLSDR_PKG_LIBRARY_DIRS}
	      /usr/lib
	      /usr/local/lib
  )

  if(LIBRTLSDR_INCLUDE_DIR AND LIBRTLSDR_LIBRARIES)
	set(LIBRTLSDR_FOUND TRUE CACHE INTERNAL "librtlsdr found")
	message(STATUS "Found librtlsdr: ${LIBRTLSDR_INCLUDE_DIR}, ${LIBRTLSDR_LIBRARIES}")
  else(LIBRTLSDR_INCLUDE_DIR AND LIBRTLSDR_LIBRARIES)
	set(LIBRTLSDR_FOUND FALSE CACHE INTERNAL "librtlsdr found")
	message(STATUS "librtlsdr not found.")
  endif(LIBRTLSDR_INCLUDE_DIR AND LIBRTLSDR_LIBRARIES)

  mark_as_advanced(LIBRTLSDR_INCLUDE_DIR LIBRTLSDR_LIBRARIES)

endif(NOT LIBRTLSDR_FOUND)
