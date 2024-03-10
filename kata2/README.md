	--KATA: CARTILLA BANCARIA -> PYTHON--

Práctica realizada por:
    - Gonzalo Márquez de Torres
    
La realización de la kata consiste en realizar una plantilla de una cartilla bancaria siguiendo 
el modelo anterior, donde podamos detallar los movimientos de entrada y salida mediante el 
uso de Python. Para la realización de este, hemos seguido una estructura Modelo-Vista-Controlador:

	- controller.py: controlador del MVC
	- main.py: programa main para acoplar la estructura MVC
	- model.py: modelo del MVC
	- view.py: vistas del MVC

En cuanto a cada movimiento, se definiran ciertos aspectos, como:
	- fecha: en la que se realiza el movimiento.
	- valor: del movimiento, ya sea de entrada o de la salida.
	- total: valor total de la cuenta.
	- motivo: del movimiento de dinero.

Esta kata se puede realizar de diferentes formas y de diferentes formas:
	- Mocks: mediante mocks para simular el comportamiento de objetos.
	- Refactoring: mejora la estructura.
	- TDD: mediante el desarrollo de pruebas, comprobando su funcionamiento.