#include <iostream>
#include <fstream>
using namespace std;

                                                    //personas

struct persona{

    int codigo;
    string nombre;
    int edad;
    string pais;

    persona *next;
    persona *inferior;

}; 

struct cancion{

    int ID;
    string nombre;
    int ano;
    string artista;
    string genero;

    cancion *next;
    cancion *inferior;

}; 

void insertar_personas(persona*& p, int codigo, string nombre, int edad, string pais) {
    persona* nueva_persona = new persona;
    nueva_persona->codigo = codigo;
    nueva_persona->nombre = nombre;
    nueva_persona->edad = edad;
    nueva_persona->pais = pais;
    nueva_persona->next = nullptr;
    nueva_persona->inferior = nullptr;

    if (p == nullptr) {
        p = nueva_persona;
    } else {
        persona* ultimo = p;
        while (ultimo->next != nullptr) {
            ultimo = ultimo->next;
        }
        ultimo->next = nueva_persona;
    }
} 

void buscar_persona_por_codigo(persona* p, int codigo) {
    while (p != nullptr) {
        if (p->codigo == codigo) {
            cout << "codigo: " << p->codigo << endl;
            cout << "nombre: " << p->nombre << endl;
            cout << "edad: " << p->edad << endl;
            cout << "pais: " << p->pais << endl;
            return; 
        }
        p = p->next;
    }
    cout << "persona de cedula " << codigo << " no encontrada" << endl;
}

