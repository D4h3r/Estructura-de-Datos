#define maxClientes 1000

//DECLARACION DE LAS ESTRUCTURAS A UTILIZAR
struct CocaCola
{
    struct NodoProducto *productos;
    struct NodoCiudad *ciudades;
}

struct NodoProducto
{
    struct Producto *producto;
    struct NodoProducto *siguiente;
}

struct Producto
{
    char *nombre;
    int precio;
    int id;
    int cantidadProducida;
}

struct NodoCiudad
{
    struct Ciudad *ciudad;
    struct NodoCiudad *siguiente;
}

struct Ciudad
{
    char *nombre;
    char *comuna;
    int id;
    struct NodoPlanta *plantas;
};

struct NodoPlanta
{
    struct Planta *planta;
    struct NodoPlanta *siguiente;
};

struct Planta
{
    char *nombre;
    char *tipoPlanta; //distribucion o produccion
    char *ciudad;
    char *comuna;
    int capacidad;
    int idPlanta;
    struct listaVehiculos *vehiculos;
};

struct listaVehiculos
{
    int cantVehiculos;
    struct NodoVehiculo *abbVehiculos;
};

struct NodoVehiculo
{
    struct Vehiculo *vehiculo;
    struct NodoVehiculo *izq, *der;
};

struct Vehiculo
{
    char *patente;
    char *marca;
    char *modelo;
    char *tipoVehiculo;
    int capacidadVehiculo;
    struct Cliente **clientes;
};

struct Cliente
{
    char *rut;
    char *nombre;
    char *direccion;
    char *comuna;
    char *ciudad;
    char *telefono;
    int cantidadComprada;
    struct Producto *producto;
};


//DECLARACION DE LAS FUNCIONES A UTILIZAR

struct NodoCiudad crearNodoCiudad()
{
    struct NodoCiudad *nuevo;
    nuevo = (struct NodoCiudad *)malloc(sizeof(struct NodoCiudad));

    /*Se completa con los datos*/
    printf("Ingrese el nombre de la ciudad: ");
    scanf("%s", &nuevo->ciudad->nombre);
    printf("Ingrese la comuna de la ciudad: ");
    scanf("%s", &nuevo->ciudad->comuna);
    printf("Ingrese el id de la ciudad: ");
    scanf("%d", &nuevo->ciudad->id);

    nuevo->siguiente = NULL;
    return nuevo;
}

//AGREGAR CIUDAD, lista simplemente enlazada con nodo fantasma
void agregarCiudad(struct NodoCiudad **headLista)
{
    struct NodoCiudad *rec = *headLista;
    struct NodoCiudad *nuevo;

    while(rec != NULL)
    {
        /*si el nodo siguiente es nulo, se agrega el nuevo nodo*/
        if(rec->siguiente == NULL)
        {
            nuevo = crearNodoCiudad();
            rec->siguiente = nuevo;
            return;
        }
        rec = rec->siguiente;
    }
}

//eliminar ciudad, lista simplemente enlazada con nodo fantasma
void eliminarCiudad(struct NodoCiudad **ciudades, int id)
{
    struct NodoCiudad *rec = *ciudades;
    struct NodoCiudad *aux;

    while(rec != NULL)
    {
        if(rec->siguiente->ciudad->id == id)
        {
            aux = rec->siguiente;
            rec->siguiente = rec->siguiente->siguiente;
            free(aux);
            return;
        }
        rec = rec->siguiente;
    }
}

int buscarCiudad(struct NodoCiudad *ciudades, int id)
{
    struct NodoCiudad *rec = ciudades;
    while(rec != NULL)
    {
        if(rec->ciudad->id == id)
            return 1;
        rec = rec->siguiente;
    }
    return 0;
}

void mostrarCiudades(struct NodoCiudad *ciudades)
{
    struct NodoCiudad *rec = ciudades;
    while (rec != NULL)
    {
        printf("La ciudad es: %s, la comuna es: %s, el id es: %d", rec->ciudad->nombre, rec->ciudad->comuna, rec->ciudad->id);
        rec = rec->siguiente;
    }
}

