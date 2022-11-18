import window_test

time = 0

def functions():
    window_test.Ui_MainWindow().setupUi().button_30min.clicked.connect(lambda: window_test.Ui_MainWindow().time.setText("30"))
    window_test.Ui_MainWindow().setupUi().button_10min.clicked.connect(lambda: window_test.Ui_MainWindow().time.setText("10"))

def time_work(time):
    time_h = time // 3600
    time - time // 3600
    time_min = time / 60
    time - time / 60
    time_end = time_h, '.', time_min, '.', time
    return time_end


#def functions(self, MainWindow):
#    window_test.Ui_MainWindow(MainWindow).button_30min.clicked.connect(lambda: window_test.Ui_MainWindow().time.setText(str(int(window_test.Ui_MainWindow().time.text()) + 30)))
#    window_test.Ui_MainWindow(MainWindow).button_10min.clicked.connect(lambda: window_test.Ui_MainWindow().time.setText(str(int(window_test.Ui_MainWindow().time.text()) + 10)))