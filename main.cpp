#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Gym Management System");
    window.resize(400, 350);

    QLabel *title = new QLabel("GYM MANAGEMENT SYSTEM");
    title->setStyleSheet("font-size:18px; font-weight:bold; color:red;");
    title->setAlignment(Qt::AlignCenter);

    QLabel *nameLabel = new QLabel("Name:");
    QLineEdit *nameEdit = new QLineEdit();

    QLabel *ageLabel = new QLabel("Age:");
    QLineEdit *ageEdit = new QLineEdit();

    QLabel *weightLabel = new QLabel("Weight:");
    QLineEdit *weightEdit = new QLineEdit();

    QLabel *memberLabel = new QLabel("Membership:");
    QLineEdit *memberEdit = new QLineEdit();

    QPushButton *addBtn = new QPushButton("Add Member");
    QPushButton *clearBtn = new QPushButton("Clear");

    addBtn->setStyleSheet("background-color:green; color:white; padding:6px;");
    clearBtn->setStyleSheet("background-color:gray; color:white; padding:6px;");

    QObject::connect(addBtn, &QPushButton::clicked, [&](){
        if(nameEdit->text().isEmpty() ||
            ageEdit->text().isEmpty() ||
            weightEdit->text().isEmpty() ||
            memberEdit->text().isEmpty())
        {
            QMessageBox::warning(&window, "Error", "Please fill all fields");
            return;
        }

        QMessageBox::information(
            &window,
            "Success",
            "Member Added Successfully!\n\nName: " + nameEdit->text()
            );
    });

    QObject::connect(clearBtn, &QPushButton::clicked, [&](){
        nameEdit->clear();
        ageEdit->clear();
        weightEdit->clear();
        memberEdit->clear();
    });

    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(title);
    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);
    layout->addWidget(ageLabel);
    layout->addWidget(ageEdit);
    layout->addWidget(weightLabel);
    layout->addWidget(weightEdit);
    layout->addWidget(memberLabel);
    layout->addWidget(memberEdit);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(addBtn);
    btnLayout->addWidget(clearBtn);

    layout->addLayout(btnLayout);

    window.setLayout(layout);
    window.show();

    return app.exec();
}

