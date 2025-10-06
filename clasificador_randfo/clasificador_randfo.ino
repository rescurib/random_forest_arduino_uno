#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "random_forest_model.h"

// Definiciones
typedef enum {
  CLASS_0 = 0, 
  CLASS_1 = 1,
  CLASS_2 = 2
} PredictionClass_t;

typedef struct {
  double features[13]; // Conjunto de datos Wine (UC Irvine)
} InputFeatures_t;

// Variables globales
InputFeatures_t   inputData;
PredictionClass_t predictedClass;

// Función para leer y parsear datos del puerto serie
bool parseSerialInput(double* features);

void setup() {
  // Inicializar puerto serie
  Serial.begin(9600);
}

void loop() {
  // Variables para medición de tiempo de inferencia
  unsigned long startInfer, endInfer, inferenceTime;
  
  if(Serial.available() > 0) 
  {
    // Leer y parsear los datos de entrada
    if (parseSerialInput(inputData.features)) 
    {
      // Medir tiempo de inferencia en microsegundos
      startInfer = micros();

      // Realizar la predicción
      double output[3] = {0.0, 0.0, 0.0};
      score(inputData.features, output);

      endInfer = micros();
      inferenceTime = endInfer - startInfer;

      // elegir la clase con mayor probabilidad
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

// Función para leer y parsear datos del puerto serie
constexpr int NUM_FEATURES      = 13;
constexpr int SERIAL_TIMEOUT_MS = 5000;

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

    return (featureIndex == NUM_FEATURES);
}