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


#ifndef SBK_QTLOCATION_PYTHON_H
#define SBK_QTLOCATION_PYTHON_H

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
#include <pyside2_qtpositioning_python.h>

// Binded library includes
#include <qplacecontactdetail.h>
#include <qgeoroute.h>
#include <qplaceresult.h>
#include <qgeoserviceprovider.h>
#include <qplacereview.h>
#include <qplacematchreply.h>
#include <qplacecontent.h>
#include <qplaceproposedsearchresult.h>
#include <qplacematchrequest.h>
#include <qplaceattribute.h>
#include <qplaceuser.h>
#include <qplacereply.h>
#include <qplacemanagerengine.h>
#include <qplace.h>
#include <qplacemanager.h>
#include <qgeocodingmanagerengine.h>
#include <qplacecontentreply.h>
#include <qplacesearchresult.h>
#include <qplaceimage.h>
#include <qgeorouterequest.h>
#include <qplacesearchreply.h>
#include <qgeoroutingmanager.h>
#include <qplacesearchrequest.h>
#include <qplacecontentrequest.h>
#include <qplaceratings.h>
#include <qgeoserviceproviderfactory.h>
#include <qplacedetailsreply.h>
#include <qplaceidreply.h>
#include <qplacecategory.h>
#include <qgeoroutingmanagerengine.h>
#include <qplacesupplier.h>
#include <qgeomaneuver.h>
#include <qgeocodereply.h>
#include <qgeoroutereply.h>
#include <qgeocodingmanager.h>
#include <qplaceeditorial.h>
#include <qplaceicon.h>
#include <qgeoroutesegment.h>
#include <qplacesearchsuggestionreply.h>
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
#define SBK_QPLACEUSER_IDX                                           71
#define SBK_QPLACESEARCHREQUEST_IDX                                  65
#define SBK_QPLACESEARCHREQUEST_RELEVANCEHINT_IDX                    66
#define SBK_QPLACEMATCHREQUEST_IDX                                   56
#define SBK_QPLACESEARCHRESULT_IDX                                   67
#define SBK_QPLACESEARCHRESULT_SEARCHRESULTTYPE_IDX                  68
#define SBK_QPLACEPROPOSEDSEARCHRESULT_IDX                           57
#define SBK_QPLACERESULT_IDX                                         62
#define SBK_QPLACESUPPLIER_IDX                                       70
#define SBK_QPLACECONTENTREQUEST_IDX                                 46
#define SBK_QPLACE_IDX                                               39
#define SBK_QPLACECONTACTDETAIL_IDX                                  42
#define SBK_QPLACEATTRIBUTE_IDX                                      40
#define SBK_QPLACERATINGS_IDX                                        58
#define SBK_QPLACECONTENT_IDX                                        43
#define SBK_QPLACECONTENT_TYPE_IDX                                   44
#define SBK_QPLACEREVIEW_IDX                                         63
#define SBK_QPLACEIMAGE_IDX                                          52
#define SBK_QPLACEEDITORIAL_IDX                                      48
#define SBK_QPLACECATEGORY_IDX                                       41
#define SBK_QGEOSERVICEPROVIDERFACTORY_IDX                           37
#define SBK_QGEOSERVICEPROVIDERFACTORYV2_IDX                         38
#define SBK_QGEOROUTESEGMENT_IDX                                     27
#define SBK_QGEOROUTE_IDX                                            17
#define SBK_QGEOROUTEREQUEST_IDX                                     20
#define SBK_QGEOROUTEREQUEST_TRAVELMODE_IDX                          26
#define SBK_QFLAGS_QGEOROUTEREQUEST_TRAVELMODE__IDX                  5
#define SBK_QGEOROUTEREQUEST_FEATURETYPE_IDX                         21
#define SBK_QFLAGS_QGEOROUTEREQUEST_FEATURETYPE__IDX                 0
#define SBK_QGEOROUTEREQUEST_FEATUREWEIGHT_IDX                       22
#define SBK_QFLAGS_QGEOROUTEREQUEST_FEATUREWEIGHT__IDX               1
#define SBK_QGEOROUTEREQUEST_ROUTEOPTIMIZATION_IDX                   24
#define SBK_QFLAGS_QGEOROUTEREQUEST_ROUTEOPTIMIZATION__IDX           3
#define SBK_QGEOROUTEREQUEST_SEGMENTDETAIL_IDX                       25
#define SBK_QFLAGS_QGEOROUTEREQUEST_SEGMENTDETAIL__IDX               4
#define SBK_QGEOROUTEREQUEST_MANEUVERDETAIL_IDX                      23
#define SBK_QFLAGS_QGEOROUTEREQUEST_MANEUVERDETAIL__IDX              2
#define SBK_QGEOMANEUVER_IDX                                         15
#define SBK_QGEOMANEUVER_INSTRUCTIONDIRECTION_IDX                    16
#define SBK_QPLACEICON_IDX                                           49
#define SBK_QGEOSERVICEPROVIDER_IDX                                  30
#define SBK_QGEOSERVICEPROVIDER_ERROR_IDX                            31
#define SBK_QGEOSERVICEPROVIDER_ROUTINGFEATURE_IDX                   36
#define SBK_QFLAGS_QGEOSERVICEPROVIDER_ROUTINGFEATURE__IDX           10
#define SBK_QGEOSERVICEPROVIDER_GEOCODINGFEATURE_IDX                 32
#define SBK_QFLAGS_QGEOSERVICEPROVIDER_GEOCODINGFEATURE__IDX         6
#define SBK_QGEOSERVICEPROVIDER_MAPPINGFEATURE_IDX                   33
#define SBK_QFLAGS_QGEOSERVICEPROVIDER_MAPPINGFEATURE__IDX           7
#define SBK_QGEOSERVICEPROVIDER_PLACESFEATURE_IDX                    35
#define SBK_QFLAGS_QGEOSERVICEPROVIDER_PLACESFEATURE__IDX            9
#define SBK_QGEOSERVICEPROVIDER_NAVIGATIONFEATURE_IDX                34
#define SBK_QFLAGS_QGEOSERVICEPROVIDER_NAVIGATIONFEATURE__IDX        8
#define SBK_QGEOROUTINGMANAGERENGINE_IDX                             29
#define SBK_QGEOROUTINGMANAGER_IDX                                   28
#define SBK_QGEOROUTEREPLY_IDX                                       18
#define SBK_QGEOROUTEREPLY_ERROR_IDX                                 19
#define SBK_QGEOCODINGMANAGERENGINE_IDX                              14
#define SBK_QGEOCODINGMANAGER_IDX                                    13
#define SBK_QGEOCODEREPLY_IDX                                        11
#define SBK_QGEOCODEREPLY_ERROR_IDX                                  12
#define SBK_QPLACEMANAGERENGINE_IDX                                  54
#define SBK_QPLACEMANAGER_IDX                                        53
#define SBK_QPLACEREPLY_IDX                                          59
#define SBK_QPLACEREPLY_ERROR_IDX                                    60
#define SBK_QPLACEREPLY_TYPE_IDX                                     61
#define SBK_QPLACESEARCHSUGGESTIONREPLY_IDX                          69
#define SBK_QPLACEMATCHREPLY_IDX                                     55
#define SBK_QPLACEIDREPLY_IDX                                        50
#define SBK_QPLACEIDREPLY_OPERATIONTYPE_IDX                          51
#define SBK_QPLACEDETAILSREPLY_IDX                                   47
#define SBK_QPLACECONTENTREPLY_IDX                                   45
#define SBK_QPLACESEARCHREPLY_IDX                                    64
#define SBK_QtLocation_IDX_COUNT                                     72

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_QtLocationTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_QtLocationTypeConverters;

