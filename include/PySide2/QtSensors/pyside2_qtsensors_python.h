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


#ifndef SBK_QTSENSORS_PYTHON_H
#define SBK_QTSENSORS_PYTHON_H

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
#include <qtiltsensor.h>
#include <qgyroscope.h>
#include <qorientationsensor.h>
#include <qaltimeter.h>
#include <qmagnetometer.h>
#include <qrotationsensor.h>
#include <qsensorplugin.h>
#include <qcompass.h>
#include <qsensorbackend.h>
#include <qproximitysensor.h>
#include <qsensormanager.h>
#include <qsensorgesturemanager.h>
#include <qambientlightsensor.h>
#include <qsensorgesturerecognizer.h>
#include <qpressuresensor.h>
#include <qaccelerometer.h>
#include <qambienttemperaturesensor.h>
#include <qholstersensor.h>
#include <qtapsensor.h>
#include <qsensorgestureplugininterface.h>
#include <qhumiditysensor.h>
#include <qlightsensor.h>
#include <qlidsensor.h>
#include <qirproximitysensor.h>
#include <qdistancesensor.h>
#include <qsensor.h>
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
#define SBK_QSENSORCHANGESINTERFACE_IDX                              59
#define SBK_QSENSORPLUGININTERFACE_IDX                               65
#define SBK_QSENSORGESTUREPLUGININTERFACE_IDX                        62
#define SBK_QSENSORBACKENDFACTORY_IDX                                58
#define SBK_QSENSORMANAGER_IDX                                       64
#define SBK_QSENSORFILTER_IDX                                        60
#define SBK_QIRPROXIMITYFILTER_IDX                                   29
#define SBK_QTILTFILTER_IDX                                          71
#define SBK_QHUMIDITYFILTER_IDX                                      26
#define SBK_QTAPFILTER_IDX                                           67
#define SBK_QHOLSTERFILTER_IDX                                       23
#define SBK_QGYROSCOPEFILTER_IDX                                     21
#define SBK_QDISTANCEFILTER_IDX                                      17
#define SBK_QCOMPASSFILTER_IDX                                       15
#define SBK_QROTATIONFILTER_IDX                                      51
#define SBK_QAMBIENTTEMPERATUREFILTER_IDX                            11
#define SBK_QPROXIMITYFILTER_IDX                                     48
#define SBK_QAMBIENTLIGHTFILTER_IDX                                  7
#define SBK_QPRESSUREFILTER_IDX                                      45
#define SBK_QALTIMETERFILTER_IDX                                     5
#define SBK_QORIENTATIONFILTER_IDX                                   41
#define SBK_QACCELEROMETERFILTER_IDX                                 2
#define SBK_QMAGNETOMETERFILTER_IDX                                  39
#define SBK_QLIGHTFILTER_IDX                                         35
#define SBK_QLIDFILTER_IDX                                           32
#define SBK_QOUTPUTRANGE_IDX                                         74
#define SBK_QSENSORGESTUREMANAGER_IDX                                61
#define SBK_QSENSORGESTURERECOGNIZER_IDX                             63
#define SBK_QSENSORBACKEND_IDX                                       57
#define SBK_QSENSORREADING_IDX                                       66
#define SBK_QIRPROXIMITYREADING_IDX                                  30
#define SBK_QTILTREADING_IDX                                         72
#define SBK_QHUMIDITYREADING_IDX                                     27
#define SBK_QTAPREADING_IDX                                          68
#define SBK_QTAPREADING_TAPDIRECTION_IDX                             69
#define SBK_QHOLSTERREADING_IDX                                      24
#define SBK_QGYROSCOPEREADING_IDX                                    22
#define SBK_QDISTANCEREADING_IDX                                     18
#define SBK_QCOMPASSREADING_IDX                                      16
#define SBK_QROTATIONREADING_IDX                                     52
#define SBK_QAMBIENTTEMPERATUREREADING_IDX                           12
#define SBK_QPROXIMITYREADING_IDX                                    49
#define SBK_QAMBIENTLIGHTREADING_IDX                                 8
#define SBK_QAMBIENTLIGHTREADING_LIGHTLEVEL_IDX                      9
#define SBK_QPRESSUREREADING_IDX                                     46
#define SBK_QALTIMETERREADING_IDX                                    6
#define SBK_QORIENTATIONREADING_IDX                                  42
#define SBK_QORIENTATIONREADING_ORIENTATION_IDX                      43
#define SBK_QACCELEROMETERREADING_IDX                                3
#define SBK_QMAGNETOMETERREADING_IDX                                 40
#define SBK_QLIGHTREADING_IDX                                        36
#define SBK_QLIDREADING_IDX                                          33
#define SBK_QSENSOR_IDX                                              54
#define SBK_QSENSOR_FEATURE_IDX                                      56
#define SBK_QSENSOR_AXESORIENTATIONMODE_IDX                          55
#define SBK_QIRPROXIMITYSENSOR_IDX                                   31
#define SBK_QTILTSENSOR_IDX                                          73
#define SBK_QHUMIDITYSENSOR_IDX                                      28
#define SBK_QTAPSENSOR_IDX                                           70
#define SBK_QHOLSTERSENSOR_IDX                                       25
#define SBK_QGYROSCOPE_IDX                                           20
#define SBK_QDISTANCESENSOR_IDX                                      19
#define SBK_QCOMPASS_IDX                                             14
#define SBK_QROTATIONSENSOR_IDX                                      53
#define SBK_QAMBIENTTEMPERATURESENSOR_IDX                            13
#define SBK_QPROXIMITYSENSOR_IDX                                     50
#define SBK_QAMBIENTLIGHTSENSOR_IDX                                  10
#define SBK_QPRESSURESENSOR_IDX                                      47
#define SBK_QALTIMETER_IDX                                           4
#define SBK_QORIENTATIONSENSOR_IDX                                   44
#define SBK_QACCELEROMETER_IDX                                       0
#define SBK_QACCELEROMETER_ACCELERATIONMODE_IDX                      1
#define SBK_QMAGNETOMETER_IDX                                        38
#define SBK_QLIGHTSENSOR_IDX                                         37
#define SBK_QLIDSENSOR_IDX                                           34
#define SBK_QtSensors_IDX_COUNT                                      75

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_QtSensorsTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_QtSensorsTypeConverters;

