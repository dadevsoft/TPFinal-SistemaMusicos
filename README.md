# TPFinal-SistemaMusicos en c++
Este proyecto es una aplicación de consola desarrollada en C++ que permite la gestión de músicos a través de operaciones de Altas, Bajas, Modificaciones y Listados (ABML) con archivos.  
Año: **2023**
Funcionalidades principales:
El sistema permite:
- Agregar músicos al archivo
- Buscar y mostrar músico por DNI
- Listar todos los músicos
- Modificar fecha de inscripción
- Baja lógica de músico
- Persistencia en archivo binario (`musicos.dat`)

-
Arquitectura del proyecto:
- Manejo de archivos binarios
- Menús y submenús organizados por módulos
- Validaciones básicas de entrada
- Baja lógica mediante bandera de estado
---
  Notas
- El sistema utiliza **baja lógica**, por lo que los registros no se eliminan físicamente.
- Está pensado como práctica de manejo de archivos binarios en C++.
