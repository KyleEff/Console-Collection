#include "Storage.cpp"

int main() {

    Collection* col = new Collection();
    Storage building(col);

    building.storeCollection();
    //building.readCollection();
}