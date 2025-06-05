# Edge-Computing-GS

Projeto de Edge Computing & IoT para a Global Solution FIAP

## Nome dos Participantes
- Gabriel Santos Oliveira – RM 562419  
- Gustavo Rocha – RM 564152  
- Matheus Kitamura Gurther – RM 563205  

## Descrição do Problema

Durante períodos de chuvas intensas, muitas cidades enfrentam problemas graves com alagamentos em ruas e avenidas, que causam prejuízos materiais, dificultam o tráfego de veículos e colocam em risco a segurança da população. A falta de sistemas inteligentes de monitoramento e drenagem agrava a situação, já que as ações de prevenção e resposta geralmente são lentas e manuais.

Em áreas urbanas vulneráveis, é comum que o nível da água suba rapidamente, sem aviso, e sem que haja um sistema de alerta ou de acionamento automático de bombas de escoamento. Isso torna urgente o desenvolvimento de soluções que detectem de forma rápida o nível de alagamento e que ajam automaticamente para minimizar os danos causados pela água acumulada.

## Visão Geral da Solução

Para solucionar esse problema, este projeto tem como objetivo **simular uma rua alagada equipada com um sistema automatizado de monitoramento e drenagem**, utilizando sensores e atuadores programados com Arduino. O sistema é capaz de:

- Detectar o nível de água acumulada na rua por meio do **sensor ultrassônico HC-SR04**  
- Emitir **alertas visuais (LEDs)** e **sonoros (buzzer)** de acordo com o nível de risco  
- Acionar automaticamente uma **bomba de drenagem simulada por um servo motor** quando o nível crítico de alagamento é atingido

## Funcionamento

O sistema utiliza um sensor ultrassônico (HC-SR04) para medir a altura da água simulada sobre a rua. A lógica de funcionamento é baseada na distância medida:

- **Nível Baixo (> 80 cm)**:  
  LED verde aceso. Situação segura, sem ações adicionais.

- **Nível Alto (entre 31cm e 80 cm)**:  
  LED amarelo aceso. Indica atenção; a bomba entra em modo de espera.

- **Nível Crítico (≤ 31 cm)**:  
  LED vermelho aceso, buzzer ativado e servo motor aciona a bomba de drenagem simulada.

As leituras são atualizadas constantemente, permitindo que o sistema reaja em tempo real, sem necessidade de intervenção manual.

Para testar o sistema, basta alterar manualmente a distância entre o sensor e a "superfície da água". Isso permite verificar a resposta dos LEDs, do buzzer e do servo motor conforme as condições simuladas.

## 📷 Imagem do Projeto no Wokwi
<p align="center">
  <img src="https://github.com/user-attachments/assets/ab55e6f3-c652-442e-bb08-1d2369722c07" alt="Simulação do circuito" width="800"/>
</p>

## 🔗 Link para o Projeto no Wokwi

[Projeto no Wokwi](https://wokwi.com/projects/432243058316748801)

## 🔗 Link para o Projeto no Youtube

[Projeto no Youtube]((https://www.youtube.com/watch?v=7mpA8zQmfrM))

