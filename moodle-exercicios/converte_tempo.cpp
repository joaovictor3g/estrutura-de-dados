#include <iostream>

// Recebe tempo em 'segundos', converte para horas, minutos e seguntos, e 
// retorna o resultado através dos parâmetros 'hor', 'min' e 'seg'.
void converte_tempo(int segundos, int *hor, int *min, int *seg) {
    *hor = segundos / 3600;
    *min = segundos % 3600;
    *min /= 60;
    *seg = (segundos - *hor * 3600 - *min * 60);

}

int main() {
   int tempo, h, m, s;
   std::cin >> tempo;
   // Chame a função 'converte_tempo' para converter o valor de 'tempo' em horas
   // minutos e segundos, gravando o resultado nas variáveis 'h', 'm' e 's'.
   converte_tempo(tempo, &h, &m, &s);
   std::cout << h << ":" << m << ":" << s << std::endl;
   
   return 0;
}
