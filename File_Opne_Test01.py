import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QIcon


class FileOpenTest(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()


    def initUI(self):

        self.textEdit = QTextEdit()
        self.setCentralWidget(self.textEdit)
        self.statusBar()

        openFile = QAction(QIcon('open.png'), '開く', self)
        openFile.setShortcut('Ctrl+O')
        openFile.setStatusTip('新しいファイルを開く')
        openFile.triggered.connect(self.showDialog)

        menubar = self.menuBar()
        fileMenu = menubar.addMenu('&ファイル')
        fileMenu.addAction(openFile)

        self.setGeometry(300, 300, 350, 300)
        self.setWindowTitle('ファイルダイアログ')


    def showDialog(self):
        fname = QFileDialog.getOpenFileName(self,'Open file', '/', filter="Image Files (*.csv *.txt *.html *.xml *.py *.pyw)")

        if fname[0]:
            f = open(fname[0], 'r')

            with f:
                data = f.read()
                self.textEdit.setText(data)

if __name__ == '__main__':

    app = QApplication(sys.argv)
    win = FileOpenTest()
    win.show()
    sys.exit(app.exec_())
