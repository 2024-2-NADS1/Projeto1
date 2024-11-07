# 🤓 Modelo Conceitual:

- Modelo conceitual sem atributos.

<p align="center">
<img src="https://github.com/user-attachments/assets/08598f42-ebd7-406a-8114-d83c1ec3762a" width="700px" border="0" >
  <p align="center">
  <a> Desenvolvido por Vinicius Cardoso de Lima <a>
</p>
<br><br>

- Modelo conceitual com atributos e identificadores.

<p align="center">
<img src="https://github.com/user-attachments/assets/7cad259c-59cb-4588-9f98-b3375710c7ad" width="700px" border="0" >
  <p align="center">
  <a> Desenvolvido por Vinicius Cardoso de Lima <a>
</p>
<br><br>

# 🤖 Modelo Lógico:
- Modelo lógico.
<p align="center">
<img src="https://github.com/user-attachments/assets/dce22fef-436e-4d26-8c09-f6e27c526162" width="700px" border="0" >
  <p align="center">
  <a> Desenvolvido por Vinicius Cardoso de Lima <a>
</p>

# 🖥️ Modelo Físico:

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

CREATE TABLE PONTE_H_MOTOR_2_MOTOR_1 (
    voltagem VARCHAR2(20),
    porta NUMBER(3),
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
```
