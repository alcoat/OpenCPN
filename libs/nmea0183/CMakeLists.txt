cmake_minimum_required(VERSION 3.10.0)

if (TARGET ocpn::nmea0183)
    return ()
endif ()

SET(SRC
    src/LatLong.hpp
    src/latlong.cpp
    src/long.cpp
    src/nmea0183.cpp
    src/nmea0183.hpp
    src/Response.hpp
    src/response.cpp
    src/RMB.hpp
    src/rmb.cpp
    src/Sentence.hpp
    src/sentence.cpp
    src/talkerid.cpp
    src/RMC.HPP
    src/rmc.cpp
    src/hexvalue.cpp
    src/lat.cpp
    src/expid.cpp
    src/wpl.hpp
    src/wpl.cpp
    src/rte.hpp
    src/rte.cpp
    src/hdt.hpp
    src/hdt.cpp
    src/hdg.hpp
    src/hdg.cpp
    src/hdm.hpp
    src/hdm.cpp
    src/gll.hpp
    src/gll.cpp
    src/vtg.hpp
    src/vtg.cpp
    src/gga.hpp
    src/gga.cpp
    src/gsv.hpp
    src/gsv.cpp
    src/GPwpl.cpp
    src/GPwpl.hpp
    src/apb.cpp
    src/apb.hpp
    src/xte.cpp
    src/xte.hpp
    src/mwd.cpp
    src/mwd.hpp
    src/mwv.cpp
    src/mwv.hpp

)
if (NOT wxWidgets_INCLUDE_DIRS)
    include(SimpleWxConfig)
    SimpleWxConfig()
endif ()

add_library(NMEA0183 STATIC ${SRC})
add_library(ocpn::nmea0183 ALIAS NMEA0183)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang|GNU")  # Apple is AppleClang
  target_compile_options(NMEA0183 PRIVATE -fvisibility=default -fPIC)
endif ()

target_include_directories(NMEA0183 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_include_directories(NMEA0183 PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(NMEA0183 PRIVATE ${wxWidgets_LIBRARIES})
