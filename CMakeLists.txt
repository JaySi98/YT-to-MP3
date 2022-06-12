############################################################
# Basic
############################################################
# min wersja cmake
cmake_minimum_required(VERSION 3.16.3)

# nazwa projektu i wersja
project(YTtoMP3 VERSION 1.0)

set(SOURCES
    Src/Main.cpp
    Src/CommandParser.cpp
)

set(HEADERS
    Include/Config.h.in
    Include/CommandParser.h
)

# wskazanie maina
add_executable(${PROJECT_NAME} ${SOURCES})

# dodanie pliku konfiguracyjnego projektu
configure_file(Include/Config.h.in Include/Config.h)


############################################################
# External Libraries
############################################################
option(ADD_BOOST   "Include boost libs in project"   ON)
option(ADD_QT_CLI  "Include QT libs in project"   ON)

if(ADD_BOOST)
    set(Boost_FIND_REQUIRED TRUE)
    set(Boost_FIND_QUIETLY TRUE)
    set(Boost_DEBUG FALSE)
    set(Boost_USE_MULTITHREADED TRUE)
    set(Boost_USE_STATIC_LIBS TRUE)
    #set(Boost_ADDITIONAL_VERSIONS "1.67" "1.67.0")

    find_package(Boost COMPONENTS regex)

    list(APPEND EXTRA_INCLUDES ${Boost_INCLUDE_DIRS})
    list(APPEND EXTRA_LINKS    ${Boost_LIBRARIES})    
endif()

if(ADD_QT_CLI)
    # set(CMAKE_AUTOUIC ON)
    # set(CMAKE_AUTOMOC ON)
    # set(CMAKE_AUTORCC ON)

    # set(CMAKE_CXX_STANDARD 11)
    # set(CMAKE_CXX_STANDARD_REQUIRED ON)

    set(CMAKE_PREFIX_PATH "/home/jakub/ExternalFiles/Qt/6.3.0/gcc_64")
    find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Concurrent Network REQUIRED)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Concurrent Network REQUIRED)

    # target_link_libraries(Thread Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Concurrent Qt${QT_VERSION_MAJOR}::Network)
    list(APPEND EXTRA_LINKS Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Concurrent Qt${QT_VERSION_MAJOR}::Network)    
endif()

############################################################
# Target 
############################################################
# dodanie podfolderów do projektu
add_subdirectory(Lib)
add_subdirectory(Tests)

# wskazanie folderów "include"(plików nagłówkowych bibliotek)
target_include_directories(${PROJECT_NAME} 
    PRIVATE ${PROJECT_BINARY_DIR}
    PRIVATE ${EXTRA_INCLUDES}
    PRIVATE ${PROJECT_SOURCE_DIR}/Include
)

# wskazanie folderów "src"(plików źródłowych bibliotek)
target_link_directories(${PROJECT_NAME}
    PRIVATE ${EXTRA_LIBS}
)

# linkowanie blibliotek
target_link_libraries(${PROJECT_NAME} 
    ${EXTRA_LINKS}
)

############################################################
# Install
############################################################
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES   ${HEADERS}      DESTINATION include)