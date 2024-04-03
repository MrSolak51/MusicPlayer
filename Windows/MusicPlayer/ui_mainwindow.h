/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_File;
    QAction *actionAdd_Folder;
    QAction *actionOpen_File;
    QAction *actionOpenFolder;
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *playerGroupBox;
    QVBoxLayout *verticalLayout;
    QLabel *musicNameLabel;
    QSlider *positionHorizontalSlider;
    QGroupBox *volumeGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *volumePushButton;
    QSlider *volumeHorizontalSlider;
    QGroupBox *buttonsGroupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *previousMusicPushButton;
    QPushButton *start_pauseMusicPushButton;
    QPushButton *nextMusicPushButton;
    QListWidget *musicListWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(318, 367);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/headphones-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAdd_File = new QAction(MainWindow);
        actionAdd_File->setObjectName("actionAdd_File");
        actionAdd_Folder = new QAction(MainWindow);
        actionAdd_Folder->setObjectName("actionAdd_Folder");
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        actionOpenFolder = new QAction(MainWindow);
        actionOpenFolder->setObjectName("actionOpenFolder");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        playerGroupBox = new QGroupBox(centralwidget);
        playerGroupBox->setObjectName("playerGroupBox");
        verticalLayout = new QVBoxLayout(playerGroupBox);
        verticalLayout->setObjectName("verticalLayout");
        musicNameLabel = new QLabel(playerGroupBox);
        musicNameLabel->setObjectName("musicNameLabel");
        musicNameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(musicNameLabel);

        positionHorizontalSlider = new QSlider(playerGroupBox);
        positionHorizontalSlider->setObjectName("positionHorizontalSlider");
        positionHorizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(positionHorizontalSlider);

        volumeGroupBox = new QGroupBox(playerGroupBox);
        volumeGroupBox->setObjectName("volumeGroupBox");
        horizontalLayout_2 = new QHBoxLayout(volumeGroupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        volumePushButton = new QPushButton(volumeGroupBox);
        volumePushButton->setObjectName("volumePushButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/volume-high-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        volumePushButton->setIcon(icon1);

        horizontalLayout_2->addWidget(volumePushButton);

        volumeHorizontalSlider = new QSlider(volumeGroupBox);
        volumeHorizontalSlider->setObjectName("volumeHorizontalSlider");
        volumeHorizontalSlider->setMaximum(100);
        volumeHorizontalSlider->setValue(100);
        volumeHorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(volumeHorizontalSlider);


        verticalLayout->addWidget(volumeGroupBox);

        buttonsGroupBox = new QGroupBox(playerGroupBox);
        buttonsGroupBox->setObjectName("buttonsGroupBox");
        horizontalLayout = new QHBoxLayout(buttonsGroupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        previousMusicPushButton = new QPushButton(buttonsGroupBox);
        previousMusicPushButton->setObjectName("previousMusicPushButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/backward-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        previousMusicPushButton->setIcon(icon2);

        horizontalLayout->addWidget(previousMusicPushButton);

        start_pauseMusicPushButton = new QPushButton(buttonsGroupBox);
        start_pauseMusicPushButton->setObjectName("start_pauseMusicPushButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icons/play-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        start_pauseMusicPushButton->setIcon(icon3);

        horizontalLayout->addWidget(start_pauseMusicPushButton);

        nextMusicPushButton = new QPushButton(buttonsGroupBox);
        nextMusicPushButton->setObjectName("nextMusicPushButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icons/forward-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        nextMusicPushButton->setIcon(icon4);

        horizontalLayout->addWidget(nextMusicPushButton);


        verticalLayout->addWidget(buttonsGroupBox);


        verticalLayout_2->addWidget(playerGroupBox);

        musicListWidget = new QListWidget(centralwidget);
        musicListWidget->setObjectName("musicListWidget");

        verticalLayout_2->addWidget(musicListWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 318, 19));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAdd_File);
        menuFile->addAction(actionAdd_Folder);
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionOpenFolder);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdd_File->setText(QCoreApplication::translate("MainWindow", "Add File", nullptr));
#if QT_CONFIG(shortcut)
        actionAdd_File->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAdd_Folder->setText(QCoreApplication::translate("MainWindow", "Add Folder", nullptr));
#if QT_CONFIG(shortcut)
        actionAdd_Folder->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_File->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpenFolder->setText(QCoreApplication::translate("MainWindow", "OpenFolder", nullptr));
#if QT_CONFIG(shortcut)
        actionOpenFolder->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        playerGroupBox->setTitle(QString());
        musicNameLabel->setText(QCoreApplication::translate("MainWindow", "No music...", nullptr));
        volumeGroupBox->setTitle(QString());
        volumePushButton->setText(QString());
        buttonsGroupBox->setTitle(QString());
        previousMusicPushButton->setText(QString());
        start_pauseMusicPushButton->setText(QString());
        nextMusicPushButton->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
