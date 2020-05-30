//
//  FileManager.hpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 18.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include <stdio.h>

#include "Hotel.hpp"
///Клас отговарящ за работа с файлове
///
///Той представялява връзката ни с фаила и се грижи единствено за него, без да се интересъва от информацията
class FileManager{
    char* fileName; //Пазим името на файла
    int len;
    
    Hotel hotel; //Обект от тип клас с който да боравим
    
public:
    FileManager(const char* name,Hotel& h);
    void SetFileName(const char* fileName); //задава името на работния файл
    
    void write(); //записва настоящия хотел във файла
    void writeTo(const char* otherName); //записва настоящия хотел във файл със зададено има
    void read(); ////отваря файла и чете от него, като инициализира календара
    //void close();
};

#endif /* FileManager_hpp */
