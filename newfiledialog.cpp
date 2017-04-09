#include "newfiledialog.h"
#include "ui_newfiledialog.h"

void NewFileDialog::accept(){
    dimension.setX(ui->spinWidth->value());
    dimension.setY(ui->spinHeight->value());
    close();
}

QVector2D NewFileDialog::getFrameDim(QWidget *parent, const QString &caption){
    NewFileDialog *dialog = new NewFileDialog(parent, caption);
    dialog->exec();
    return dialog->dimension;
}

NewFileDialog::NewFileDialog(QWidget *parent, const QString &caption) :
    QDialog(parent, Qt::WindowTitleHint),
    ui(new Ui::NewFileDialog)
{
    ui->setupUi(this);
    setWindowTitle(caption);
}


NewFileDialog::~NewFileDialog()
{
    delete ui;
}
