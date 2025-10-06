/*
 * Random Forest generado con m2cgen
 * Exactitud en test: 0.97
 */

#include <string.h>
static void add_vectors(double *v1, double *v2, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] + v2[i];
}
static void mul_vector_number(double *v1, double num, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] * num;
}
void score(double * input, double * output) {
    double var0[3];
    double var1[3];
    double var2[3];
    double var3[3];
    double var4[3];
    double var5[3];
    double var6[3];
    double var7[3];
    double var8[3];
    double var9[3];
    double var10[3];
    if (input[11] <= 2.125) {
        if (input[0] <= 12.40999984741211) {
            if (input[1] <= 3.1649999022483826) {
                memcpy(var10, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var10, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            if (input[6] <= 1.3849999904632568) {
                memcpy(var10, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                memcpy(var10, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        }
    } else {
        if (input[6] <= 2.340000033378601) {
            if (input[9] <= 4.759999990463257) {
                memcpy(var10, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var10, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            if (input[4] <= 89.5) {
                memcpy(var10, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[8] <= 3.194999933242798) {
                    if (input[9] <= 3.4649999141693115) {
                        memcpy(var10, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var10, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    }
    double var11[3];
    if (input[6] <= 1.2899999618530273) {
        if (input[4] <= 128.0) {
            if (input[2] <= 2.2300000190734863) {
                if (input[2] <= 2.2050000429153442) {
                    memcpy(var11, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var11, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var11, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var11, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        if (input[6] <= 2.319999933242798) {
            if (input[9] <= 7.099999904632568) {
                memcpy(var11, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var11, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            if (input[9] <= 3.590000033378601) {
                memcpy(var11, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[12] <= 710.0) {
                    memcpy(var11, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var10, var11, 3, var9);
    double var12[3];
    if (input[6] <= 0.9550000131130219) {
        memcpy(var12, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    } else {
        if (input[6] <= 2.319999933242798) {
            if (input[11] <= 1.6200000047683716) {
                memcpy(var12, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                if (input[0] <= 13.010000228881836) {
                    memcpy(var12, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[5] <= 2.25) {
                        memcpy(var12, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[4] <= 89.5) {
                memcpy(var12, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[12] <= 680.0) {
                    memcpy(var12, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var9, var12, 3, var8);
    double var13[3];
    if (input[6] <= 1.35999995470047) {
        if (input[10] <= 0.8980000019073486) {
            memcpy(var13, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            if (input[9] <= 3.7850000858306885) {
                memcpy(var13, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var13, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        }
    } else {
        if (input[4] <= 90.5) {
            memcpy(var13, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[6] <= 2.350000023841858) {
                memcpy(var13, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[10] <= 0.8100000023841858) {
                    memcpy(var13, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[3] <= 27.5) {
                        memcpy(var13, (double[]){0.9791666666666666, 0.020833333333333332, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var8, var13, 3, var7);
    double var14[3];
    if (input[6] <= 1.399999976158142) {
        if (input[2] <= 2.2200000286102295) {
            memcpy(var14, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[7] <= 0.1550000011920929) {
                memcpy(var14, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[10] <= 1.004999965429306) {
                    memcpy(var14, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var14, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        if (input[9] <= 3.865000009536743) {
            if (input[6] <= 2.8350000381469727) {
                if (input[3] <= 15.75) {
                    memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var14, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            if (input[4] <= 89.5) {
                memcpy(var14, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[6] <= 1.8899999260902405) {
                    memcpy(var14, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var7, var14, 3, var6);
    double var15[3];
    if (input[0] <= 12.744999885559082) {
        if (input[6] <= 0.9399999976158142) {
            if (input[10] <= 0.9349999725818634) {
                memcpy(var15, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                memcpy(var15, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var15, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        if (input[5] <= 2.334999918937683) {
            if (input[4] <= 87.0) {
                if (input[11] <= 1.9050000309944153) {
                    memcpy(var15, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var15, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var15, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            if (input[7] <= 0.5099999904632568) {
                memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[9] <= 7.460000038146973) {
                    memcpy(var15, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var15, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var6, var15, 3, var5);
    double var16[3];
    if (input[6] <= 2.3149999380111694) {
        if (input[5] <= 1.7100000381469727) {
            if (input[4] <= 86.5) {
                memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[5] <= 1.175000011920929) {
                    memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var16, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[0] <= 12.349999904632568) {
                memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[6] <= 1.2899999618530273) {
                    if (input[10] <= 1.004999965429306) {
                        memcpy(var16, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        if (input[12] <= 670.0) {
            memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[4] <= 135.5) {
                memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        }
    }
    add_vectors(var5, var16, 3, var4);
    double var17[3];
    if (input[5] <= 2.3799999952316284) {
        if (input[1] <= 2.2200000286102295) {
            if (input[11] <= 1.5699999928474426) {
                memcpy(var17, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                memcpy(var17, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            if (input[6] <= 1.2700000405311584) {
                memcpy(var17, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                memcpy(var17, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        }
    } else {
        if (input[12] <= 670.0) {
            if (input[11] <= 2.350000023841858) {
                memcpy(var17, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                memcpy(var17, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            if (input[9] <= 3.4649999141693115) {
                memcpy(var17, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            }
        }
    }
    add_vectors(var4, var17, 3, var3);
    double var18[3];
    if (input[7] <= 0.39499999582767487) {
        if (input[12] <= 726.5) {
            if (input[8] <= 0.9849999845027924) {
                if (input[2] <= 2.119999945163727) {
                    memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var18, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            if (input[6] <= 2.350000023841858) {
                if (input[0] <= 12.885000228881836) {
                    memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                if (input[3] <= 25.5) {
                    memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        if (input[6] <= 1.175000011920929) {
            memcpy(var18, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            if (input[0] <= 13.510000228881836) {
                memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            }
        }
    }
    add_vectors(var3, var18, 3, var2);
    double var19[3];
    if (input[9] <= 3.7699999809265137) {
        if (input[2] <= 3.0) {
            memcpy(var19, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        if (input[11] <= 2.5049999952316284) {
            if (input[10] <= 0.945000022649765) {
                memcpy(var19, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                memcpy(var19, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            if (input[5] <= 3.409999966621399) {
                memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var19, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        }
    }
    add_vectors(var2, var19, 3, var1);
    mul_vector_number(var1, 0.1, 3, var0);
    memcpy(output, var0, 3 * sizeof(double));
}