//modificar ciudad, lista simplemente enlazada con nodo fantasma
void modificarCiudad(struct NodoCiudad *headCiudades, int id, char *nombre, char *comuna)
{
    struct NodoCiudad *rec = headCiudades;
    while (rec->siguiente != NULL)
    {
        if (id == rec->ciudad->id)
        {
            rec->ciudad->nombre = nombre;
            rec->ciudad->comuna = comuna;
            return;
        }
        rec = rec->siguiente;
    }
}

//crear nodo producto
struct NodoProducto crearNodoProducto()
{
    struct NodoProducto *nuevo;
    nuevo = (struct NodoProducto *)malloc(sizeof(struct NodoProducto));

    /*Se completa con los datos*/
    printf("Ingrese el nombre del producto: ");
    scanf("%s", &nuevo->producto->nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%d", &nuevo->producto->precio);
    printf("Ingrese el id del producto: ");
    scanf("%d", &nuevo->producto->id);
    printf("Ingrese la cantidad producida del producto: ");
    scanf("%d", &nuevo->producto->cantidadProducida);

    nuevo->siguiente = NULL;
    return nuevo;
}

//agregar producto, lista simplemente enlazada con nodo fantasma
void agregarProducto(struct NodoProducto **headLista)
{
    struct NodoProducto *rec = *headLista;
    struct NodoProducto *nuevo;

    while(rec != NULL)
    {
        /*si el nodo siguiente es nulo, se agrega el nuevo nodo*/
        if(rec->siguiente == NULL)
        {
            nuevo = crearNodoProducto();
            rec->siguiente = nuevo;
            return;
        }
        rec = rec->siguiente;
    }
}

void mostrarProductos(struct NodoProducto *productos)
{
    struct NodoProducto *rec = productos;
    while (rec != NULL)
    {
        printf("El producto es: %s, el precio es: %d, el id es: %d, la cantidad producida es: %d", rec->dato->nombre, rec->dato->precio, rec->dato->id, rec->dato->cantidadProducida);
        rec = rec->siguiente;
    }
}



//eliminar producto, lista simplemente enlazada con nodo fantasma
void eliminarProducto(struct NodoProducto **productos, int id)
{
    struct NodoProducto *rec = *productos;
    while(rec->siguiente != NULL)
    {
        if(rec->producto->id == id)
        {
            rec->siguiente = rec->siguiente->siguiente;
            free(rec->siguiente);
            return;
        }
        rec = rec->siguiente;
    }
}



//modificar producto, lista simplemente enlazada con nodo fantasma
void modificarProducto(struct NodoProducto *productos, int id, char *nuevoNombre, int nuevoPrecio, int nuevaCantidadProducida)
{
    struct NodoProducto *rec = productos;
    while(rec->siguiente != NULL)
    {
        if(rec->producto->id == id)
        {
            rec->producto->nombre = nuevoNombre;
            rec->producto->precio = nuevoPrecio;
            rec->producto->cantidadProducida = nuevaCantidadProducida;
            return;
        }
        rec = rec->siguiente;
    }
}

int buscarProducto(struct NodoProducto *productos, int id)
{
    struct NodoProducto *rec = productos;
    while(rec->siguiente != NULL)
    {
        if(rec->producto->id == id)
            return 1;
        rec = rec->siguiente;
    }
    return 0;
}

//crear nodo planta
struct NodoPlanta crearNodoPlanta()
{
    struct NodoPlanta *nuevo;
    nuevo = (struct NodoPlanta *)malloc(sizeof(struct NodoPlanta));

