/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <codeeditor.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewFile;
    QAction *actionOpen;
    QAction *actionSelectAll;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionAbout;
    QAction *actionDocument;
    QAction *actionSave_File;
    QAction *actionRun;
    QAction *actionSetting;
    QAction *actionError_Datos;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QFrame *line;
    QSplitter *splitter_2;
    QSplitter *splitter;
    CodeEditor *editor;
    QMdiArea *mdiArea;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *slider5;
    QSlider *slider6;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_3;
    QSlider *slider4;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSlider *slider3;
    QSpinBox *spinBox;
    QSlider *slider1;
    QLabel *label;
    QSlider *slider2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuEdit_O;
    QMenu *menuHelp_H;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1188, 809);
        MainWindow->setWindowTitle(QStringLiteral("Robot Script Editor"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/UNI-Script.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNewFile = new QAction(MainWindow);
        actionNewFile->setObjectName(QStringLiteral("actionNewFile"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewFile->setIcon(icon1);
        QFont font;
        font.setFamily(QStringLiteral("Tlwg Mono"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        actionNewFile->setFont(font);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName(QStringLiteral("actionSelectAll"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/format.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectAll->setIcon(icon3);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/revoke.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon4);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/recovery.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon5);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/learning.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon6);
        actionDocument = new QAction(MainWindow);
        actionDocument->setObjectName(QStringLiteral("actionDocument"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDocument->setIcon(icon7);
        actionSave_File = new QAction(MainWindow);
        actionSave_File->setObjectName(QStringLiteral("actionSave_File"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/floppy-disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_File->setIcon(icon8);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/robot.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon9);
        actionSetting = new QAction(MainWindow);
        actionSetting->setObjectName(QStringLiteral("actionSetting"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/image/Setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetting->setIcon(icon10);
        actionSetting->setVisible(false);
        actionError_Datos = new QAction(MainWindow);
        actionError_Datos->setObjectName(QStringLiteral("actionError_Datos"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/img/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QStringLiteral(":/img/error_red.png"), QSize(), QIcon::Active, QIcon::On);
        actionError_Datos->setIcon(icon11);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 1, 1, 1);

        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        editor = new CodeEditor(splitter);
        editor->setObjectName(QStringLiteral("editor"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editor->sizePolicy().hasHeightForWidth());
        editor->setSizePolicy(sizePolicy);
        editor->setMinimumSize(QSize(10, 0));
        editor->setMaximumSize(QSize(800, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Serif"));
        font1.setPointSize(14);
        editor->setFont(font1);
        editor->setFrameShadow(QFrame::Plain);
        splitter->addWidget(editor);
        mdiArea = new QMdiArea(splitter);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        sizePolicy.setHeightForWidth(mdiArea->sizePolicy().hasHeightForWidth());
        mdiArea->setSizePolicy(sizePolicy);
        mdiArea->setMinimumSize(QSize(400, 0));
        splitter->addWidget(mdiArea);
        splitter_2->addWidget(splitter);
        gridLayoutWidget = new QWidget(splitter_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        slider5 = new QSlider(gridLayoutWidget);
        slider5->setObjectName(QStringLiteral("slider5"));
        slider5->setOrientation(Qt::Horizontal);
        slider5->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(slider5, 0, 7, 1, 1);

        slider6 = new QSlider(gridLayoutWidget);
        slider6->setObjectName(QStringLiteral("slider6"));
        slider6->setOrientation(Qt::Horizontal);
        slider6->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(slider6, 1, 7, 1, 1);

        spinBox_4 = new QSpinBox(gridLayoutWidget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        gridLayout->addWidget(spinBox_4, 1, 5, 1, 1);

        spinBox_3 = new QSpinBox(gridLayoutWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        gridLayout->addWidget(spinBox_3, 0, 5, 1, 1);

        slider4 = new QSlider(gridLayoutWidget);
        slider4->setObjectName(QStringLiteral("slider4"));
        slider4->setOrientation(Qt::Horizontal);
        slider4->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(slider4, 1, 4, 1, 1);

        spinBox_2 = new QSpinBox(gridLayoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 1, 2, 1, 1);

        spinBox_5 = new QSpinBox(gridLayoutWidget);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));

        gridLayout->addWidget(spinBox_5, 0, 8, 1, 1);

        spinBox_6 = new QSpinBox(gridLayoutWidget);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));

        gridLayout->addWidget(spinBox_6, 1, 8, 1, 1);

        slider3 = new QSlider(gridLayoutWidget);
        slider3->setObjectName(QStringLiteral("slider3"));
        slider3->setOrientation(Qt::Horizontal);
        slider3->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(slider3, 0, 4, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 0, 2, 1, 1);

        slider1 = new QSlider(gridLayoutWidget);
        slider1->setObjectName(QStringLiteral("slider1"));
        slider1->setOrientation(Qt::Horizontal);
        slider1->setInvertedControls(false);
        slider1->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(slider1, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        slider2 = new QSlider(gridLayoutWidget);
        slider2->setObjectName(QStringLiteral("slider2"));
        slider2->setOrientation(Qt::Horizontal);
        slider2->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(slider2, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 6, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 6, 1, 1);

        splitter_2->addWidget(gridLayoutWidget);

        gridLayout_3->addWidget(splitter_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1188, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuEdit_O = new QMenu(menuBar);
        menuEdit_O->setObjectName(QStringLiteral("menuEdit_O"));
        menuHelp_H = new QMenu(menuBar);
        menuHelp_H->setObjectName(QStringLiteral("menuHelp_H"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QFont font2;
        font2.setFamily(QStringLiteral("Tlwg Mono"));
        mainToolBar->setFont(font2);
        mainToolBar->setAutoFillBackground(true);
        mainToolBar->setIconSize(QSize(18, 18));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuEdit_O->menuAction());
        menuBar->addAction(menuHelp_H->menuAction());
        menu->addAction(actionNewFile);
        menu->addAction(actionOpen);
        menu->addAction(actionSave_File);
        menuEdit_O->addAction(actionSelectAll);
        menuEdit_O->addAction(actionUndo);
        menuEdit_O->addAction(actionRedo);
        menuHelp_H->addAction(actionAbout);
        menuHelp_H->addAction(actionDocument);
        mainToolBar->addAction(actionNewFile);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave_File);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSelectAll);
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);
        mainToolBar->addAction(actionRun);
        mainToolBar->addAction(actionSetting);

        retranslateUi(MainWindow);
        QObject::connect(slider1, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(slider2, SIGNAL(valueChanged(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider1, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), slider2, SLOT(setValue(int)));
        QObject::connect(slider3, SIGNAL(valueChanged(int)), spinBox_3, SLOT(setValue(int)));
        QObject::connect(slider4, SIGNAL(valueChanged(int)), spinBox_4, SLOT(setValue(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), slider3, SLOT(setValue(int)));
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), slider4, SLOT(setValue(int)));
        QObject::connect(slider5, SIGNAL(valueChanged(int)), spinBox_5, SLOT(setValue(int)));
        QObject::connect(slider6, SIGNAL(valueChanged(int)), spinBox_6, SLOT(setValue(int)));
        QObject::connect(spinBox_5, SIGNAL(valueChanged(int)), slider5, SLOT(setValue(int)));
        QObject::connect(spinBox_6, SIGNAL(valueChanged(int)), slider6, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionNewFile->setText(QApplication::translate("MainWindow", "Nuevo", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionNewFile->setToolTip(QApplication::translate("MainWindow", "Crear nuevo archivo Script LVR", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionNewFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Abrir", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Abrir Archivo Script LVR", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        actionSelectAll->setText(QApplication::translate("MainWindow", "Seleccionar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSelectAll->setToolTip(QApplication::translate("MainWindow", "Seleccionar Todo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSelectAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("MainWindow", "Atras", Q_NULLPTR));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("MainWindow", "Adelante", Q_NULLPTR));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About Editor", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "HJ Editor", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionDocument->setText(QApplication::translate("MainWindow", "Documentaci\303\263n", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDocument->setToolTip(QApplication::translate("MainWindow", "Ver documentaci\303\263n", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSave_File->setText(QApplication::translate("MainWindow", "Guardar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSave_File->setToolTip(QApplication::translate("MainWindow", "Guardar Archivo ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSave_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionRun->setText(QApplication::translate("MainWindow", "Actualizar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRun->setToolTip(QApplication::translate("MainWindow", "Actualizar Robot", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionRun->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", Q_NULLPTR));
        actionSetting->setText(QApplication::translate("MainWindow", "Setting", Q_NULLPTR));
        actionError_Datos->setText(QApplication::translate("MainWindow", "Error", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionError_Datos->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Este icono se activara si se ingreso un par\303\241metro al robot fuera de su espacio de trabajo.</p><p>Favor Leer la Hoja de Datos del robot a controlar.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">1DOF</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">2DOF</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">3DOF</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">4DOF</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">5DOF</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">6DOF</span></p></body></html>", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "Archivo", Q_NULLPTR));
        menuEdit_O->setTitle(QApplication::translate("MainWindow", "Editar", Q_NULLPTR));
        menuHelp_H->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
