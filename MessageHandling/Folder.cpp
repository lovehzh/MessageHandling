//
//  Folder.cpp
//  MessageHandling
//
//  Created by hezhenhua on 13-5-6.
//  Copyright (c) 2013年 ZHABG. All rights reserved.
//

#include "Folder.h"
using namespace std;

Folder::Folder(const Folder &f):messages(f.messages)
{
    cout << "folder 复制控制" << endl;
    //将该目录加到f所指向的每个消息中
    put_Fldr_in_Messages(messages);
}

//将该目录加到rhs所指的消息集中
void Folder::put_Fldr_in_Messages(const std::set<Message*> &rhs)
{
    for (set<Message*>::const_iterator beg = rhs.begin(); beg != rhs.end(); ++beg) {
        (*beg)->addFldr(this); //*beg指向一个消息
    }
}

Folder& Folder::operator=(const Folder &rhs)
{
    cout << "folder 赋值操作" << endl;
    if (&rhs != this) {
        remove_Fldr_from_Messages(); //更新现有消息
        messages = rhs.messages;     //从rhs复制消息指针集
        //将该目录加到rhs中的每个消息中
        put_Fldr_in_Messages(rhs.messages);
    }
    return *this;
}

//从对应消息中删除该目录
void Folder::remove_Fldr_from_Messages()
{
    for (set<Message*>::const_iterator beg = messages.begin(); beg != messages.end(); ++beg) {
        (*beg)->remFldr(this);//*beg指向一个消息
    }
}

Folder::~Folder()
{
    remove_Fldr_from_Messages();
}

void Folder::save(Message &msg)
{
    addMsg(&msg);
    msg.addFldr(this);//更新相应的消息
}

void Folder::remove(Message &msg)
{
    remMsg(&msg);
    msg.remFldr(this);//更新相应的消息
}

void Folder::addMsg(Message *msg)
{
    messages.insert(msg);
}

void Folder::remMsg(Message *msg)
{
    messages.erase(msg);
}

int Folder::getMsgCount()
{
    return messages.size();
}

void Folder::printf()
{
    cout << "该目录中的消息是：" <<endl;
    for (set<Message*>::const_iterator beg = messages.begin(); beg != messages.end(); ++beg) {
        (*beg)->printf();
    }
}