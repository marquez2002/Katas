#include "kata.cc"
#include <cstdlib>
#include "gtest/gtest.h"

TEST(kata, reglas){
  cout<<"\nDefiniremos a 0 como indefinido, 1 como muerto y 2 como vivo\n";
  cout<<"REGLA I. Una celula viva con menos de dos vecinos: muere\n";
  cout<<"REGLA II. Una celula viva con dos o tres vecinos: vive\n";
  cout<<"REGLA III. Una celula viva con mas de tres vecinos: muere\n";
  cout<<"REGLA IV. Una celula muerta con tres vecinos exactamente: vive\n\n";
  cout<<"REGLA V. No se puede usar else\n";
}

TEST(kata, Crearinterrogacion) {
  Kata k;
  k.setValor(0, 0, 0);
  k.setValor(0, 0, 1);
  k.setValor(0, 0, 2);
  k.setValor(0, 1, 0);
  k.setValor(0, 1, 1);
  k.setValor(0, 1, 2);
  k.setValor(0, 2, 0);
  k.setValor(0, 2, 1);
  k.setValor(0, 2, 2);
  k.prinft();
  EXPECT_EQ(0, k.getValor(0, 0));
  EXPECT_EQ(0, k.getValor(0, 1));
  EXPECT_EQ(0, k.getValor(0, 2));
  EXPECT_EQ(0, k.getValor(1, 0));
  EXPECT_EQ(0, k.getValor(1, 1));
  EXPECT_EQ(0, k.getValor(1, 2));
  EXPECT_EQ(0, k.getValor(2, 0));
  EXPECT_EQ(0, k.getValor(2, 1));
  EXPECT_EQ(0, k.getValor(2, 2));
}

TEST(kata, Crearmuertos) {
  Kata k;
  k.setValor(1, 0, 0);
  k.setValor(1, 0, 1);
  k.setValor(1, 0, 2);
  k.setValor(1, 1, 0);
  k.setValor(1, 1, 1);
  k.setValor(1, 1, 2);
  k.setValor(1, 2, 0);
  k.setValor(1, 2, 1);
  k.setValor(1, 2, 2);
  k.prinft();
  EXPECT_EQ(1, k.getValor(0, 0));
  EXPECT_EQ(1, k.getValor(0, 1));
  EXPECT_EQ(1, k.getValor(0, 2));
  EXPECT_EQ(1, k.getValor(1, 0));
  EXPECT_EQ(1, k.getValor(1, 1));
  EXPECT_EQ(1, k.getValor(1, 2));
  EXPECT_EQ(1, k.getValor(2, 0));
  EXPECT_EQ(1, k.getValor(2, 1));
  EXPECT_EQ(1, k.getValor(2, 2));
}

TEST(kata, Crearvivos) {
  Kata k;
  k.setValor(2, 0, 0);
  k.setValor(2, 0, 1);
  k.setValor(2, 0, 2);
  k.setValor(2, 1, 0);
  k.setValor(2, 1, 1);
  k.setValor(2, 1, 2);
  k.setValor(2, 2, 0);
  k.setValor(2, 2, 1);
  k.setValor(2, 2, 2);
  k.prinft();
  EXPECT_EQ(2, k.getValor(0, 0));
  EXPECT_EQ(2, k.getValor(0, 1));
  EXPECT_EQ(2, k.getValor(0, 2));
  EXPECT_EQ(2, k.getValor(1, 0));
  EXPECT_EQ(2, k.getValor(1, 1));
  EXPECT_EQ(2, k.getValor(1, 2));
  EXPECT_EQ(2, k.getValor(2, 0));
  EXPECT_EQ(2, k.getValor(2, 1));
  EXPECT_EQ(2, k.getValor(2, 2));
}

TEST(kata, comprobar1) {
  Kata k;
  k.setValor(1, 0, 0);
  k.setValor(0, 0, 1);
  k.setValor(1, 0, 2);
  k.setValor(1, 1, 0);
  k.setValor(2, 1, 1);
  k.setValor(1, 1, 2);
  k.setValor(1, 2, 0);
  k.setValor(1, 2, 1);
  k.setValor(1, 2, 2);
  k.prinft();
  k.contarPoblacion();
  k.aplicarReglas();
  k.cambio();
  EXPECT_EQ(1, k.getValor(0, 0));
  EXPECT_EQ(0, k.getValor(0, 1));
  EXPECT_EQ(1, k.getValor(0, 2));
  EXPECT_EQ(1, k.getValor(1, 0));
  EXPECT_EQ(1, k.getValor(1, 1));
  EXPECT_EQ(1, k.getValor(1, 2));
  EXPECT_EQ(1, k.getValor(2, 0));
  EXPECT_EQ(1, k.getValor(2, 1));
  EXPECT_EQ(1, k.getValor(2, 2));
  k.reset();
}

