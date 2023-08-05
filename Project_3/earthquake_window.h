#pragma once
#include <QLabel>
#include <iostream>
#include <QtWidgets>
#include <QLabel>
#include <QColor>
#include <QFont>
#include <QDir>
#include <QPainter>
#include <QPushButton>
#include "EarthquakeData.h"
#include <functional>
#include "quicksort.h"
#include "mergesort.h"
#include "comparators.h"
using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::endl;

QByteArray BUTTON_STYLE = "QPushButton {color: white; background: rgb(91,10,10); border-style: outset; border-width: 1.2px; border-radius: 5px;  border-color: black; font: bold 14px; min-width: 3em;  padding: 6px;}";
QString HEADER_STRING = QString::fromStdString("Magnitude\t\tLatitude\t\tLongitude\t\tDate");

class Earthquake_window{
    QWidget* earthquakeWindow;

public:
    Earthquake_window(vector<EarthquakeData>& earthquakeData, vector<EarthquakeData>& earthquakeData2, std::function<bool(const EarthquakeData&, const EarthquakeData&, string operation, bool equals)>& comparator)
    {
        earthquakeWindow = new QWidget();
        earthquakeWindow->setFixedSize(725, 427);
        earthquakeWindow->setStyleSheet("QWidget {background-image: url(../Images/bcko.png)}");
        QFont f("Arial", 15);

        QLabel* earthquakeLabel = new QLabel("Earthquake Data");
        earthquakeLabel->setFont(f);
        earthquakeLabel->setStyleSheet("QLabel {color : white; background: transparent}");
        earthquakeLabel->move(286- ((earthquakeWindow->width() - earthquakeLabel->sizeHint().width()) / 2), 10);

        auto buttonLayout = new QHBoxLayout;
        QVBoxLayout* listLayout = new QVBoxLayout;
        QListWidget* listWidget = new QListWidget;
        listWidget->setStyleSheet("QListWidget {background:transparent;} QListWidget::item {background:rgba(0,0,0,0.75);color: white;}");
        listLayout->addWidget(listWidget);

        QPushButton* dateSort = new QPushButton("Date");
        dateSort->setStyleSheet(BUTTON_STYLE);

        QObject::connect(dateSort, &QPushButton::clicked, [&, listWidget]() {
            comparator = compareByDate;

            // quicksort
            auto start_quick = std::chrono::high_resolution_clock::now();
            quickSort(earthquakeData, comparator);
            auto end_quick = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

            // mergesort
            auto start_merge = std::chrono::high_resolution_clock::now();
            mergeSort(earthquakeData2, comparator);
            auto end_merge = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_merge = end_merge - start_merge;

            QString message = "Quicksort took: " + QString::number(elapsed_quick.count()) + " seconds.\n" +
                              "Mergesort took: " + QString::number(elapsed_merge.count()) + " seconds.\n";
            QMessageBox messageBox;
            messageBox.setWindowTitle("Sorting times");
            messageBox.setText(message);
            messageBox.setStyleSheet("QLabel{min-width: 400 px; font-size: 16px; color: white;} QMessageBox{background-color: rgba(0,0,0, 70%);}");
            messageBox.exec();
            listWidget->clear();

            // headers
            QListWidgetItem* header = new QListWidgetItem(HEADER_STRING);
            listWidget->addItem(header);
            // content
            for (auto i: earthquakeData) {
                QString qstr = QString::fromStdString(i.toString());
                QListWidgetItem* item = new QListWidgetItem(qstr);
                QUrl url = QUrl(QString::fromStdString(i.getURL()));
                item->setData(Qt::UserRole, url);
                listWidget->addItem(item);
            }
            listWidget->show();

            QObject::connect(listWidget, &QListWidget::itemClicked, [&](QListWidgetItem* item){
                QUrl url = item->data(Qt::UserRole).toUrl();
                if (url.isValid()) {
                    QDesktopServices::openUrl(url);
                }
            });

        });
        buttonLayout->addWidget(dateSort);

        QPushButton* magnitudeSort = new QPushButton("Magnitude");

        magnitudeSort->setStyleSheet(BUTTON_STYLE);
        QObject::connect(magnitudeSort, &QPushButton::clicked, [&, listWidget]() {
            comparator = compareByMagnitude;

            // quicksort
            auto start_quick = std::chrono::high_resolution_clock::now();
            quickSort(earthquakeData, comparator);
            auto end_quick = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

            // mergesort
            auto start_merge = std::chrono::high_resolution_clock::now();
            mergeSort(earthquakeData2, comparator);
            auto end_merge = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_merge = end_merge - start_merge;

            QString message = "Quicksort took: " + QString::number(elapsed_quick.count()) + " seconds.\n" +
                              "Mergesort took: " + QString::number(elapsed_merge.count()) + " seconds.\n";
            QMessageBox messageBox;
            messageBox.setWindowTitle("Sorting times");
            messageBox.setText(message);
            messageBox.setStyleSheet("QLabel{min-width: 400 px; font-size: 16px; color: white;} QMessageBox{background-color: rgba(0,0,0, 70%);}");
            messageBox.exec();
            listWidget->clear();

            // headers
            QListWidgetItem* header = new QListWidgetItem(HEADER_STRING);
            listWidget->addItem(header);
            // content
            for (auto i: earthquakeData) {
                QString qstr = QString::fromStdString(i.toString());
                QListWidgetItem* item = new QListWidgetItem(qstr);
                QUrl url = QUrl(QString::fromStdString(i.getURL()));
                item->setData(Qt::UserRole, url);
                listWidget->addItem(item);
            }
            listWidget->show();

            QObject::connect(listWidget, &QListWidget::itemClicked, [&](QListWidgetItem* item){
                QUrl url = item->data(Qt::UserRole).toUrl();
                if (url.isValid()) {
                    QDesktopServices::openUrl(url);
                }
            });
        });
        buttonLayout->addWidget(magnitudeSort);

        QPushButton* longitudeSort = new QPushButton("Longitude");
        longitudeSort->setStyleSheet(BUTTON_STYLE);
        QObject::connect(longitudeSort, &QPushButton::clicked, [&, listWidget]() {
            comparator = compareByLongitude;

            // quicksort
            auto start_quick = std::chrono::high_resolution_clock::now();
            quickSort(earthquakeData, comparator);
            auto end_quick = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

            // mergesort
            auto start_merge = std::chrono::high_resolution_clock::now();
            mergeSort(earthquakeData2, comparator);
            auto end_merge = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_merge = end_merge - start_merge;
            //cout << "Quicksort took: " << elapsed_quick.count() << " seconds.\n";
            //cout << "Mergesort took: " << elapsed_merge.count() << " seconds.\n\n";
            QString message = "Quicksort took: " + QString::number(elapsed_quick.count()) + " seconds.\n" +
                              "Mergesort took: " + QString::number(elapsed_merge.count()) + " seconds.\n";
            QMessageBox messageBox;
            messageBox.setWindowTitle("Sorting times");
            messageBox.setText(message);
            messageBox.setStyleSheet("QLabel{min-width: 400 px; font-size: 16px; color: white;} QMessageBox{background-color: rgba(0,0,0, 70%);}");
            messageBox.exec();
            listWidget->clear();

            // headers
            QListWidgetItem* header = new QListWidgetItem(HEADER_STRING);
            listWidget->addItem(header);
            // content
            for (auto i: earthquakeData) {
                QString qstr = QString::fromStdString(i.toString());
                QListWidgetItem* item = new QListWidgetItem(qstr);
                QUrl url = QUrl(QString::fromStdString(i.getURL()));
                item->setData(Qt::UserRole, url);
                listWidget->addItem(item);
            }
            listWidget->show();

            QObject::connect(listWidget, &QListWidget::itemClicked, [&](QListWidgetItem* item){
                QUrl url = item->data(Qt::UserRole).toUrl();
                if (url.isValid()) {
                    QDesktopServices::openUrl(url);
                }
            });
        });

        buttonLayout->addWidget(longitudeSort);

        QPushButton* latitudeSort = new QPushButton("Latitude");
        latitudeSort->setStyleSheet(BUTTON_STYLE);
        QObject::connect(latitudeSort, &QPushButton::clicked, [&, listWidget]() {
            comparator = compareByLatitude;

            // quicksort
            auto start_quick = std::chrono::high_resolution_clock::now();
            quickSort(earthquakeData, comparator);
            auto end_quick = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

            // mergesort
            auto start_merge = std::chrono::high_resolution_clock::now();
            mergeSort(earthquakeData2, comparator);
            auto end_merge = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_merge = end_merge - start_merge;

            QString message = "Quicksort took: " + QString::number(elapsed_quick.count()) + " seconds.\n" +
                              "Mergesort took: " + QString::number(elapsed_merge.count()) + " seconds.\n";
            QMessageBox messageBox;
            messageBox.setWindowTitle("Sorting times");
            messageBox.setText(message);
            messageBox.setStyleSheet("QLabel{min-width: 400 px; font-size: 16px; color: white;} QMessageBox{background-color: rgba(0,0,0, 70%);}");
            messageBox.exec();
            listWidget->clear();

            // headers
            QListWidgetItem* header = new QListWidgetItem(HEADER_STRING);
            listWidget->addItem(header);
            // content
            for (auto i: earthquakeData) {
                QString qstr = QString::fromStdString(i.toString());
                QListWidgetItem* item = new QListWidgetItem(qstr);
                QUrl url = QUrl(QString::fromStdString(i.getURL()));
                item->setData(Qt::UserRole, url);
                listWidget->addItem(item);
            }
            listWidget->show();

            QObject::connect(listWidget, &QListWidget::itemClicked, [&](QListWidgetItem* item){
                QUrl url = item->data(Qt::UserRole).toUrl();
                if (url.isValid()) {
                    QDesktopServices::openUrl(url);
                }
            });
        });
        buttonLayout->addWidget(latitudeSort);

        QVBoxLayout* mainLayout = new QVBoxLayout;
        mainLayout->addWidget(earthquakeLabel);
        mainLayout->addLayout(listLayout);
        mainLayout->addLayout(buttonLayout);
        earthquakeLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        earthquakeWindow->setLayout(mainLayout);

    }

    void show()
    {
        earthquakeWindow->show();
    }

    ~Earthquake_window()
    {
        delete earthquakeWindow;
    }

};