    /*Se completa con los datos*/
    printf("Ingrese el nombre de la planta: ");
    scanf("%s", &nuevo->planta->nombre);
    printf("Ingrese el tipo de planta: ");
    scanf("%s", &nuevo->planta->tipoPlanta);
    printf("Ingrese la ciudad de la planta: ");
    scanf("%s", &nuevo->planta->ciudad);
    printf("Ingrese la comuna de la planta: ");
    scanf("%s", &nuevo->planta->comuna);
    printf("Ingrese la capacidad de la planta: ");
    scanf("%d", &nuevo->planta->capacidad);
    printf("Ingrese el id de la planta: ");
    scanf("%d", &nuevo->planta->idPlanta);

    nuevo->siguiente = NULL;
    return nuevo;
}

//agregar planta, lista simplemente enlazada con nodo fantasma
void agregarPlanta(struct NodoPlanta **headLista)
{
    struct NodoPlanta *rec = *headLista;
    struct NodoPlanta *nuevo;

    while(rec != NULL)
    {
        /*si el nodo siguiente es nulo, se agrega el nuevo nodo*/
        if(rec->siguiente == NULL)
        {
            nuevo = crearNodoPlanta();
            rec->siguiente = nuevo;
            return;
        }
        rec = rec->siguiente;
    }
}


void mostrarPlanta(struct NodoPlanta *plantas)
{
    struct NodoPlanta *rec = plantas;
    while (rec != NULL)
    {
        printf("La planta es: %s, la ciudad es: %s, el id es: %d", rec->planta->nombre, rec->planta->ciudad, rec->planta->id);
        rec = rec->siguiente;
    }
}

//eliminar planta, lista simplemente enlazada con nodo fantasma
void eliminarPlanta(struct NodoPlanta **plantas, int id)
{
    struct NodoPlanta *rec = *plantas;
    while(rec->siguiente != NULL)
    {
        if(rec->planta->idPlanta == id)
        {
            rec->siguiente = rec->siguiente->siguiente;
            free(rec->siguiente);
            return;
        }
        rec = rec->siguiente;
    }
}

//modificar planta, lista simplemente enlazada con nodo fantasma
void modificarPlanta(struct NodoPlanta *plantas, int id, char *nuevoNombre, char *nuevoTipoPlanta, char *nuevaCiudad, char *nuevaComuna, int nuevaCapacidad)
{
    struct NodoPlanta *rec = plantas;
    while(rec->siguiente != NULL)
    {
        if(rec->planta->idPlanta == id)
        {
            rec->planta->nombre = nuevoNombre;
            rec->planta->tipoPlanta = nuevoTipoPlanta;
            rec->planta->ciudad = nuevaCiudad;
            rec->planta->comuna = nuevaComuna;
            rec->planta->capacidad = nuevaCapacidad;
            return;
        }
        rec = rec->siguiente;
    }
}

int buscarPlanta(struct NodoPlanta *plantas, int id)
{
    struct NodoPlanta *rec = plantas;
    while(rec->siguiente != NULL)
    {
        if(rec->planta->idPlanta == id)
            return 1;
        rec = rec->siguiente;
    }
    return 0;
}

//buscar cliente, arreglo compacto
void buscarCliente(struct Cliente *clientes, int rut)
{
    int i;
    for(i = 0; i < maxClientes; i++)
    {
        if(clientes[i] != NULL)
        {
            if(clientes[i]->rut == rut)
                return 1;
        }
    }
    return 0;
}

void mostrarClientes(struct Cliente *clientes)
{
    int i;
    for(i = 0; i < maxClientes; i++)
    {
        if(clientes[i] != NULL)
            printf("El cliente es: %s, el rut es: %d", clientes[i]->nombre, clientes[i]->rut);
    }
}

void eliminarCliente(struct Cliente **clientes, char *rut)
{
    int i, k;
    for(i = 0; i < maxClientes; i++)
    {
        if(clientes[i] == NULL)
        {
            for(k = i; k < maxClientes - 1; k++)
            {
                clientes[k] = clientes[k + 1];
            }
            clientes[maxClientes - 1] = NULL;
            i--;
        }
    }
}

void modificarCliente(struct Cliente *clientes, char *rut, char *nombre, char *direccion, char *comuna, char *ciudad, int telefono, int cantidad)
{
    int i;
    for(i = 0; i < maxClientes; i++)
    {
        if(clientes[i] != NULL)
        {
            if(clientes[i]->rut == rut)
            {
                clientes[i]->rut = rut;
                clientes[i]->nombre = nombre;
                clientes[i]->direccion = direccion;
                clientes[i]->comuna = comuna;
                clientes[i]->ciudad = ciudad;
                clientes[i]->telefono = telefono;
                clientes[i]->cantidadComprada = cantidad;
                return;
            }
        }
    }
}

//crear nodo cliente
struct NodoCliente crearNodoCliente()
{
    struct NodoCliente *nuevo;
    nuevo = (struct NodoCliente *)malloc(sizeof(struct NodoCliente));

