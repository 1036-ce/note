#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory>

class Folder;
class Message {
	friend class Folder;
public:
	explicit Message(const std::string &str = ""):
		contents(str) {}
	Message(const Message&);
	Message &operator=(const Message&);
	~Message();

	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

class Folder {
public:
	Folder() =default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();

	void addMsg(Message*);
	void remMsg(Message*);
private:
	std::set<Message*> msgs;
};

void Folder::addMsg(Message *m)
{
	msgs.insert(m);
}

void Folder::remMsg(Message *m)
{
	msgs.erase(m);
}

Folder::Folder(const Folder &f) 
{
	for (auto m: f.msgs)
		m->save(*this);
}

Folder& Folder::operator=(const Folder &f)
{
	auto tmp = f.msgs;
	for (auto m: msgs)
		m->remove(*this);
	for (auto m: tmp)
		m->save(*this);
	return *this;
}
Folder::~Folder()
{
	for (auto m: msgs)
		m->remove(*this);
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f: m.folders)
		f->addMsg(this);
}

Message::Message(const Message &m):
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

void Message::remove_from_Folders()
{
	for (auto f: folders)
		f->remMsg(this);
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
int main(void)
{
	Folder f;
	Folder f1;
	Message m("123");
	Message m1("456");
	m1 = m;
	m.save(f);
	f1 = f;
	m.remove(f);
	return 0;
}
