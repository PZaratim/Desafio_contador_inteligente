# Controle de Padrões de LEDs com ESP32
#3 Descrição

Projeto embarcado com ESP32 utilizando FreeRTOS para controle de dois LEDs a partir de um contador cíclico. Os padrões de acionamento são definidos com base em condições lógicas envolvendo múltiplos de 3 e 5.

## Funcionamento

O sistema utiliza um contador de 0 a 15 em loop contínuo. A cada ciclo, um padrão de LEDs é executado conforme o valor atual.

## Regras
Múltiplos de 3: ambos os LEDs piscam 3 vezes (100 ms)
Múltiplos de 5 (não múltiplos de 3): LEDs alternam (200 ms)
Demais valores: LED 1 pisca uma vez (400 ms)

## Lógica
Contador inicia em 0
Incrementa de 1 em 1
Ao chegar em 16, retorna para 0
Execução contínua

## Tecnologias
ESP32
FreeRTOS
Linguagem C
GPIO

## Objetivo
Praticar controle de fluxo, uso de operadores lógicos, organização de código com funções e controle de tempo em sistemas embarcados.
