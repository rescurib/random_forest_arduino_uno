#!/bin/bash

# Crear entorno virtual
python3 -m venv .venv

# Activar entorno virtual
source .venv/bin/activate

# Actualizar pip
python3 -m pip install --upgrade pip

# Instalar dependencias
pip install scikit-learn joblib numpy m2cgen pyserial
