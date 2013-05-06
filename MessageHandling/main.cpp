//
//  main.cpp
//  MessageHandling
//
//  Created by hezhenhua on 13-5-6.
//  Copyright (c) 2013年 ZHABG. All rights reserved.
//

#include <iostream>
#include "Message.h"
#include "Folder.h"
using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    Message msg1 = Message("aaa");
    Message msg2 = Message("bbb");
    
    Folder f1;
    f1.addMsg(&msg1);
    f1.addMsg(&msg2);
    
    Folder f2 = f1;
    
    Folder f3(f1);
    
    f3 = f2;
    
//    f3.save(msg1);
//    f3.save(msg1);
//    f3.save(msg1);
//    f3.remove(msg1);
    
    f3.addMsg(new Message("ccc"));
    
    Message *msg3;
    msg3 = &msg2;
    
    f3.save(*msg3);
    
    
    cout << f3.getMsgCount() << endl;
    f3.printf();
    cout << endl;
    
//    msg3->remFldr(&f3);
//    f3.printf();
//    cout << endl;
    
//    msg3->remove(f3);
//    f3.printf();
    
    f3.remove(*msg3);
    f3.printf();
    cout << endl;
    
    f3.remMsg(&msg2);
    f3.printf();
    cout << endl;
    return 0;
}

