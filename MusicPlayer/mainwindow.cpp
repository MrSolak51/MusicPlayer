#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    selectedMusic.clear();
    selectedMusicPath.clear();
    musicPaths.clear();
    musicPlay = false;

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput();
    audioOutput->setVolume(1.0);
    player->setAudioOutput(audioOutput);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangePLayPause(){
    if (musicPlay) {
        ui->start_pauseMusicPushButton->setIcon(QIcon(":/new/icons/pause-solid.svg"));
        player->play();
    }
    else {
        ui->start_pauseMusicPushButton->setIcon(QIcon(":/new/icons/play-solid.svg"));
        player->pause();
    }
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "", "sound files(*.mp3 || *.wmv)");
    QString fileName = filePath.split("/").last().split(".").first();
    if(!fileName.isEmpty()){
        ui->musicNameLabel->setText(fileName);
        selectedMusic = fileName;
        selectedMusicPath = filePath;
        musicPlay = true;
        player->setSource(QUrl(selectedMusicPath));
        player->setPosition(0);
        ChangePLayPause();
    }
}


void MainWindow::on_actionOpenFolder_triggered()
{

    QString folderPath = QFileDialog::getExistingDirectory(this, "Open Folder", "", QFileDialog::ShowDirsOnly);

    if (!folderPath.isEmpty()) {
        if (QMessageBox::question(this, "Warning!", "Do you want to change existing folder?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {

            player->stop();

            selectedMusic.clear();
            selectedMusicPath.clear();

            ui->musicListWidget->clear();

            musicPaths.clear();

            QDirIterator it(folderPath, QStringList() << "*.wmv", QDir::Files, QDirIterator::Subdirectories);
            while (it.hasNext()){
                QString filePath = it.next();
                QString fileName = filePath.split("/").last().split(".").first();
                ui->musicListWidget->addItem(fileName);
                musicPaths.push_back(filePath);
            }
            QDirIterator it1(folderPath, QStringList() << "*.mp3", QDir::Files, QDirIterator::Subdirectories);
            while (it1.hasNext()){
                QString filePath = it1.next();
                QString fileName = filePath.split("/").last().split(".").first();
                ui->musicListWidget->addItem(fileName);
                musicPaths.push_back(filePath);
            }

            ui->musicListWidget->setCurrentRow(0);
            musicPlay = false;
            ui->musicNameLabel->setText("No music...");
            ChangePLayPause();
        }
    }
}


void MainWindow::on_start_pauseMusicPushButton_clicked()
{
    if (!selectedMusic.isEmpty()) {
        if (musicPlay) {
            musicPlay = false;
            ChangePLayPause();
        }
        else {
            musicPlay = true;
            ChangePLayPause();
        }
    }
}


void MainWindow::on_nextMusicPushButton_clicked()
{
    if (ui->musicListWidget->currentRow() < ui->musicListWidget->count() - 1) {
        ui->musicListWidget->setCurrentRow(ui->musicListWidget->currentRow() + 1);
    }
    else{
        ui->musicListWidget->setCurrentRow(0);
    }
}


void MainWindow::on_previousMusicPushButton_clicked()
{

    if (ui->musicListWidget->currentRow() > 0) {
        ui->musicListWidget->setCurrentRow(ui->musicListWidget->currentRow() - 1);
    }
    else{
        ui->musicListWidget->setCurrentRow(ui->musicListWidget->count() - 1);
    }
}


void MainWindow::on_musicListWidget_currentRowChanged(int currentRow)
{
    if (ui->musicListWidget->currentItem() != NULL) {
        QFontMetrics metrics(ui->musicNameLabel->font());
        QString elidedText = metrics.elidedText(ui->musicListWidget->currentItem()->text(), Qt::ElideRight, ui->musicNameLabel->width());
        ui->musicNameLabel->setText(elidedText);

        musicPlay = true;
        selectedMusic = ui->musicListWidget->currentItem()->text();
        for (QString path : musicPaths) {
            if (path.contains(selectedMusic)) {
                selectedMusicPath = path;
                musicPlay = true;
                player->setSource(QUrl(selectedMusicPath));
                player->setPosition(0);
                ChangePLayPause();
            }
        }
        ChangePLayPause();
    }
}


void MainWindow::on_volumeHorizontalSlider_valueChanged(int value)
{
    audioOutput->setVolume(((float)value)/100);
    if (value > 50) {
        ui->volumePushButton->setIcon(QIcon(":/new/icons/volume-high-solid.svg"));
    }else if (value > 0) {
        ui->volumePushButton->setIcon(QIcon(":/new/icons/volume-low-solid.svg"));
    }else {
        ui->volumePushButton->setIcon(QIcon(":/new/icons/volume-off-solid.svg"));
    }
}


void MainWindow::on_durationChanged(qint64 duration){
    ui->positionHorizontalSlider->setMaximum(duration);
}

void MainWindow::on_positionChanged(qint64 position){
    ui->positionHorizontalSlider->setValue(position);
}

void MainWindow::on_actionAdd_File_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Add File", "", "sound files(*.mp3 || *.wmv)");
    QString fileName = filePath.split("/").last().split(".").first();
    if(!fileName.isEmpty()){
        musicPaths.push_back(filePath);
        ui->musicListWidget->addItem(fileName);
    }
}


void MainWindow::on_actionAdd_Folder_triggered()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Add Folder", "", QFileDialog::ShowDirsOnly);
    QDirIterator it(folderPath, QStringList() << "*.wmv", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){
        QString filePath = it.next();
        QString fileName = filePath.split("/").last().split(".").first();
        ui->musicListWidget->addItem(fileName);

        musicPaths.push_back(filePath);

        musicPlay = false;
        ChangePLayPause();
        selectedMusic.clear();
    }
    QDirIterator it1(folderPath, QStringList() << "*.mp3", QDir::Files, QDirIterator::Subdirectories);
    while (it1.hasNext()){
        QString filePath = it1.next();
        QString fileName = filePath.split("/").last().split(".").first();
        ui->musicListWidget->addItem(fileName);

        musicPaths.push_back(filePath);

        musicPlay = false;
        ChangePLayPause();
        selectedMusic.clear();
    }
}


void MainWindow::on_volumePushButton_clicked()
{
    if (ui->volumeHorizontalSlider->value() == 0) {
        ui->volumeHorizontalSlider->setValue(100);
        ui->volumePushButton->setIcon(QIcon(":/new/icons/volume-high-solid.svg"));
    }
    else{
        ui->volumeHorizontalSlider->setValue(0);
        ui->volumePushButton->setIcon(QIcon(":/new/icons/volume-off-solid.svg"));
    }
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

