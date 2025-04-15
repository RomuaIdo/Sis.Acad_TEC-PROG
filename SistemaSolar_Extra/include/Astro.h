#ifndef _ASTRO_H
#define _ASTRO_H

class Astro{
private:
  int NA;

public:
  Astro();
  ~Astro();
  void Inicializa(int Na=0);
  void setNA(int na=0);
  int getNA();
};

#endif
