"""
@file generador_de_clasificador.py
@brief Entrena un modelo Random Forest con el dataset Wine y lo exporta como código C para usar en Arduino Uno.
@author Rodolfo Escobar
@date 2024-06-10
"""

# Importación de librerías
from sklearn.datasets import load_wine
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.feature_selection import SelectFromModel
import joblib
import numpy as np
import m2cgen as m2c


def main():
    """
    @brief Función principal para entrenar y guardar el modelo Random Forest.
    """
    # Cargar el dataset Wine
    data = load_wine()
    X = data.data
    y = data.target

    # Dividir en conjunto de entrenamiento y prueba
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.2, random_state=42
    )

    # Crear y entrenar el modelo Random Forest
    clf = RandomForestClassifier(n_estimators=10, max_depth=5, random_state=42)
    clf.fit(X_train, y_train)

    # Evaluar el modelo
    y_pred = clf.predict(X_test)
    acc = accuracy_score(y_test, y_pred)
    print(f"Exactitud del modelo: {acc:.2f}")
    print("Número de árboles entrenados:", len(clf.estimators_))

    importances = clf.feature_importances_
    indices = np.argsort(importances)[::-1]

    print("Ranking de características:")
    for i in indices:
      print(f"{i}: {importances[i]:.4f}")

    # Guardar el modelo entrenado en un archivo (por si se necesita reutilizar)
    joblib.dump(clf, "random_forest_model.pkl")

    # Generar código C a partir del modelo
    c_code = m2c.export_to_c(clf)

    # Guardar el código generado en un archivo .c
    with open("random_forest_model.c", "w") as f:
        f.write("/*\n")
        f.write(" * Random Forest generado con m2cgen\n")
        f.write(f" * Exactitud en test: {acc:.2f}\n")
        f.write(" */\n\n")
        f.write(c_code)

    print("Código C generado en random_forest_model.c")


if __name__ == "__main__":
    main()
