#!/usr/bin/python
"""
Main del programa con el objetivo de realizar una cartilla bancaria
donde se pueda realizar tanto ingresos como retiradas
Author: i02matog
"""
import sys
from PyQt5 import QtWidgets
import view as vts

app = QtWidgets.QApplication(sys.argv)  # Crea una aplicacion
form = vts.calificaciones()  
sys.exit(app.exec_())  # Se inicia la aplicacion