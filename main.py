import sys
import osr_mainwindow
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
# from osr_mainwindow import Ui_MainWindow
from HandWriteWindow import *

class MainWindow(QMainWindow,osr_mainwindow.Ui_MainWindow):
   def __init__(self,parent=None):
       super(QMainWindow,self).__init__(parent)
       # self.ui = Ui_MainWindow()
       self.setupUi(self)

   def paint_image(self):
       self.textEdit.append("open paint window...")
       view_paint.show()

if __name__ == '__main__':
   app = QApplication(sys.argv)
   window = MainWindow()
   window.show()
   view_paint = Widget()
   window.pushButton.clicked.connect(lambda: window.paint_image())

   sys.exit(app.exec_())
