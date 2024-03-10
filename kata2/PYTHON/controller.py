#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Controlador del programa con el objetivo de realizar una cartilla bancaria
donde se pueda realizar tanto ingresos como retiradas
@author: i02tomag
"""

import model as model

#Insertamos las funciones de los diferentes botones
def eventOpenFile(self):
    model.openFile(self)

def eventSave(self):
    model.save(self)   
    
def eventIngresoAdd(self):
    model.ingresoAdd(self)   

def eventRetiradaAdd(self):
    model.retiradaAdd(self)       

