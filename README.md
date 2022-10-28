# NM

NM is a system command. It allows to list the symbols of objects files.<br>
The goal is to recreate this command with the <elf. h> or <macho. h> library depending on the operating system chosen.<br>

Bonus flags:

- r
- p

## Usage

- Clone Repository
```bash
git clone https://github.com/vvaucoul/NM && cd NM
```

- Compilation
```bash
make
```

## Exemple

With a simple main.c

<img src="https://user-images.githubusercontent.com/66129673/198730380-5463c052-f3e0-45ac-a35a-11e0cfcc43ce.png" width="50%">
<img src="https://user-images.githubusercontent.com/66129673/198730496-d8d5847b-f4f3-454e-b870-cd8fc61f2b1d.png" width="50%">

## Ressources

- [NM](http://www.linuxcertif.com/man/1/nm/)
- [ELF](http://manpagesfr.free.fr/man/man5/elf.5.html)
- [Medium](https://medium.com/a-42-journey/nm-otool-everything-you-need-to-know-to-build-your-own-7d4fef3d7507)
