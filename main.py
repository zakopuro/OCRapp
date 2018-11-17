#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from PySide2 import QtWidgets
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import sip

def show_message():
    messagebox = QtWidgets.QMessageBox(QtWidgets.QMessageBox.Information,
                                       'Title - Hello',
                                       'Hello, Qt for Python!',
                                       QtWidgets.QMessageBox.Close
                                       )
    messagebox.exec_()

def main():
   app = QtWidgets.QApplication(sys.argv)
   button = QtWidgets.QPushButton("click me!!!!!")
   button.resize(100,40)
   button.show()

   button.clicked.connect(show_message)
   sys.exit(app.exec_())

if __name__ == '__main__':
   main()

