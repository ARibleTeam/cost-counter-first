#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    if((ui->weigth->text()).isEmpty() || (ui->cost->text()).isEmpty()) return;
    if((ui->cost->text().count('.') > 1) || (ui->weigth->text().count('.') > 1)){
        ui->price_result->setText("Ошибка ввода!");
        return;
    }

    QChar numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    // когда функция выполнится, выделенная память очиститься. Поэтому, я думаю, не стоит в данном случае делать временные переменные.
    bool this_number = false;

    QString price = ui->cost->text().replace(',', '.');
    for(auto& first : price) {
        this_number = false;
        for(auto& second : numbers) {
            if(first == second) {
                this_number = true;
                break;
            }
        }
        if(this_number == false) break;
    }

    if(!this_number) {
        ui->price_result->setText("Ошибка ввода!");
        return;
    }

    QString weigth = ui->weigth->text().replace(',', '.');

    for(auto& first : weigth) {
        this_number = false;
        for(auto& second : numbers) {
            if(first == second) {
                this_number = true;
                break;
            }
        }
        if(this_number == false) break;
    }

    if(!this_number) {
        ui->price_result->setText("Ошибка ввода!");
        return;
    }

    ui->price_result->setText("Итоговая стоимость: " + QString::number(double(price.toDouble() * weigth.toDouble())) + " руб");
}

