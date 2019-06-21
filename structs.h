//
// Created by amdressel8336 on 6/19/2019.
//

#ifndef HELLOWORLD_STRUCTS_H
#define HELLOWORLD_STRUCTS_H
using namespace std;

#include <string>

/*
 * Product struct used for adding products to the catalog/ProductLine
 * These are the products that an employee can produce.
 *
 * A vector is created to hold each catalog item inside an index.
 * */
struct Product {
    string manu;
    string name;
    string item_type;
};

/*
 * Holds individual item stats. Each product produced has a serial and production number.
 * The prodRecord also holds the same name manufacturer and type as the Product struct.
 * */
struct Prod_record {
    string prod_num;
    string serialNum;
    string name;
    string manufac;
    string type;
};

/*
 * ProdRecStats holds the statistics for the current ProductionLog file.
 * Each item_type count is held, as well as the latest production number.
 * The latest production number is essentially the items produced to date.
 * */
struct Prod_rec_stat {
    int prodNum;
    int MM_count;
    int VI_count;
    int VM_count;
    int AM_count;
};
/*
struct Employee {
    string user_id;
    string password;
};
*/

#endif //HELLOWORLD_STRUCTS_H
