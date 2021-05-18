#pragma once
#include "Document.h"

class Email :public Document {
	string sender, recipient, title;
public:
	Email() {
		sender = "";
		recipient = "";
		title = "";
	}
	Email(string t, string s, string r, string l):Document(t) {
		sender = s;
		recipient = r;
		title = l;
	}
	string getSender() { return sender; }
	string getRecipient() { return recipient; }
	string getTitle() { return title; }
	void setSender(string s) { sender = s; }
	void setRecipient(string s) { recipient = s; }
	void setTitle(string s) { title = s; }
	Email& operator =(Email e) {
		setText(e.getText());
		sender = e.sender;
		recipient = e.recipient;
		title = e.title;
		return *this;
	}
};