//
//  Message.cpp
//  MessageHandling
//
//  Created by hezhenhua on 13-5-6.
//  Copyright (c) 2013年 ZHABG. All rights reserved.
//

#include "Message.h"
using namespace std;

Message::Message(const Message& m):contents(m.contents), folders(m.folders)
{
    put_Msg_in_Folders(folders);
}

Message& Message::operator= (const Message &rhs)
{
    if(&rhs != this){
        remove_Msg_fromFolders();
        contents = rhs.contents;
        folders = rhs.folders;
        put_Msg_in_Folders(rhs.folders);
    }
    return *this;
}

void Message::addFldr(Folder *fldr)
{
    folders.insert(fldr);
}

void Message::remFldr(Folder *fldr)
{
    folders.erase(fldr);
}

void Message::save(Folder &fldr)
{
    addFldr(&fldr);
    fldr.addMsg(this);
}

void Message::remove(Folder &fldr)
{
    remFldr(&fldr);
    fldr.remMsg(this);
}

void Message::put_Msg_in_Folders(const set<Folder*> &rhs)
{
    for (set<Folder*>::const_iterator beg = rhs.begin(); beg != rhs.end(); ++beg) {
        (*beg)->addMsg(this);
    }
}

void Message::remove_Msg_fromFolders()
{
    for (set<Folder*>::const_iterator beg = folders.begin(); beg != folders.end(); ++beg) {
        (*beg)->remMsg(this);
    }
}

Message::~Message()
{
    remove_Msg_fromFolders();
}

void Message::printf()
{
    cout << contents << endl;
}