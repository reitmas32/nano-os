/*
* kc.c
*/
void kmain(void) {
	const char *str = "Bienvenidos a Nano OS";
	char *vidptr = (char*)0xb8000; 	//La memoria de video inicia aqui.
	unsigned int i = 0;
	unsigned int j = 0;

	/* Este bucle limpia la pantalla
	* Hay 25 lineas de 80 columnas; cada elemento ocupa 2 bytes*/
	while(j < 80 * 25 * 2) {
		/* Caracter espacio */
		vidptr[j] = ' ';
		/* byte de atributo - gris claro sobre pantalla negra */
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}

	j = 0;

	/* Este bucle escribe nuestro texto en la memoria de video */
	while(str[j] != '\0') {
		/* caracter ascii */
		vidptr[i] = str[j];
		/* byte de atributo - escribe caracter gris claro sobre fondo negro */
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}
