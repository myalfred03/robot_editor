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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <codeeditor.h>
#include <console.h>

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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    CodeEditor *editor;
    QGridLayout *gridLayout_4;
    QFrame *line;
    QMdiArea *mdiArea;
    Console *outputText;
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
        MainWindow->resize(733, 524);
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
        icon9.addFile(QStringLiteral(":/img/run.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        editor = new CodeEditor(centralWidget);
        editor->setObjectName(QStringLiteral("editor"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editor->sizePolicy().hasHeightForWidth());
        editor->setSizePolicy(sizePolicy);
        editor->setMinimumSize(QSize(10, 0));
        editor->setMaximumSize(QSize(320, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Serif"));
        font1.setPointSize(14);
        editor->setFont(font1);
        editor->setFrameShadow(QFrame::Plain);

        gridLayout_3->addWidget(editor, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 0, 0, 1, 1);

        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mdiArea->sizePolicy().hasHeightForWidth());
        mdiArea->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(mdiArea, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 0, 0, 1, 1);

        outputText = new Console(centralWidget);
        outputText->setObjectName(QStringLiteral("outputText"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(outputText->sizePolicy().hasHeightForWidth());
        outputText->setSizePolicy(sizePolicy2);
        outputText->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(outputText, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 733, 18));
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
        actionAbout->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216 HJ Editor", Q_NULLPTR));
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
        actionRun->setText(QApplication::translate("MainWindow", "Ejecutar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRun->setToolTip(QApplication::translate("MainWindow", "Ejecutar Simulaci\303\263n", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionRun->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", Q_NULLPTR));
        actionSetting->setText(QApplication::translate("MainWindow", "Setting", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSetting->setToolTip(QApplication::translate("MainWindow", "\346\233\264\346\224\271\347\274\226\350\276\221\345\231\250\347\232\204\350\256\276\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionError_Datos->setText(QApplication::translate("MainWindow", "Error", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionError_Datos->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Este icono se activara si se ingreso un par\303\241metro al robot fuera de su espacio de trabajo.</p><p>Favor Leer la Hoja de Datos del robot a controlar.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
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
