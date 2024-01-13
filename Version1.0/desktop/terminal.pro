QT += widgets serialport
requires(qtConfig(combobox))

TARGET = terminal
TEMPLATE = app

SOURCES += \
    aboutme.cpp \
    debug.cpp \
    main.cpp \
    mainwindow.cpp \
    monitor.cpp \
    panel.cpp \
    settingsdialog.cpp \
    console.cpp

HEADERS += \
    aboutme.h \
    debug.h \
    mainwindow.h \
    monitor.h \
    panel.h \
    settingsdialog.h \
    console.h

FORMS += \
    aboutme.ui \
    debug.ui \
    mainwindow.ui \
    monitor.ui \
    settingsdialog.ui

RESOURCES += \
    terminal.qrc
    images

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target
