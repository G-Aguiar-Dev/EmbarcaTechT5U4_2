# EmbarcaTechT5U4_2
Projeto realizado de acordo as instruções da atividade referente ao Capítulo 5 da Unidade 4. Esta referência se aplica ao programa de capacitação EmbarcaTech - TIC 37

# Instruções
O programa pode ser utilizado tanto em ambiente de simulador, utilizando a extensão Wokwi Simulator do VSCode, como na placa de desenvolvimento BitDogLab. <br>
O projeto visa aplicar o conceito de alarme apresentado durante o curso, utilizando uma interrupção gerada após 3 segundos que o botão foi pressionado.<br>
Caso utilize a placa BitDogLab, o botão utilizado foi o Botao_A. <br>
Após o pressionamento do botão, é imprimida uma mensagem via comunicação serial informando que todos os LEDs foram ligados. Além da mudança de estado dos LEDs, é setado um alarme para 3 segundos. Este, por fim, irá iniciar a sequência de desligamento dos LEDs um por um, verificando qual LED está sendo desligado e imprimindo uma mensagem o indicando. Dentro desta função é definido outro alarme para desligar o LED seguinte, o processo se repete até que todos estejam desligados.