TEST(kata, comprobar2) {
  Kata k;
  k.setValor(1, 0, 0);
  k.setValor(0, 0, 1);
  k.setValor(2, 0, 2);
  k.setValor(1, 1, 0);
  k.setValor(2, 1, 1);
  k.setValor(2, 1, 2);
  k.setValor(1, 2, 0);
  k.setValor(1, 2, 1);
  k.setValor(1, 2, 2);
  k.prinft();
  k.contarPoblacion();
  k.aplicarReglas();
  k.cambio();
  EXPECT_EQ(1, k.getValor(0, 0));
  EXPECT_EQ(0, k.getValor(0, 1));
  EXPECT_EQ(2, k.getValor(0, 2));
  EXPECT_EQ(1, k.getValor(1, 0));
  EXPECT_EQ(1, k.getValor(1, 1));
  EXPECT_EQ(2, k.getValor(1, 2));
  EXPECT_EQ(1, k.getValor(2, 0));
  EXPECT_EQ(1, k.getValor(2, 1));
  EXPECT_EQ(1, k.getValor(2, 2));
  k.reset();
}

TEST(kata, comprobar3) {
  Kata k;
  k.setValor(0, 0, 0);
  k.setValor(0, 0, 1);
  k.setValor(0, 0, 2);
  k.setValor(0, 1, 0);
  k.setValor(2, 1, 1);
  k.setValor(2, 1, 2);
  k.setValor(2, 2, 0);
  k.setValor(2, 2, 1);
  k.setValor(2, 2, 2);
  k.prinft();
  k.contarPoblacion();
  k.aplicarReglas();
  k.cambio();
  EXPECT_EQ(0, k.getValor(0, 0));
  EXPECT_EQ(0, k.getValor(0, 1));
  EXPECT_EQ(0, k.getValor(0, 2));
  EXPECT_EQ(0, k.getValor(1, 0));
  EXPECT_EQ(1, k.getValor(1, 1));
  EXPECT_EQ(2, k.getValor(1, 2));
  EXPECT_EQ(2, k.getValor(2, 0));
  EXPECT_EQ(2, k.getValor(2, 1));
  EXPECT_EQ(2, k.getValor(2, 2));
  k.reset();
}

TEST(kata, comprobar4) {
  Kata k;
  k.setValor(1, 0, 0);
  k.setValor(1, 0, 1);
  k.setValor(2, 0, 2);
  k.setValor(1, 1, 0);
  k.setValor(1, 1, 1);
  k.setValor(2, 1, 2);
  k.setValor(1, 2, 0);
  k.setValor(1, 2, 1);
  k.setValor(2, 2, 2);
  k.prinft();
  k.contarPoblacion();
  k.aplicarReglas();
  k.cambio();
  EXPECT_EQ(1, k.getValor(0, 0));
  EXPECT_EQ(1, k.getValor(0, 1));
  EXPECT_EQ(2, k.getValor(0, 2));
  EXPECT_EQ(1, k.getValor(1, 0));
  EXPECT_EQ(1, k.getValor(1, 1));
  EXPECT_EQ(2, k.getValor(1, 2));
  EXPECT_EQ(1, k.getValor(2, 0));
  EXPECT_EQ(1, k.getValor(2, 1));
  EXPECT_EQ(2, k.getValor(2, 2));
  k.reset();
}

TEST(kata, comprobarRandom) {
  Kata k;
  k.getRandom(0, 0);
  k.getRandom(0, 1);
  k.getRandom(0, 2);
  k.getRandom(1, 0);
  k.getRandom(1, 1);
  k.getRandom(1, 2);
  k.getRandom(2, 0);
  k.getRandom(2, 1);
  k.getRandom(2, 2);
  k.prinft();
  k.contarPoblacion();
  k.aplicarReglas();
  k.cambio();
  k.reset();
}