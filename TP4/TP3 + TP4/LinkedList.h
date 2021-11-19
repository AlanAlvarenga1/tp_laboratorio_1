/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
/**
 * @fn LinkedList ll_newLinkedList*(void)
 * @brief Crea la linkedList que se usara en el programa
 *
 * @return Devolvera la linkedList
 */
LinkedList* ll_newLinkedList(void);
/**
 * @fn int ll_len(LinkedList*)
 * @brief retorna el tamaño total de la LinkedList
 *
 * @param this LinkedList que sera analizado
 * @return Devuelve la cantidad de elementos en la LinkedList
 */
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
/**
 * @fn int ll_add(LinkedList*, void*)
 * @brief Añade un elemento a la LinkedList
 *
 * @param this LinkedList a la que se le añadira el elemento
 * @param pElement Elemento a añadir
 * @return
 */
int ll_add(LinkedList* this, void* pElement);
/**
 * @fn void ll_get*(LinkedList*, int)
 * @brief Toma un elemento de la LinkedList
 *
 * @param this LinkedList en la que se tomara el elemento
 * @param index Posicion del elemento en la LinkedList
 */
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
/**
 * @fn int ll_remove(LinkedList*, int)
 * @brief Elimina un elemento de la LinkedList
 *
 * @param this LinkedList en la que se eliminara el elemento
 * @param index Posicion del elemento a eliminar
 * @return
 */
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
/**
 * @fn int ll_deleteLinkedList(LinkedList*)
 * @brief Elimina la LinkedList
 *
 * @param this LinkedList a eliminar
 * @return
 */
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
/**
 * @fn int ll_sort(LinkedList*, int(*)(void*, void*), int)
 * @brief Funcion encargada de realizar el ordenamiento de los elementos de la LinkedList
 *
 * @param this LinkedList a ordenar
 * @param pFunc Puntero a funcion que sera utilizada para determinar si un elemento es mas grande a otro, y de esa manera resolver si se realiza el ordenamiento
 * @param order Si se inserta 1 sera ordenado ascendentemente, y si se inserta 0 se ordenara descendientemente
 * @return
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
