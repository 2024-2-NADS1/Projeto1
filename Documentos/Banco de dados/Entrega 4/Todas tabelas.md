# 🖥️ Modelo Físico:
Modelagem física de todas as tabelas referentes aos sensores utilizados no projeto.

<br>

```sh
CREATE TABLE ESP_32 (
    tipo_de_alimentacao VARCHAR2(20),
    quantidade_de_conexoes NUMEBER(3),
    IPv4 NUMBER(12),
    modelo VARCHAR2(20),
    FK_REDE_IPv4 NUMBER(12)
);

CREATE TABLE MODULO_HX711_SENSOR_DE_PESO (
    porta NUMBER(5),
    voltagem VARCHAR2(20),
    sensores_conectados VARCHAR2(20),
    FK_ESP_32_modelo VARCHAR2(20),
    modelo VARCHAR2(20)
);

CREATE TABLE PONTE_H_MOTOR_2_MOTOR_1 (
    voltagem VARCHAR2(20),
    porta NUMBER(5),
    quantidade_de_conexoes NUMBER(2),
    FK_ESP_32_modelo VARCHAR2(20)
);

CREATE TABLE APLICATIVO (
    dados_recebidos VARCHAR2(20),
    protocolo_de_comunicacao VARCHAR2(20),
    nome VARCHAR2(20)
);

CREATE TABLE REDE (
    IPv4 NUMBER(12),
    gateway NUMBER(12),
    mascara_de_subrede NUMBER(12)
);

CREATE TABLE SENSOR_LASER (
    intensidade_do_feixe NUMBER(5),
    FK_ESP_32_modelo VARCHAR2(20)
);

CREATE TABLE FOTORRESISTOR (
    voltagem VARCHAR2(20),
    intensidade_do_feixe NUMBER(5),
    porta NUMBER(5),
    FK_ESP_32_modelo VARCHAR2(20)
);

CREATE TABLE RECEBE (
    FK_FOTORRESISTOR_porta NUMBER(5),
    FK_SENSOR_LASER_intensidade_do_feixe NUMEBER(5)
);
``
