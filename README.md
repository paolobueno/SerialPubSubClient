# SerialPubSubClient

Biblioteca para testar código para a biblioteca [PubSubClient](https://github.com/knolleary/pubsubclient) utilizando a porta serial ao invés de porta ethernet real.

## Instalação

Clone este repositório para sua pasta de **Bibliotecas** (No Windows o padrão é`{usuário}\Documentos\Arduino\libraries\`):

```bash
cd ~/Arduino/libraries/
git clone https://github.com/paolobueno/SerialPubSubClient
```

## Utilização
Substitua o `#include` da biblioteca real por esta, isso também é possível ser feito através de [diretivas de pré-processador](https://pt.wikibooks.org/wiki/Programar_em_C/Pr%C3%A9-processador#Usos_comuns_das_diretivas):

```c++
#ifdef ONLINE
#include <PubSubClient.h>
#else
#include <SerialPubSubClient.h>
#endif
```

Para trocar de volta para a biblioteca original, então, é necessário somente definir o nome `ONLINE`:

```c++
#define ONLINE 1
```

Esta biblioteca define métodos iguais à da **PubSubClient**, porém com comunicação serial.

## Enviando mensagens MQTT falsas

Para enviar uma mensagem MQTT falsa via serial:

1. Configure seu *Serial Monitor* para adicionar um **terminador de linha**

2. Envie mensagens no formato `{tópico}|{payload}\n`, com `'\n'` sendo o caractere de quebra de linha que deve ser inserido pelo *Serial Monitor*

**NOTA**: Esta biblioteca não leva em consideração os tópicos incritos através de `subscribe()`, a função de callback será chamada com qualquer tópico enviado através de comunicação serial.

## Exemplos

Veja pasta [examples](./examples)