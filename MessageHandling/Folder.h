//
//  Folder.h
//  MessageHandling
//
//  Created by hezhenhua on 13-5-6.
//  Copyright (c) 2013年 ZHABG. All rights reserved.
//

#ifndef __MessageHandling__Folder__
#define __MessageHandling__Folder__

#include <iostream>
#include <set>
#include "Message.h"

class Message;

class Folder
{
public:
    Folder() {}
    
    //复制成员
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    
    //在指定Message的目录集中增加/删除该目录
    void save(Message &);
    void remove(Message &);
    
    
    //在该目录的消息集中增加/删除指定Message
    void addMsg(Message *m);
    void remMsg(Message *m);
    
    int getMsgCount();
    void printf();
private:
    std::set<Message*> messages;
    
    //复制控制成员所使用的实用函数
    //将目录加到形参所指的消息集中
    void put_Fldr_in_Messages(const std::set<Message*>&);
    
    //从目录所指的所有消息中删除该目录
    void remove_Fldr_from_Messages();
};

#endif /* defined(__MessageHandling__Folder__) */
