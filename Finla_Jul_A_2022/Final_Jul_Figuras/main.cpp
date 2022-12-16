#include <iostream>
#include "FiguraGeometrica.h"
#include "Cuadrado.h"
#include "Circulo.h"

using namespace std;

void calcularAreaYPerimetro(const FiguraGeometrica *figura);

int main()
{
    FiguraGeometrica *circ = new Circulo("Circulo", 1);
    calcularAreaYPerimetro(circ);
    FiguraGeometrica *cuad = new Cuadrado("Cuadrado", 1);
    calcularAreaYPerimetro(cuad);
    return 0;
}

void calcularAreaYPerimetro(const FiguraGeometrica *figura)
{
    cout << figura->get_nombre() << "\nArea: "
         << figura->area() << " Perimetro: "
         << figura->perimetro() << endl;
}
