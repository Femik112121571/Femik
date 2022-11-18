from PyQt5 import QtCore, QtGui, QtWidgets

time_all = 0

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setEnabled(True)
        MainWindow.resize(500, 600)
        font = QtGui.QFont()
        font.setKerning(True)
        MainWindow.setFont(font)
        MainWindow.setStyleSheet("\n""\n""\n""\n""")
        MainWindow.setAnimated(True)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.time = QtWidgets.QLabel(self.centralwidget)
        self.time.setGeometry(QtCore.QRect(0, 0, 500, 100))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(48)
        font.setBold(False)
        font.setItalic(False)
        font.setUnderline(False)
        font.setWeight(50)
        font.setStrikeOut(False)
        font.setKerning(False)
        font.setStyleStrategy(QtGui.QFont.PreferDefault)
        self.time.setFont(font)
        self.time.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.time.setTextFormat(QtCore.Qt.AutoText)
        self.time.setScaledContents(False)
        self.time.setAlignment(QtCore.Qt.AlignCenter)
        self.time.setObjectName("time")
        self.button_30min = QtWidgets.QPushButton(self.centralwidget)
        self.button_30min.setGeometry(QtCore.QRect(0, 200, 200, 100))
        font = QtGui.QFont()
        font.setPointSize(32)
        font.setItalic(True)
        self.button_30min.setFont(font)
        self.button_30min.setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(50, 0,50, 150), stop:1 rgba(155, 0, 155, 150));\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));")
        self.button_30min.setObjectName("button_30min")
        self.background = QtWidgets.QLabel(self.centralwidget)
        self.background.setGeometry(QtCore.QRect(0, 0, 500, 600))
        self.background.setStyleSheet("background-image: url(:/pictures/background.jpg);")
        self.background.setText("")
        self.background.setObjectName("background")
        self.button_10min = QtWidgets.QPushButton(self.centralwidget)
        self.button_10min.setGeometry(QtCore.QRect(300, 200, 200, 100))
        font = QtGui.QFont()
        font.setPointSize(32)
        font.setItalic(True)
        self.button_10min.setFont(font)
        self.button_10min.setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(150, 0,0, 150), stop:1 rgba(50, 0, 0, 150));\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));")
        self.button_10min.setObjectName("button_10min")
        self.background.raise_()
        self.time.raise_()
        self.button_30min.raise_()
        self.button_10min.raise_()
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        self.functions()

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Window"))
        self.time.setText(_translate("MainWindow", "0"))
        self.button_30min.setText(_translate("MainWindow", "30min"))
        self.button_10min.setText(_translate("MainWindow", "10min"))

    def functions(self):
        self.button_30min.clicked.connect(lambda: self.time_work(30))
        self.button_10min.clicked.connect(lambda: self.time_work(10))


    def time_work(self, time_now):
        time_all += time_now
        time_now = time_all
        #time_h = time_now // 3600
        #time_now -= time_h * 3600
        #time_min = time_now // 60
        #time_now -= time_min * 60
        #time_end = str(time_h), '.', str(time_min), '.', str(time_now)
        self.time.setText(str(time_now))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
