# ImageSocket

## Requirements
This was performed on ubuntu 18.04, but it will work on others as well. with little tweaking.

## Installation

**For ZMQ**
```
sudo apt-get install libzmq5-dev
sudo pip3 install zmq

wget https://github.com/zeromq/libzmq/releases/download/v4.2.1/zeromq-4.2.1.tar.gz
tar -xvzf zeromq-4.2.1.tar.gz
cd zeromq-4.2.1/

sudo apt-get install libtool pkg-config build-essential autoconf automake uuid-dev
sudo apt-get install checkinstall

./configure
make
sudo checkinstall
sudo ldconfig
```
**For Opencv**

Follow instructions from [here:](https://github.com/jayrambhia/Install-OpenCV)

## Execution

On First teminal execute ```python3 server.py ```

On Second terminal execute ```g++ client.cpp ConvertImage.cpp -lzmq `pkg-config --cflags --libs opencv` && ./a.out ```

## License

ImageSocket is under [MIT license](http://en.wikipedia.org/wiki/MIT_License). It can be reused within proprietary software provided that all copies of the licensed software include a copy of the MIT License terms and the copyright notice.
