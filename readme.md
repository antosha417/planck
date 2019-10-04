# The Default Planck Layout

How to install:
```console
cd ~
git clone https://github.com/qmk/qmk_firmware
cd qmk_firmware/keyboards/planck/keymaps/
git clone https://github.com/antosha417/planck
cd ~/qmk_firmware
make planck/rev6:planck:dfu-util
```
Useful:
* [keycodes](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md)
* [string keycodes](https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string_keycodes.h)  

Todo:  
    remove copypast using defines  
    read about music mode
