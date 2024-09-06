#!/bin/bash
# Royden Contreras Vallejos
# C12260
# Laboratorio 1

# Primeramente asignare variables que contenga los tados que necesitamos tales como la fecha y el nombre del mes que tenemos que poner como variable. 


dia="$(date +%A)"
fecha="$(date +%d)"
mes="$(date +%B)"
a="$(date +%G)"
mivariable=December 


# Temiendo en cuenta que quedan pocos meses para finalizar, ya que no se como ver cuantos dias quedan hasta la proxima fecha vamos a hacer lo siguiente 

August=8
September=9
Octover=10
November=11
December=12

# Al asignarles numeros a los meses puedo hacer una resta para ver cuantos meses quedan de la siguiente manera

meses=$(($mivariable-$mes))

# Despues de investigar un poco encontre un video donde mostraban como ver cual es el ultimo dia del mes, de esta manera despues de hacer una resta se pueden ver los dias restantes, entonces voy a usar el comando para ayudarme a resolver el problema


ultimo=$(($(date -d "$(date +%Y-%m-01) + 1 month -d" +%d) - $(date +%d)))




# Ya que obtube todos los datos puedo generar la respuesta 

echo "Hoy es $dia, $fecha de $mes, del ano $a. Faltan $meses meses y $ultimo dias para $mivariable"























