/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QAction *actionDebug;
    QAction *actionTerminal;
    QAction *actionAboutQt;
    QAction *actionAbout;
    QAction *actionAboutMe;
    QAction *actionMonitor;
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QWidget *terminalWidget;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *Statuslabel;
    QLabel *label_3;
    QLabel *ModeLabel;
    QPushButton *stopButton;
    QPushButton *uploadButton;
    QTabWidget *tabWidget;
    QWidget *EvenModeTab;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QSlider *EvenmodehorizontalSlider;
    QSpinBox *EvenmodespinBox;
    QCheckBox *checkBox_even_auto;
    QWidget *GustModeTab;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QSlider *gust_upper_limit_slider;
    QLabel *label_4;
    QSlider *gust_lower_limit_slider;
    QSpinBox *gust_upper_limit_spinbox;
    QSpinBox *gust_lower_limit_spinbox;
    QLabel *label_2;
    QLabel *label_5;
    QSlider *gust_period_slider;
    QSpinBox *gust_period_spinbox;
    QLabel *label_6;
    QWidget *SheerModeTab;
    QListView *listView;
    QFrame *line;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *sheer_spinBox;
    QPushButton *sheer_mode_append_button;
    QPushButton *pushButton_3;
    QPushButton *sheer_clear_button;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QComboBox *sheer_comboBox;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *sheer_count_label;
    QWidget *tab;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(758, 464);
        MainWindow->setMinimumSize(QSize(758, 464));
        MainWindow->setMaximumSize(QSize(9000, 9000));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/dronejpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(39, 39));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName("actionConnect");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName("actionDisconnect");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon2);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName("actionConfigure");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon3);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon4);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon5);
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName("actionDebug");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons8-bug-60.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDebug->setIcon(icon6);
        actionTerminal = new QAction(MainWindow);
        actionTerminal->setObjectName("actionTerminal");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/terminal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTerminal->setIcon(icon7);
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName("actionAboutQt");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionAboutMe = new QAction(MainWindow);
        actionAboutMe->setObjectName("actionAboutMe");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/aboutme.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAboutMe->setIcon(icon8);
        actionMonitor = new QAction(MainWindow);
        actionMonitor->setObjectName("actionMonitor");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/computer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMonitor->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName("gridLayout_6");
        terminalWidget = new QWidget(centralWidget);
        terminalWidget->setObjectName("terminalWidget");
        gridLayout_4 = new QGridLayout(terminalWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        groupBox = new QGroupBox(terminalWidget);
        groupBox->setObjectName("groupBox");
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Statuslabel = new QLabel(groupBox);
        Statuslabel->setObjectName("Statuslabel");
        Statuslabel->setFont(font);

        gridLayout->addWidget(Statuslabel, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        ModeLabel = new QLabel(groupBox);
        ModeLabel->setObjectName("ModeLabel");
        ModeLabel->setFont(font);

        gridLayout->addWidget(ModeLabel, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        stopButton = new QPushButton(groupBox);
        stopButton->setObjectName("stopButton");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/icons8-stop-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon10);

        gridLayout_5->addWidget(stopButton, 1, 0, 1, 1);

        uploadButton = new QPushButton(groupBox);
        uploadButton->setObjectName("uploadButton");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/icons8-play-100.png"), QSize(), QIcon::Normal, QIcon::Off);
        uploadButton->setIcon(icon11);

        gridLayout_5->addWidget(uploadButton, 2, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox);

        tabWidget = new QTabWidget(terminalWidget);
        tabWidget->setObjectName("tabWidget");
        EvenModeTab = new QWidget();
        EvenModeTab->setObjectName("EvenModeTab");
        gridLayoutWidget_2 = new QWidget(EvenModeTab);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(20, 50, 411, 131));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        EvenmodehorizontalSlider = new QSlider(gridLayoutWidget_2);
        EvenmodehorizontalSlider->setObjectName("EvenmodehorizontalSlider");
        EvenmodehorizontalSlider->setMaximum(4095);
        EvenmodehorizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(EvenmodehorizontalSlider, 0, 0, 1, 1);

        EvenmodespinBox = new QSpinBox(gridLayoutWidget_2);
        EvenmodespinBox->setObjectName("EvenmodespinBox");
        EvenmodespinBox->setMaximum(4098);

        gridLayout_2->addWidget(EvenmodespinBox, 0, 1, 1, 1);

        checkBox_even_auto = new QCheckBox(EvenModeTab);
        checkBox_even_auto->setObjectName("checkBox_even_auto");
        checkBox_even_auto->setGeometry(QRect(30, 210, 151, 51));
        tabWidget->addTab(EvenModeTab, QString());
        GustModeTab = new QWidget();
        GustModeTab->setObjectName("GustModeTab");
        widget = new QWidget(GustModeTab);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 40, 410, 109));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName("gridLayout_3");
        gust_upper_limit_slider = new QSlider(widget);
        gust_upper_limit_slider->setObjectName("gust_upper_limit_slider");
        gust_upper_limit_slider->setMaximum(4095);
        gust_upper_limit_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(gust_upper_limit_slider, 0, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        gust_lower_limit_slider = new QSlider(widget);
        gust_lower_limit_slider->setObjectName("gust_lower_limit_slider");
        gust_lower_limit_slider->setMaximum(4095);
        gust_lower_limit_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(gust_lower_limit_slider, 1, 1, 1, 1);

        gust_upper_limit_spinbox = new QSpinBox(widget);
        gust_upper_limit_spinbox->setObjectName("gust_upper_limit_spinbox");
        gust_upper_limit_spinbox->setMaximum(4095);

        gridLayout_3->addWidget(gust_upper_limit_spinbox, 0, 2, 1, 1);

        gust_lower_limit_spinbox = new QSpinBox(widget);
        gust_lower_limit_spinbox->setObjectName("gust_lower_limit_spinbox");
        gust_lower_limit_spinbox->setMaximum(4095);

        gridLayout_3->addWidget(gust_lower_limit_spinbox, 1, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        gust_period_slider = new QSlider(widget);
        gust_period_slider->setObjectName("gust_period_slider");
        gust_period_slider->setMinimum(500);
        gust_period_slider->setMaximum(20000);
        gust_period_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(gust_period_slider, 2, 1, 1, 1);

        gust_period_spinbox = new QSpinBox(widget);
        gust_period_spinbox->setObjectName("gust_period_spinbox");
        gust_period_spinbox->setMinimum(500);
        gust_period_spinbox->setMaximum(20000);

        gridLayout_3->addWidget(gust_period_spinbox, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        tabWidget->addTab(GustModeTab, QString());
        SheerModeTab = new QWidget();
        SheerModeTab->setObjectName("SheerModeTab");
        listView = new QListView(SheerModeTab);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(30, 20, 111, 231));
        line = new QFrame(SheerModeTab);
        line->setObjectName("line");
        line->setGeometry(QRect(303, 20, 20, 261));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        widget1 = new QWidget(SheerModeTab);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(170, 30, 111, 221));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        sheer_spinBox = new QSpinBox(widget1);
        sheer_spinBox->setObjectName("sheer_spinBox");
        sheer_spinBox->setMaximum(4095);

        verticalLayout_2->addWidget(sheer_spinBox);

        sheer_mode_append_button = new QPushButton(widget1);
        sheer_mode_append_button->setObjectName("sheer_mode_append_button");

        verticalLayout_2->addWidget(sheer_mode_append_button);

        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout_2->addWidget(pushButton_3);

        sheer_clear_button = new QPushButton(widget1);
        sheer_clear_button->setObjectName("sheer_clear_button");

        verticalLayout_2->addWidget(sheer_clear_button);

        widget2 = new QWidget(SheerModeTab);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(320, 50, 111, 81));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget2);
        label_7->setObjectName("label_7");

        verticalLayout_3->addWidget(label_7);

        sheer_comboBox = new QComboBox(widget2);
        sheer_comboBox->addItem(QString());
        sheer_comboBox->addItem(QString());
        sheer_comboBox->setObjectName("sheer_comboBox");

        verticalLayout_3->addWidget(sheer_comboBox);

        widget3 = new QWidget(SheerModeTab);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(30, 260, 91, 17));
        horizontalLayout = new QHBoxLayout(widget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget3);
        label_8->setObjectName("label_8");

        horizontalLayout->addWidget(label_8);

        sheer_count_label = new QLabel(widget3);
        sheer_count_label->setObjectName("sheer_count_label");

        horizontalLayout->addWidget(sheer_count_label);

        tabWidget->addTab(SheerModeTab, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(80, 60, 256, 192));
        tabWidget->addTab(tab, QString());

        horizontalLayout_2->addWidget(tabWidget);


        gridLayout_4->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_6->addWidget(terminalWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 758, 20));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName("menuCalls");
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName("menuTools");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuHelp->addAction(actionAboutMe);
        menuHelp->addAction(actionAboutQt);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionMonitor);
        mainToolBar->addAction(actionDebug);
        mainToolBar->addAction(actionTerminal);
        mainToolBar->addAction(actionClear);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAboutMe);
        mainToolBar->addAction(actionQuit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Wind", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "C&onnect", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect->setToolTip(QCoreApplication::translate("MainWindow", "Connect to serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionConnect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "&Disconnect", nullptr));
