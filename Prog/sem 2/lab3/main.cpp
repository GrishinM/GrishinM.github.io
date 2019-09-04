#include <iostream>
#include "as.h"
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
    /*cout<<"Команды:"<<endl<<"1 - создать множество"<<endl<<"2 - проверка на содержание во множестве элемента"<<endl<<"3 - добавление элемента в множество"<<endl;
    cout<<"4 - удаление элемента из множества"<<endl<<"5 - вывести множество"<<endl<<"6 - пересечение двух множеств"<<endl<<"7 - объединение двух множеств"<<endl;
    cout<<"8 - добавление элементов 2-го множества в 1-ое"<<endl<<"9 - удаление элементов 2-го множества из 1-ого"<<endl<<"10 - выход"<<endl;*/
    view mainview;
    menu s(20);
    while(true)    s(mainview.get());
    return 0;
}
