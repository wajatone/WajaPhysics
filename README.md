# WajaPhysics

**Resolvedor de ejercicios de cinemática desarrollado en C.**

WajaPhysics es un proyecto personal cuyo objetivo es facilitar la resolución de ejercicios de física relacionados con el movimiento, aplicando las fórmulas matemáticas correspondientes mediante un programa escrito en C.

El proyecto está desarrollado desde cero como una forma de aprender programación, practicar C y comprender cómo trasladar problemas físicos a código.

## Características

### MRU — Movimiento Rectilíneo Uniforme
- Cálculo de posición final.
- Cálculo de velocidad.
- Cálculo de tiempo.

### MRUA — Movimiento Rectilíneo Uniformemente Acelerado
- Cálculo de posición final.
- Cálculo de velocidad final.
- Cálculo de velocidad inicial.
- Cálculo de aceleración.
- Cálculo del tiempo, incluyendo los casos con dos posibles soluciones.

### Otras características
- Selección del tipo de movimiento y de la incógnita.
- Comprobaciones para evitar determinados cálculos no válidos.
- Resultados y mensajes de error diferenciados mediante colores en la terminal.

## Tecnologías utilizadas

- **Lenguaje:** C
- **Compilador:** GCC
- **Entorno de desarrollo:** Visual Studio Code
- **Bibliotecas:** `stdio.h`, `math.h` y otras bibliotecas estándar de C.

## Cómo ejecutar el programa

Es necesario tener GCC instalado.

1. Clona este repositorio o descarga sus archivos.
2. Abre una terminal en la carpeta del proyecto.
3. Compila el programa:

```bash
gcc resolvedor.c -o WajaPhysics
```

4. Ejecuta el programa:

En Windows:

```powershell
.\WajaPhysics.exe
```

En Linux:

```bash
./WajaPhysics
```

## Limitaciones conocidas

- El programa necesita que el usuario introduzca manualmente los datos del ejercicio.
- No interpreta enunciados escritos en lenguaje natural.
- Los cálculos están limitados a los tipos de movimiento y operaciones implementados.
- Algunas situaciones físicas pueden requerir interpretar las soluciones antes de decidir cuál corresponde al ejercicio.

## Próximamente

- Terminar los ejercicios mixtos de MRU y MRUA.
- Mejorar las comprobaciones y el tratamiento de errores.
- Añadir nuevos tipos de movimiento, como el tiro parabólico.

## Sobre el proyecto

WajaPhysics es un proyecto personal de aprendizaje. Está construido poco a poco, experimentando con C y aplicando los conocimientos adquiridos a problemas reales de física.

**Hecho por Wajatone.**
