#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QDirIterator>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_File_triggered();

    void on_actionOpenFolder_triggered();

    void on_start_pauseMusicPushButton_clicked();

    void on_nextMusicPushButton_clicked();

    void on_musicListWidget_currentRowChanged(int currentRow);

    void on_previousMusicPushButton_clicked();

    void on_volumeHorizontalSlider_valueChanged(int value);


    void on_durationChanged(qint64 duration);

    void on_positionChanged(qint64 position);

    void on_actionAdd_File_triggered();

    void on_actionAdd_Folder_triggered();

    void on_volumePushButton_clicked();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    void ChangePLayPause();
    bool musicPlay;
    QString selectedMusic;
    QString selectedMusicPath;
    QStringList musicPaths;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QPropertyAnimation *mMoveAnimation;
};
#endif // MAINWINDOW_H
