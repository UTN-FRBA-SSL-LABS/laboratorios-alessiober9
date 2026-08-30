#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    
    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};
    
    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);
    
    /* Verificamos el total ($600 + $700 = $1300) */
    int total = carrito_total(&c);
    ASSERT_IGUAL(1300, total);
    
    /* Verificamos el descuento del 10% ($1300 - 10% = $1170) */
    int total_con_descuento = carrito_descuento(total, 10);
    ASSERT_IGUAL(1170, total_con_descuento);
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 1};

    /* Llenamos el carrito hasta la capacidad maxima (4 productos) */
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);

    /* Verificamos que el conteo es MAX_ITEMS (4) */
    ASSERT_IGUAL(4, carrito_contar(&c));

    /* Verificamos que intentar agregar uno mas devuelve 0 (error) */
    ASSERT_IGUAL(0, carrito_agregar(&c, p));

    /* Verificamos que el conteo sigue siendo MAX_ITEMS (no cambio) */
    ASSERT_IGUAL(4, carrito_contar(&c));
}
int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
