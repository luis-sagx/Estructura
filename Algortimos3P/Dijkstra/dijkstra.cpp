#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

using namespace std;
//Clase nodo de adyacencia
class Nodo{
    public:
        int vertice; //Indica el vertice con que se conecta
        int peso;    //Y el peso de la arista
        Nodo* sig;
    
    Nodo(int destino, int ponderacion){
        vertice = destino;
        peso = ponderacion;
        sig = nullptr;
    }
};

class Lista{ //Contiene la lista de vertices adyacentes a un vertice particular
    public:
        Nodo* cabeza;
        Lista(){
            cabeza = nullptr;
        }//Puede recorrer o agregar conexiones
        void recorrer();
        void insertar(Nodo* nodo);
};

void Lista::insertar(Nodo* nodo){;
    if(cabeza == nullptr){
        cabeza = nodo;
        return;
    }
    //Realiza la insercion por orden de valores
    if(nodo->vertice < cabeza->vertice){ //Si es menor a la cabeza se inserta antes
        nodo->sig = cabeza;
        cabeza = nodo;
        return;
    }

    Nodo* aux = cabeza;//Y si no, se inserta al final
    while (aux->sig != nullptr){
        aux = aux->sig;
    }

    aux->sig = nodo;    
}

void Lista::recorrer(){//Muestra en orden, con que otros vertices est� conectado
    Nodo* aux = cabeza;
    while(aux != nullptr){
        if(aux->sig != nullptr){
            printf("[%d(%d)]->",aux->vertice,aux->peso);
        }else{
           printf("[%d(%d)]\n",aux->vertice,aux->peso);
        }
        aux = aux->sig;
    }
}

class Grafo{ //Un grafo esta compuesto por "n" vertices
    public:
        int n;
        Lista* listady;//Cada vertice tiene su lista de adyacencia

    Grafo(int num_nodos){
        n = num_nodos;
        listady = new Lista[n]{};
    }

    void agregarArista(int fuente, int destino, int peso);
    int obtenerPeso(int fuente, int destino);
    void summary();

};

void Grafo::summary(){//Muestra las listas de adyacencia de cada vertice del grafo
    printf("===== LISTA DE ADYACENCIA DEL GRAFO =====\n");
    printf("Formato por nodo: [Valor(Peso)]\n\n");
    for(int i=0;i<n;i++){
        printf("Nodo %d:\n",i);
        listady[i].recorrer();
        printf("\n");
    }
}

void Grafo::agregarArista(int fuente, int destino, int peso){//Crea una arista entre 2 nodos
    //A su vez, al crear la arista, crea los nodos extremo
    Nodo *nodoDestino = new Nodo(destino, peso);//Crea un extremo
    listady[fuente].insertar(nodoDestino);//Y lo coloca en la lista de adyacencia del otro

    Nodo *nodoFuente = new Nodo(fuente, peso);//Hace lo mismo en el otro extremo
    listady[destino].insertar(nodoFuente);
}

int Grafo::obtenerPeso(int fuente, int destino){//Peso de una arista entre 2 vertices adyacentes
    Nodo *aux = listady[fuente].cabeza;//Selecciona el vertice de partida
    while(aux != nullptr){//Y busca al de llegada
        if(aux->vertice == destino){
            return aux->peso;
        }
        aux = aux->sig;
    }
    return 0;
}
 
void imprimirSolucion(int distancias[], int previos[], int vertices){
    printf("Vertices   Distancia de la Fuente  Vertice Anterior\n");//Imprime en formato de tabla:
    for (int i = 0; i < vertices; ++i)//Los vertices, su camino de nodos  mas corto desde el origen hasta el destino
        printf("   %d \t\t\t %d \t\t %d\n", i, distancias[i],previos[i]);
}

