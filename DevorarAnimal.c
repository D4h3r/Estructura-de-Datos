#define maxVisitantes 1000

//existe el animal
int existeAnimal(struct Zoologico *zoo, int idAnimal){
    struct NodoAnimal *rec = zoo->animales;
    while(rec != NULL){
        if(rec->datosAnimal->idAnimal == idAnimal){
            return 1;
        }
        rec = rec->sig;
    }
    return 0;
}


//tipo de alimentacion
char* tipoAlimentacion(struct Zoologico *zoo, int idAnimal){
    struct NodoAnimal *rec = zoo->animales;
    while(rec != NULL){
        if(aux->datosAnimal->idAnimal == idAnimal){
            return rec->datosAnimal->tipoAlimentacion;
        }
        rec = rec->sig;
    }
    return NULL;
}

//el visitante visito al animal
int visitoAlAnimal(struct Zoologico *zoo, int idAnimal, char *rutVisitante){
    struct NodoVisitante *rec = zoo->visitantes;
    while(rec->sig != NULL){
        if(strcmp(rec->datosVisitante->rut, rutVisitante) == 0){
            for(int i = 0; i < maxVisitantes; i++){
                if(rec->datosVisitante->visitas[i] != NULL){
                    if(rec->datosVisitante->visitas[i]->idAnimal == idAnimal){
                        return 1;
                    }
                }
            }
        }
        rec = rec->sig;
    }
    return 0;
}

//cumple las condiciones y retorna el rut del visitante
char* cumpleCondiciones(struct Zoologico *zoo, int idAnimal, char *rutVisitante, char *tipoAlimentacion){
    if(existeAnimal(zoo, idAnimal) == 1){
        if(strcmp(tipoAlimentacion(zoo, idAnimal), tipoAlimentacion) == 0){
            if(visitoAlAnimal(zoo, idAnimal, rutVisitante) == 1){
                return rutVisitante;
            }
        }
    }
    return NULL;
}

//eliminar visitante
int eliminarVisitante(struct NodoVisitante **headVisitantes, char *rutVisitante){
    struct NodoVisitante *rec = *headVisitantes;
    while(rec != NULL){
        if(strcmp(rec->datosVisitante->rut, rutVisitante) == 0){
            rec->ant->sig = rec->sig;
            rec->sig->ant = rec->ant;
            free(rec);
            return 1;
        }
        rec = rec->sig;
    }
    return 0;
}
            


//eliminar animal
void eliminarAnimal(struct NodoAnimal **animal, int idAnimal){
    struct NodoAnimal *rec = *animal;
    if((*animal)->datosAnimal->idAnimal == idAnimal){
        *animal = (*animal)->sig;
        free(rec);
    }else{
        while(rec->sig != NULL){
            if(rec->sig->datosAnimal->idAnimal == idAnimal){
                rec->sig = rec->sig->sig;
                free(rec->sig);
            }
            rec = rec->sig;
        }
    }
}


int devorarVisitante(struct Zoologico *zoo, int idAnimal, char *rutVisitante){
    if(cumpleCondiciones(zoo, idAnimal, rutVisitante, zoo->animales->datosAnimal->tipoAlimentacion) != NULL){
        if(eliminarVisitante(&zoo->visitantes, rutVisitante) == 1){
            eliminarAnimal(&zoo->animales, idAnimal);
            return 1;
        }
    }
    return 0;
}