    /*Se completa con los datos*/
    printf("Ingrese el rut del cliente: ");
    scanf("%s", &nuevo->cliente->rut);
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", &nuevo->cliente->nombre);
    printf("Ingrese la direccion del cliente: ");
    scanf("%s", &nuevo->cliente->direccion);
    printf("Ingrese la comuna del cliente: ");
    scanf("%s", &nuevo->cliente->comuna);
    printf("Ingrese la ciudad del cliente: ");
    scanf("%s", &nuevo->cliente->ciudad);
    printf("Ingrese el telefono del cliente: ");
    scanf("%s", &nuevo->cliente->telefono);
    printf("Ingrese la cantidad comprada del cliente: ");
    scanf("%d", &nuevo->cliente->cantidadComprada);

    nuevo->siguiente = NULL;
    return nuevo;
}

void agregarCliente(struct Cliente **clientes)
{
    int i;
    for(i = 0; i < maxClientes; i++)
    {
        if(clientes[i] == NULL)
        {
            clientes[i] = crearNodoCliente();
            return;
        }
    }
}


//crear nodo vehiculo
struct NodoVehiculo crearNodoVehiculo()
{
    struct NodoVehiculo *nuevo;
    nuevo = (struct NodoVehiculo *)malloc(sizeof(struct NodoVehiculo));

