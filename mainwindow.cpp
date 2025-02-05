#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Открыть изображение"), "", tr("Изображения (*.png *.jpg)")); // выбор фильтруя файлы

    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            ui->label->setPixmap(pixmap);
            ui->label->adjustSize();
        }
        else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось загрузить изображение."));
        }
    }

}

