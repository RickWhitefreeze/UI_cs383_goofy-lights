#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include <QDialog>
#include <QVector2D>

namespace Ui {
class NewFileDialog;
}

class NewFileDialog : public QDialog
{
    Q_OBJECT

public:
    static QVector2D getFrameDim(QWidget *parent = 0, const QString &caption = QString());

    explicit NewFileDialog(QWidget *parent = 0, const QString &caption = QString());
    ~NewFileDialog();

public slots:
    void accept();

private:
    Ui::NewFileDialog *ui;
    QVector2D dimension;
};

#endif // NEWFILEDIALOG_H
