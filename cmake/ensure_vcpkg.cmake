function (ensure_vcpkg VCPKG_ROOT)
    if(WIN32)
        set(VCPKG_EXECUTABLE "${VCPKG_ROOT}/vcpkg.exe")
        set(VCPKG_BOOTSTRAP_SCRIPT "${VCPKG_ROOT}/bootstrap-vcpkg.bat")
    else()
        message(FATAL_ERROR "Project only configured for Windows! Exiting...")
    endif()

    # Run the bootstrap script if the executable doesn't exist
    if(NOT EXISTS ${VCPKG_EXECUTABLE})
        message(STATUS "Running vcpkg bootstrap script")
        execute_process(COMMAND ${VCPKG_BOOTSTRAP_SCRIPT}
                        WORKING_DIRECTORY ${VCPKG_ROOT}
                        RESULT_VARIABLE VCPKG_BOOTSTRAP_RESULT)
        if(NOT VCPKG_BOOTSTRAP_RESULT EQUAL 0)
            message(FATAL_ERROR "vcpkg bootstrap failed, exiting...")
        else()
            message(STATUS "vcpkg bootstrap complete")
        endif()
    endif()
endfunction()