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


#ifndef SBK_QT3DCORE_PYTHON_H
#define SBK_QT3DCORE_PYTHON_H

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
#include <pyside2_qtgui_python.h>
#include <pyside2_qtcore_python.h>

// Binded library includes
#include <qarmature.h>
#include <qpropertyupdatedchange.h>
#include <qstaticpropertyvalueaddedchangebase.h>
#include <qnodeid.h>
#include <qnodedestroyedchange.h>
#include <Qt3DCore/qtransform.h>
#include <qjoint.h>
#include <qcomponentremovedchange.h>
#include <qpropertyvalueaddedchange.h>
#include <qpropertyvalueaddedchangebase.h>
#include <qstaticpropertyupdatedchangebase.h>
#include <qstaticpropertyvalueremovedchangebase.h>
#include <qpropertyvalueremovedchangebase.h>
#include <qnode.h>
#include <qnodecommand.h>
#include <qentity.h>
#include <qpropertyupdatedchangebase.h>
#include <qabstractaspect.h>
#include <qnodecreatedchange.h>
#include <qpropertyvalueremovedchange.h>
#include <qcomponentaddedchange.h>
#include <qbackendnode.h>
#include <qpropertynodeaddedchange.h>
#include <qcomponent.h>
#include <qdynamicpropertyupdatedchange.h>
#include <qskeleton.h>
#include <qpropertynoderemovedchange.h>
#include <qscenechange.h>
#include <qaspectjob.h>
#include <qaspectengine.h>
#include <qabstractskeleton.h>
#include <qskeletonloader.h>
// Conversion Includes - Primitive Types
#include <QStringList>
#include <QString>
#include <signalmanager.h>
#include <qabstractitemmodel.h>

// Conversion Includes - Container Types
#include <QSet>
#include <QList>
#include <QMultiMap>
#include <QMap>
#include <QLinkedList>
#include <QStack>
#include <QVector>
#include <QQueue>
#include <QPair>
#include <pysideqflags.h>

// Type indices
#define SBK_QT3DCORE_IDX                                             2
#define SBK_QT3DCORE_CHANGEFLAG_IDX                                  3
#define SBK_QFLAGS_QT3DCORE_CHANGEFLAG__IDX                          0
#define SBK_QT3DCORE_QBACKENDNODE_IDX                                9
#define SBK_QT3DCORE_QBACKENDNODE_MODE_IDX                           10
#define SBK_QT3DCORE_QASPECTJOB_IDX                                  8
#define SBK_QT3DCORE_QNODEIDTYPEPAIR_IDX                             23
#define SBK_QT3DCORE_QSCENECHANGE_IDX                                32
#define SBK_QT3DCORE_QSCENECHANGE_DELIVERYFLAG_IDX                   33
#define SBK_QFLAGS_QT3DCORE_QSCENECHANGE_DELIVERYFLAG__IDX           1
#define SBK_QT3DCORE_QPROPERTYUPDATEDCHANGEBASE_IDX                  27
#define SBK_QT3DCORE_QSTATICPROPERTYUPDATEDCHANGEBASE_IDX            37
#define SBK_QT3DCORE_QPROPERTYUPDATEDCHANGE_IDX                      26
#define SBK_QT3DCORE_QDYNAMICPROPERTYUPDATEDCHANGE_IDX               14
#define SBK_QT3DCORE_QCOMPONENTREMOVEDCHANGE_IDX                     13
#define SBK_QT3DCORE_QCOMPONENTADDEDCHANGE_IDX                       12
#define SBK_QT3DCORE_QPROPERTYVALUEREMOVEDCHANGEBASE_IDX             31
#define SBK_QT3DCORE_QSTATICPROPERTYVALUEREMOVEDCHANGEBASE_IDX       39
#define SBK_QT3DCORE_QPROPERTYVALUEREMOVEDCHANGE_IDX                 30
#define SBK_QT3DCORE_QPROPERTYNODEREMOVEDCHANGE_IDX                  25
#define SBK_QT3DCORE_QNODECOMMAND_IDX                                19
#define SBK_QT3DCORE_QPROPERTYVALUEADDEDCHANGEBASE_IDX               29
#define SBK_QT3DCORE_QSTATICPROPERTYVALUEADDEDCHANGEBASE_IDX         38
#define SBK_QT3DCORE_QPROPERTYVALUEADDEDCHANGE_IDX                   28
#define SBK_QT3DCORE_QPROPERTYNODEADDEDCHANGE_IDX                    24
#define SBK_QT3DCORE_QNODECREATEDCHANGEBASE_IDX                      20
#define SBK_QT3DCORE_QNODEDESTROYEDCHANGE_IDX                        21
#define SBK_QT3DCORE_QNODEID_IDX                                     22
#define SBK_QT3DCORE_QASPECTENGINE_IDX                               7
#define SBK_QT3DCORE_QNODE_IDX                                       17
#define SBK_QT3DCORE_QNODE_PROPERTYTRACKINGMODE_IDX                  18
#define SBK_QT3DCORE_QCOMPONENT_IDX                                  11
#define SBK_QT3DCORE_QTRANSFORM_IDX                                  40
#define SBK_QT3DCORE_QARMATURE_IDX                                   6
#define SBK_QT3DCORE_QABSTRACTSKELETON_IDX                           5
#define SBK_QT3DCORE_QSKELETONLOADER_IDX                             35
#define SBK_QT3DCORE_QSKELETONLOADER_STATUS_IDX                      36
#define SBK_QT3DCORE_QSKELETON_IDX                                   34
#define SBK_QT3DCORE_QJOINT_IDX                                      16
#define SBK_QT3DCORE_QENTITY_IDX                                     15
#define SBK_QT3DCORE_QABSTRACTASPECT_IDX                             4
#define SBK_Qt3DCore_IDX_COUNT                                       41

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_Qt3DCoreTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_Qt3DCoreTypeConverters;