// Converter indices
#define SBK_QTSENSORS_QLIST_QSENSORGESTURERECOGNIZERPTR_IDX          0 // QList<QSensorGestureRecognizer* >
#define SBK_QTSENSORS_QLIST_QOBJECTPTR_IDX                           1 // const QList<QObject* > &
#define SBK_QTSENSORS_QLIST_QBYTEARRAY_IDX                           2 // QList<QByteArray >
#define SBK_QTSENSORS_QPAIR_INT_INT_IDX                              3 // QPair<int,int >
#define SBK_QTSENSORS_QLIST_QPAIR_INT_INT_IDX                        4 // QList<QPair< int,int > >
#define SBK_QTSENSORS_QLIST_QSENSORFILTERPTR_IDX                     5 // QList<QSensorFilter* >
#define SBK_QTSENSORS_QLIST_QOUTPUTRANGE_IDX                         6 // QList<qoutputrange >
#define SBK_QTSENSORS_QLIST_QVARIANT_IDX                             7 // QList<QVariant >
#define SBK_QTSENSORS_QLIST_QSTRING_IDX                              8 // QList<QString >
#define SBK_QTSENSORS_QMAP_QSTRING_QVARIANT_IDX                      9 // QMap<QString,QVariant >
#define SBK_QtSensors_CONVERTERS_IDX_COUNT                           10

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QSensorChangesInterface >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORCHANGESINTERFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensorPluginInterface >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORPLUGININTERFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensorGesturePluginInterface >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORGESTUREPLUGININTERFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensorBackendFactory >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORBACKENDFACTORY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensorManager >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORMANAGER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensorFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QIRProximityFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QIRPROXIMITYFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTiltFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QTILTFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QHumidityFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QHUMIDITYFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTapFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QTAPFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QHolsterFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QHOLSTERFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGyroscopeFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QGYROSCOPEFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDistanceFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QDISTANCEFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QCompassFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QCOMPASSFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QRotationFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QROTATIONFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAmbientTemperatureFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QAMBIENTTEMPERATUREFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QProximityFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QPROXIMITYFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAmbientLightFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QAMBIENTLIGHTFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPressureFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QPRESSUREFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAltimeterFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QALTIMETERFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOrientationFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QORIENTATIONFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAccelerometerFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QACCELEROMETERFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMagnetometerFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QMAGNETOMETERFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QLightFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QLIGHTFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QLidFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QLIDFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::qoutputrange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QOUTPUTRANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensorGestureManager >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORGESTUREMANAGER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensorGestureRecognizer >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORGESTURERECOGNIZER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensorBackend >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORBACKEND_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensorReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSORREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QIRProximityReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QIRPROXIMITYREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTiltReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QTILTREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QHumidityReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QHUMIDITYREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTapReading::TapDirection >() { return SbkPySide2_QtSensorsTypes[SBK_QTAPREADING_TAPDIRECTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTapReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QTAPREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QHolsterReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QHOLSTERREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGyroscopeReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QGYROSCOPEREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDistanceReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QDISTANCEREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QCompassReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QCOMPASSREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QRotationReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QROTATIONREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAmbientTemperatureReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QAMBIENTTEMPERATUREREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QProximityReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QPROXIMITYREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAmbientLightReading::LightLevel >() { return SbkPySide2_QtSensorsTypes[SBK_QAMBIENTLIGHTREADING_LIGHTLEVEL_IDX]; }
template<> inline PyTypeObject* SbkType< ::QAmbientLightReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QAMBIENTLIGHTREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPressureReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QPRESSUREREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAltimeterReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QALTIMETERREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOrientationReading::Orientation >() { return SbkPySide2_QtSensorsTypes[SBK_QORIENTATIONREADING_ORIENTATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOrientationReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QORIENTATIONREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAccelerometerReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QACCELEROMETERREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMagnetometerReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QMAGNETOMETERREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QLightReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QLIGHTREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QLidReading >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QLIDREADING_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSensor::Feature >() { return SbkPySide2_QtSensorsTypes[SBK_QSENSOR_FEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QSensor::AxesOrientationMode >() { return SbkPySide2_QtSensorsTypes[SBK_QSENSOR_AXESORIENTATIONMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QIRProximitySensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QIRPROXIMITYSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTiltSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QTILTSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QHumiditySensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QHUMIDITYSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTapSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QTAPSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QHolsterSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QHOLSTERSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGyroscope >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QGYROSCOPE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDistanceSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QDISTANCESENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QCompass >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QCOMPASS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QRotationSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QROTATIONSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAmbientTemperatureSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QAMBIENTTEMPERATURESENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QProximitySensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QPROXIMITYSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAmbientLightSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QAMBIENTLIGHTSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPressureSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QPRESSURESENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAltimeter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QALTIMETER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOrientationSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QORIENTATIONSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAccelerometer::AccelerationMode >() { return SbkPySide2_QtSensorsTypes[SBK_QACCELEROMETER_ACCELERATIONMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QAccelerometer >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QACCELEROMETER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMagnetometer >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QMAGNETOMETER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QLightSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QLIGHTSENSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QLidSensor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtSensorsTypes[SBK_QLIDSENSOR_IDX]); }

} // namespace Shiboken

#endif // SBK_QTSENSORS_PYTHON_H

