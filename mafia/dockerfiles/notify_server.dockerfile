FROM python:3.10

RUN pip install grpcio-tools
RUN pip install pika

COPY ../proto ./proto
COPY ../notify_server.py .

CMD ["python3", "notify_server.py"]