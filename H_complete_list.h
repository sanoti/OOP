//
//  H_complete_list.h
//  ob
//
//  Created by Даниил on 22.11.2020.
//
#pragma once
#include "H_complete.h"

using namespace std;

class complete_list{
private:
    vector <complete*> list;
public:
    void add_complete(complete& ccomplete){ //  добавляем выполненную работу в лист
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if (ccomplete.get_id() == (*it)->get_id()){
                cout << "complete is already on the list"s;
                return;
            }
        }
        list.push_back(&ccomplete);
    }
    
    void del_complete(complete& ccomplete){ //   удаляем выполненную работу из листа
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if (ccomplete.get_id() == (*it)->get_id()){
                list.erase(it);
                return;
            }
        }
    }
    
    void del_complete_by_id(int id){ //   удаляем выполненную работу из листа
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                list.erase(it);
                return;
            }
        }
    }
    
    void clear_list(){ //   очищаем весь лист
        list.clear();
    }
    
    //  set'ы  //
    void set_com_trip_by_id(int id, trip* ttrip){ //    добавляем путешествие по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_com_trip(ttrip);
            }
        }
    }
    
    void set_com_driver_by_id(int id, driver* ddriver){ //    добавляем водителя по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_com_driver(ddriver);
            }
        }
    }
    
    void set_departure_by_id(int id, string departure){ //    добавляем departure по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_departure(departure);
            }
        }
    }
    
    void set_arrival_by_id(int id, string arrival){ //    добавляем arrival по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_arrival(arrival);
            }
        }
    }
    
    void set_premium_by_id(int id, double premium){ //    добавляем premium по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_premium(premium);
            }
        }
    }
    //  set'ы  //

    //  get'ы  //
    string get_out_com_by_id(int id){ //     возвращаем конкретный complete по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id)
                return (*it)->out_com();
        }
        return "this complete isn't on the list\n";
    }
    
    trip* get_com_trip_by_id(int id){ //     возвращаем путешествие по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_trip();
            }
        }
//        trip x = trip();
//        trip* u = &x;
//        return u;
        trip* x = new trip();
        return x;
    }
    
    driver* get_com_driver_by_id(int id){ //     возвращаем водителя по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_driver();
            }
        }
//        driver x = driver();
//        driver* u = &x;
        driver* x = new driver();
        return x;
    }

    string get_departure_by_id(int id){ //     возвращаем departure по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_departure();
            }
        }
        return "complete(and its 'departure') isn't on the list\n";
    }

    string get_arrival_by_id(int id){ //     возвращаем arrival по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_arrival();
            }
        }
        return "complete(and its 'arrival') isn't on the list\n";
    }


    double get_premium_by_id(int id){ //     возвращаем premium по id
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_premium();
            }
        }
        return -1;
    }
    
    //  list'ы  //
    vector <complete*> get_list(){ //   возвращаем весь list
        return list;
    }
    
    vector <int>  get_id_complete_list(){ //     возвращаем вектор со всеми id
        vector <int> result;
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            result.push_back((*it)->get_id());
        }
        return result;
    }
    //  list'ы  //
    //  get'ы  //
    
    bool check_complete_by_id(int id){ //     проверка на наличие законченого путешествия в списке
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id)
                return true;
        }
        return false;
    }
    
    string out_list(){ //     вывод всех выполненых поездок из списка
        if (list.size() == 0){
            return "list is empty"s;
        }
        string result = "all complete trip:\n";
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            result += (*it)->out_com() + "\n";
        }
        return result;
    }
};

