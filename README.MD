# Fungame

## Description

This was a game i made for myself and my family to ease off boredom and possibly help learn more english words.

### How to Run

For this game to run you need at least

- Python 3.10 or newer
- Tkinter
- pyenchant with libenchant and nuspell or aspell-en
- And some friends to compete with (Or not)

For Arch

```bash
pip install pyenchant
sudo pacman -S enchant aspell-en nuspell
git clone https://github.com/WafiWadud/fungame
python3 main.py
```

Other linux chads and windows soyjaks try yourself

There are precompiled .so files for linux chads in the build/lib.linux-86_64-cpython-311/ directory to run these files use the following commands
```bash
git clone https://github.com/WafiWadud/fungame
cd fungame/build/lib.linux-x86_64-cpython-311/
python3 -c 'import main'
```

There are also precompiled .pyd files for windows soyjaks in the build/lib.win-amd64-cpython-311/ directory to run these files use the following commands
```bat
git clone https://github.com/WafiWadud/fungame
cd fungame/build/lib.win-amd64-cpython-311/
python3 -c 'import main'
```
