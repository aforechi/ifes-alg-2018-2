#include "pnmfile.h"

template <size_t dimensao>
void construir_mapa(const char* arquivo, const bool (&mapa_livre)[dimensao][dimensao]) {
    segment::image<unsigned char> *map = 0;
    map = new segment::image<unsigned char>(dimensao, dimensao, false);
    map->init(1); //assume todo o mapa livre
    
    for(int i=0; i<dimensao; i++)
        for(int j=0; j<dimensao; j++) 
            if (!mapa_livre[i][j])
                map->access[i][j] = 0; 
        
    segment::savePBM(map, arquivo);
    
    delete map;
}