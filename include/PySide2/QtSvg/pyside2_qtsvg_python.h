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


#ifndef SBK_QTSVG_PYTHON_H
#define SBK_QTSVG_PYTHON_H

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
#include <pyside2_qtwidgets_python.h>
#include <pyside2_qtgui_python.h>
#include <pyside2_qtcore_python.h>

// Binded library includes
#include <qsvggenerator.h>
#include <qgraphicssvgitem.h>
#include <qsvgwidget.h>
#include <qsvgrenderer.h>
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
#define SBK_QSVGGENERATOR_IDX                                        1
#define SBK_QGRAPHICSSVGITEM_IDX                                     0
#define SBK_QSVGRENDERER_IDX                                         2
#define SBK_QSVGWIDGET_IDX                                           3
#define SBK_QtSvg_IDX_COUNT                                          4

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_QtSvgTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_QtSvgTypeConverters;

// Converter indices
#define SBK_QTSVG_QLIST_QGRAPHICSITEMPTR_IDX                         0 // QList<QGraphicsItem* >
#define SBK_QTSVG_QLIST_QGRAPHICSTRANSFORMPTR_IDX                    1 // const QList<QGraphicsTransform* > &
#define SBK_QTSVG_QLIST_QOBJECTPTR_IDX                               2 // const QList<QObject* > &
#define SBK_QTSVG_QLIST_QBYTEARRAY_IDX                               3 // QList<QByteArray >
#define SBK_QTSVG_QLIST_QACTIONPTR_IDX                               4 // QList<QAction* >
#define SBK_QTSVG_QLIST_QVARIANT_IDX                                 5 // QList<QVariant >
#define SBK_QTSVG_QLIST_QSTRING_IDX                                  6 // QList<QString >
#define SBK_QTSVG_QMAP_QSTRING_QVARIANT_IDX                          7 // QMap<QString,QVariant >
#define SBK_QtSvg_CONVERTERS_IDX_COUNT                               8

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QSvgGenerator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSvgTypes[SBK_QSVGGENERATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGraphicsSvgItem >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSvgTypes[SBK_QGRAPHICSSVGITEM_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSvgRenderer >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSvgTypes[SBK_QSVGRENDERER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSvgWidget >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSvgTypes[SBK_QSVGWIDGET_IDX]); }

} // namespace Shiboken

#endif // SBK_QTSVG_PYTHON_H

