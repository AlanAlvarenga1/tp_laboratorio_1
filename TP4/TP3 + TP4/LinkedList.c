#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this=(LinkedList*)malloc(sizeof(LinkedList));

    if (this!=NULL) {
    	this->size=0;
    	this->pFirstNode=NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int retorno=-1;

	if (this!=NULL) {
		retorno=this->size;
	}

    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodoActual=NULL;
	int len=ll_len(this);
	int i;

	if (this!=NULL && nodeIndex>-1 && nodeIndex<len) {
		nodoActual=this->pFirstNode;
		for (i=0;i<nodeIndex;i++) {
			nodoActual=nodoActual->pNextNode;
		}
	}
    return nodoActual;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this,nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevo=NULL;
    Node* anterior=NULL;
    int len=ll_len(this);

    if (this!=NULL && nodeIndex>-1 && nodeIndex<=len) {
    	nuevo=(Node*)malloc(sizeof(Node));
    	nuevo->pElement=pElement;
    	nuevo->pNextNode=NULL;

    	if (nodeIndex>0) {
        	anterior=getNode(this,nodeIndex-1);
        	anterior->pNextNode=nuevo;
    	}
    	else {
    		nuevo->pNextNode=this->pFirstNode;
    		this->pFirstNode=nuevo;
    	}

    	this->size++;
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);

    if (this!=NULL) {
    	returnAux=addNode(this, len,pElement);
    	returnAux=0;
    }
    return returnAux;
}

/**
 * @fn void ll_get*(LinkedList*, int)
 * @brief Toma un elemento de la lista
 *
 * @param this Puntero a la lista
 * @param index Ubicacion del elemento a tomar
 * \return int Retorna  (NULL) Si no se encontro el elemento
                        (El elemento) Si funciono correctamente
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);

    if (this!=NULL && index>-1 && index<=len) {
    	Node* nodoActual;
    	nodoActual=getNode(this,index);
    	if (nodoActual!=NULL) {
    		returnAux=nodoActual->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoActual = NULL;
    int len=ll_len(this);

    if (this!=NULL && index>-1 && index<=len) {
    	nodoActual=getNode(this,index);
    	if (nodoActual!=NULL) {
    		nodoActual->pElement=pElement;
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
	Node* nodoAnterior=getNode(this,index-1);
    Node* nodoActual=getNode(this,index);
	Node* nodoSiguiente=getNode(this,index+1);
    int len=ll_len(this);

    if (this!=NULL && index>-1 && index<=len && nodoActual!=NULL) {
    	if (index>0) {
    		nodoAnterior->pNextNode=nodoSiguiente;
    		free(nodoActual);
    		this->size--;
    		returnAux=0;
    	}
    	else {
    		this->pFirstNode=nodoSiguiente;
    		free(nodoActual);
    		this->size--;
    		returnAux=0;
    	}


    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len=ll_len(this);
    int i;

    if (this!=NULL) {
    	for (i=0;i<len;i++) {
    		ll_remove(this,i);
    	}
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this!=NULL) {
    	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodoActual=NULL;

    int i;
    int len=ll_len(this);

    if (this!=NULL) {
    	for (i=0;i<len;i++) {
    		nodoActual=getNode(this,i);

    		if (pElement==nodoActual->pElement) {
    			returnAux=i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len=ll_len(this);

    if (this!=NULL) {
    	if (len==0) {
    		returnAux=1;
    	}
    	else {
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
    int i;

    if (this!=NULL && index<=len && index>-1) {
        Node* nodoActual=NULL;

    	for (i=index;i<len;i++) {
    		nodoActual=getNode(this,i);
    		nodoActual->pNextNode=nodoActual;

    	}
    	addNode(this, index, pElement);
		returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);
    Node* nodoActual=getNode(this,index);

    if (this!=NULL && index<len && index>-1) {
    	if (nodoActual!=NULL) {
    		returnAux=nodoActual->pElement;
    		ll_remove(this, index);
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodoActual=NULL;
    int i;
    int len=ll_len(this);
    int flag=-1; //-1=NO ESTA CONTENIDO		0=CONTENIDO

    if (this!=NULL) {
    	for (i=0;i<len;i++) {
    		nodoActual=getNode(this,i);

    		if (nodoActual->pElement==pElement) {
    			flag=0;
    		}
    	}

    	if (flag==0) {
    		returnAux=1;
    	}
    	else {
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int lenThis=ll_len(this);
    int lenThis2=ll_len(this2);
    void* pElement;
    int flag=0; //-1=NO ESTA CONTENIDO		0=CONTENIDO

    if (this!=NULL && this2!=NULL) {
    	if (lenThis2<=lenThis) {
    		for (i=0;i<lenThis2;i++) {
    			pElement=ll_get(this,i);

    			if (ll_contains(this, pElement)!=1) {
    				flag=-1;
    				break;
    			}
    		}
    	}
    	else {
    		flag=-1;
    	}

    	if (flag==0) {
    		returnAux=1;
    	}
    	else {
    		returnAux=0;
    	}


    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len=ll_len(this);
    void* elementoAClonar;
    int i;

    if (this!=NULL && from>-1 && to>-1 && from<=len && to<=len) {
    	cloneArray=ll_newLinkedList();

    	for (i=from;i<to;i++) {
    		elementoAClonar=ll_get(this,i);
    		ll_add(cloneArray, elementoAClonar);
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len=ll_len(this);
    void* elementoAClonar;
    int i;

    if (this!=NULL) {
    	cloneArray=ll_newLinkedList();

    	for (i=0;i<len;i++) {
    		elementoAClonar=ll_get(this,i);
    		ll_add(cloneArray, elementoAClonar);
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    int len=ll_len(this);

	if (this!=NULL && pFunc!=NULL && order>=0 && order<=1) {
		void* aux1;
		void* aux2;
		returnAux=0;

		for (i=0;i<len-1;i++) {
			for (j=i+1;j<len;j++) {
				aux1=ll_get(this,i);
				aux2=ll_get(this,j);

				if (pFunc(aux1,aux2)==1 && order==1) {
					ll_set(this,i,aux2);
					ll_set(this,i,aux1);
				}
				else if (pFunc(aux1,aux2)==-1 && order==0) {
					ll_set(this,i,aux2);
					ll_set(this,j,aux1);
				}

			}
		}
	}
    return returnAux;

}

