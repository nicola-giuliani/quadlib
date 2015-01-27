#----------------------------------------------------------------------------
#Doxygen documentation
#----------------------------------------------------------------------------
configure_file(${PROJECT_SOURCE_DIR}/cmake/Doxyfile ${PROJECT_BINARY_DIR})
INCLUDE( FindDoxygen )
IF (DOXYGEN_EXECUTABLE)
	MESSAGE( STATUS "Doxygen found")
	ADD_CUSTOM_TARGET(doc ALL
		COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile 
		VERBATIM)
ENDIF(DOXYGEN_EXECUTABLE)
