import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from ui_test_designer import Ui_MainWindow

class Test(QDialog):
    def __init__(self,parent=None):
        super(Test, self).__init__(parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = Test()
    window.show()
    sys.exit(app.exec_())