// Converter indices
#define SBK_QTLOCATION_QLIST_QPLACECATEGORY_IDX                      0 // QList<QPlaceCategory >
#define SBK_QTLOCATION_QLIST_QPLACE_IDX                              1 // QList<QPlace >
#define SBK_QTLOCATION_QLIST_QPLACESEARCHRESULT_IDX                  2 // const QList<QPlaceSearchResult > &
#define SBK_QTLOCATION_QLIST_QPLACECONTACTDETAIL_IDX                 3 // QList<QPlaceContactDetail >
#define SBK_QTLOCATION_QMAP_INT_QPLACECONTENT_IDX                    4 // QMap<int,QPlaceContent >
#define SBK_QTLOCATION_QLIST_QGEOCOORDINATE_IDX                      5 // QList<QGeoCoordinate >
#define SBK_QTLOCATION_QLIST_QGEORECTANGLE_IDX                       6 // QList<QGeoRectangle >
#define SBK_QTLOCATION_QLIST_QGEOROUTEREQUEST_FEATURETYPE_IDX        7 // QList<QGeoRouteRequest::FeatureType >
#define SBK_QTLOCATION_QLIST_QVARIANTMAP_IDX                         8 // const QList<QVariantMap > &
#define SBK_QTLOCATION_QLIST_QOBJECTPTR_IDX                          9 // const QList<QObject* > &
#define SBK_QTLOCATION_QLIST_QBYTEARRAY_IDX                          10 // QList<QByteArray >
#define SBK_QTLOCATION_QLIST_QGEOROUTE_IDX                           11 // const QList<QGeoRoute > &
#define SBK_QTLOCATION_QLIST_QGEOLOCATION_IDX                        12 // QList<QGeoLocation >
#define SBK_QTLOCATION_QLIST_QLOCALE_IDX                             13 // QList<QLocale >
#define SBK_QTLOCATION_QLIST_QVARIANT_IDX                            14 // QList<QVariant >
#define SBK_QTLOCATION_QLIST_QSTRING_IDX                             15 // QList<QString >
#define SBK_QTLOCATION_QMAP_QSTRING_QVARIANT_IDX                     16 // QMap<QString,QVariant >
#define SBK_QtLocation_CONVERTERS_IDX_COUNT                          17

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QPlaceUser >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEUSER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceSearchRequest::RelevanceHint >() { return SbkPySide2_QtLocationTypes[SBK_QPLACESEARCHREQUEST_RELEVANCEHINT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPlaceSearchRequest >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACESEARCHREQUEST_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceMatchRequest >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEMATCHREQUEST_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceSearchResult::SearchResultType >() { return SbkPySide2_QtLocationTypes[SBK_QPLACESEARCHRESULT_SEARCHRESULTTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPlaceSearchResult >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACESEARCHRESULT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceProposedSearchResult >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEPROPOSEDSEARCHRESULT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceResult >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACERESULT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceSupplier >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACESUPPLIER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceContentRequest >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACECONTENTREQUEST_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlace >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceContactDetail >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACECONTACTDETAIL_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceAttribute >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEATTRIBUTE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceRatings >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACERATINGS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceContent::Type >() { return SbkPySide2_QtLocationTypes[SBK_QPLACECONTENT_TYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPlaceContent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACECONTENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceReview >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEREVIEW_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceImage >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEIMAGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceEditorial >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEEDITORIAL_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceCategory >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACECATEGORY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoServiceProviderFactory >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOSERVICEPROVIDERFACTORY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoServiceProviderFactoryV2 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOSERVICEPROVIDERFACTORYV2_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoRouteSegment >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOROUTESEGMENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoRoute >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOROUTE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoRouteRequest::TravelMode >() { return SbkPySide2_QtLocationTypes[SBK_QGEOROUTEREQUEST_TRAVELMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoRouteRequest::TravelMode> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOROUTEREQUEST_TRAVELMODE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoRouteRequest::FeatureType >() { return SbkPySide2_QtLocationTypes[SBK_QGEOROUTEREQUEST_FEATURETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoRouteRequest::FeatureType> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOROUTEREQUEST_FEATURETYPE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoRouteRequest::FeatureWeight >() { return SbkPySide2_QtLocationTypes[SBK_QGEOROUTEREQUEST_FEATUREWEIGHT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoRouteRequest::FeatureWeight> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOROUTEREQUEST_FEATUREWEIGHT__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoRouteRequest::RouteOptimization >() { return SbkPySide2_QtLocationTypes[SBK_QGEOROUTEREQUEST_ROUTEOPTIMIZATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoRouteRequest::RouteOptimization> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOROUTEREQUEST_ROUTEOPTIMIZATION__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoRouteRequest::SegmentDetail >() { return SbkPySide2_QtLocationTypes[SBK_QGEOROUTEREQUEST_SEGMENTDETAIL_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoRouteRequest::SegmentDetail> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOROUTEREQUEST_SEGMENTDETAIL__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoRouteRequest::ManeuverDetail >() { return SbkPySide2_QtLocationTypes[SBK_QGEOROUTEREQUEST_MANEUVERDETAIL_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoRouteRequest::ManeuverDetail> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOROUTEREQUEST_MANEUVERDETAIL__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoRouteRequest >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOROUTEREQUEST_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoManeuver::InstructionDirection >() { return SbkPySide2_QtLocationTypes[SBK_QGEOMANEUVER_INSTRUCTIONDIRECTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoManeuver >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOMANEUVER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceIcon >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEICON_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoServiceProvider::Error >() { return SbkPySide2_QtLocationTypes[SBK_QGEOSERVICEPROVIDER_ERROR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoServiceProvider::RoutingFeature >() { return SbkPySide2_QtLocationTypes[SBK_QGEOSERVICEPROVIDER_ROUTINGFEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoServiceProvider::RoutingFeature> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOSERVICEPROVIDER_ROUTINGFEATURE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoServiceProvider::GeocodingFeature >() { return SbkPySide2_QtLocationTypes[SBK_QGEOSERVICEPROVIDER_GEOCODINGFEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoServiceProvider::GeocodingFeature> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOSERVICEPROVIDER_GEOCODINGFEATURE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoServiceProvider::MappingFeature >() { return SbkPySide2_QtLocationTypes[SBK_QGEOSERVICEPROVIDER_MAPPINGFEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoServiceProvider::MappingFeature> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOSERVICEPROVIDER_MAPPINGFEATURE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoServiceProvider::PlacesFeature >() { return SbkPySide2_QtLocationTypes[SBK_QGEOSERVICEPROVIDER_PLACESFEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoServiceProvider::PlacesFeature> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOSERVICEPROVIDER_PLACESFEATURE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoServiceProvider::NavigationFeature >() { return SbkPySide2_QtLocationTypes[SBK_QGEOSERVICEPROVIDER_NAVIGATIONFEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QGeoServiceProvider::NavigationFeature> >() { return SbkPySide2_QtLocationTypes[SBK_QFLAGS_QGEOSERVICEPROVIDER_NAVIGATIONFEATURE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoServiceProvider >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOSERVICEPROVIDER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoRoutingManagerEngine >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOROUTINGMANAGERENGINE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoRoutingManager >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOROUTINGMANAGER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoRouteReply::Error >() { return SbkPySide2_QtLocationTypes[SBK_QGEOROUTEREPLY_ERROR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoRouteReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOROUTEREPLY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoCodingManagerEngine >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOCODINGMANAGERENGINE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoCodingManager >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOCODINGMANAGER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGeoCodeReply::Error >() { return SbkPySide2_QtLocationTypes[SBK_QGEOCODEREPLY_ERROR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGeoCodeReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QGEOCODEREPLY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceManagerEngine >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEMANAGERENGINE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceManager >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEMANAGER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceReply::Error >() { return SbkPySide2_QtLocationTypes[SBK_QPLACEREPLY_ERROR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPlaceReply::Type >() { return SbkPySide2_QtLocationTypes[SBK_QPLACEREPLY_TYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPlaceReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEREPLY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceSearchSuggestionReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACESEARCHSUGGESTIONREPLY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceMatchReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEMATCHREPLY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceIdReply::OperationType >() { return SbkPySide2_QtLocationTypes[SBK_QPLACEIDREPLY_OPERATIONTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPlaceIdReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEIDREPLY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceDetailsReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACEDETAILSREPLY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceContentReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACECONTENTREPLY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPlaceSearchReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtLocationTypes[SBK_QPLACESEARCHREPLY_IDX]); }

} // namespace Shiboken

#endif // SBK_QTLOCATION_PYTHON_H

