/****************************************************************************
** Meta object code from reading C++ file 'bulldog_pad.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/rviz_bulldog_commander/src/bulldog_pad.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bulldog_pad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz_bulldog_commander__BulldogPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      38,   37,   37,   37, 0x08,
      58,   37,   37,   37, 0x08,
      80,   37,   37,   37, 0x08,
     107,   37,   37,   37, 0x08,
     134,   37,   37,   37, 0x08,
     156,   37,   37,   37, 0x08,
     183,   37,   37,   37, 0x08,
     203,   37,   37,   37, 0x08,
     228,   37,   37,   37, 0x08,
     249,   37,   37,   37, 0x08,
     270,   37,   37,   37, 0x08,
     296,   37,   37,   37, 0x08,
     317,   37,   37,   37, 0x08,
     349,   37,   37,   37, 0x08,
     383,   37,   37,   37, 0x08,
     418,   37,   37,   37, 0x08,
     451,   37,   37,   37, 0x08,
     493,  485,   37,   37, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz_bulldog_commander__BulldogPanel[] = {
    "rviz_bulldog_commander::BulldogPanel\0"
    "\0button_auto_click()\0button_detect_click()\0"
    "button_navigation1_click()\0"
    "button_navigation2_click()\0"
    "button_arrive_click()\0button_arrive_plan_click()\0"
    "button_pick_click()\0button_pick_plan_click()\0"
    "button_reset_click()\0button_place_click()\0"
    "button_place_plan_click()\0"
    "button_power_click()\0"
    "button_gripper_activate_click()\0"
    "button_left_gripper_close_click()\0"
    "button_right_gripper_close_click()\0"
    "button_left_gripper_open_click()\0"
    "button_right_gripper_open_click()\0"
    "pub,str\0pub_gripper(ros::Publisher*,std::string)\0"
};

void rviz_bulldog_commander::BulldogPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BulldogPanel *_t = static_cast<BulldogPanel *>(_o);
        switch (_id) {
        case 0: _t->button_auto_click(); break;
        case 1: _t->button_detect_click(); break;
        case 2: _t->button_navigation1_click(); break;
        case 3: _t->button_navigation2_click(); break;
        case 4: _t->button_arrive_click(); break;
        case 5: _t->button_arrive_plan_click(); break;
        case 6: _t->button_pick_click(); break;
        case 7: _t->button_pick_plan_click(); break;
        case 8: _t->button_reset_click(); break;
        case 9: _t->button_place_click(); break;
        case 10: _t->button_place_plan_click(); break;
        case 11: _t->button_power_click(); break;
        case 12: _t->button_gripper_activate_click(); break;
        case 13: _t->button_left_gripper_close_click(); break;
        case 14: _t->button_right_gripper_close_click(); break;
        case 15: _t->button_left_gripper_open_click(); break;
        case 16: _t->button_right_gripper_open_click(); break;
        case 17: _t->pub_gripper((*reinterpret_cast< ros::Publisher*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz_bulldog_commander::BulldogPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz_bulldog_commander::BulldogPanel::staticMetaObject = {
    { &rviz::Panel::staticMetaObject, qt_meta_stringdata_rviz_bulldog_commander__BulldogPanel,
      qt_meta_data_rviz_bulldog_commander__BulldogPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz_bulldog_commander::BulldogPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz_bulldog_commander::BulldogPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz_bulldog_commander::BulldogPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz_bulldog_commander__BulldogPanel))
        return static_cast<void*>(const_cast< BulldogPanel*>(this));
    typedef rviz::Panel QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int rviz_bulldog_commander::BulldogPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef rviz::Panel QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
