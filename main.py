# -*- coding: utf-8 -*-
import sys
import cv2
import numpy as np
from PIL import Image
import scipy
import osr_mainwindow
import mnist_recognizer
import re
from PyQt5 import QtCore, QtGui
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from scipy import ndimage
from HandWriteWindow import *



try:
    _encoding = QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QApplication.translate(context, text, disambig)


width = 1200
height = 200
paint_width = 360
paint_height = 360
mnist_width = 28
mnist_height = 28
mnist_size = (mnist_width, mnist_height)

# 16*16近傍の定義
kernel = np.ones((16, 16), np.uint8)

class MainWindow(QMainWindow,osr_mainwindow.Ui_MainWindow):
   def __init__(self,parent=None):
    #    super(QMainWindow,self).__init__(parent)
       # self.ui = Ui_MainWindow()
       super(self. __class__, self).__init__()
       self.setupUi(self)
       self.move(width,height)
       self.image = np.zeros((paint_width, paint_height,3), np.uint8)
       self.image = cv2.cvtColor(self.image, cv2.COLOR_RGB2GRAY)
       self.mnist_image = np.zeros((mnist_width, mnist_height,3), np.uint8)
       self.mnist_image = cv2.cvtColor(self.mnist_image, cv2.COLOR_RGB2GRAY)

   def paint_image(self):
       view_paint.show()

   def recognizer_number(self):
       for point in view_paint.points_saved:
           self.image[point.x(),point.y()] = 255

       # 上下反転
       self.image = cv2.flip(self.image, 0)
       # 時計回り回転
       self.image = ndimage.rotate(self.image, 270)
       # 膨張処理
       img_dilation = cv2.dilate(self.image, kernel, iterations = 1)
       # 白黒反転
       img_negaposi = 255 - img_dilation
       # 二値化
       ret,img_gray = cv2.threshold(img_dilation, 0, 255, cv2.THRESH_OTSU)
       # (28,28)にリサイズ
       img_resize = cv2.resize(img_gray,(28,28))
       # 画像を保存
       cv2.imwrite("img_resize.bmp", img_resize)
       image = img_resize
       # AIにデータを渡す
       result = mnist_recognizer.mnist_recognizer(image)
       # 結果を表示する
       self.lcdNumber.display(result)

       self.image = np.zeros((paint_width, paint_height,3), np.uint8)
       self.image = cv2.cvtColor(self.image, cv2.COLOR_RGB2GRAY)
       self.mnist_image = np.zeros((mnist_width, mnist_height,3), np.uint8)
       self.mnist_image = cv2.cvtColor(self.mnist_image, cv2.COLOR_RGB2GRAY)

   def clear_points(self):
      view_paint.close()
      view_paint.__init__()
      view_paint.move(width,height+250)
      view_paint.setWindowTitle(_translate("", "数字を書く", None))
      view_paint.setFixedSize(QSize(360,360))
      view_paint.show()

      self.image = np.zeros((paint_width, paint_height,3), np.uint8)
      self.image = cv2.cvtColor(self.image, cv2.COLOR_RGB2GRAY)
      self.mnist_image = np.zeros((mnist_width, mnist_height,3), np.uint8)
      self.mnist_image = cv2.cvtColor(self.mnist_image, cv2.COLOR_RGB2GRAY)



if __name__ == '__main__':
   app = QApplication(sys.argv)
   window = MainWindow()
   window.show()
   view_paint = Widget()
   view_paint.move(width,height+250)
   view_paint.setWindowTitle(_translate("", "数字を書く", None))
   view_paint.setFixedSize(QSize(360,360))

   window.pushButton.clicked.connect(lambda: window.paint_image())
   window.pushButton_2.clicked.connect(lambda: window.recognizer_number())
   window.pushButton_3.clicked.connect(lambda: window.clear_points())

   sys.exit(app.exec_())
