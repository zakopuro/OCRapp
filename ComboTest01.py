import sys
from PyQt5.QtWidgets import *

class ComboTest01(QWidget):
    def __init__(self, parent=None):
        super(ComboTest01, self).__init__(parent)
        self.initUI()

    def initUI(self):
        self.label = QLabel("東京",self)
        combo = QComboBox(self)
        combo.addItem("C/C++")
        combo.addItem("Python")
        combo.addItem("Java")
        combo.addItem("Julia")
        combo.addItem("ruby")
        combo.addItem("R")
        combo.move(50,50)
        self.label.move(50,150)
        combo.activated[str].connect(self.onActivated)
        self.setGeometry(300,300,300,200)
        self.setWindowTitle("QComboBox")

    def onActivated(self,text):
        self.label.setText(text)
        self.label.adjustSize()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    win = ComboTest01()
    win.show()
    sys.exit(app.exec_())
