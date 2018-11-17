/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt for Python.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef SBK_QTSCXML_PYTHON_H
#define SBK_QTSCXML_PYTHON_H

//workaround to access protected functions
#define protected public

#include <sbkpython.h>
#include <sbkconverter.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

#include <pysidesignal.h>
// Module Includes
#include <pyside2_qtcore_python.h>

// Binded library includes
#include <qscxmlinvokableservice.h>
#include <qscxmlevent.h>
#include <qscxmltabledata.h>
#include <qscxmlcompiler.h>
#include <qscxmlexecutablecontent.h>
#include <qscxmlerror.h>
#include <qscxmlstatemachine.h>
// Conversion Includes - Primitive Types
#include <qabstractitemmodel.h>
#include <QString>
#include <signalmanager.h>
#include <QStringList>

// Conversion Includes - Container Types
#include <QStack>
#include <QList>
#include <QMap>
#include <pysideqflags.h>
#include <QPair>
#include <QQueue>
#include <QMultiMap>
#include <QSet>
#include <QLinkedList>
#include <QVector>

// Type indices
#define SBK_QSCXMLEXECUTABLECONTENT_IDX                              6
#define SBK_QSCXMLEXECUTABLECONTENT_INVOKEINFO_IDX                   10
#define SBK_QSCXMLEXECUTABLECONTENT_PARAMETERINFO_IDX                11
#define SBK_QSCXMLEXECUTABLECONTENT_FOREACHINFO_IDX                  9
#define SBK_QSCXMLEXECUTABLECONTENT_ASSIGNMENTINFO_IDX               7
#define SBK_QSCXMLEXECUTABLECONTENT_EVALUATORINFO_IDX                8
#define SBK_QSCXMLTABLEDATA_IDX                                      16
#define SBK_QSCXMLEVENT_IDX                                          4
#define SBK_QSCXMLEVENT_EVENTTYPE_IDX                                5
#define SBK_QSCXMLCOMPILER_IDX                                       0
#define SBK_QSCXMLCOMPILER_LOADER_IDX                                1
#define SBK_QSCXMLERROR_IDX                                          3
#define SBK_QSCXMLSTATEMACHINE_IDX                                   14
#define SBK_QSCXMLINVOKABLESERVICEFACTORY_IDX                        13
#define SBK_QSCXMLDYNAMICSCXMLSERVICEFACTORY_IDX                     2
#define SBK_QSCXMLSTATICSCXMLSERVICEFACTORY_IDX                      15
#define SBK_QSCXMLINVOKABLESERVICE_IDX                               12
#define SBK_QtScxml_IDX_COUNT                                        17

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_QtScxmlTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_QtScxmlTypeConverters;

// Converter indices
#define SBK_QTSCXML_QVECTOR_QSCXMLERROR_IDX                          0 // QVector<QScxmlError >
#define SBK_QTSCXML_QLIST_QOBJECTPTR_IDX                             1 // const QList<QObject* > &
#define SBK_QTSCXML_QLIST_QBYTEARRAY_IDX                             2 // QList<QByteArray >
#define SBK_QTSCXML_QVECTOR_QSCXMLINVOKABLESERVICEPTR_IDX            3 // QVector<QScxmlInvokableService* >
#define SBK_QTSCXML_QVECTOR_INT_IDX                                  4 // const QVector<int > &
#define SBK_QTSCXML_QVECTOR_QSCXMLEXECUTABLECONTENT_PARAMETERINFO_IDX 5 // const QVector<QScxmlExecutableContent::ParameterInfo > &
#define SBK_QTSCXML_QLIST_QVARIANT_IDX                               6 // QList<QVariant >
#define SBK_QTSCXML_QLIST_QSTRING_IDX                                7 // QList<QString >
#define SBK_QTSCXML_QMAP_QSTRING_QVARIANT_IDX                        8 // QMap<QString,QVariant >
#define SBK_QtScxml_CONVERTERS_IDX_COUNT                             9

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QScxmlExecutableContent::InvokeInfo >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLEXECUTABLECONTENT_INVOKEINFO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlExecutableContent::ParameterInfo >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLEXECUTABLECONTENT_PARAMETERINFO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlExecutableContent::ForeachInfo >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLEXECUTABLECONTENT_FOREACHINFO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlExecutableContent::AssignmentInfo >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLEXECUTABLECONTENT_ASSIGNMENTINFO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlExecutableContent::EvaluatorInfo >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLEXECUTABLECONTENT_EVALUATORINFO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlTableData >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLTABLEDATA_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlEvent::EventType >() { return SbkPySide2_QtScxmlTypes[SBK_QSCXMLEVENT_EVENTTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QScxmlEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlCompiler >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLCOMPILER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlCompiler::Loader >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLCOMPILER_LOADER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlError >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLERROR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlStateMachine >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLSTATEMACHINE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlInvokableServiceFactory >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLINVOKABLESERVICEFACTORY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlDynamicScxmlServiceFactory >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLDYNAMICSCXMLSERVICEFACTORY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlStaticScxmlServiceFactory >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLSTATICSCXMLSERVICEFACTORY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScxmlInvokableService >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtScxmlTypes[SBK_QSCXMLINVOKABLESERVICE_IDX]); }

} // namespace Shiboken

#endif // SBK_QTSCXML_PYTHON_H