void eliminar_persona_por_codigo(persona*& p, int codigo) {
    if (p == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    if (p->codigo == codigo) {
        persona* e = p;
        p = p->next;
        delete e;
        cout << "usuario eliminado correctamente" << endl;
        return;
    }

    persona* anterior = p;
    persona* actual = p->next;

    while (actual != nullptr) {
        if (actual->codigo == codigo) {
            anterior->next = actual->next;
            delete actual;
            cout << "usuario eliminado correctamente" << endl;
            return;
        }
        anterior = actual;
        actual = actual->next;
    }

    cout << "usuario de cedula " << codigo << " no encontrado" << endl;
}


void mostrar_todos_los_usuarios(persona* p) {
    cout << "usuarios registrados\n";
    while (p != nullptr) {
        cout << "codigo: " << p->codigo << endl;
        cout << "nombre: " << p->nombre << endl;
        cout << "edad: " << p->edad << endl;
        cout << "pais: " << p->pais << endl;
        cout << "------------------------\n";
        p = p->next;
    }
}


                                                //canciones



void insertar_canciones(cancion*& c, int ID, string nombre, int ano, string artista, string genero) {
    cancion* nueva_cancion = new cancion;
    nueva_cancion->ID = ID;
    nueva_cancion->nombre = nombre;
    nueva_cancion->ano = ano;
    nueva_cancion->artista = artista;
    nueva_cancion->genero = genero;
    nueva_cancion->next = NULL;
    nueva_cancion->inferior = NULL;

    if (c == NULL) {
        c = nueva_cancion;
    } else {
        cancion* ultimo = c;
        while (ultimo->next != NULL) {
            ultimo = ultimo->next;
        }
        ultimo->next = nueva_cancion;
    }
} 

void buscar_cancion_por_ID(cancion* c, int ID) {
    while (c != NULL) {
        if (c->ID == ID) {
            cout << "ID: " << c->ID << endl;
            cout << "nombre: " << c->nombre << endl;
            cout << "artista: " << c->artista << endl;
            cout << "genero: " << c->genero << endl;
            cout << "ano: " << c->ano << endl;
            return; 
        }
        c = c->next;
    }
    cout << "cancion de ID " << ID << " no encontrada" << endl;
}

void eliminar_cancion_por_ID(cancion*& c, int ID) {
    if (c == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    if (c->ID == ID) {
        cancion* e = c;
        c = c->next;
        delete e;
        cout << "usuario eliminado correctamente" << endl;
        return;
    }

    cancion* anterior = c;
    cancion* actual = c->next;

    while (actual != NULL) {
        if (actual->ID == ID) {
            anterior->next = actual->next;
            delete actual;
            cout << "usuario eliminado correctamente" << endl;
            return;
        }
        anterior = actual;
        actual = actual->next;
    }

    cout << "usuario de cedula " << ID << " no encontrado" << endl;
}


void mostrar_todas_las_canciones(cancion* c) {
    cout << "canciones registradas\n";
    while (c != NULL) {
        cout << "ID: " << c->ID << endl;
        cout << "nombre: " << c->nombre << endl;
        cout << "artista: " << c->artista << endl;
        cout << "genero: " << c->genero << endl;
        cout << "ano: " << c->ano << endl;
        cout << "------------------------\n";
        c = c->next;
    }
}

void escribir_en_archivo(cancion* c) {
    ofstream archivo("C:/Users/user/Desktop/canciones.txt", ios::out); 

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    while (c != nullptr) {
        archivo << "ID: " << c->ID << endl;
        archivo << "nombre: " << c->nombre << endl;
        archivo << "ano: " << c->ano << endl;
        archivo << "artista: " << c->artista << endl;
        archivo << "genero: " << c->genero << endl;
        archivo << "------------------------" << endl;

        c = c->next; 
    }

    archivo.close();
    cout << "Archivo 'canciones.txt' actualizado en el escritorio" << endl;
}



int main() {
    persona* p = NULL;
    cancion* c = NULL; 
    char continuar = 's';

    do {
        int resp;
        cout << "MENU\n\n";
        cout << "1) ver usuarios\n";
        cout << "2) Insertar usuario\n";
        cout << "3) buscar usuario\n";
        cout << "4) eliminar usuario\n\n\n";
        cout << "-------------------------\n\n\n"; 
        cout << "\t\tapartado de canciones \n\n\n"; 
        cout << "5) ver canciones\n"; 
        cout << "6) insertar canciones\n";
        cout << "7) buscar canciones\n";
        cout << "8) eliminar canciones\n";
        cout << "0) Salir\n\n";
        cout << "\tmarca una opcion: ";
        cin >> resp;

        switch (resp) {
            case 0: {
                cout << "programa finalizado\n";
                continuar = 'n';
            } break;

            case 1: {
                mostrar_todos_los_usuarios(p);
                
            } break;

            case 2: {
                int codigo;
                string nombre, pais;
                int edad;

                cout << "ingresa la cedula de identidad: ";
                cin >> codigo;
                cout << "ingrese el nombre: ";
                cin >> nombre;
                getline(cin,nombre);
                cout << "ingresa la edad: ";
                cin >> edad;
                cout << "ingresa el pais :";
                cin >> pais;
                getline(cin,pais);

                insertar_personas(p, codigo, nombre, edad, pais);
                cout << "se ha registrado exitosamente!\n";

            } break;

            case 3:{

                int codigo_buscar;
                cout << "ingresa la cedula de la persona a buscar: ";
                cin >> codigo_buscar;
                buscar_persona_por_codigo(p, codigo_buscar);

            }break;

            case 4:{
                int cedula;
                cout << "ingresa la cedula de la persona que quieres eliminar : ";
                cin >> cedula;
                eliminar_persona_por_codigo(p,cedula);

            }break;

            case 5:{
                mostrar_todas_las_canciones(c);
            }break;

            case 6:{
                int ID, ano;
                string nombre, genero, artista;

                cout << "ingresa el ID: ";
                cin >> ID;
                cout << "ingrese el nombre: ";
                cin >> nombre;
                getline(cin,nombre);
                cout << "ingresa ano: ";
                cin >> ano;
                cout << "ingresa el artista :";
                cin >> artista;
                getline(cin,artista);
                cout << "ingresa el genero :";
                cin >> genero;
                getline(cin,genero);

                insertar_canciones(c, ID, nombre, ano, artista, genero);
                escribir_en_archivo(c);
                cout << "se ha registrado exitosamente!\n";
            }break;

            case 7:{
                int ID;
                cout << "ingresa el ID de la cancion a buscar: ";
                cin >> ID;
                buscar_cancion_por_ID(c, ID);
            }break;

            case 8:{
                int ID;
                cout << "ID de la cancion que deseas eliminar : ";
                cin >> ID;
                eliminar_cancion_por_ID(c,ID);
                escribir_en_archivo(c);
            }break;

        }

    } while (continuar == 's' || continuar == 'S');

    return 0;
}       