cmake_minimum_required(VERSION 3.16)

project(PetroPlanner VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    telainicial.ui
    acompanhamentodisciplina.ui
    EditarDisciplinasEmCurso.ui
    modulogradecompleta.ui
    quadrodehorarios.ui
    simulacaoplanejamentosem.ui
    EditarDisciplinasAprovadas.ui

    telainicial.h
    acompanhamentodisciplina.h
    EditarDisciplinasEmCurso.h
    modulogradecompleta.h
    quadrodehorarios.h
    simulacaoplanejamentosem.h
    CAluno.h
    CDisciplinas.h
    EditarDisciplinasAprovadas.h

    telainicial.cpp
    acompanhamentodisciplina.cpp
    EditarDisciplinasEmCurso.cpp
    modulogradecompleta.cpp
    quadrodehorarios.cpp
    simulacaoplanejamentosem.cpp
    CAluno.cpp
    CDisciplinas.cpp
    main.cpp
    EditarDisciplinasAprovadas.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PetroPlanner
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        modulogradecompleta.h modulogradecompleta.cpp modulogradecompleta.ui
        acompanhamentodisciplina.h acompanhamentodisciplina.cpp acompanhamentodisciplina.ui
        simulacaoplanejamentosem.h simulacaoplanejamentosem.cpp simulacaoplanejamentosem.ui
        quadrodehorarios.h quadrodehorarios.cpp quadrodehorarios.ui
        EditarDisciplinasEmCurso.h EditarDisciplinasEmCurso.cpp EditarDisciplinasEmCurso.ui
        EditarDisciplinasAprovadas.h EditarDisciplinasAprovadas.cpp EditarDisciplinasAprovadas.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PetroPlanner APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PetroPlanner SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PetroPlanner
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(PetroPlanner PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PetroPlanner)
endif()
set_target_properties(PetroPlanner PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS PetroPlanner
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PetroPlanner)
endif()
