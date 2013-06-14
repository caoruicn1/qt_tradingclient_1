/* 
 * File:   MainWindow.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 24, 2013, 12:45 AM
 */

#include "MainWindow.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include "reqMktDataGUI.h"
    
cf16tradingclient_1::cf16tradingclient_1(boost::shared_ptr<IB::PosixClient> client_ptr): 
host(""), port(7496), clientId(5), client(client_ptr){
    widget.setupUi(this);
        QObject::connect(widget.connectButton, SIGNAL(clicked()), this, SLOT(connectClicked()));
        QObject::connect(widget.disconnectButton, SIGNAL(clicked()), this, SLOT(disconnectClicked()));
        QObject::connect(widget.actionReqMktData, SIGNAL(triggered()), this, SLOT(actionReqMktDataClicked()));
}

cf16tradingclient_1::~cf16tradingclient_1() {
    //endProcessMessages();
    if (client->isConnected()) {
        client->disconnect();
        if (!client->isConnected()) {
            widget.label_6_connected->setText(QStringLiteral("not connected"));
        }
    }
}

//public slots
void cf16tradingclient_1::connectClicked() {
    if (!client->isConnected()) {
        client->connect(host, port, clientId);
        if (client->isConnected()) {
            widget.label_6_connected->setText(QStringLiteral("connected"));
        }
        //processMessages();
    }
}

void cf16tradingclient_1::disconnectClicked() {
    if (client->isConnected()) {
        client->disconnect();
        if (!client->isConnected()) {
            widget.label_6_connected->setText(QStringLiteral("not connected"));
        }
    }
}

void cf16tradingclient_1::actionReqMktDataClicked(){
    //reqMDGUI_ptr=boost::shared_ptr<reqMktDataGUI>(new reqMktDataGUI(client));
    //reqMDGUI_ptr->show();
    ptr=new reqMktDataGUI(client);
    ptr->show();
}

