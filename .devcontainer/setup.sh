#!/usr/bin/env bash

set -eEuo pipefail

wget https://bootstrap.pypa.io/get-pip.py
python3 get-pip.py
python3 -m pip install qmk
rm get-pip.py

python3 -m pip install --upgrade milc

userspacePath="$1"

git config --global --add safe.directory "$userspacePath"
git submodule update --init --recursive

[ -d $userspacePath/qmk_firmware ] || git clone https://github.com/qmk/qmk_firmware.git $userspacePath/qmk_firmware
git config --global --add safe.directory $userspacePath/qmk_firmware

qmk config user.qmk_home=$userspacePath/qmk_firmware
qmk config user.overlay_dir="$userspacePath"

qmk git-submodule

chmod +x compile_keyboard.py
