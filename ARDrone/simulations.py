#!/usr/bin/env python
# -*- coding: utf-8 -*-

import time
import json
import arDemo


class ConnectionMock():
    def __init__(self, data):
        self.data = data

    def recv(self, *args):
        if self.data['comm_count'] == 50:
            self.data['RocketLaunch'] = 1

        if self.data['comm_count'] == 100:
            self.data['RocketDestroy'] = 1

        time.sleep(0.1)

        return json.dumps(self.data)

    def close(self, *args):
        pass


class SocketMock():

    def __init__(self, *args):
        self.counter = 0

    def bind(self, *args):
        pass

    def listen(self, *args):
        pass

    def accept(self, *args):
        self.counter += 1
        data = {'RocketLaunch': 0,
                'RocketDestroy': 0,
                'comm_count': self.counter}
        return ConnectionMock(data), 'Endereço mockado'


def mock_communications():
    arDemo.scade_socket = SocketMock()


if __name__ == '__main__':
    mock_communications()
    arDemo.DEBUG = True
    arDemo.main()
