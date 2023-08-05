//
// Created by deepd on 8/5/2023.
//
#pragma once
#include <QLabel>
#include <QtWidgets>
#include <QLabel>
#include <QColor>
#include <QFont>
#include <QDir>
#include <QPainter>
#include <QPushButton>

#ifndef PROJECT_3_EARTHQUAKETABLE_H
#define PROJECT_3_EARTHQUAKETABLE_H
void earthquakeTable_window()
{
    QWidget temp;
    temp.setFixedSize(574, 427);

// Color Window and add background image
    temp.setStyleSheet("QWidget {background-image: url(../Images/bcko.png)}");

// Initialize buttons
    QPushButton dateSort("Date", &temp);
    dateSort.move(286 - (dateSort.sizeHint().width() / 2), 330);
    dateSort.setStyleSheet(
            "QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");

    QPushButton magnitudeSort("MagnitudeSort", &temp);
    magnitudeSort.move(270 - (magnitudeSort.sizeHint().width() / 2), 330);
    magnitudeSort.setStyleSheet(
            "QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");

    QPushButton longitudeSort("Longitude", &temp);
    longitudeSort.move(292 - (longitudeSort.sizeHint().width() / 2), 330);
    longitudeSort.setStyleSheet(
            "QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");

    QPushButton latitudeSort("Latitude", &temp);
    latitudeSort.move(308 - (latitudeSort.sizeHint().width() / 2), 330);
    latitudeSort.setStyleSheet(
            "QPushButton {background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}");

// Add welcome label
    QLabel *welcomeLabel = new QLabel(&temp);
    welcomeLabel->setText("Welcome to the sorting window!");
    QFont f("Arial", 15);
    welcomeLabel->setFont(f);
    welcomeLabel->move(50, 50);
    welcomeLabel->setStyleSheet("QLabel {color : white; background: transparent}");

    temp.show();  // Make the QWidget visible
    qDebug() << "Button clicked!";
}

#endif //PROJECT_3_EARTHQUAKETABLE_H
