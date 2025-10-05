@echo off
REM Crear entorno virtual
py -m venv .venv

REM Activar entorno virtual
call .venv\Scripts\activate.bat

REM Actualizar pip
py -m pip install --upgrade pip

REM Instalar dependencias
pip install scikit-learn joblib numpy m2cgen