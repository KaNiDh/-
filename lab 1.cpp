#include <iostream>

using namespace std;

class Hotel {
private:
    int number_of_rooms_on_the_floor; // количество комнат на этажах (кроме последнего)
    int number_of_rooms;              // общее количество комнат
    int price;                        // цена за одну комнату
    int tenant;                       // количество заселённых комнат

public:
    // Метод для установки начальных значений
    void setInitialValues(int rooms_on_floor, int total_rooms, int room_price, int occupied_rooms) {
        number_of_rooms_on_the_floor = rooms_on_floor;
        number_of_rooms = total_rooms;
        price = room_price;
        tenant = occupied_rooms;
    }

    // Метод для расчёта количества этажей и комнат на последнем этаже
    void calculateFloorsAndLastFloorRooms(int& total_floors, int& last_floor_rooms) {
        // Количество полных этажей, на которых одинаковое количество комнат
        total_floors = number_of_rooms / number_of_rooms_on_the_floor;
        // Комнаты на последнем этаже (если есть "неполный" этаж)
        last_floor_rooms = number_of_rooms % number_of_rooms_on_the_floor;

        // Если остаток равен 0, то последний этаж тоже полностью заполнен
        if (last_floor_rooms == 0) {
            last_floor_rooms = number_of_rooms_on_the_floor;
        } else {
            total_floors++; // увеличиваем количество этажей, так как есть неполный этаж
        }
    }

    // Метод для расчета прибыли отеля
    int calculateProfit() {
        return tenant * price; // прибыль: количество заселённых комнат * цена за комнату
    }

    // Метод для вывода текущего состояния
    void displayInfo() {
        int total_floors, last_floor_rooms;
        calculateFloorsAndLastFloorRooms(total_floors, last_floor_rooms);
        cout << "Количество этажей в отеле: " << total_floors << endl;
        cout << "Количество комнат на последнем этаже: " << last_floor_rooms << endl;
        cout << "Прибыль отеля: " << calculateProfit() << " у.е." << endl;
    }
};

// Вне класса, основная программа
int main() {
    Hotel myHotel;

    // Установка начальных значений (например: 5 комнат на каждом этаже, всего 23 комнаты, цена 100, заселено 18 комнат)
    myHotel.setInitialValues(5, 23, 100, 18);

    // Вывод текущей информации об отеле
    myHotel.displayInfo();

    return 0;
}