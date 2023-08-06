#pragma once
#include <QLabel>
#include <QtWidgets>
#include <QLabel>
#include <QColor>
#include <QFont>
#include <QDir>
#include <QPainter>
#include <QPushButton>
#include "earthquake_window.h"

class WelcomeWindow{
    QWidget* welcomeWindow;
public:

    WelcomeWindow(vector<EarthquakeData>& earthquakeData, vector<EarthquakeData>& earthquakeData2, std::function<bool(const EarthquakeData&, const EarthquakeData&, string operation, bool equals)>& comparator)
    {
        welcomeWindow = new QWidget();
        welcomeWindow->setFixedSize(574, 427);

        //Color Window and add background image
        QPalette pal = welcomeWindow->palette();
        welcomeWindow->setStyleSheet("QWidget {background-image: url(../Images/bcko.png)}");

        //Add Welcome text to window
        QLabel *welcomeLabel = new QLabel(welcomeWindow);
        welcomeLabel->setText("Welcome To Our Application");

        //change font size and font type
        QFont f("Arial", 15);
        welcomeLabel->setFont(f);

        //center text and change color
        welcomeLabel->setStyleSheet("QLabel {color : white; background: transparent}");
        welcomeLabel->move(286 - (welcomeLabel->sizeHint().width() / 2), 36);

        // Add button
        QPushButton* welcomebutton = new QPushButton("Start!", welcomeWindow);
        //QPushButton button ("Start!", welcomeWindow);
        welcomebutton->move(286 - (welcomebutton->sizeHint().width() / 2), 330);
        welcomebutton->setStyleSheet("QPushButton {color: white; background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;} QPushButton:pressed {color: white; background: green; border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");

        // Set Title
        welcomeWindow->setWindowTitle(QApplication::translate("toplevel", "Project 3"));

        QObject::connect(welcomebutton, &QPushButton::clicked, [&]() {
            welcomeWindow->close();
            delete welcomeWindow;
            Earthquake_window* earthquakeWindow = new Earthquake_window(earthquakeData, earthquakeData2, comparator);
            earthquakeWindow->show();
        });
    }

    ~WelcomeWindow()
    {
        // This also deletes all the children of welcomeWindow
        delete welcomeWindow;
    }

    void show()
    {
        welcomeWindow->show();
    }

    void close()
    {
        welcomeWindow->close();
    }

};