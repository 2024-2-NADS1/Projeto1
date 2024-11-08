# 🖥️ Modelo Físico:

Modelagem física de duas tabelas. As tabelas a seguir são referentes ao ESP32 e o módulo conversor para o sensor de peso, contendo os atributos e tipos de informação contidas no atributo.

<br>

```sh
CREATE TABLE ESP_32 (
    tipo_de_alimentacao VARCHAR2(20),
    quantidade_de_conexoes NUMBER(10),
    IP NUMBER(12),
    modelo VARCHAR2(20),
    FK_REDE_IPv4 NUMBER(12)
);

CREATE TABLE MODULO_HX711_SENSOR_DE_PESO (
    porta NUMBER(3),
    voltagem VARCHARCHAR2(20),
    sensores_conectados VARCHAR2(20),
    FK_ESP_32_modelo VARCHAR2(20),
    modelo VARCHAR2(20)
);
``
