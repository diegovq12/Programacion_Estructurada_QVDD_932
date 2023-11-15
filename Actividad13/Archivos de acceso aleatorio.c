/*Archivos de acceso aleatorio
Los archivos de acceso aleatorio son más versátiles, permiten acceder a cualquier parte del fichero en cualquier momento, como si fueran arrays en memoria. Las operaciones de lectura y/o escritura pueden hacerse en cualquier punto del archivo.

En general se suelen establecer ciertas normas para la creación, aunque no todas son obligatorias:

Abrir el archivo en un modo que te permita leer y escribir. Esto no es imprescindible, es posible usar archivos de acceso aleatorio sólo de lectura o de escritura.
Abrirlo en modo binario, ya que algunos o todos los campos de la estructura pueden no ser caracteres.
Usar funciones como fread y fwrite, que permiten leer y escribir registros de longitud constante desde y hacia un fichero.
Usar la función fseek para situar el puntero de lectura/escritura en el lugar apropiado de tu archivo.
Por ejemplo, supongamos que nuestros registros tienen la siguiente estructura:

struct stRegistro {
   char Nombre[34];
   int dato;
   int matriz[23];
} reg;
Teniendo en cuenta que los registros empiezan a contarse desde el cero, para hacer una lectura del registro número 6 usaremos:

fseek(fichero, 5*sizeof(stRegistro), SEEK_SET);
fread(&reg, sizeof(stRegistro), 1, fichero);
Análogamente, para hacer una operación de escritura, usaremos:

fseek(fichero, 5*sizeof(stRegistro), SEEK_SET);
fwrite(&reg, sizeof(stRegistro), 1, fichero);
Muy importante: después de cada operación de lectura o escritura, el cursor del fichero se actualiza automáticamente a la siguiente posición, así que es buena idea hacer siempre un fseek antes de un fread o un fwrite.

En el caso de streams, la forma de trabajar es análoga:

fichero.seekg(5*sizeof(stRegistro), ios::beg);
fichero.read(&reg, sizeof(stRegistro));
Y para hacer una operación de escritura, usaremos:

fichero.seekp(5*sizeof(stRegistro), ios::beg);
fichero.write(&reg, sizeof(stRegistro));
Calcular la longitud de un fichero
Para calcular el tamaño de un fichero, ya sea en bytes o en registros se suele usar el siguiente procedimiento:

long nRegistros;
long nBytes;
fseek(fichero, 0, SEEK_END); // Colocar el cursor al final del fichero
nBytes = ftell(fichero); // Tamaño en bytes
nRegistros = ftell(fich)/sizeof(stRegistro); // Tamaño en registros
En el caso de streams:

long nRegistros;
long nBytes;
fichero.seekg(0, ios::end); // Colocar el cursor al final del fichero
nBytes = fichero.tellg(); // Tamaño en bytes
nRegistros = fichero.tellg()/sizeof(stRegistro); // Tamaño en registros
Borrar registros
Borrar registros puede ser complicado, ya que no hay ninguna función de biblioteca estándar que lo haga.

Es su lugar se suele usar uno de estos dos métodos:

Marcar el registro como borrado o no válido, para ello hay que añadir un campo extra en la estructura del registro:

struct stRegistro {
   char Valido;  // Campo que indica si el registro es válido
   char Nombre[34];
   int dato;
   int matriz[23];
};
Si el campo Valido tiene un valor prefijado, por ejemplo 'S' o ' ', el registro es válido. Si tiene un valor prefijado, por ejemplo 'N' o '*', el registro será inválido o se considerará borrado.

De este modo, para borrar un registro sólo tienes que cambiar el valor de ese campo.

Pero hay que tener en cuenta que será el programa el encargado de tratar los registros del modo adecuado dependiendo del valor del campo Valido, el hecho de marcar un registro no lo borra físicamente.

Si se quiere elaborar más, se puede mantener un fichero auxiliar con la lista de los registros borrados. Esto tiene un doble propósito:

Que se pueda diseñar una función para sustituir a fseek() de modo que se tengan en cuenta los registros marcados.
Que al insertar nuevos registros, se puedan sobrescribir los anteriormente marcados como borrados, si existe alguno.
Hacer una copia del fichero en otro fichero, pero sin copiar el registro que se quiere borrar. Este sistema es más tedioso y lento, y requiere cerrar el fichero y borrarlo o renombrarlo, antes de poder usar de nuevo la versión con el registro eliminado.
Lo normal es hacer una combinación de ambos, durante la ejecución normal del programa se borran registros con el método de marcarlos, y cuando se cierra la aplicación, o se detecta que el porcentaje de registros borrados es alto o el usuario así lo decide, se "empaqueta" el fichero usando el segundo método.

Ejemplo
A continuación se incluye un ejemplo de un programa que trabaja con registros de acceso aleatorio, es un poco largo, pero bastante completo:
*/
// alea.c: Ejemplo de ficheros de acceso aleatorio.
#include <stdio.h>
#include <stdlib.h>

