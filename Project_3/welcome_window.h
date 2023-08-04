#include <QLabel>
#include <QtWidgets>
#include <QLabel>
#include <QColor>
#include <QFont>
#include <QDir>
#include <QPainter>
#include <QPushButton>

int welcome_window(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget window;
    window.setFixedSize(574, 427);

//Color Window and add background image
    QPalette pal = window.palette();
    window.setStyleSheet("QWidget {background-image: url(../Images/bcko.png)}");

//Add Welcome text to window
    QLabel *welcomeLabel = new QLabel(&window);
    welcomeLabel->setText("Welcome To Our Application");

//change font size and font type
    QFont f("Arial", 15);
    welcomeLabel->setFont(f);

//center text and change color
    welcomeLabel->setStyleSheet("QLabel {color : white; background: transparent}");
    welcomeLabel->move(286 - (welcomeLabel->sizeHint().width() / 2), 36);

// Add button
    QPushButton button ("Start!", &window);
    button.move(286 - (button.sizeHint().width() / 2), 330);
    button.setStyleSheet("QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");
    window.show();
    window.setWindowTitle(
            QApplication::translate("toplevel", "Project 3"));
    return app.exec();
}
