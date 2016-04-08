#include "JabberHandler.h"

#include <iostream>
#include <gloox/gloox.h>
#include <gloox/client.h>
#include <gloox/connectionlistener.h>
#include <gloox/presencehandler.h>
#include <gloox/messagehandler.h>
#include <gloox/message.h>

using namespace std;
using namespace gloox;

// TODO rename Class

// ////// CONSTRUCTORS AND DESTRUCTORS

JabberHandler::JabberHandler() {
	// TODO Template stub
}

//JabberHandler::~JabberHandler() {
//	// TODO Template stub
//}

void JabberHandler::connect(string jidString, string password) {
	JID jid(jidString);
	client = new Client(jid, password);
	client->registerConnectionListener(this);
	client->registerPresenceHandler(this);
	client->registerMessageHandler(this);
	client->connect();
}

// gloox Handlers

void JabberHandler::onConnect() {
	// connection established, auth done (see API docs for exceptions)
	cout << "onConnect()" << endl;
}

void JabberHandler::onDisconnect(ConnectionError e) {
	// connection established, auth done (see API docs for exceptions)
	cout << "onDisconnect()" << endl;
}

bool JabberHandler::onTLSConnect(const CertInfo& info) {
	// examine certificate info
	cout << "onTLSConnect()" << endl;
	return true;
}

void JabberHandler::handlePresence(const Presence& presence) {
	// presence info
	cout << "handlePresence()" << endl;
}

void JabberHandler::handleMessage(const Message& msg, MessageSession* msgSess) {
	// message handler
	cout << "handleMessage()" << endl;
	cout << "-- Message from " << msg.from().full() << ": " << msg.body() << endl;
	
	if (! msg.body().compare("mau")) {
		Message responseMsg (
			msg.subtype(),
			msg.from(),
			"mau mau"
		);
		
		cout << "-- Sending \"mau mau\" response to " << msg.from().full() << endl;
		client->send(responseMsg);
	}
}

