#!/usr/bin/env python3
"""
Vista del programa con el objetivo de realizar una cartilla bancaria
donde se pueda introducir tanto ingresos como retiradas
@author: i02tomag
"""

import sys
import controller as controlador
from PyQt5.QtWidgets import QWidget, QApplication, QLabel, QLineEdit, QVBoxLayout, QHBoxLayout, QPushButton, QGridLayout, QTableWidget, QTableWidgetItem


class calificaciones(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.title = QLabel('Cartilla Bancaria')
        self.titleEdit = QLineEdit()
        self.openFileButton = QPushButton("Abrir")
        self.files = QLabel('Cartilla')

        # Creamos dos tablas, una para clasificaciones y otra para clasificaciones por encima del 5
        self.tableWidget = QTableWidget()
        self.tableWidget2 = QTableWidget()

        # Creacion de una tabla con 30 filas
        self.tableWidget.setRowCount(15)
        
        # Creacion de 3 columnas, indicando el nombre de cada una de ellas.
        self.tableWidget.setColumnCount(4)
        self.tableWidget.setItem(0, 0, QTableWidgetItem("Fecha"))
        self.tableWidget.setItem(0, 1, QTableWidgetItem("Movimiento"))
        self.tableWidget.setItem(0, 2, QTableWidgetItem("Total"))
        self.tableWidget.setItem(0, 3, QTableWidgetItem("Motivo"))
        
        # Obtenemos la cabecera de la tabla y la hacemos fija
        header = self.tableWidget.horizontalHeader()
        header.setSectionsMovable(True)

        # Introducimos los botones indicados
        self.openButton = QPushButton("Abrir")
        self.ingresoButton = QPushButton("Ingreso")
        self.retiradaButton = QPushButton("Retirada")        
        self.saveButton = QPushButton("Guardar")        

        mainVbox = QVBoxLayout()
        mainVbox.setSpacing(25)

        folderHbox = QHBoxLayout()
        folderHbox.addWidget(self.title)
        folderHbox.addWidget(self.titleEdit)
        folderHbox.addWidget(self.openButton)

        mainVbox.addLayout(folderHbox)
        grid = QGridLayout()
        grid.setSpacing(10)

        # Colocamos cada una de las tablas y botones.
        grid.addWidget(self.files, 0, 0)
        grid.addWidget(self.tableWidget, 1, 0, 1, 8)
        
        grid.addWidget(self.openFileButton, 2, 0)
        grid.addWidget(self.ingresoButton, 2, 1)
        grid.addWidget(self.retiradaButton, 2, 2)
        grid.addWidget(self.saveButton, 2, 3)
        
        mainVbox.addLayout(grid)
        self.setLayout(mainVbox)

        # Geometria y titulo de la ventana
        self.setGeometry(600, 750, 450, 500)
        self.setWindowTitle('Cartilla')
        self.show()

        # Conectamos los botones con ciertas señales
        self.openFileButton.clicked.connect(self.openFile)
        self.saveButton.clicked.connect(self.save)
        self.openButton.clicked.connect(self.openFile)
        

    # Guardar fichero
    def save(self):
        controlador.eventSave(self)
    
    # Abrir fichero
    def openFile(self):
        controlador.eventOpenFile(self)
    
    # Introduce un ingreso
    def ingresoAdd(self):
        controlador.eventIngresoAdd
        
    # Borrar una fila selecionada
    def retiradaAdd(self):
        controlador.eventRetiradaAdd
        
if __name__ == "__main__":
    app = QApplication(sys.argv)
    form = calificaciones()
    sys.exit(app.exec_())