// Converter indices
#define SBK_QT3DCORE_QVECTOR_QT3DCORE_QABSTRACTASPECTPTR_IDX         0 // QVector<Qt3DCore::QAbstractAspect* >
#define SBK_QT3DCORE_QLIST_QOBJECTPTR_IDX                            1 // const QList<QObject* > &
#define SBK_QT3DCORE_QLIST_QBYTEARRAY_IDX                            2 // QList<QByteArray >
#define SBK_QT3DCORE_QVECTOR_QT3DCORE_QNODEPTR_IDX                   3 // QVector<Qt3DCore::QNode* >
#define SBK_QT3DCORE_QVECTOR_QT3DCORE_QENTITYPTR_IDX                 4 // QVector<Qt3DCore::QEntity* >
#define SBK_QT3DCORE_QVECTOR_QT3DCORE_QJOINTPTR_IDX                  5 // QVector<Qt3DCore::QJoint* >
#define SBK_QT3DCORE_QVECTOR_QT3DCORE_QCOMPONENTPTR_IDX              6 // QVector<Qt3DCore::QComponent* >
#define SBK_QT3DCORE_QVECTOR_QT3DCORE_QNODEIDTYPEPAIR_IDX            7 // const QVector<Qt3DCore::QNodeIdTypePair > &
#define SBK_QT3DCORE_QLIST_QVARIANT_IDX                              8 // QList<QVariant >
#define SBK_QT3DCORE_QLIST_QSTRING_IDX                               9 // QList<QString >
#define SBK_QT3DCORE_QMAP_QSTRING_QVARIANT_IDX                       10 // QMap<QString,QVariant >
#define SBK_Qt3DCore_CONVERTERS_IDX_COUNT                            11

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::Qt3DCore::ChangeFlag >() { return SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_CHANGEFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<Qt3DCore::ChangeFlag> >() { return SbkPySide2_Qt3DCoreTypes[SBK_QFLAGS_QT3DCORE_CHANGEFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QBackendNode::Mode >() { return SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QBACKENDNODE_MODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QBackendNode >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QBACKENDNODE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QAspectJob >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QASPECTJOB_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QNodeIdTypePair >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QNODEIDTYPEPAIR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QSceneChange::DeliveryFlag >() { return SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QSCENECHANGE_DELIVERYFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<Qt3DCore::QSceneChange::DeliveryFlag> >() { return SbkPySide2_Qt3DCoreTypes[SBK_QFLAGS_QT3DCORE_QSCENECHANGE_DELIVERYFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QSceneChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QSCENECHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QPropertyUpdatedChangeBase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QPROPERTYUPDATEDCHANGEBASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QStaticPropertyUpdatedChangeBase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QSTATICPROPERTYUPDATEDCHANGEBASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QPropertyUpdatedChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QPROPERTYUPDATEDCHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QDynamicPropertyUpdatedChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QDYNAMICPROPERTYUPDATEDCHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QComponentRemovedChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QCOMPONENTREMOVEDCHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QComponentAddedChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QCOMPONENTADDEDCHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QPropertyValueRemovedChangeBase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QPROPERTYVALUEREMOVEDCHANGEBASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QStaticPropertyValueRemovedChangeBase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QSTATICPROPERTYVALUEREMOVEDCHANGEBASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QPropertyValueRemovedChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QPROPERTYVALUEREMOVEDCHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QPropertyNodeRemovedChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QPROPERTYNODEREMOVEDCHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QNodeCommand >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QNODECOMMAND_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QPropertyValueAddedChangeBase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QPROPERTYVALUEADDEDCHANGEBASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QStaticPropertyValueAddedChangeBase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QSTATICPROPERTYVALUEADDEDCHANGEBASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QPropertyValueAddedChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QPROPERTYVALUEADDEDCHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QPropertyNodeAddedChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QPROPERTYNODEADDEDCHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QNodeCreatedChangeBase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QNODECREATEDCHANGEBASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QNodeDestroyedChange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QNODEDESTROYEDCHANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QNodeId >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QNODEID_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QAspectEngine >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QASPECTENGINE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QNode::PropertyTrackingMode >() { return SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QNODE_PROPERTYTRACKINGMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QNode >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QNODE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QComponent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QCOMPONENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QTransform >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QTRANSFORM_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QArmature >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QARMATURE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QAbstractSkeleton >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QABSTRACTSKELETON_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QSkeletonLoader::Status >() { return SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QSKELETONLOADER_STATUS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QSkeletonLoader >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QSKELETONLOADER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QSkeleton >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QSKELETON_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QJoint >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QJOINT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QEntity >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QENTITY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DCore::QAbstractAspect >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DCoreTypes[SBK_QT3DCORE_QABSTRACTASPECT_IDX]); }

} // namespace Shiboken

#endif // SBK_QT3DCORE_PYTHON_H

