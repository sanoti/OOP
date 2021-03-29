//
//  main.cpp
//  ob
//
//  Created by Даниил on 26.10.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Htrip.h"
#include "H_driver.h"
#include "H_complete.h"
#include "H_trip_list.h"
#include "H_driver_list.h"
#include "H_complete_list.h"
#include "H_lowboy.h"
#include "data_xml.h"
#include "pugi.hpp"
#include "data_sql.h"


using namespace std;

//uywhtrfijesoiper
 



int main() {
    data_xml data;
    lowboy low, lowx;
    lowx = data.read("/Users/daniil/Desktop/Новая папка/ob/ob/data.xml");
    trip_list tl;
    driver_list dl;
    complete_list cl;
    trip x = trip(1, "Habarovsk-Vladivistok", 760.5, 9, 57);
    trip x1 = trip();
    
    //cout << x.out_trip() << endl;
    
    x.set_name_of_trip("Vladivistok-Habarovsk");
    x.set_distanse(765);
    
    //cout << x.out_trip() << endl;
    
    driver y = driver(1, "Alexey", "Zaytsev", 4);
    
    y.set_surename("Zont");
    y.set_xp(2);
    
    x.set_duration(x.get_distanse());
    //cout << x.out_trip() << endl;
    
    complete com = complete(2, &x, &y, "20.10.2020", "01.11.2020", 10.);
    //cout << com.out_com();
    
    complete_list c;
    c.add_complete(com);
    cout << c.get_com_trip_by_id(0)->out_trip();
    cout << c.get_out_com_by_id(21);
    
    tl.add_trip(x);
    tl.add_trip(x1);
    dl.add_driver(y);
    cl.add_complete(com);
    
    low.set_trip_list(tl);
    low.set_driver_list(dl);
    low.set_complete_list(cl);
    cout << low.out_all_driver();
    
    lowx.add_trip(x);
    cout << lowx.out_all_trip();
    
//    low.add_complete(com);
//    low.add_driver(y);
//    low.add_trip(x);
    
    cout << "----------" << endl;
    low.set_driver_surename(1, "Zont");
    //cout << low.out_all_complete();
    cout <<low.out_all_complete();
    
    
    trip *test_trip;
    test_trip = low.get_com_trip(2); //метод работает коректно, просто в аргументах надо указывать id,
    cout << test_trip->out_trip();   //именно законченного путешествия, а переменная "com" у иеня с id = 2
    
    trip *test_trip2;
    test_trip2 = low.get_trip(1);
    cout <<test_trip2->out_trip();
    
    
    //cout << low.get_com_trip(1)->out_trip();

    driver *test_driver;
    test_driver = low.get_com_driver(2); //здесь у меня тоже самое
    cout << test_driver->out_driver();   //я так сделал потому что в complete по одному маршруту и одному водителю

    
    data.write(low, "/Users/daniil/Desktop/Новая папка/ob/ob/out_data.xml");
}
