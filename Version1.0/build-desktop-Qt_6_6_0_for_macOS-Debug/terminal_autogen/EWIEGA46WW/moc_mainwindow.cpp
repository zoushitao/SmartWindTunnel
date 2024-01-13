/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../desktop/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "openSerialPort",
    "",
    "closeSerialPort",
    "about",
    "writeData",
    "data",
    "readData",
    "handleError",
    "QSerialPort::SerialPortError",
    "error",
    "handleBytesWritten",
    "bytes",
    "handleWriteTimeout",
    "handleTerminal",
    "on_terminalWidget_destroyed",
    "on_EvenmodehorizontalSlider_sliderMoved",
    "position",
    "on_EvenmodespinBox_valueChanged",
    "arg1",
    "on_uploadButton_clicked",
    "on_actionAboutMe_triggered",
    "on_stopButton_clicked",
    "on_gust_upper_limit_slider_sliderMoved",
    "on_gust_lower_limit_slider_sliderMoved",
    "on_gust_upper_limit_spinbox_valueChanged",
    "on_gust_lower_limit_spinbox_valueChanged",
    "on_gust_period_slider_sliderMoved",
    "on_gust_period_spinbox_valueChanged",
    "on_sheer_mode_append_button_clicked",
    "on_sheer_clear_button_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[62];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[6];
    char stringdata5[10];
    char stringdata6[5];
    char stringdata7[9];
    char stringdata8[12];
    char stringdata9[29];
    char stringdata10[6];
    char stringdata11[19];
    char stringdata12[6];
    char stringdata13[19];
    char stringdata14[15];
    char stringdata15[28];
    char stringdata16[40];
    char stringdata17[9];
    char stringdata18[32];
    char stringdata19[5];
    char stringdata20[24];
    char stringdata21[27];
    char stringdata22[22];
    char stringdata23[39];
    char stringdata24[39];
    char stringdata25[41];
    char stringdata26[41];
    char stringdata27[34];
    char stringdata28[36];
    char stringdata29[36];
    char stringdata30[30];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 14),  // "openSerialPort"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 15),  // "closeSerialPort"
        QT_MOC_LITERAL(43, 5),  // "about"
        QT_MOC_LITERAL(49, 9),  // "writeData"
        QT_MOC_LITERAL(59, 4),  // "data"
        QT_MOC_LITERAL(64, 8),  // "readData"
        QT_MOC_LITERAL(73, 11),  // "handleError"
        QT_MOC_LITERAL(85, 28),  // "QSerialPort::SerialPortError"
        QT_MOC_LITERAL(114, 5),  // "error"
        QT_MOC_LITERAL(120, 18),  // "handleBytesWritten"
        QT_MOC_LITERAL(139, 5),  // "bytes"
        QT_MOC_LITERAL(145, 18),  // "handleWriteTimeout"
        QT_MOC_LITERAL(164, 14),  // "handleTerminal"
        QT_MOC_LITERAL(179, 27),  // "on_terminalWidget_destroyed"
        QT_MOC_LITERAL(207, 39),  // "on_EvenmodehorizontalSlider_s..."
        QT_MOC_LITERAL(247, 8),  // "position"
        QT_MOC_LITERAL(256, 31),  // "on_EvenmodespinBox_valueChanged"
        QT_MOC_LITERAL(288, 4),  // "arg1"
        QT_MOC_LITERAL(293, 23),  // "on_uploadButton_clicked"
        QT_MOC_LITERAL(317, 26),  // "on_actionAboutMe_triggered"
        QT_MOC_LITERAL(344, 21),  // "on_stopButton_clicked"
        QT_MOC_LITERAL(366, 38),  // "on_gust_upper_limit_slider_sl..."
        QT_MOC_LITERAL(405, 38),  // "on_gust_lower_limit_slider_sl..."
        QT_MOC_LITERAL(444, 40),  // "on_gust_upper_limit_spinbox_v..."
        QT_MOC_LITERAL(485, 40),  // "on_gust_lower_limit_spinbox_v..."
        QT_MOC_LITERAL(526, 33),  // "on_gust_period_slider_sliderM..."
        QT_MOC_LITERAL(560, 35),  // "on_gust_period_spinbox_valueC..."
        QT_MOC_LITERAL(596, 35),  // "on_sheer_mode_append_button_c..."
        QT_MOC_LITERAL(632, 29)   // "on_sheer_clear_button_clicked"
    },
    "MainWindow",
    "openSerialPort",
    "",
    "closeSerialPort",
    "about",
    "writeData",
    "data",
    "readData",
    "handleError",
    "QSerialPort::SerialPortError",
    "error",
    "handleBytesWritten",
    "bytes",
    "handleWriteTimeout",
    "handleTerminal",
    "on_terminalWidget_destroyed",
    "on_EvenmodehorizontalSlider_sliderMoved",
    "position",
    "on_EvenmodespinBox_valueChanged",
    "arg1",
    "on_uploadButton_clicked",
    "on_actionAboutMe_triggered",
    "on_stopButton_clicked",
    "on_gust_upper_limit_slider_sliderMoved",
    "on_gust_lower_limit_slider_sliderMoved",
    "on_gust_upper_limit_spinbox_valueChanged",
    "on_gust_lower_limit_spinbox_valueChanged",
    "on_gust_period_slider_sliderMoved",
    "on_gust_period_spinbox_valueChanged",
    "on_sheer_mode_append_button_clicked",
    "on_sheer_clear_button_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  152,    2, 0x08,    1 /* Private */,
       3,    0,  153,    2, 0x08,    2 /* Private */,
       4,    0,  154,    2, 0x08,    3 /* Private */,
       5,    1,  155,    2, 0x08,    4 /* Private */,
       7,    0,  158,    2, 0x08,    6 /* Private */,
       8,    1,  159,    2, 0x08,    7 /* Private */,
      11,    1,  162,    2, 0x08,    9 /* Private */,
      13,    0,  165,    2, 0x08,   11 /* Private */,
      14,    0,  166,    2, 0x08,   12 /* Private */,
      15,    0,  167,    2, 0x08,   13 /* Private */,
      16,    1,  168,    2, 0x08,   14 /* Private */,
      18,    1,  171,    2, 0x08,   16 /* Private */,
      20,    0,  174,    2, 0x08,   18 /* Private */,
      21,    0,  175,    2, 0x08,   19 /* Private */,
      22,    0,  176,    2, 0x08,   20 /* Private */,
      23,    1,  177,    2, 0x08,   21 /* Private */,
      24,    1,  180,    2, 0x08,   23 /* Private */,
      25,    1,  183,    2, 0x08,   25 /* Private */,
      26,    1,  186,    2, 0x08,   27 /* Private */,
      27,    1,  189,    2, 0x08,   29 /* Private */,
      28,    1,  192,    2, 0x08,   31 /* Private */,
      29,    0,  195,    2, 0x08,   33 /* Private */,
      30,    0,  196,    2, 0x08,   34 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'openSerialPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeSerialPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'about'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'readData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSerialPort::SerialPortError, std::false_type>,
        // method 'handleBytesWritten'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'handleWriteTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleTerminal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_terminalWidget_destroyed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_EvenmodehorizontalSlider_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_EvenmodespinBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_uploadButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAboutMe_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stopButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_gust_upper_limit_slider_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_gust_lower_limit_slider_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_gust_upper_limit_spinbox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_gust_lower_limit_spinbox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_gust_period_slider_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_gust_period_spinbox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_sheer_mode_append_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sheer_clear_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openSerialPort(); break;
        case 1: _t->closeSerialPort(); break;
        case 2: _t->about(); break;
        case 3: _t->writeData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 4: _t->readData(); break;
        case 5: _t->handleError((*reinterpret_cast< std::add_pointer_t<QSerialPort::SerialPortError>>(_a[1]))); break;
        case 6: _t->handleBytesWritten((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 7: _t->handleWriteTimeout(); break;
        case 8: _t->handleTerminal(); break;
        case 9: _t->on_terminalWidget_destroyed(); break;
        case 10: _t->on_EvenmodehorizontalSlider_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_EvenmodespinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->on_uploadButton_clicked(); break;
        case 13: _t->on_actionAboutMe_triggered(); break;
        case 14: _t->on_stopButton_clicked(); break;
        case 15: _t->on_gust_upper_limit_slider_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_gust_lower_limit_slider_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_gust_upper_limit_spinbox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_gust_lower_limit_spinbox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_gust_period_slider_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->on_gust_period_spinbox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_sheer_mode_append_button_clicked(); break;
        case 22: _t->on_sheer_clear_button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP
