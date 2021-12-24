# The Default Planck Layout

How to install:
```console
cd ~
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
util/qmk_install.sh
cd keyboards/planck/keymaps/
git clone https://github.com/antosha417/planck
cd ~/qmk_firmware
make planck/rev6:planck:dfu-util
```
Useful:
* [keycodes](https://docs.qmk.fm/#/keycodes)
* [string keycodes](https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string_keycodes.h)

Todo:
* read about music mode
* try language change buttons

