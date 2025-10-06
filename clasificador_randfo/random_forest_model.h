/**
 * @file random_forest_model.h
 * @brief Header para el modelo Random Forest generado con m2cgen para Arduino Uno.
 * @author Auto-generado por GitHub Copilot
 *
 * Proporciona las funciones necesarias para utilizar el modelo Random Forest en C.
 */

#ifndef RANDOM_FOREST_MODEL_H
#define RANDOM_FOREST_MODEL_H

#include <stddef.h>

/**
 * @brief Realiza la inferencia del modelo Random Forest.
 * @param input Vector de entrada con las características. Tamaño: 13.
 * @param output Vector de salida con las probabilidades para cada clase. Tamaño: 3.
 */
// Ensure C linkage for C++
#ifdef __cplusplus
extern "C" {
#endif
void score(double *input, double *output);
#ifdef __cplusplus
}
#endif

#endif // RANDOM_FOREST_MODEL_H
