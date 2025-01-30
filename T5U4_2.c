// Inclusão de bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"
// Define os pinos do botão e dos LEDs
#define BUTTON_PIN 5
#define LED_PIN_GREEN 11
#define LED_PIN_BLUE 12
#define LED_PIN_RED 13
// Variável de controle do contador
static uint cont = 0;

// Função de callback do alarme
int64_t alarm_callback(alarm_id_t id, void *user_data) {
    cont++; // Incrementa o contador a cada execução
    if (cont == 1) { // 1ª execução - Desliga LED verde
        printf("Desligando LED verde\n");
        gpio_put(LED_PIN_GREEN, 0);
        gpio_put(LED_PIN_BLUE, 1);
        gpio_put(LED_PIN_RED, 1);
        add_alarm_in_ms(3000, alarm_callback, NULL, true);
    } else if (cont == 2) { // 2ª execução - Desliga LED azul
        printf("Desligando LED azul\n");
        gpio_put(LED_PIN_GREEN, 0);
        gpio_put(LED_PIN_BLUE, 0);
        gpio_put(LED_PIN_RED, 1);
        add_alarm_in_ms(3000, alarm_callback, NULL, true);
    } else if (cont == 3) { // 3ª execução - Desliga LED vermelho
        printf("Desligando LED vermelho\n");
        gpio_put(LED_PIN_GREEN, 0);
        gpio_put(LED_PIN_BLUE, 0);
        gpio_put(LED_PIN_RED, 0);
        cont = 0; // Reseta o contador
    }
return 0;
}

// Função de setup
void setup() {
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    gpio_put(LED_PIN_GREEN, 0);

    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_put(LED_PIN_BLUE, 0);

    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_put(LED_PIN_RED, 0);
}

// Função principal
int main()
{
    stdio_init_all(); // Inicializa a comunicação serial
    setup(); // Chama a função de setup

    // Loop principal
    while (true) {
        if (!gpio_get(BUTTON_PIN) && !gpio_get(LED_PIN_RED)) { // Leitura do botão e do último LED aceso
            sleep_ms(100); // Debounce
            if(!gpio_get(BUTTON_PIN)){ // Releitura do botão
                printf("Ligando LEDs\n"); // Mensagem de depuração
                // Ligar os LEDs
                gpio_put(LED_PIN_GREEN, 1);
                gpio_put(LED_PIN_BLUE, 1);
                gpio_put(LED_PIN_RED, 1);
                add_alarm_in_ms(3000, alarm_callback, NULL, true); // Inicia a sequência de desligamento através de alarme
            }
        }
    sleep_ms(10); // Evitar leituras em excesso
    }
return 0;
}
