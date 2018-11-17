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


#ifndef SBK_QT3DLOGIC_PYTHON_H
#define SBK_QT3DLOGIC_PYTHON_H

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
#include <pyside2_qt3dcore_python.h>
#include <pyside2_qtgui_python.h>
#include <pyside2_qtcore_python.h>

// Binded library includes
#include <qframeaction.h>
#include <qlogicaspect.h>
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
#define SBK_QT3DLOGIC_IDX                                            0
#define SBK_QT3DLOGIC_QFRAMEACTION_IDX                               1
#define SBK_QT3DLOGIC_QLOGICASPECT_IDX                               2
#define SBK_Qt3DLogic_IDX_COUNT                                      3

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_Qt3DLogicTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_Qt3DLogicTypeConverters;

// Converter indices
#define SBK_QT3DLOGIC_QLIST_QOBJECTPTR_IDX                           0 // const QList<QObject* > &
#define SBK_QT3DLOGIC_QLIST_QBYTEARRAY_IDX                           1 // QList<QByteArray >
#define SBK_QT3DLOGIC_QVECTOR_QT3DCORE_QNODEPTR_IDX                  2 // QVector<Qt3DCore::QNode* >
#define SBK_QT3DLOGIC_QVECTOR_QT3DCORE_QENTITYPTR_IDX                3 // QVector<Qt3DCore::QEntity* >
#define SBK_QT3DLOGIC_QLIST_QVARIANT_IDX                             4 // QList<QVariant >
#define SBK_QT3DLOGIC_QLIST_QSTRING_IDX                              5 // QList<QString >
#define SBK_QT3DLOGIC_QMAP_QSTRING_QVARIANT_IDX                      6 // QMap<QString,QVariant >
#define SBK_Qt3DLogic_CONVERTERS_IDX_COUNT                           7

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::Qt3DLogic::QFrameAction >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DLogicTypes[SBK_QT3DLOGIC_QFRAMEACTION_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DLogic::QLogicAspect >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DLogicTypes[SBK_QT3DLOGIC_QLOGICASPECT_IDX]); }

} // namespace Shiboken

#endif // SBK_QT3DLOGIC_PYTHON_H

