/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MusicPlayer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[434];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 28), // "on_actionOpen_File_triggered"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 29), // "on_actionOpenFolder_triggered"
QT_MOC_LITERAL(71, 37), // "on_start_pauseMusicPushButton..."
QT_MOC_LITERAL(109, 30), // "on_nextMusicPushButton_clicked"
QT_MOC_LITERAL(140, 36), // "on_musicListWidget_currentRow..."
QT_MOC_LITERAL(177, 10), // "currentRow"
QT_MOC_LITERAL(188, 34), // "on_previousMusicPushButton_cl..."
QT_MOC_LITERAL(223, 38), // "on_volumeHorizontalSlider_val..."
QT_MOC_LITERAL(262, 5), // "value"
QT_MOC_LITERAL(268, 18), // "on_durationChanged"
QT_MOC_LITERAL(287, 8), // "duration"
QT_MOC_LITERAL(296, 18), // "on_positionChanged"
QT_MOC_LITERAL(315, 8), // "position"
QT_MOC_LITERAL(324, 27), // "on_actionAdd_File_triggered"
QT_MOC_LITERAL(352, 29), // "on_actionAdd_Folder_triggered"
QT_MOC_LITERAL(382, 27), // "on_volumePushButton_clicked"
QT_MOC_LITERAL(410, 23) // "on_actionExit_triggered"

    },
    "MainWindow\0on_actionOpen_File_triggered\0"
    "\0on_actionOpenFolder_triggered\0"
    "on_start_pauseMusicPushButton_clicked\0"
    "on_nextMusicPushButton_clicked\0"
    "on_musicListWidget_currentRowChanged\0"
    "currentRow\0on_previousMusicPushButton_clicked\0"
    "on_volumeHorizontalSlider_valueChanged\0"
    "value\0on_durationChanged\0duration\0"
    "on_positionChanged\0position\0"
    "on_actionAdd_File_triggered\0"
    "on_actionAdd_Folder_triggered\0"
    "on_volumePushButton_clicked\0"
    "on_actionExit_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    0,   95,    2, 0x08,    4 /* Private */,
       6,    1,   96,    2, 0x08,    5 /* Private */,
       8,    0,   99,    2, 0x08,    7 /* Private */,
       9,    1,  100,    2, 0x08,    8 /* Private */,
      11,    1,  103,    2, 0x08,   10 /* Private */,
      13,    1,  106,    2, 0x08,   12 /* Private */,
      15,    0,  109,    2, 0x08,   14 /* Private */,
      16,    0,  110,    2, 0x08,   15 /* Private */,
      17,    0,  111,    2, 0x08,   16 /* Private */,
      18,    0,  112,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void, QMetaType::LongLong,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionOpen_File_triggered(); break;
        case 1: _t->on_actionOpenFolder_triggered(); break;
        case 2: _t->on_start_pauseMusicPushButton_clicked(); break;
        case 3: _t->on_nextMusicPushButton_clicked(); break;
        case 4: _t->on_musicListWidget_currentRowChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_previousMusicPushButton_clicked(); break;
        case 6: _t->on_volumeHorizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_durationChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 8: _t->on_positionChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 9: _t->on_actionAdd_File_triggered(); break;
        case 10: _t->on_actionAdd_Folder_triggered(); break;
        case 11: _t->on_volumePushButton_clicked(); break;
        case 12: _t->on_actionExit_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
