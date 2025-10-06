"""
Programa para enviar una muestra aleatoria del dataset Wine al Arduino y mostrar la respuesta recibida.
"""
import serial
import time
import numpy as np
from sklearn.datasets import load_wine
import random

# Configuración del puerto serie (ajusta el nombre según tu sistema)
SERIAL_PORT = 'COM11'  # Cambia esto por el puerto correcto
BAUD_RATE = 9600
TIMEOUT = 5

# Cargar el dataset Wine
data = load_wine()
X = data.data

# Seleccionar una muestra aleatoria
idx = random.randint(0, X.shape[0] - 1)
sample = X[idx]
print(f"Muestra seleccionada: índice {idx}, Clase: {data.target[idx]} ")

# Formatear los datos para enviar por serial (13 valores separados por coma)
sample_str = ','.join([f"{x:.5f}" for x in sample])

# Abrir el puerto serie
try:
    with serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=TIMEOUT) as ser:
        time.sleep(5)  # Esperar a que el Arduino reinicie
        # Añadir símbolo de inicio '$' antes de los datos
        datos_con_inicio = f"${sample_str}\n"
        print(f"Enviando datos al Arduino: {datos_con_inicio.strip()}")
        ser.write(datos_con_inicio.encode())
        
        # Leer la respuesta del Arduino
        start_time = time.time()
        arduino_class = None
        while True:
            if ser.in_waiting > 0:
                response = ser.readline().decode(errors='ignore').strip()
                print(f"Respuesta del Arduino: {response}")
                if "Clase más probable" in response:
                    # Extraer la clase predicha por el Arduino
                    try:
                        arduino_class = int(response.split(":")[-1].strip())
                    except Exception:
                        arduino_class = None
                    break
                elif "Error" in response:
                    break
            if time.time() - start_time > TIMEOUT:
                print("Timeout esperando respuesta del Arduino.")
                break

        # Verificar si la clasificación es correcta
        if arduino_class is not None:
            true_class = int(data.target[idx])
            if arduino_class == true_class:
                print("¡Clasificación CORRECTA!")
            else:
                print("Clasificación INCORRECTA.")
except serial.SerialException as e:
    print(f"Error abriendo el puerto serie: {e}")
