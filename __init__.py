__all__ = list("Qt" + body for body in
    "Core;Gui;Widgets;PrintSupport;Sql;Network;Test;Concurrent;MacExtras;Xml;XmlPatterns;Help;Multimedia;MultimediaWidgets;OpenGL;Positioning;Location;Qml;Quick;QuickWidgets;Scxml;Sensors;TextToSpeech;Charts;Svg;DataVisualization;UiTools;WebChannel;WebEngineCore;WebEngine;WebEngineWidgets;WebSockets;3DCore;3DRender;3DInput;3DLogic;3DAnimation;3DExtras"
    .split(";"))
__version__ = "5.11.2"
__version_info__ = (5, 11, 2, "", "")

__build_date__ = '2018-09-19T07:13:10+00:00'




# Timestamp used for snapshot build, which is part of snapshot package version.
__setup_py_package_timestamp__ = ''

def _setupQtDirectories():
    import sys
    import os

    pyside_package_dir =  os.path.abspath(os.path.dirname(__file__))
    # Used by signature module.
    os.environ["PYSIDE_PACKAGE_DIR"] = pyside_package_dir

    if sys.platform == 'win32':
        # PATH has to contain the package directory, otherwise plugins
        # won't be able to find their required Qt libraries (e.g. the
        # svg image plugin won't find Qt5Svg.dll).
        os.environ['PATH'] = pyside_package_dir + os.pathsep + os.environ['PATH']

        # On Windows add the PySide2\openssl folder (if it exists) to
        # the PATH so that the SSL DLLs can be found when Qt tries to
        # dynamically load them. Tell Qt to load them and then reset
        # the PATH.
        openssl_dir = os.path.join(pyside_package_dir, 'openssl')
        if os.path.exists(openssl_dir):
            path = os.environ['PATH']
            try:
                os.environ['PATH'] = openssl_dir + os.pathsep + path
                try:
                    from . import QtNetwork
                except ImportError:
                    pass
                else:
                    QtNetwork.QSslSocket.supportsSsl()
            finally:
                os.environ['PATH'] = path

_setupQtDirectories()
