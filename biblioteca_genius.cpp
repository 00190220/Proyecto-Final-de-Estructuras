#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

struct Libro {
    string nombre;
    string genero;
    string autor;
    int isbn;

};

struct Cliente {
    string nombre;
    int numero_cliente;
    string nombre_libro;
};

struct Devolver {
     string nombre;
     int numero_cliente;
     Libro devol_libro;
};

Cliente cliente; // Nombre de la estructura
queue<Cliente> cola_cliente; // Cola de clientes Global
list<Libro> lista_libros; // Lista Global
stack <Devolver> devolv_libro; // Pila Global

void menu_principal();
void agregar_libro(list<Libro>); //Opción 1, agrega un libro a una lista.
void buscar_libros(list<Libro>); //Opción 2, buscar un libro dentro de la lista
void mostrar_librosdisp(list<Libro>); //Opción 3, mostrar los libros que aún no han sido alquilados
void alquilar(); //Opción 4, el libro se elimina de la lista y se agrega un cliente a la cola
void devolver_libro();  //Opción 5, el libro se agrega a la pila 
void mostrar_librosreturn(stack<Devolver>); //Opción 6, los libros retornados se guardara en una la pila
void mostrar_clientes(queue<Cliente>); //Opcion 7, mostrar cola de clientes
void buscar_clientes(); //Opción 8, buscar en la cola de clientes

int main(){

    menu_principal();
    return 0;
}

void menu_principal(){ //menu principal
    int opcion;

    bool status = true;

    do
    {
      
        cout<<endl<<"------------------ MENU PRINCIPAL -------------------"<<endl;
        cout<<"Bienvenido a Biblioteca Genius, "<<endl<<"por favor ingrese la opcion que desea elegir: "<<endl;
        cout<<"1) Agregar libros\t" << "\t2) Buscar libros" << endl;
        cout<<"3) Mostrar libros disponibles\t" << "4) Alquilar libro" << endl;
        cout<<"5) Devolver libro\t" << "\t6) Mostrar libros retornados"<<endl; 
        cout<<"7) Historial de clientes" << "\t8) Buscar clientes\n" << "9) Salir"<<endl;  
        cout<<"Opci"<<char(162)<<"n: ";
        cin>>opcion; cout <<endl;
        
        switch (opcion)
        {
        case 1:
            agregar_libro(lista_libros);
            break;
        case 2:
            buscar_libros(lista_libros);
            break;
        case 3:
            mostrar_librosdisp(lista_libros);
            break;
        case 4:
            alquilar();
            break;
        case 5:
            devolver_libro();
            break;
        case 6:
            mostrar_librosreturn(devolv_libro);
            break;
        case 7:
            mostrar_clientes(cola_cliente);
            break;
        case 8:
            buscar_clientes();
            break;
        case 9: 
            fflush(stdin);
            cout<<"\nGracias por utilizar nuestros servicios."<<endl;
            status = false;
            break;
        default:
            cout << "Opci" << char(162) << "n no valida. Por favor intente nuevamente."<< endl;
            break;
        }
    } while (status);
    
}

