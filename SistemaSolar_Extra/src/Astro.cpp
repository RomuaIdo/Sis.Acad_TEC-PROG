#include "../include/Astro.h"

Astro::Astro() {
  Inicializa(0);
}

Astro::~Astro() {
}

void Astro::Inicializa(int Na) {
  setNA(Na);
}

void Astro::setNA(int na) {
  NA = na;
}

int Astro::getNA() {
  return NA;
}