void mostrarRuta(int previos[],int origen, int final,int size){
    int recorrido[size];//Considera un recorrido que visite todos los vertices

    int anterior = final;//Toma el nodo de destino
    int i = 0;

    do{//Realiza el recorrido al reves
        recorrido[i] = anterior;
        anterior = previos[anterior];//va colocando los predecesores hasta llegar al origen
        i++;
    }while(anterior != -1);//Sale del bucle al llegar al origen (cuando: previos[i]==-1)
    
    printf("\nRecorrido mas corto del nodo [%d] hasta el nodo [%d]\n",origen,final);
    for(int j=i-1;j>=0;j--){//Imprime el recorrido en el orden correcto
        if(j == 0 ){
            printf("[%d]\n",recorrido[j]);
        }else{
            printf("[%d]-",recorrido[j]);
        }
    }
}

int minimaDistancia(int distancias[], bool visitados[], int V){
    int minimo = INT_MAX;//Fija el maximo en un valor similar a infinito
    int indice_minimo;//Almacena el indice del vertice con quien la distancia es minima

    for (int i = 0; i < V; i++){
        if (visitados[i] == false && distancias[i] <= minimo){
            indice_minimo = i;//Si el vertice revisado no ha sido visitado y tiene distancia menor al minimo
            minimo = distancias[i];//Ese pasa a ser el nuevo minimo.
        }
    }

    return indice_minimo;//Retorna el nodo con el camino de menor longitud, de un vertice con los demas
}

void dijkstra(Grafo grafo, int fuente, int destino){
     
    printf("==== Ruta mas corta a cada nodo desde el nodo [%d] ====\n",fuente);
    int V = grafo.n;//Extrae el numero de vertices del grafo
    int distancias[V];//Crea vectores que almacenen las distancias y verifiquen vertices ya visitados
    bool visitados[V];
    int previos[V];//Indica de donde partieron
    previos[fuente] = -1;//Fuente no tiene nodos previos, se le asigna un "-1"

    for (int i = 0; i < V; i++){
        distancias[i] = INT_MAX; //Se fijan todas las distancias como infinito al principio
        visitados[i] = false;
    }

    distancias[fuente] = 0; //La distancia de la fuente a la fuente es cero
 
   // Obtencion del camino mas corto desde el orien hacia todos los vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minimaDistancia(distancias, visitados, V);//Saca el vertice con la menor distancia al anterior
        visitados[u] = true;//Marca a ese vertice como visitado
        for (int v = 0; v < V; v++)//Lo identifica como minimo local y compara con los demas vertices
        //Considera 4 condiciones
                    //1.-No toma en cuenta vertices ya visitados (!visitados[v])
                    //2.-Que sean adyacentes (grafo.obtenerPeso(u,v)!=0)
                    //3.-Que el camino mas corto no sea infinito (distancias[u] != INT_MAX)
            if (!visitados[v] && grafo.obtenerPeso(u,v) && distancias[u] != INT_MAX && distancias[u] + grafo.obtenerPeso(u,v) < distancias[v]){
                //4.- Para cada vertice analizado compara:
                    //A: Su camino mas corto al orgien actualmente. distancias[v]
                    //B: El camino al origen pasando por el minimo local (distancias[u] + grafo.obtenerPeso(u,v))
                    //Si B<A
                distancias[v] = distancias[u] + grafo.obtenerPeso(u,v);//Su camino mas corto se actualiza a B
                previos[v] = u;//Por lo tanto, el minimo local es predecesor de este vertice (Penultimo del camino)
            }
    }
    imprimirSolucion(distancias,previos, V);//Muestra todos los caminos minimos a cada vertice desde el de partida(fuente)
    mostrarRuta(previos,fuente,destino,V);//Muestra el camino nodo a nodo de la fuente al destino especifico.
}

int main(){
    // Crear un grafo
    int V = 6;
    Grafo grafo = Grafo(V);

    grafo.agregarArista(0,1,2);
    grafo.agregarArista(0,2,3);
    grafo.agregarArista(1,3,5);
    grafo.agregarArista(1,4,2);
    grafo.agregarArista(2,4,5);
    grafo.agregarArista(3,4,1);
    grafo.agregarArista(4,5,4);
    grafo.agregarArista(3,5,2);


    grafo.summary();
 
    dijkstra(grafo, 0,5);
 
    return 0;
}