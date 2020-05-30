//
//  Test.hpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 18.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include "FileManager.hpp"

const int LENGTH=1024;
const int COMMAND_MAX_SIZE=30;

///Клас който приема информация от потребилтеля  (потребителски интерфейс)
///
///  Работи с потребителски вход от конзолата или с потребителски файл
/// Отговаря за изпълнението на командите свързани с календара или с файла
class Test{
    char* command; //потребителска команда
    int len;
    Hotel h; //обект от тип хотел, върху когото да извършваме промените
    
public:
    Test(Hotel hotel,const char* command);
    
    void SetCommand(const char* command);
    
    void Command(); //изпълнява някоя от фънкциите на хотела спрямо подадения низ
    void FileCommand(); //изпълнява някоя от фънкциите на файла спрямо подадения низ
};

#endif /* Test_hpp */