struct stRegistro {
   char valido;  // Campo que indica si el registro es válido S->Válido, N->Inválido
   char nombre[34];
   int dato[4];
};

int Menu();
void Leer(struct stRegistro *reg);
void Mostrar(struct stRegistro *reg);
void Listar(long n, struct stRegistro *reg);
long LeeNumero();
void Empaquetar(FILE **fa);

int main()
{
   struct stRegistro reg;
   FILE *fa;
   int opcion;
   long numero;
   fa = fopen("alea.dat", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("alea.dat", "w+b");  // si el fichero no existe, lo crea.
   do {
      opcion = Menu();
      switch(opcion) {
         case '1': // Añadir registro
            Leer(&reg);
            // Insertar al final:
            fseek(fa, 0, SEEK_END);
            fwrite(&reg, sizeof(struct stRegistro), 1, fa);
            break;
         case '2': // Mostrar registro
            system("cls");
            printf("Mostrar registro: ");
            numero = LeeNumero();
            fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
            fread(&reg, sizeof(struct stRegistro), 1, fa);
            Mostrar(&reg);
            break;
         case '3': // Eliminar registro
            system("cls");
            printf("Eliminar registro: ");
            numero = LeeNumero();
            fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
            fread(&reg, sizeof(struct stRegistro), 1, fa);
            reg.valido = 'N';
            fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
            fwrite(&reg, sizeof(struct stRegistro), 1, fa);
            break;
         case '4': // Mostrar todo
            rewind(fa);
            numero = 0;
            system("cls");
            printf("Nombre                             Datos\n");
            while(fread(&reg, sizeof(struct stRegistro), 1, fa))
               Listar(numero++, &reg);
            system("PAUSE");
            break;
         case '5': // Eliminar marcados
            Empaquetar(&fa);
            break;
      }
   } while(opcion != '0');
   fclose(fa);
   return 0;
}

// Muestra un menú con las opciones disponibles y captura una opción del usuario
int Menu()
{
   char resp[20];
   do {
      system("cls");
      printf("MENU PRINCIPAL\n");
      printf("--------------\n\n");
      printf("1- Insertar registro\n");
      printf("2- Mostrar registro\n");
      printf("3- Eliminar registro\n");
      printf("4- Mostrar todo\n");
      printf("5- Eliminar registros marcados\n");
      printf("0- Salir\n");
      fgets(resp, 20, stdin);
   } while(resp[0] < '0' && resp[0] > '5');
   return resp[0];
}

// Permite que el usuario introduzca un registro por pantalla
void Leer(struct stRegistro *reg)
{
   int i;
   char numero[6];
   system("cls");
   printf("Leer registro:\n\n");
   reg->valido = 'S';
   printf("Nombre: ");
   fgets(reg->nombre, 34, stdin);
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(reg->nombre)-1; i && reg->nombre[i] < ' '; i--)
      reg->nombre[i] = 0;
   for(i = 0; i < 4; i++) {
      printf("Dato[%1d]: ", i);
      fgets(numero, 6, stdin);
      reg->dato[i] = atoi(numero);
   }
}

// Muestra un registro en pantalla, si no está marcado como borrado
void Mostrar(struct stRegistro *reg)
{
   int i;
   system("cls");
   if(reg->valido == 'S') {
      printf("Nombre: %s\n", reg->nombre);
      for(i = 0; i < 4; i++) printf("Dato[%1d]: %d\n", i, reg->dato[i]);
   }
   system("PAUSE");
}

// Muestra un registro por pantalla en forma de listado,
// si no está marcado como borrado
void Listar(long n, struct stRegistro *reg)
{
   int i;
   if(reg->valido == 'S') {
      printf("[%6ld] %-34s", n, reg->nombre);
      for(i = 0; i < 4; i++) printf(", %4d", reg->dato[i]);
      printf("\n");
   }
}

// Lee un número suministrado por el usuario
long LeeNumero()
{
   char numero[6];
   fgets(numero, 6, stdin);
   return atoi(numero);
}

// Elimina los registros marcados como borrados
void Empaquetar(FILE **fa)
{
   FILE *ftemp;
   struct stRegistro reg;

   ftemp = fopen("alea.tmp", "wb");
   rewind(*fa);
   while(fread(&reg, sizeof(struct stRegistro), 1, *fa))
      if(reg.valido == 'S')
         fwrite(&reg, sizeof(struct stRegistro), 1, ftemp);
   fclose(ftemp);
   fclose(*fa);
   remove("alea.bak");
   rename("alea.dat", "alea.bak");
   rename("alea.tmp", "alea.dat");
   *fa = fopen("alea.dat", "r+b");
}
