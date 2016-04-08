#ifndef JABBERHANDLER_H
#define JABBERHANDLER_H

#include <string.h>
#include <gloox/gloox.h>
#include <gloox/client.h>
#include <gloox/connectionlistener.h>
#include <gloox/presencehandler.h>
#include <gloox/messagehandler.h>
#include <gloox/message.h>

using namespace std;
using namespace gloox;

class JabberHandler : public ConnectionListener, PresenceHandler, MessageHandler {
public:
	// ////// CONSTRUCTORS AND DESTRUCTORS
	JabberHandler();
	
	//~JabberHandler();
	~JabberHandler() {};
	
	void connect(string jidString, string password);
	
	// gloox Handlers
	virtual void onConnect();
	virtual void onDisconnect(ConnectionError e);
	virtual bool onTLSConnect(const CertInfo& info);
	virtual void handlePresence(const Presence& presence);
	virtual void handleMessage(const Message& msg, MessageSession* session);

private:
	// Properties
	Client* client;
};

#endif