void agregar_libro(list<Libro>lista_li){ //Funcion de agregar libro
    Libro libro_nuevo;
    bool status = true;
    int opcion;
    do
    {
        cout << char(168) <<"Qu" << char(130) <<" desea hacer?" << endl;
        cout<<"1) Agregar libro"<<endl;
        cout<<"2) Regresar"<<endl;
        cout << "Opci" <<char(162)<<"n: ";
        cin>>opcion;
        cout << endl;
        cin.ignore();


        switch (opcion)
        {
        case 1:
            cout<<"Nombre del libro: ";
            getline(cin, libro_nuevo.nombre);     
            cout << "G"<<char(130)<<"nero: ";
            getline(cin, libro_nuevo.genero);
            cout<<"Autor: ";
            getline(cin, libro_nuevo.autor);
            cout<<"Digite el ISBN: ";

            cin>>libro_nuevo.isbn;
            lista_libros.push_back(libro_nuevo);
            cout<<"El libro "<<libro_nuevo.nombre<<" se ha agregado a la lista.\n";
            cout<<endl;
            
            break;
        case 2: 
            cout << "Regresando al menu principal..." << endl;
            menu_principal();
            status = false;
            break;
        default:
            cout<<"Opcion no valida, por favor intente nuevamente."<<endl;
            break;
        }

    } while (status);
}
void buscar_libros(list<Libro> lista_libros){ //Funcion de buscar libro
    int isbn_buscar, opc;
    string nombre_libro;
    list <Libro> aux_lista = lista_libros;
    bool status = true;

    do
    {
        cout << "Buscar por: "<<endl;
        cout << "1) Nombre del libro\n";
        cout << "2) ISBN" << endl;
        cout << "3) Regresar" <<endl;
        cout << "Opci"<<char(162)<<"n: "; cin >> opc; cout << endl;
        cin.ignore();

            switch (opc) {
                case 1:
                    cout << "Ingresa el nombre del libro a buscar: ";
                    getline(cin,nombre_libro);
                        if(lista_libros.empty()){
                            cout<<"No hay libros disponibles en este momento."<<endl;
                        return;
                        }
                            else {
      
                                auto l = find_if(lista_libros.begin(), lista_libros.end(), [&nombre_libro](const Libro &l)
                                    {return l.nombre == nombre_libro;}); 

                                if (l == lista_libros.end())
                                    cout << "El libro con nombre: " << nombre_libro << " no ha sido encontrado.\n\n";
                         
                                else
                                    cout << "El libro "<< nombre_libro <<" se encuentra disponible. "<<endl <<endl;
                            }
                    break;

                case 2: 
                    cout << "Ingrese el ISBN del libro: ";
                    cin >> isbn_buscar;
                        if(lista_libros.empty()){
                            cout<<"No hay libros disponibles en este momento."<<endl;
                            return;
                        }
                        else {
                            auto l = find_if(lista_libros.begin(), lista_libros.end(), [&isbn_buscar](const Libro &l)
                                {
								return l.isbn == isbn_buscar;}); 

                                if (l == lista_libros.end())
                                    cout << "El libro con ISBN: " << isbn_buscar << " no ha sido encontrado."<<endl;
                                else
                                cout << "El libro "<< isbn_buscar <<" se encuentra disponible. "<<endl;
                        }          
                break;
                case 3: 
                    cout << "Regresando al menu principal..." << endl;
                    menu_principal();
                    status = false;
                break;
            default: 
                cout << "Opci" <<char(162)<<"n no disponible."<<endl;
            break;
    } 
    } while (status); 
}
///////////////////////////////////////////////
void mostrar_librosdisp(list<Libro> lista_li){   
    list<Libro> nueva_lista = lista_li;
    if (nueva_lista.empty()){
        cout <<char(173)<<"La lista est"<< char(160) <<" vacia!" << endl;
    }
    else if (!nueva_lista.empty()){
        
            while (!nueva_lista.empty()){
            cout<<"\nNombre del libro: "<<nueva_lista.back().nombre<<endl;
            cout<<"Autor del libro: "<<nueva_lista.back().autor<<endl;
            cout<<"Genero del libro: "<<nueva_lista.back().genero<<endl;
            cout<<"ISBN del libro: "<<nueva_lista.back().isbn<<endl;
            nueva_lista.pop_back();
            cout<<endl;
            }
    }      
}

void alquilar(){ //Al alquilar un libro, este se elimina de la lista.
    string libro_alq;
    bool status = true;
    int opc;
    
    do { 
    cout << char(168) <<"Que" << char(130) <<" desea hacer?" << endl;
    cout << "1) Alquilar libro" << endl;
    cout << "2) Regresar" << endl;
    cout << "Opci" << char(162) << "n: "; cin >> opc;

    switch (opc){
        case 1:
            cin.ignore();
            cout<<"Ingrese el nombre completo del cliente: ";
            getline(cin, cliente.nombre);
            cout<<"Ingrese el numero de cliente: ";
            cin>>cliente.numero_cliente;
            cin.ignore();
            cout<<"Ingrese el nombre del libro que desea alquilar: ";
            getline(cin, libro_alq);

                if(!lista_libros.empty()){
            
                            auto l = find_if(lista_libros.begin(), lista_libros.end(), [&libro_alq](const Libro &l)
                            {
                            return l.nombre == libro_alq;}); 

                            if (l == lista_libros.end())
                            cout << "El libro con nombre: " <<cliente.nombre_libro << " no ha sido encontrado."<<endl;
                                
                            else
                                cliente.nombre_libro = libro_alq;
                                
                                cout << "El libro "<< cliente.nombre_libro <<" ha sido alquilado exitosamente. "<<endl;
                                lista_libros.erase(l);
                                cola_cliente.push(cliente);
                }
                else
                {
                    cout<<"No hay libros disponibles para alquilar."<<endl;
                }
            break;
        
        case 2: 
            cout << "Regresando al menu principal...\n";
            status = false;
            menu_principal();
            break;
        default:
            break;
        }
    
    } while (status);

}
/////////////////////////////////////////////////////////