    /*Se completa con los datos*/
    printf("Ingrese la patente del vehiculo: ");
    scanf("%s", &nuevo->vehiculo->patente);
    printf("Ingrese la marca del vehiculo: ");
    scanf("%s", &nuevo->vehiculo->marca);
    printf("Ingrese el modelo del vehiculo: ");
    scanf("%s", &nuevo->vehiculo->modelo);
    printf("Ingrese el tipo de vehiculo: ");
    scanf("%s", &nuevo->vehiculo->tipoVehiculo);
    printf("Ingrese la capacidad del vehiculo: ");
    scanf("%d", &nuevo->vehiculo->capacidadVehiculo);

    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

//arbol binario recursivo
void agregarVehiculo(struct NodoVehiculo **headArbol, char *patente, char *marca, char *modelo, char *tipoVehiculo, int capacidad)
{
    if(*headArbol == NULL)
    {
        *headArbol = crearNodoVehiculo();
        return;
    }
    if(strcmp((*headArbol)->vehiculo->patente, patente) > 0)
        agregarVehiculo(&(*headArbol)->izq, patente, marca, modelo, tipoVehiculo, capacidad);
    else
        agregarVehiculo(&(*headArbol)->der, patente, marca, modelo, tipoVehiculo, capacidad);
}


void mostrarVehiculos(struct NodoVehiculo *abb)
{
    if(abb != NULL)
    {
        mostrarVehiculos(abb->izq);
        printf("La patente es: %s, la marca es: %s, el modelo es: %s", abb->vehiculo->patente, abb->vehiculo->marca, abb->vehiculo->modelo);
        mostrarVehiculos(abb->der);
    }
}

//buscar vehiculo, arbol binario recursivo
void buscarVehiculo(struct NodoVehiculo *abb, char *patente)
{
    if(!abb | abb->vehiculo->patente == patente)
        return abb;
    if(strcmp(abb->vehiculo->patente, patente) > 0)
        return buscarVehiculo(abb->izq, patente);
    else
        return buscarVehiculo(abb->der, patente);
}

void modificarVehiculo(struct NodoVehiculo *abb, char *patente, char *marca, char *modelo, char *tipoVehiculo, int capacidadVehiculo)
{
    if(abb != NULL)
    {
        if(strcmp(abb->vehiculo->patente, patente) == 0)
        {
            abb->vehiculo->marca = marca;
            abb->vehiculo->modelo = modelo;
            abb->vehiculo->tipoVehiculo = tipoVehiculo;
            abb->vehiculo->capacidadVehiculo = capacidadVehiculo;
            return;
        }
        else
        {
            if(strcmp(abb->vehiculo->patente, patente) > 0)
                modificarVehiculo(abb->izq, patente, marca, modelo, tipoVehiculo, capacidadVehiculo);
            else
                modificarVehiculo(abb->der, patente, marca, modelo, tipoVehiculo, capacidadVehiculo);
        }
    }
}

void reemplazar(struct NodoVehiculo *abb, struct NodoVehiculo **aux)
{
    if(!((*abb)->der))
    {
        (*aux)->vehiculo = (*abb)->vehiculo;
        (*aux) = (*abb);
        (*abb) = (*abb)->izq;
    }
    else
        reemplazar(&(*abb)->der, &(*aux));
}

void eliminarVehiculo(struct NodoVehiculo **abb, char *patente)
{
    struct NodoVehiculo *aux = NULL;
    if(!(*abb))
        return;
    if(strcmp((*abb)->vehiculo->patente, patente) > 0)
        eliminarVehiculo(&(*abb)->izq, patente);
    else
    {
        if(strcmp((*abb)->vehiculo->patente, patente) < 0)
            eliminarVehiculo(&(*abb)->der, patente);
        else
        {
            aux = *abb;
            if(!aux->der)
                *abb = aux->izq;
            else
            {
                if(!aux->izq)
                    *abb = aux->der;
                else
                    reemplazar(&aux->izq, &aux);
            }
            free(aux);
        }
    }
}

//funcion que cuenta cuanto gasto un cliente en una compra
int calcularGastoCliente(struct Cliente *cliente, char *rutCliente)
{
    int i, gasto = 0;
    for(i = 0; i < maxClientes; i++)
    {
        if(cliente[i] != NULL)
        {
            if(strcmp(cliente[i]->rut, rutCliente) == 0)
            {
                gasto += cliente[i]->producto->precio;
            }
        }
    }
    return gasto;
}

//funcion que ve que cliente gasto mas en una compra
char  *clienteMasGasto(struct Cliente **clientes)
{
    int i, mayor = 0;
    struct Cliente *clienteMayor = NULL;
    for(i = 0; i < maxClientes; i++)
    {
        if(clientes[i] != NULL)
        {
            if(clienteMayor == NULL || calcularGastoCliente(clientes[i], clientes[i]->rut) > mayor)
            {
                clienteMayor = clientes[i];
                mayor = calcularGastoCliente(clientes[i], clientes[i]->rut);
            }
        }
    }
    if(clienteMayor != NULL)
        return clienteMayor->rut;
    return NULL;
}

//le pasamos los valores por referencia para que se modifiquen en la funcion
void menu(struct NodoCliente *cliente, struct NodoCiudad *ciudad, struct NodoPlanta *planta, struct NodoVehiculo *vehiculo, struct NodoProducto *producto)
{
    int opcion;
    do
    {
        printf("1. Agregar cliente");
        printf("2. Eliminar cliente");
        printf("3. Modificar cliente");
        printf("4. Buscar cliente");
        printf("5. Mostrar clientes");
        printf("6. Agregar ciudad");
        printf("7. Eliminar ciudad");
        printf("8. Modificar ciudad");
        printf("9. Buscar ciudad");
        printf("10. Mostrar ciudades");
        printf("11. Agregar planta");
        printf("12. Eliminar planta");
        printf("13. Modificar planta");
        printf("14. Buscar planta");
        printf("15. Mostrar plantas");
        printf("16. Agregar vehiculo");
        printf("17. Eliminar vehiculo");
        printf("18. Modificar vehiculo");
        printf("19. Buscar vehiculo");
        printf("20. Mostrar vehiculos");
        printf("21. Agregar producto");
        printf("22. Eliminar producto");
        printf("23. Modificar producto");
        printf("24. Buscar producto");
        printf("25. Mostrar productos");
        printf("26. Calculo de gasto de un cliente");
        printf("27. Cliente que mas gasto");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("Ingrese el rut del cliente");
                agregarCliente(cliente);
                break;
            case 2:
                eliminarCliente(cliente, cliente->cliente->rut);
                break;
            case 3:
                modificarCliente(cliente, cliente->cliente->rut, cliente->cliente->nombre, cliente->cliente->direccion, cliente->cliente->comuna, cliente->cliente->ciudad, cliente->cliente->telefono, cliente->cliente->cantidadComprada);
                break;
            case 4:
                buscarCliente(cliente, cliente->cliente->rut);
                break;
            case 5:
                mostrarClientes(cliente);
                break;
            case 6:
                agregarCiudad(ciudad);
                break;
            case 7:
                eliminarCiudad(ciudad, ciudad->ciudad->id);
                break;
            case 8:
                modificarCiudad(ciudad, ciudad->ciudad->id, ciudad->ciudad->nombre, ciudad->ciudad->comuna);
                break;
            case 9:
                buscarCiudad(ciudad, ciudad->ciudad->id);
                break;
            case 10:
                mostrarCiudades(ciudad);
                break;
            case 11:
                agregarPlanta(planta);
                break;
            case 12:
                eliminarPlanta(planta, planta->planta->idPlanta);
                break;
            case 13:
                modificarPlanta(planta, planta->planta->nombre, planta->planta->tipoPlanta, planta->planta->ciudad, planta->planta->comuna, planta->planta->capacidad);
                break;
            case 14:
                buscarPlanta(planta, planta->planta->idPlanta);
                break;
            case 15:
                mostrarPlanta(planta);
                break;
            case 16:
                agregarVehiculo(vehiculo, vehiculo->vehiculo->patente, vehiculo->vehiculo->marca, vehiculo->vehiculo->modelo, vehiculo->vehiculo->tipoVehiculo, vehiculo->vehiculo->capacidadVehiculo);
                break;
            case 17:
                eliminarVehiculo(vehiculo);
                break;
            case 18:
                modificarVehiculo(vehiculo, vehiculo->vehiculo->patente, vehiculo->vehiculo->marca, vehiculo->vehiculo->modelo, vehiculo->vehiculo->tipoVehiculo, vehiculo->vehiculo->capacidadVehiculo);
                break;
            case 19:
                buscarVehiculo(vehiculo, vehiculo->vehiculo->patente);
                break;
            case 20:
                mostrarVehiculos(vehiculo);
                break;
            case 21:
                agregarProducto(producto);
                break;
            case 22:
                eliminarProducto(producto, producto->producto->id);
                break;
            case 23:
                modificarProducto(producto, producto->producto->id, producto->producto->nombre, producto->producto->precio, producto->producto->cantidadProducida);
                break;
            case 24:
                buscarProducto(producto, producto->producto->id);
                break;
            case 25:
                mostrarProductos(producto);
                break;
            case 26:
                calcularGastoCliente(cliente, cliente->cliente->rut);
                break;
            case 27:
                clienteMasGasto(cliente);
                break;
            case 28:
                printf("Saliendo...");
                break;
            default:
                printf("Opcion invalida");
                break;
        }
    }while(opcion != 28);
}

int main()
{
    return 0;
}
