# :ocean: Minishell

## :full_moon_with_face: Demo

https://github.com/user-attachments/assets/6910f700-2922-48b4-a8e1-99d29b3ccd4d


## :eyes: Overview
> Shell reimplementation.

## :gun: Usage
```
git clone git@github.com:punchlemon/minishell ; cd minishell
```
```
make ; ./minishell
```

## :pushpin: Requirements
<p>
	<img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white" />
</p>

- Ubuntu 22.04.3 2023.11.28 LTS
- Ubuntu clang version 12.0.1-19ubuntu3

## :circus_tent: Environments
<p>
	<img src="https://img.shields.io/badge/VSCode-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
	<img src="https://img.shields.io/badge/VIM-%2311AB00.svg?&style=for-the-badge&logo=vim&logoColor=white" />
	<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
</p>

## :memo: Reference
* [https://github.com/Wolframike/minishell/wiki/minishell-syntax-diagram](https://github.com/Wolframike/minishell/wiki/minishell-syntax-diagram)
* [https://github.com/harsssh/minishell/wiki/Railroad-Diagram](https://github.com/harsssh/minishell/wiki/Railroad-Diagram)
* [https://www.bottlecaps.de/rr/ui](https://www.bottlecaps.de/rr/ui)
* [https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10)

## :moyai: Author
* [noburestaurant](https://github.com/noburestaurant)
* [punchlemon](https://github.com/punchlemon)

## :black_nib: Licence
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## :memo: To-Do
- [ ] pipeの構造体名が少し違和感があるのでpipeに変更する "change name p_cmd -> pipe"
- [ ] exitでminishellを終了できるようにする "enable exit"
- [ ] ctrl+cでプログラムが終了しないようにする "disable ctrl+c"
- [ ] ただ改行が入力されたときに改行のみを出力する部分を関数かする "functionalize enter"

## :rocket: WIP

## :star2: Done
- [x] 現状ではand_orには対応しているが、'|'一文字をキャンセルしているのでパイプに対応していない。これを対応させる "fix pipe"
