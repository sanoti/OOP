//
//  H_trip_list.h
//  ob
//
//  Created by Даниил on 12.11.2020.
//
#pragma once
#include "Htrip.h"

using namespace std;

class trip_list{
private:
    vector <trip*> list;
public:
    void add_trip(trip& ttrip){ //  добавляем путешествие в лист
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if (ttrip.get_id() == (*it)->get_id()){
                cout << "trip is already on the list"s;
                return;
            }
        }
        list.push_back(&ttrip);
    }
    
    void del_trip(trip& ttrip){ //   удаляем путешествие из листа
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if (ttrip.get_id() == (*it)->get_id()){
                list.erase(it);
                return;
            }
        }
    }
    
    void del_trip_by_id(int id){ //   удаляем путешествие из листа
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
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
    void set_name_of_trip_by_id(int id, string name_of_trip){ //    добавляем name_of_trip по id
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_name_of_trip(name_of_trip);
            }
        }
    }
    
    void set_distanse_by_id(int id, double distanse){ //    добавляем distanse по id
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_distanse(distanse);
            }
        }
    }
    
    void set_duration_by_id(int id, double duration){ //    добавляем duration по id
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_duration(duration);
            }
        }
    }
    
    void set_paiment_by_id(int id, double paiment){ //    добавляем paiment по id
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_duration(paiment);
            }
        }
    }
    //  set'ы  //
    
//    trip* get_trip_by_id(int id){
//        if (this->check_trip_by_id(id))
//            for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
//                if ((*it)->get_id() == id){
//                    return *it;
//            }
//        }
//    }
    
    
    //  get'ы  //
    vector <trip*> get_list(){ //   возвращаем весь list
        return list;
    }
    trip* get_trip_by_id(int id){ //     возвращаем путешествие по id
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it);
            }
        }
        trip x = trip();
        trip* u = &x;
        return u;
    }
    
    string get_out_trip(int id){ //     возвращаем конкретный trip по id в виде строки
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id)
                return (*it)->out_trip();
        }
        return "trip isn't on the list\n";
    }
    
    string get_name_of_trip_by_id(int id){ //     возвращаем name_of_trip по id
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_name_of_trip();
            }
        }
        return "trip(and it's 'name_of_trip') isn't on the list\n";
    }
    
    double get_distanse_by_id(int id){ //     возвращаем distanse по id
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_distanse();
            }
        }
        return -1;
    }
    
    double get_duration_by_id(int id){ //     возвращаем duration по id
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_duration();
            }
        }
        return -1;
    }

    double get_paiment_by_id(int id){ //     возвращаем paiment по id
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_paiment();
            }
        }
        return -1;
    }
    
    vector <int>  get_id_trip_list(){ //     возвращаем вектор со всеми id
        vector <int> result;
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            result.push_back((*it)->get_id());
        }
        return result;
    }
    //  get'ы  //

    
    bool check_trip_by_id(int id){ //     проверка на наличие поездки в списке
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id)
                return true;
        }
        return false;
    }
    
    
    string out_list(){ //     вывод всех поездок из списка
        if (list.size() == 0){
            return "list is empty\n"s;
        }
        string result = "all trips:\n";
        for (vector <trip*>::iterator it = list.begin(); it != list.end(); it++){
            result += (*it)->out_trip();
        }
        return result;
    }
    
    
};


