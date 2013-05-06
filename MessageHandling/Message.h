//
//  Message.h
//  MessageHandling
//
//  Created by hezhenhua on 13-5-6.
//  Copyright (c) 2013年 ZHABG. All rights reserved.
//

#ifndef __MessageHandling__Message__
#define __MessageHandling__Message__

#include <iostream>
#include <set>
#include "Folder.h"
class Folder;
class Message
{
public:
    Message(const std::string &str = ""):
        contents(str){}
    
    Message(const Message&);
    
    Message& operator= (const Message&);
    
    ~Message();
    
    void save(Folder&);
    void remove(Folder&);
    
    void addFldr(Folder*);
    void remFldr(Folder*);
    
    void printf();
private:
    std::string contents;
    std::set<Folder*> folders;
    
    void put_Msg_in_Folders(const std::set<Folder*> &);
    
    void remove_Msg_fromFolders();
};

#endif /* defined(__MessageHandling__Message__) */
