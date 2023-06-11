FROM python:3.10

RUN pip install pika
RUN pip install grpcio-tools
COPY ../server.py .
COPY ../proto ./proto

CMD ["python3", "server.py"]
