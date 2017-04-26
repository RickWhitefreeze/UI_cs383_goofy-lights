/********************************************************************************
** Form generated from reading UI file 'newfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFILEDIALOG_H
#define UI_NEWFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_NewFileDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinWidth;
    QSpinBox *spinHeight;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewFileDialog)
    {
        if (NewFileDialog->objectName().isEmpty())
            NewFileDialog->setObjectName(QStringLiteral("NewFileDialog"));
        NewFileDialog->resize(165, 96);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewFileDialog->sizePolicy().hasHeightForWidth());
        NewFileDialog->setSizePolicy(sizePolicy);
        NewFileDialog->setMinimumSize(QSize(165, 96));
        NewFileDialog->setMaximumSize(QSize(165, 96));
        formLayout = new QFormLayout(NewFileDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(NewFileDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(NewFileDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinWidth = new QSpinBox(NewFileDialog);
        spinWidth->setObjectName(QStringLiteral("spinWidth"));
        spinWidth->setMaximumSize(QSize(110, 16777215));
        spinWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinWidth->setMinimum(1);
        spinWidth->setMaximum(50);
        spinWidth->setValue(15);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinWidth);

        spinHeight = new QSpinBox(NewFileDialog);
        spinHeight->setObjectName(QStringLiteral("spinHeight"));
        spinHeight->setMaximumSize(QSize(110, 16777215));
        spinHeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinHeight->setMinimum(1);
        spinHeight->setMaximum(50);
        spinHeight->setValue(20);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinHeight);

        buttonBox = new QDialogButtonBox(NewFileDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setMaximumSize(QSize(110, 16777215));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::FieldRole, buttonBox);


        retranslateUi(NewFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewFileDialog);
    } // setupUi

    void retranslateUi(QDialog *NewFileDialog)
    {
        NewFileDialog->setWindowTitle(QApplication::translate("NewFileDialog", "Frame Size", Q_NULLPTR));
        label->setText(QApplication::translate("NewFileDialog", "Width", Q_NULLPTR));
        label_2->setText(QApplication::translate("NewFileDialog", "Height", Q_NULLPTR));
        spinWidth->setSuffix(QApplication::translate("NewFileDialog", " px", Q_NULLPTR));
        spinHeight->setSuffix(QApplication::translate("NewFileDialog", " px", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewFileDialog: public Ui_NewFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILEDIALOG_H
