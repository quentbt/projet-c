#include "quizzdesign.h"
#include "ui_quizzdesign.h"

quizzdesign::quizzdesign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::quizzdesign)
{
    ui->setupUi(this);
}

quizzdesign::~quizzdesign()
{
    delete ui;
}

