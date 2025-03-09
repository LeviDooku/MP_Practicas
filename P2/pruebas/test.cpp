/*
 * File:   main.cpp
 * Author: David A. Pelta
 *
 * Created on 10 de marzo de 2023
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//#include <iostream>
#include "proceso.h"
#include <cstring>

using namespace std;


TEST_CASE("Prueba Iguales y Longitud") {

    SUBCASE("Prueba de sonIguales") {
        char cad1[MAX_SIZE] = "abcdefg";
        char cad2[MAX_SIZE] = "abcdefg";
        CHECK(sonIguales(cad1,cad2) == true);
        cad2[1] = 'B';
        CHECK(sonIguales(cad1,cad2) == false);
        cad1[0] = TERMINADOR;
        CHECK(sonIguales(cad1,cad2) == false);
        cad2[0] = TERMINADOR;
        CHECK(sonIguales(cad1,cad2) == true);

    }

    SUBCASE("Prueba de longitud") {
        char cad1[MAX_SIZE] = "123456789";
        char cad2[MAX_SIZE] = "123456";
        CHECK(longitud(cad1) == 9);
        CHECK(longitud(cad2) == 6);

        cad1[3] = TERMINADOR;
        CHECK(longitud(cad1) == 3);

    }
}

TEST_CASE("Prueba Anagramas") {

    SUBCASE("Anagramas") {
        char cad1[MAX_SIZE] = "abcdefg";
        char cad2[MAX_SIZE] = "badcefg";

        // sin caracteres repetidos
        CHECK(anagrama(cad1, cad2) == true);
        cad2[0] = 'x';
        CHECK(anagrama(cad1, cad2) == false);

        // con caracteres repetidos
        strcpy(cad1,"abcabcabc");
        strcpy(cad2,"aabbccabc");
        CHECK(anagrama(cad1, cad2) == true);

        cad2[0] = 'b';
        CHECK(anagrama(cad1, cad2) == false);


        cad2[0] = 'G';
        CHECK(anagrama(cad1, cad2) == false);

        strcpy(cad2,"cccaaabbb");
        CHECK(anagrama(cad1, cad2) == true);

        cad2[0] = TERMINADOR;
        CHECK(anagrama(cad1, cad2) == false);





    }
}

TEST_CASE("Prueba caracteres unicos") {
    SUBCASE(" Prueba 1"){
        char cad1[MAX_SIZE] = "abcda";

        int n = carsUnicos(cad1);
        CHECK(n == 3);

        strcpy(cad1, "12344321()");
        n = carsUnicos(cad1);
        CHECK(n == 2);
        cad1[0] = TERMINADOR;
        n = carsUnicos(cad1);
        CHECK(n == 0);
    }
}


TEST_CASE("Prueba Compress/decompress") {
    SUBCASE(" Prueba Compress / decompress"){
        char cad1[MAX_SIZE] = "abbcccddddcccbba";
        char cad2[MAX_SIZE];
        char cad3[MAX_SIZE];

        compress(cad1, cad2);
        CHECK(longitud(cad1) - longitud(cad2) > 0);

        strcpy(cad1, "abcde");
        compress(cad1, cad2);
        CHECK(longitud(cad1)*2 == longitud(cad2));

        decompress(cad2, cad3);
        CHECK(sonIguales(cad1, cad3) == true);

        strcpy(cad1, "abbcccddddcccbba");
        compress(cad1, cad2);
        CHECK(longitud(cad2) == 14);
        decompress(cad2, cad3);
        CHECK(sonIguales(cad1, cad3) == true);


        cad1[0] = TERMINADOR;
        compress(cad1, cad2);
        CHECK(longitud(cad2) == 0);
        decompress(cad2, cad3);
        CHECK(longitud(cad3) == 0);

    }
}










