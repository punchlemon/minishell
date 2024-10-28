# 🌊 Minishell

## 🌝 Demo

https://github.com/user-attachments/assets/6910f700-2922-48b4-a8e1-99d29b3ccd4d

## 👀 Overview

> Shell reimplementation.

## 🔫 Usage

```
git clone git@github.com:punchlemon/minishell ; cd minishell
```

```
make ; ./minishell
```

## 📌 Requirements

<p>
	<img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white" />
</p>

- Ubuntu 22.04.3 2023.11.28 LTS
- Ubuntu clang version 12.0.1-19ubuntu3

## 🎪 Environments

<p>
	<img src="https://img.shields.io/badge/VSCode-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
	<img src="https://img.shields.io/badge/VIM-%2311AB00.svg?&style=for-the-badge&logo=vim&logoColor=white" />
	<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
</p>

## 📝 Reference

* [https://github.com/Wolframike/minishell/wiki/minishell-syntax-diagram](https://github.com/Wolframike/minishell/wiki/minishell-syntax-diagram)
* [https://github.com/harsssh/minishell/wiki/Railroad-Diagram](https://github.com/harsssh/minishell/wiki/Railroad-Diagram)
* [https://www.bottlecaps.de/rr/ui](https://www.bottlecaps.de/rr/ui)
* [https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10)

## 🗿 Author

* [noburestaurant](https://github.com/noburestaurant)
* [punchlemon](https://github.com/punchlemon)

## ✒️ Licence

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 📝 To-Do

- [ ] \*.oだけでなく\*.dも出力できるようにする
- [ ] ctrl+cでプログラムが終了しないようにする "disable ctrl+c"
- [ ] *の処理について考える
- [ ] /の処理について考える
- [ ] $の処理について考える
- [ ] wikiのsyntax diagramを書き換える

## 🚀 WIP

- [ ] parserを実行できるようにする "add parser"
- [ ] check関数のバグを解消する
- [ ] print_redsを完成させる

## 🌟 Done

- [X] condsの中身がNULLである原因を調査する
- [X] count関数で数えた情報を使ってstore関数では数えなくていいようにしたい
- [X] parserのcreate関数は終端をtailではなくlenで管理するべき "fix tail -> len"
- [X] create_wordを完成させる
