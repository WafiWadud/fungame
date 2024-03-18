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
sudo pacman -S libenchant aspell-en nuspell
git clone https://github.com/WafiWadud/fungame
python3 main.py
```

Other linux users try yourself

There are precompiled .so files for linux in the build/lib/ directory to run these files use the following command
```bash
git clone https://github.com/WafiWadud/fungame
cd build/lib
python3 -c 'import main'
```
