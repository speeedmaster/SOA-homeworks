# Чат на основе очереди RabbitMQ

Проект состоит из клиента, сервера, обрабатывающего запросы клиента, сервера, рассылающего сообщения и брокера RabbitMQ.

## Описание

Для начала общения клиент регистрируется на сервере. После того, как в текущей сессии набирается достаточное количество участников, открывается чат.
Сервер уведомляет сервис сообщений о новой сессии и передает информацию об участниках. В том числе, возможность писать в секретный чат (могло пригодиться для Мафий).
Сервис с сообщениями поддерживает два типа рассылок: секретную и обычную. Клиент сам может выбрать, какой именно рассылкой отправить сообщение.

## Запуск контейнеров

Из корня директории:

```bash
serialization$ docker-compose up
```

Клиент:

```bash
serialization$ python3 client.py
```