#if QT_CONFIG(tooltip)
        actionDisconnect->setToolTip(QCoreApplication::translate("MainWindow", "Disconnect from serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionDisconnect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionConfigure->setText(QCoreApplication::translate("MainWindow", "&Configure", nullptr));
#if QT_CONFIG(tooltip)
        actionConfigure->setToolTip(QCoreApplication::translate("MainWindow", "Configure serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionConfigure->setShortcut(QCoreApplication::translate("MainWindow", "Alt+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear->setText(QCoreApplication::translate("MainWindow", "C&lear", nullptr));
#if QT_CONFIG(tooltip)
        actionClear->setToolTip(QCoreApplication::translate("MainWindow", "Clear data", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionClear->setShortcut(QCoreApplication::translate("MainWindow", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDebug->setText(QCoreApplication::translate("MainWindow", "Debug", nullptr));
#if QT_CONFIG(shortcut)
        actionDebug->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTerminal->setText(QCoreApplication::translate("MainWindow", "Terminal", nullptr));
        actionAboutQt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "About program", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Alt+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAboutMe->setText(QCoreApplication::translate("MainWindow", "AboutMe", nullptr));
        actionMonitor->setText(QCoreApplication::translate("MainWindow", "Monitor", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Status", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        Statuslabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        ModeLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        uploadButton->setText(QCoreApplication::translate("MainWindow", "upload and start", nullptr));
        checkBox_even_auto->setText(QCoreApplication::translate("MainWindow", "automatically upload", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(EvenModeTab), QCoreApplication::translate("MainWindow", "Even Mode", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Lower Limit :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Upper limit :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Period (ms) :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "WARNING : upper limit cannot be assigned smaller than lower limit!!! ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(GustModeTab), QCoreApplication::translate("MainWindow", "Gust Mode", nullptr));
        sheer_mode_append_button->setText(QCoreApplication::translate("MainWindow", "Append", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Delete last", nullptr));
        sheer_clear_button->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "set at : ", nullptr));
        sheer_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Row", nullptr));
        sheer_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Column", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Total:", nullptr));
        sheer_count_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SheerModeTab), QCoreApplication::translate("MainWindow", "Sheer Mode", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
        menuCalls->setTitle(QCoreApplication::translate("MainWindow", "Calls", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
