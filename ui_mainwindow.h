/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblPort;
    QComboBox *portList;
    QLabel *lblBaudRate;
    QComboBox *baudrateList;
    QPushButton *connectButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblDataBits;
    QComboBox *cbDataBits;
    QLabel *lblParity;
    QComboBox *cbParity;
    QLabel *lblStopBits;
    QComboBox *cbStopBits;
    QLabel *lblFlowControl;
    QComboBox *cbFlowControl;
    QPushButton *disconnectButton;
    QFrame *line_7;
    QGridLayout *gridLayout_2;
    QFrame *line_15;
    QFrame *line_13;
    QFrame *line_12;
    QLabel *lblCh7;
    QFrame *line_11;
    QFrame *line_18;
    QCheckBox *chFilter4;
    QCheckBox *chFilter6;
    QLabel *lblCh8;
    QLabel *lblADC3;
    QCheckBox *chFilter8;
    QLabel *lblADC5;
    QCheckBox *chFilter10;
    QLabel *lblADC4;
    QCheckBox *chFilter2;
    QLabel *lblADC1;
    QLabel *lblCh1;
    QLabel *lblCh10;
    QFrame *line_17;
    QLabel *lblCh3;
    QLabel *lblADC2;
    QLabel *lblCh9;
    QLabel *lblCh4;
    QCheckBox *chFilter7;
    QCheckBox *chFilter5;
    QLabel *lblCurrentData;
    QLabel *lblCh6;
    QLabel *lblCh5;
    QCheckBox *chFilter3;
    QLabel *lblCh2;
    QFrame *line_10;
    QLabel *lblADC9;
    QFrame *line_16;
    QLabel *lblADC8;
    QCheckBox *chFilter1;
    QLabel *lblADC7;
    QFrame *line_9;
    QCheckBox *chFilter9;
    QFrame *line_14;
    QLabel *lblADC6;
    QLabel *lblADC10;
    QFrame *line_19;
    QFrame *line_5;
    QCustomPlot *customPlot;
    QFrame *line_6;
    QGridLayout *gridLayout;
    QPushButton *btnVisiblePlot4;
    QPushButton *btnVisiblePlot10;
    QPushButton *btnVisiblePlot3;
    QPushButton *btnVisiblePlot8;
    QPushButton *btnVisiblePlot6;
    QPushButton *btnVisiblePlot2;
    QPushButton *btnVisiblePlot1;
    QPushButton *btnVisiblePlot5;
    QPushButton *btnVisiblePlot9;
    QPushButton *btnVisiblePlot7;
    QFrame *line;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *leAlpha;
    QPushButton *pushButton;
    QPushButton *btnChangeFilterType;
    QLabel *label_3;
    QLineEdit *leWindow;
    QPushButton *btnMAWindowEdit;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblXmin;
    QLineEdit *eXmin;
    QLabel *lblXmax;
    QLineEdit *eXmax;
    QLabel *lblYmin;
    QLineEdit *eYmin;
    QLabel *lblYmax;
    QLineEdit *eYmax;
    QPushButton *btnUpdatePlotRange;
    QPushButton *btnClearPlot;
    QFrame *line_8;
    QTextEdit *outputText;
    QFrame *line_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnOutputSaver;
    QPushButton *btnSaveCSV;
    QFrame *line_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1131, 1020);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lblPort = new QLabel(centralwidget);
        lblPort->setObjectName(QString::fromUtf8("lblPort"));
        lblPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lblPort);

        portList = new QComboBox(centralwidget);
        portList->setObjectName(QString::fromUtf8("portList"));

        horizontalLayout_3->addWidget(portList);

        lblBaudRate = new QLabel(centralwidget);
        lblBaudRate->setObjectName(QString::fromUtf8("lblBaudRate"));
        lblBaudRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lblBaudRate);

        baudrateList = new QComboBox(centralwidget);
        baudrateList->setObjectName(QString::fromUtf8("baudrateList"));

        horizontalLayout_3->addWidget(baudrateList);

        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        horizontalLayout_3->addWidget(connectButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblDataBits = new QLabel(centralwidget);
        lblDataBits->setObjectName(QString::fromUtf8("lblDataBits"));
        lblDataBits->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblDataBits);

        cbDataBits = new QComboBox(centralwidget);
        cbDataBits->setObjectName(QString::fromUtf8("cbDataBits"));

        horizontalLayout_2->addWidget(cbDataBits);

        lblParity = new QLabel(centralwidget);
        lblParity->setObjectName(QString::fromUtf8("lblParity"));
        lblParity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblParity);

        cbParity = new QComboBox(centralwidget);
        cbParity->setObjectName(QString::fromUtf8("cbParity"));

        horizontalLayout_2->addWidget(cbParity);

        lblStopBits = new QLabel(centralwidget);
        lblStopBits->setObjectName(QString::fromUtf8("lblStopBits"));
        lblStopBits->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblStopBits);

        cbStopBits = new QComboBox(centralwidget);
        cbStopBits->setObjectName(QString::fromUtf8("cbStopBits"));

        horizontalLayout_2->addWidget(cbStopBits);

        lblFlowControl = new QLabel(centralwidget);
        lblFlowControl->setObjectName(QString::fromUtf8("lblFlowControl"));
        lblFlowControl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblFlowControl);

        cbFlowControl = new QComboBox(centralwidget);
        cbFlowControl->setObjectName(QString::fromUtf8("cbFlowControl"));

        horizontalLayout_2->addWidget(cbFlowControl);

        disconnectButton = new QPushButton(centralwidget);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));

        horizontalLayout_2->addWidget(disconnectButton);


        verticalLayout->addLayout(horizontalLayout_2);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_7);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        line_15 = new QFrame(centralwidget);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_15, 2, 14, 1, 1);

        line_13 = new QFrame(centralwidget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_13, 2, 10, 1, 1);

        line_12 = new QFrame(centralwidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_12, 2, 8, 1, 1);

        lblCh7 = new QLabel(centralwidget);
        lblCh7->setObjectName(QString::fromUtf8("lblCh7"));

        gridLayout_2->addWidget(lblCh7, 1, 13, 1, 1);

        line_11 = new QFrame(centralwidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_11, 2, 6, 1, 1);

        line_18 = new QFrame(centralwidget);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setFrameShape(QFrame::VLine);
        line_18->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_18, 2, 0, 1, 1);

        chFilter4 = new QCheckBox(centralwidget);
        chFilter4->setObjectName(QString::fromUtf8("chFilter4"));

        gridLayout_2->addWidget(chFilter4, 3, 7, 1, 1);

        chFilter6 = new QCheckBox(centralwidget);
        chFilter6->setObjectName(QString::fromUtf8("chFilter6"));

        gridLayout_2->addWidget(chFilter6, 3, 11, 1, 1);

        lblCh8 = new QLabel(centralwidget);
        lblCh8->setObjectName(QString::fromUtf8("lblCh8"));

        gridLayout_2->addWidget(lblCh8, 1, 15, 1, 1);

        lblADC3 = new QLabel(centralwidget);
        lblADC3->setObjectName(QString::fromUtf8("lblADC3"));
        QFont font;
        font.setFamily(QString::fromUtf8("Myanmar Text"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lblADC3->setFont(font);

        gridLayout_2->addWidget(lblADC3, 2, 5, 1, 1);

        chFilter8 = new QCheckBox(centralwidget);
        chFilter8->setObjectName(QString::fromUtf8("chFilter8"));

        gridLayout_2->addWidget(chFilter8, 3, 15, 1, 1);

        lblADC5 = new QLabel(centralwidget);
        lblADC5->setObjectName(QString::fromUtf8("lblADC5"));
        lblADC5->setFont(font);

        gridLayout_2->addWidget(lblADC5, 2, 9, 1, 1);

        chFilter10 = new QCheckBox(centralwidget);
        chFilter10->setObjectName(QString::fromUtf8("chFilter10"));

        gridLayout_2->addWidget(chFilter10, 3, 19, 1, 1);

        lblADC4 = new QLabel(centralwidget);
        lblADC4->setObjectName(QString::fromUtf8("lblADC4"));
        lblADC4->setFont(font);

        gridLayout_2->addWidget(lblADC4, 2, 7, 1, 1);

        chFilter2 = new QCheckBox(centralwidget);
        chFilter2->setObjectName(QString::fromUtf8("chFilter2"));

        gridLayout_2->addWidget(chFilter2, 3, 3, 1, 1);

        lblADC1 = new QLabel(centralwidget);
        lblADC1->setObjectName(QString::fromUtf8("lblADC1"));
        lblADC1->setFont(font);

        gridLayout_2->addWidget(lblADC1, 2, 1, 1, 1);

        lblCh1 = new QLabel(centralwidget);
        lblCh1->setObjectName(QString::fromUtf8("lblCh1"));

        gridLayout_2->addWidget(lblCh1, 1, 1, 1, 1);

        lblCh10 = new QLabel(centralwidget);
        lblCh10->setObjectName(QString::fromUtf8("lblCh10"));

        gridLayout_2->addWidget(lblCh10, 1, 19, 1, 1);

        line_17 = new QFrame(centralwidget);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setFrameShape(QFrame::VLine);
        line_17->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_17, 2, 18, 1, 1);

        lblCh3 = new QLabel(centralwidget);
        lblCh3->setObjectName(QString::fromUtf8("lblCh3"));

        gridLayout_2->addWidget(lblCh3, 1, 5, 1, 1);

        lblADC2 = new QLabel(centralwidget);
        lblADC2->setObjectName(QString::fromUtf8("lblADC2"));
        lblADC2->setFont(font);

        gridLayout_2->addWidget(lblADC2, 2, 3, 1, 1);

        lblCh9 = new QLabel(centralwidget);
        lblCh9->setObjectName(QString::fromUtf8("lblCh9"));

        gridLayout_2->addWidget(lblCh9, 1, 17, 1, 1);

        lblCh4 = new QLabel(centralwidget);
        lblCh4->setObjectName(QString::fromUtf8("lblCh4"));

        gridLayout_2->addWidget(lblCh4, 1, 7, 1, 1);

        chFilter7 = new QCheckBox(centralwidget);
        chFilter7->setObjectName(QString::fromUtf8("chFilter7"));

        gridLayout_2->addWidget(chFilter7, 3, 13, 1, 1);

        chFilter5 = new QCheckBox(centralwidget);
        chFilter5->setObjectName(QString::fromUtf8("chFilter5"));

        gridLayout_2->addWidget(chFilter5, 3, 9, 1, 1);

        lblCurrentData = new QLabel(centralwidget);
        lblCurrentData->setObjectName(QString::fromUtf8("lblCurrentData"));

        gridLayout_2->addWidget(lblCurrentData, 0, 1, 1, 1);

        lblCh6 = new QLabel(centralwidget);
        lblCh6->setObjectName(QString::fromUtf8("lblCh6"));

        gridLayout_2->addWidget(lblCh6, 1, 11, 1, 1);

        lblCh5 = new QLabel(centralwidget);
        lblCh5->setObjectName(QString::fromUtf8("lblCh5"));

        gridLayout_2->addWidget(lblCh5, 1, 9, 1, 1);

        chFilter3 = new QCheckBox(centralwidget);
        chFilter3->setObjectName(QString::fromUtf8("chFilter3"));

        gridLayout_2->addWidget(chFilter3, 3, 5, 1, 1);

        lblCh2 = new QLabel(centralwidget);
        lblCh2->setObjectName(QString::fromUtf8("lblCh2"));

        gridLayout_2->addWidget(lblCh2, 1, 3, 1, 1);

        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_10, 2, 4, 1, 1);

        lblADC9 = new QLabel(centralwidget);
        lblADC9->setObjectName(QString::fromUtf8("lblADC9"));
        lblADC9->setFont(font);

        gridLayout_2->addWidget(lblADC9, 2, 17, 1, 1);

        line_16 = new QFrame(centralwidget);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setFrameShape(QFrame::VLine);
        line_16->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_16, 2, 16, 1, 1);

        lblADC8 = new QLabel(centralwidget);
        lblADC8->setObjectName(QString::fromUtf8("lblADC8"));
        lblADC8->setFont(font);

        gridLayout_2->addWidget(lblADC8, 2, 15, 1, 1);

        chFilter1 = new QCheckBox(centralwidget);
        chFilter1->setObjectName(QString::fromUtf8("chFilter1"));

        gridLayout_2->addWidget(chFilter1, 3, 1, 1, 1);

        lblADC7 = new QLabel(centralwidget);
        lblADC7->setObjectName(QString::fromUtf8("lblADC7"));
        lblADC7->setFont(font);

        gridLayout_2->addWidget(lblADC7, 2, 13, 1, 1);

        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_9, 2, 2, 1, 1);

        chFilter9 = new QCheckBox(centralwidget);
        chFilter9->setObjectName(QString::fromUtf8("chFilter9"));

        gridLayout_2->addWidget(chFilter9, 3, 17, 1, 1);

        line_14 = new QFrame(centralwidget);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_14, 2, 12, 1, 1);

        lblADC6 = new QLabel(centralwidget);
        lblADC6->setObjectName(QString::fromUtf8("lblADC6"));
        lblADC6->setFont(font);

        gridLayout_2->addWidget(lblADC6, 2, 11, 1, 1);

        lblADC10 = new QLabel(centralwidget);
        lblADC10->setObjectName(QString::fromUtf8("lblADC10"));
        lblADC10->setFont(font);

        gridLayout_2->addWidget(lblADC10, 2, 19, 1, 1);

        line_19 = new QFrame(centralwidget);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_19, 2, 20, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setMinimumSize(QSize(640, 300));

        verticalLayout->addWidget(customPlot);

        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_6);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        btnVisiblePlot4 = new QPushButton(centralwidget);
        btnVisiblePlot4->setObjectName(QString::fromUtf8("btnVisiblePlot4"));

        gridLayout->addWidget(btnVisiblePlot4, 0, 3, 1, 1);

        btnVisiblePlot10 = new QPushButton(centralwidget);
        btnVisiblePlot10->setObjectName(QString::fromUtf8("btnVisiblePlot10"));

        gridLayout->addWidget(btnVisiblePlot10, 0, 9, 1, 1);

        btnVisiblePlot3 = new QPushButton(centralwidget);
        btnVisiblePlot3->setObjectName(QString::fromUtf8("btnVisiblePlot3"));

        gridLayout->addWidget(btnVisiblePlot3, 0, 2, 1, 1);

        btnVisiblePlot8 = new QPushButton(centralwidget);
        btnVisiblePlot8->setObjectName(QString::fromUtf8("btnVisiblePlot8"));

        gridLayout->addWidget(btnVisiblePlot8, 0, 7, 1, 1);

        btnVisiblePlot6 = new QPushButton(centralwidget);
        btnVisiblePlot6->setObjectName(QString::fromUtf8("btnVisiblePlot6"));

        gridLayout->addWidget(btnVisiblePlot6, 0, 5, 1, 1);

        btnVisiblePlot2 = new QPushButton(centralwidget);
        btnVisiblePlot2->setObjectName(QString::fromUtf8("btnVisiblePlot2"));

        gridLayout->addWidget(btnVisiblePlot2, 0, 1, 1, 1);

        btnVisiblePlot1 = new QPushButton(centralwidget);
        btnVisiblePlot1->setObjectName(QString::fromUtf8("btnVisiblePlot1"));

        gridLayout->addWidget(btnVisiblePlot1, 0, 0, 1, 1);

        btnVisiblePlot5 = new QPushButton(centralwidget);
        btnVisiblePlot5->setObjectName(QString::fromUtf8("btnVisiblePlot5"));

        gridLayout->addWidget(btnVisiblePlot5, 0, 4, 1, 1);

        btnVisiblePlot9 = new QPushButton(centralwidget);
        btnVisiblePlot9->setObjectName(QString::fromUtf8("btnVisiblePlot9"));

        gridLayout->addWidget(btnVisiblePlot9, 0, 8, 1, 1);

        btnVisiblePlot7 = new QPushButton(centralwidget);
        btnVisiblePlot7->setObjectName(QString::fromUtf8("btnVisiblePlot7"));

        gridLayout->addWidget(btnVisiblePlot7, 0, 6, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(50);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 1, 1, 1, 1);

        leAlpha = new QLineEdit(centralwidget);
        leAlpha->setObjectName(QString::fromUtf8("leAlpha"));

        gridLayout_3->addWidget(leAlpha, 1, 2, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 3, 1, 1);

        btnChangeFilterType = new QPushButton(centralwidget);
        btnChangeFilterType->setObjectName(QString::fromUtf8("btnChangeFilterType"));

        gridLayout_3->addWidget(btnChangeFilterType, 0, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 1, 1, 1);

        leWindow = new QLineEdit(centralwidget);
        leWindow->setObjectName(QString::fromUtf8("leWindow"));

        gridLayout_3->addWidget(leWindow, 2, 2, 1, 1);

        btnMAWindowEdit = new QPushButton(centralwidget);
        btnMAWindowEdit->setObjectName(QString::fromUtf8("btnMAWindowEdit"));

        gridLayout_3->addWidget(btnMAWindowEdit, 2, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        lblXmin = new QLabel(centralwidget);
        lblXmin->setObjectName(QString::fromUtf8("lblXmin"));

        horizontalLayout->addWidget(lblXmin);

        eXmin = new QLineEdit(centralwidget);
        eXmin->setObjectName(QString::fromUtf8("eXmin"));

        horizontalLayout->addWidget(eXmin);

        lblXmax = new QLabel(centralwidget);
        lblXmax->setObjectName(QString::fromUtf8("lblXmax"));

        horizontalLayout->addWidget(lblXmax);

        eXmax = new QLineEdit(centralwidget);
        eXmax->setObjectName(QString::fromUtf8("eXmax"));

        horizontalLayout->addWidget(eXmax);

        lblYmin = new QLabel(centralwidget);
        lblYmin->setObjectName(QString::fromUtf8("lblYmin"));

        horizontalLayout->addWidget(lblYmin);

        eYmin = new QLineEdit(centralwidget);
        eYmin->setObjectName(QString::fromUtf8("eYmin"));

        horizontalLayout->addWidget(eYmin);

        lblYmax = new QLabel(centralwidget);
        lblYmax->setObjectName(QString::fromUtf8("lblYmax"));

        horizontalLayout->addWidget(lblYmax);

        eYmax = new QLineEdit(centralwidget);
        eYmax->setObjectName(QString::fromUtf8("eYmax"));

        horizontalLayout->addWidget(eYmax);

        btnUpdatePlotRange = new QPushButton(centralwidget);
        btnUpdatePlotRange->setObjectName(QString::fromUtf8("btnUpdatePlotRange"));

        horizontalLayout->addWidget(btnUpdatePlotRange);

        btnClearPlot = new QPushButton(centralwidget);
        btnClearPlot->setObjectName(QString::fromUtf8("btnClearPlot"));

        horizontalLayout->addWidget(btnClearPlot);


        verticalLayout->addLayout(horizontalLayout);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_8);

        outputText = new QTextEdit(centralwidget);
        outputText->setObjectName(QString::fromUtf8("outputText"));
        outputText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(outputText);


        verticalLayout_2->addLayout(verticalLayout);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btnOutputSaver = new QPushButton(groupBox);
        btnOutputSaver->setObjectName(QString::fromUtf8("btnOutputSaver"));

        horizontalLayout_6->addWidget(btnOutputSaver);

        btnSaveCSV = new QPushButton(groupBox);
        btnSaveCSV->setObjectName(QString::fromUtf8("btnSaveCSV"));

        horizontalLayout_6->addWidget(btnSaveCSV);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(groupBox);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_4);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        lblPort->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\321\200\321\202", nullptr));
        lblBaudRate->setText(QApplication::translate("MainWindow", "BaudRate", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
        lblDataBits->setText(QApplication::translate("MainWindow", "DataBits", nullptr));
        lblParity->setText(QApplication::translate("MainWindow", "Parity", nullptr));
        lblStopBits->setText(QApplication::translate("MainWindow", "StopBits", nullptr));
        lblFlowControl->setText(QApplication::translate("MainWindow", "FlowControl", nullptr));
        disconnectButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
        lblCh7->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 7", nullptr));
        chFilter4->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        chFilter6->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        lblCh8->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 8", nullptr));
        lblADC3->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        chFilter8->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        lblADC5->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        chFilter10->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        lblADC4->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        chFilter2->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        lblADC1->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        lblCh1->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 1", nullptr));
        lblCh10->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 10", nullptr));
        lblCh3->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 3", nullptr));
        lblADC2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        lblCh9->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 9", nullptr));
        lblCh4->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 4", nullptr));
        chFilter7->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        chFilter5->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        lblCurrentData->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        lblCh6->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 6", nullptr));
        lblCh5->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 5", nullptr));
        chFilter3->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        lblCh2->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 2", nullptr));
        lblADC9->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        lblADC8->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        chFilter1->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        lblADC7->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        chFilter9->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        lblADC6->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        lblADC10->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        btnVisiblePlot4->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 4", nullptr));
        btnVisiblePlot10->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 10", nullptr));
        btnVisiblePlot3->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 3", nullptr));
        btnVisiblePlot8->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 8", nullptr));
        btnVisiblePlot6->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 6", nullptr));
        btnVisiblePlot2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 2", nullptr));
        btnVisiblePlot1->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 1", nullptr));
        btnVisiblePlot5->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 5", nullptr));
        btnVisiblePlot9->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 9", nullptr));
        btnVisiblePlot7->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 7", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\201\320\263\320\273\320\260\320\266\320\270\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Alpha:", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\270 \320\277\320\265\321\200\320\265\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        btnChangeFilterType->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\275\320\260 \321\204\320\270\320\273\321\214\321\202\321\200 \321\201 \320\261\321\203\321\204\320\265\321\200\320\276\320\274", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\261\321\203\321\204\320\265\321\200\320\260:", nullptr));
        btnMAWindowEdit->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\270 \320\277\320\265\321\200\320\265\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        lblXmin->setText(QApplication::translate("MainWindow", "Xmin", nullptr));
        lblXmax->setText(QApplication::translate("MainWindow", "Xmax", nullptr));
        lblYmin->setText(QApplication::translate("MainWindow", "Ymin", nullptr));
        lblYmax->setText(QApplication::translate("MainWindow", "Ymax", nullptr));
        btnUpdatePlotRange->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\321\213 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        btnClearPlot->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        btnOutputSaver->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\265 \320\277\320\276\320\273\321\217 \320\262\321\213\320\262\320\276\320\264\320\260 \320\262 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
        btnSaveCSV->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
