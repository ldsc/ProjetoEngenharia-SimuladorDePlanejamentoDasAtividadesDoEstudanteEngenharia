/****************************************************************************
** Meta object code from reading C++ file 'acompanhamentodisciplina.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src-v1/PetroPlanner/acompanhamentodisciplina.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'acompanhamentodisciplina.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
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
struct qt_meta_tag_ZN24AcompanhamentoDisciplinaE_t {};
} // unnamed namespace

template <> constexpr inline auto AcompanhamentoDisciplina::qt_create_metaobjectdata<qt_meta_tag_ZN24AcompanhamentoDisciplinaE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AcompanhamentoDisciplina",
        "aoClicarEditar",
        "",
        "aoClicarSalvar",
        "adicionarTrabalho",
        "removerTrabalho",
        "salvarAlteracoes"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'aoClicarEditar'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'aoClicarSalvar'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'adicionarTrabalho'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'removerTrabalho'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'salvarAlteracoes'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AcompanhamentoDisciplina, qt_meta_tag_ZN24AcompanhamentoDisciplinaE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AcompanhamentoDisciplina::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24AcompanhamentoDisciplinaE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24AcompanhamentoDisciplinaE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24AcompanhamentoDisciplinaE_t>.metaTypes,
    nullptr
} };

void AcompanhamentoDisciplina::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AcompanhamentoDisciplina *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->aoClicarEditar(); break;
        case 1: _t->aoClicarSalvar(); break;
        case 2: _t->adicionarTrabalho(); break;
        case 3: _t->removerTrabalho(); break;
        case 4: _t->salvarAlteracoes(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *AcompanhamentoDisciplina::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AcompanhamentoDisciplina::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24AcompanhamentoDisciplinaE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AcompanhamentoDisciplina::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