void devolver_libro(){ //Función para devolver libro



    Devolver devolver;
    int opcion;

    cout<<"1) Devolver libro "<<endl;
    cout<<"2) Regresar al menu principal"<<endl;
    cout<<"Opcion: ";
    cin>>opcion;
    cin.ignore();
    switch (opcion)
    {
    case 1: 
        cout<<"Ingrese el nombre del cliente: ";
        getline(cin, devolver.nombre);
        cout<<"Ingrese el numero de cliente: ";
        cin>>devolver.numero_cliente;
        cin.ignore();
        cout<<"Ingrese el nombre del libro que desea devolver: ";
        getline(cin, devolver.devol_libro.nombre);
        cout<<"Ingrese el g"<<char(130)<<"nero del libro: ";
        getline(cin, devolver.devol_libro.genero);
        cout<<"Ingrese el autor del libro: ";
        getline(cin, devolver.devol_libro.autor);
        cout<<"Ingrese el ISBN del libro: ";
        cin>>devolver.devol_libro.isbn;

        devolv_libro.push(devolver);


        cout<<"Se ha devuelto el libro con exito! "<<endl;
        break;

    case 2: 
        menu_principal();
        break;
    default:
        cout<<"Opcion no valida. Por favor intente nuevamente."<<endl;
        break;
    }  
}

ostream& operator<<(std::ostream& o, const Devolver& d) {//Sobrecarga del operator << para poder mostrar la pila de libros que han sido devueltos de la estructura Devolver
            // Usas o como si fuera cout

            o<<"Nombre del cliente: "<< d.nombre<<endl;
            o<<"Numero del cliente: "<< d.numero_cliente<<endl;
            o<<"Nombre del libro: "<< d.devol_libro.nombre<<endl;
            o<<"G"<<char(130)<<"nero del libro:"<< d.devol_libro.genero<<endl;
            o<<"Autor del libro: "<< d.devol_libro.autor<<endl;
            o<<"ISBN del libro: "<< d.devol_libro.isbn<<endl;
           
            return o;
}

void mostrar_librosreturn(stack<Devolver> devolver) { //Funcion que muestra los libros que han sido devueltos
    stack<Devolver> pila_aux = devolver;
    cout<<"----MOSTRANDO LIBROS DEVUELTOS----"<<endl<<endl;

    if (pila_aux.empty())
    {
        cout<<"No hay libros devueltos."<<endl;
    }else
    {
        while (!pila_aux.empty()){
         cout<<pila_aux.top()<<endl;
         pila_aux.pop();             
        }
    }
    
    

    
}
void buscar_clientes(){ //Se buscará en la cola.
    Cliente nombre;

    queue<Cliente> aux = cola_cliente;
    
    if(cola_cliente.empty()){
        cout<<"No hay clientes en la cola. "<<endl;
    }
    else{
        cout<<"Ingrese el nombre del cliente: ";
        cin.ignore();
        getline(cin, nombre.nombre);
        while(!aux.empty()){
            if(nombre.nombre == aux.front().nombre){
                cout<<"El cliente se ha encontrado en la cola. "<<endl;
                break;

            }else{
               aux.pop();
            }
    
        }
         
    }
}

std::ostream& operator<<(std::ostream& o, const Cliente& d) { //Sobrecarga del operator << para poder mostrar la cola de clientes de la estructura Client
        // Usas o como si fuera cout
            o<<"Nombre del cliente: "<<d.nombre<<endl;
            o<<"Numero del cliente: "<<d.numero_cliente<<endl;
            o<<"Libro alquilado: "<<d.nombre_libro<<endl;
  return o;
}

void mostrar_clientes(queue<Cliente> q) { //Funcion que muestra la cola de clientes que han alquilado un libro
    queue<Cliente> clone = q;
     cout << "Los clientes que tienen un libro alquilado son: "<<endl;
    while (!clone.empty()) {
      cout<< clone.front() << endl;
        clone.pop();
    }
}
