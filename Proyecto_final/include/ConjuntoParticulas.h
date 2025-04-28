///////////////////////////////////
// Proyecto final                //
// file: ConjuntoParticulas.h    //
// Pedro Velasco Santana         //
///////////////////////////////////

//TODO Comentar rollo doxygen

#ifndef CONJUNTOPARTICULAS_H
#define CONJUNTOPARTICULAS_H

const int TAM_BLOQUE = 3;

/**
 * @class ConjuntoParticulas
 * @brief Almacena un conjunto de objetos del tipo Particula
 */
class ConjuntoParticulas{
private:
    Particula *set = nullptr; ///< Array de Particulas
    int capacidad = 0; ///< Capacidad del array
    int utiles  = 0; ///< Posiciones ocupadas

public:
    
    ConjuntoParticulas(const int n = 0);
    ConjuntoParticulas(const ConjuntoParticulas &otro);
    ~ConjuntoParticulas();

    int getUtiles() const;
    
    void agrega(const Particula &a_agregar);
    void borrar(const int pos);
    Particula& obtener(const int pos); // ? Not sure si esto esta bien
    void reemplazar(const Particula &sustituta, const int pos);
    void mover(int tipo = 0);
    void gestionarColisones();
    std::string toString() const;
};

#endif //CONJUNTOPARTICULAS_H