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


#ifndef SBK_QTPOSITIONING_PYTHON_H
#define SBK_QTPOSITIONING_PYTHON_H

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
#include <qgeopositioninfo.h>
#include <qgeoaddress.h>
#include <qnmeapositioninfosource.h>
#include <qgeosatelliteinfo.h>
#include <qgeoareamonitorinfo.h>
#include <qgeoareamonitorsource.h>
#include <qgeopositioninfosource.h>
#include <qgeoshape.h>
#include <qgeocoordinate.h>
#include <qgeolocation.h>
#include <qgeocircle.h>
#include <qgeorectangle.h>
#include <qgeopolygon.h>
#include <qgeopositioninfosourcefactory.h>
#include <qgeopath.h>
#include <qgeosatelliteinfosource.h>
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
#define SBK_QGEOPOSITIONINFOSOURCEFACTORY_IDX                        19
#define SBK_QGEOSATELLITEINFO_IDX                                    21
#define SBK_QGEOSATELLITEINFO_ATTRIBUTE_IDX                          22
#define SBK_QGEOSATELLITEINFO_SATELLITESYSTEM_IDX                    23
#define SBK_QGEOLOCATION_IDX                                         11
#define SBK_QGEOPOSITIONINFO_IDX                                     14
#define SBK_QGEOPOSITIONINFO_ATTRIBUTE_IDX                           15
#define SBK_QGEOAREAMONITORINFO_IDX                                  3
#define SBK_QGEOSHAPE_IDX                                            26
#define SBK_QGEOSHAPE_SHAPETYPE_IDX                                  27
#define SBK_QGEOPOLYGON_IDX                                          13
#define SBK_QGEOPATH_IDX                                             12
#define SBK_QGEOCIRCLE_IDX                                           7
#define SBK_QGEORECTANGLE_IDX                                        20
#define SBK_QGEOCOORDINATE_IDX                                       8
#define SBK_QGEOCOORDINATE_COORDINATETYPE_IDX                        10
#define SBK_QGEOCOORDINATE_COORDINATEFORMAT_IDX                      9
#define SBK_QGEOADDRESS_IDX                                          2
#define SBK_QGEOSATELLITEINFOSOURCE_IDX                              24
#define SBK_QGEOSATELLITEINFOSOURCE_ERROR_IDX                        25
#define SBK_QGEOAREAMONITORSOURCE_IDX                                4
#define SBK_QGEOAREAMONITORSOURCE_ERROR_IDX                          6
#define SBK_QGEOAREAMONITORSOURCE_AREAMONITORFEATURE_IDX             5
#define SBK_QFLAGS_QGEOAREAMONITORSOURCE_AREAMONITORFEATURE__IDX     0
#define SBK_QGEOPOSITIONINFOSOURCE_IDX                               16
#define SBK_QGEOPOSITIONINFOSOURCE_ERROR_IDX                         17
#define SBK_QGEOPOSITIONINFOSOURCE_POSITIONINGMETHOD_IDX             18
#define SBK_QFLAGS_QGEOPOSITIONINFOSOURCE_POSITIONINGMETHOD__IDX     1
#define SBK_QNMEAPOSITIONINFOSOURCE_IDX                              28
#define SBK_QNMEAPOSITIONINFOSOURCE_UPDATEMODE_IDX                   29
#define SBK_QtPositioning_IDX_COUNT                                  30

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_QtPositioningTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_QtPositioningTypeConverters;

// Converter indices
#define SBK_QTPOSITIONING_QLIST_QGEOCOORDINATE_IDX                   0 // const QList<QGeoCoordinate > &
#define SBK_QTPOSITIONING_QLIST_QVARIANT_IDX                         1 // const QList<QVariant > &
#define SBK_QTPOSITIONING_QLIST_QOBJECTPTR_IDX                       2 // const QList<QObject* > &
#define SBK_QTPOSITIONING_QLIST_QBYTEARRAY_IDX                       3 // QList<QByteArray >
#define SBK_QTPOSITIONING_QLIST_QGEOSATELLITEINFO_IDX                4 // const QList<QGeoSatelliteInfo > &
#define SBK_QTPOSITIONING_QLIST_QGEOAREAMONITORINFO_IDX              5 // QList<QGeoAreaMonitorInfo >
#define SBK_QTPOSITIONING_QLIST_QSTRING_IDX                          6 // QList<QString >
#define SBK_QTPOSITIONING_QMAP_QSTRING_QVARIANT_IDX                  7 // QMap<QString,QVariant >
#define SBK_QtPositioning_CONVERTERS_IDX_COUNT                       8

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QGeoPositionInfoSourceFactory >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOPOSITIONINFOSOURCEFACTORY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoSatelliteInfo::Attribute >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOSATELLITEINFO_ATTRIBUTE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoSatelliteInfo::SatelliteSystem >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOSATELLITEINFO_SATELLITESYSTEM_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoSatelliteInfo >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOSATELLITEINFO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoLocation >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOLOCATION_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoPositionInfo::Attribute >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOPOSITIONINFO_ATTRIBUTE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoPositionInfo >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOPOSITIONINFO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoAreaMonitorInfo >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOAREAMONITORINFO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoShape::ShapeType >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOSHAPE_SHAPETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoShape >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOSHAPE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoPolygon >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOPOLYGON_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoPath >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOPATH_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoCircle >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOCIRCLE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoRectangle >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEORECTANGLE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoCoordinate::CoordinateType >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOCOORDINATE_COORDINATETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoCoordinate::CoordinateFormat >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOCOORDINATE_COORDINATEFORMAT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoCoordinate >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOCOORDINATE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoAddress >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOADDRESS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoSatelliteInfoSource::Error >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOSATELLITEINFOSOURCE_ERROR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoSatelliteInfoSource >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOSATELLITEINFOSOURCE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoAreaMonitorSource::Error >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOAREAMONITORSOURCE_ERROR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoAreaMonitorSource::AreaMonitorFeature >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOAREAMONITORSOURCE_AREAMONITORFEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoAreaMonitorSource::AreaMonitorFeature> >() { return SbkPySide2_QtPositioningTypes[SBK_QFLAGS_QGEOAREAMONITORSOURCE_AREAMONITORFEATURE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoAreaMonitorSource >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOAREAMONITORSOURCE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoPositionInfoSource::Error >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOPOSITIONINFOSOURCE_ERROR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoPositionInfoSource::PositioningMethod >() { return SbkPySide2_QtPositioningTypes[SBK_QGEOPOSITIONINFOSOURCE_POSITIONINGMETHOD_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoPositionInfoSource::PositioningMethod> >() { return SbkPySide2_QtPositioningTypes[SBK_QFLAGS_QGEOPOSITIONINFOSOURCE_POSITIONINGMETHOD__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoPositionInfoSource >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QGEOPOSITIONINFOSOURCE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QNmeaPositionInfoSource::UpdateMode >() { return SbkPySide2_QtPositioningTypes[SBK_QNMEAPOSITIONINFOSOURCE_UPDATEMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QNmeaPositionInfoSource >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtPositioningTypes[SBK_QNMEAPOSITIONINFOSOURCE_IDX]); }

} // namespace Shiboken

#endif // SBK_QTPOSITIONING_PYTHON_H

