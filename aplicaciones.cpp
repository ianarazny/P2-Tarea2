
#include "../include/aplicaciones.h"
#include "../include/cadena.h"
#include "../include/iterador.h"
#include "../include/info.h"

TCadena insertarAlFinal(nat natural, double real, TCadena cad)
{
  cad = insertarAlInicio(natural, real, cad);
  // CHEQUEAR SI ESTO ANDA SI CAD ES NULL
  return cadenaSiguiente(cad);

}


TCadena removerPrimero(TCadena cad)
{
  cad = removerDeCadena(natInfo(primeroEnCadena(cad)), cad);

  return cad;
}

TCadena copiaCadena(TCadena cad) {
  TCadena ult= NULL;
  
  for(nat i=0; i<cantidadEnCadena(cad); i++){
    ult= insertarAlFinal(natInfo(primeroEnCadena(cad)), realInfo(primeroEnCadena(cad)), ult);
    cad= cadenaSiguiente(cad);
  }
  return ult;
}

void reversoRec(TIterador iter, TIterador copiado){
  //quiero avanzar iterador si no es el último elemento
  
  if(estaDefinidaActual(iter)){
    //Creo que las sig. dos lineas sobran.
    //reiniciarIterador(iter);
    //avanzarIterador(iter);

    if(!estaDefinidaActual(iter)){
      //Si toy aca es porque estaba en el ultimo elem de iter, caso base.
    } else {
      nat aux = actualEnIterador(iter);
      avanzarIterador(iter);
      reversoRec(iter, copiado);
      agregarAIterador(aux, copiado);
      
    }
  }
}

TIterador reversoDeIterador(TIterador iter) {
  TIterador nuevo = crearIterador();
  reiniciarIterador(iter);
  if(estaDefinidaActual(iter)){
      reversoRec(iter,nuevo);
  } 
  return nuevo;

}


