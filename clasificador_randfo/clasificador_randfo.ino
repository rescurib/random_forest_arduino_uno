
// -----------------------------------------------------------------------------
//  Clasificador Random Forest para Arduino Uno
//  Este programa recibe datos por el puerto serie, realiza una inferencia usando
//  un modelo Random Forest (definido en random_forest_model.h/.c) y envía la clase
//  predicha junto con el tiempo de inferencia por el puerto serie.
// -----------------------------------------------------------------------------

#include <stdbool.h>   // Tipos booleanos estándar
#include <stdint.h>    // Tipos enteros estándar
#include <string.h>    // Funciones de manejo de cadenas
#include "random_forest_model.h" // Modelo Random Forest exportado


// -----------------------------------------------------------------------------
// Definiciones de tipos
// -----------------------------------------------------------------------------

// Enumeración para las clases posibles de predicción
typedef enum {
  CLASS_0 = 0, // Clase 0
  CLASS_1 = 1, // Clase 1
  CLASS_2 = 2  // Clase 2
} PredictionClass_t;

// Estructura para almacenar las características de entrada (13 features)
typedef struct {
  double features[13]; // Características del conjunto de datos Wine (UC Irvine)
} InputFeatures_t;


// -----------------------------------------------------------------------------
// Variables globales
// -----------------------------------------------------------------------------

InputFeatures_t   inputData;      // Estructura para almacenar los datos de entrada
PredictionClass_t predictedClass; // Clase predicha por el modelo

// Prototipo de función para leer y parsear datos del puerto serie
bool parseSerialInput(double* features);


// -----------------------------------------------------------------------------
// Configuración inicial de Arduino
// -----------------------------------------------------------------------------
void setup() {
  // Inicializar puerto serie a 9600 baudios
  Serial.begin(9600);
}


// -----------------------------------------------------------------------------
// Bucle principal de Arduino
// Espera datos por el puerto serie, realiza inferencia y envía resultados
// -----------------------------------------------------------------------------
void loop() {
  // Variables para medición de tiempo de inferencia
  unsigned long startInfer, endInfer, inferenceTime;
  
  // Verificar si hay datos disponibles en el puerto serie
  if(Serial.available() > 0) 
  {
    // Leer y parsear los datos de entrada
    if (parseSerialInput(inputData.features)) 
    {
      // Medir tiempo de inferencia en microsegundos
      startInfer = micros();

      // Realizar la predicción usando el modelo Random Forest
      double output[3] = {0.0, 0.0, 0.0}; // Vector de probabilidades para cada clase
      score(inputData.features, output);

      endInfer = micros();
      inferenceTime = endInfer - startInfer;

      // Elegir la clase con mayor probabilidad
      int maxIndex = 0;
      for (int i = 1; i < 3; i++) 
      {
        if (output[i] > output[maxIndex]) 
        {
          maxIndex = i;
        }
      }

      predictedClass = (PredictionClass_t)maxIndex;

      // Enviar el resultado por el puerto serie
      Serial.print("Clase más probable: ");
      Serial.println(predictedClass);
      Serial.print("Tiempo de inferencia (us): ");
      Serial.println(inferenceTime);
    } else 
    {
      Serial.println("Error de lectura de datos de entrada.");
    }
  }
}


// -----------------------------------------------------------------------------
// Funciones auxiliares para la lectura y parseo de datos del puerto serie
// -----------------------------------------------------------------------------

constexpr int NUM_FEATURES      = 13;   // Número de características esperadas
constexpr int SERIAL_TIMEOUT_MS = 5000; // Timeout para la lectura serial (ms)

// Espera a que haya datos disponibles en el puerto serie o hasta que expire el timeout
// Devuelve true si hay datos, false si se excede el tiempo de espera
bool waitForSerialData(unsigned long startTime) {
  while (Serial.available() == 0) 
  {
    if (millis() - startTime > SERIAL_TIMEOUT_MS) 
    {
      return false;
    }
  }
  return true;
}

// Lee y parsea una línea de entrada serial con el formato:
// $<f1>,<f2>,...,<f13>\n
// Donde $ es el símbolo de inicio y cada <fi> es un valor double
// Devuelve true si se leyeron correctamente los 13 valores
bool parseSerialInput(double* features) {
  int featureIndex = 0;
  String buffer = "";
  unsigned long startTime = millis();

  // Esperar símbolo de inicio '$'
  while (true) {
    if (!waitForSerialData(startTime)) 
    {
      Serial.println("Tiempo de espera de símbolo de inicio exedido.");
      return false;
    }
    char incoming = Serial.read();
    if (incoming == '$') break;
  }

  // Reiniciar timeout para la lectura de datos
  startTime = millis();

  // Leer y parsear los 13 valores separados por comas
  while (featureIndex < NUM_FEATURES) 
  {
    if (!waitForSerialData(startTime)) 
    {
      Serial.println("Timeout de espera de datos exedido.");
      return false;
    }

    char incoming = Serial.read();
    if (incoming == ',') 
    {
      // Si llegamos a una coma, convertimos el buffer a double
      features[featureIndex++] = buffer.toDouble();
      buffer = "";
    } 
    else if (incoming == '\n' || incoming == '\r') // Último elemento
    {
      if (buffer.length() > 0 && featureIndex < NUM_FEATURES)
      {
        features[featureIndex++] = buffer.toDouble();
        buffer = ""; // Limpiar buffer para la próxima lectura
      }
      if (featureIndex == NUM_FEATURES) break;
    } 
    else 
    {
      buffer += incoming;
    }
  }

  // Retorna true si se leyeron exactamente NUM_FEATURES valores
  return (featureIndex == NUM_FEATURES);
}