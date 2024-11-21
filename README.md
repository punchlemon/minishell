# 🌊 Minishell

## 🌝 Demo

https://github.com/user-attachments/assets/675163bd-2ad3-4ee2-9f70-c0f790d67922


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

[- [ ] $（変数）の処理について考える![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 📝 To-Do
- [ ] normを解決する "norm"
- [ ] heredocのシグナルハンドル "handle signal in heredoc"
- [ ] heredocの環境変数展開 "expand variable in heredoc"
- [ ] \に対応する。たとえば"\"" "support \"
- [ ] g_signalが機能してるのか要調査
- [ ] cat ; Ctrl + C
- [ ] cat ; Ctrl + \
- [ ] $EMPTY echo hi
- [ ] cat ; シグナル; echo $?
- [ ] シグナル; echo $?

## 🚀 WIP
- [ ] \*.oだけでなく\*.dも出力できるようにする

## 🌟 Done
- [X] export key+=value
- [X] 変数展開できるようにする "enable expand valuable"
- [X] echo "$HOME"
- [X] echo '$HOME'
- [X] echo $HOMEでセグフォを起こさないようにする "fix echo $HOME"
- [X] echo $?で"0"が出力されるようにする "fix echo $?"
- [X] expandのmallocをfreeする "free malloc of expand"
- [X] wordを処理する関数を別で設定して実行側で随時処理できるようにする
- [X] g_last_codeをなくす
- [X] export aaa ; export
- [X] export aaa ; env | grep aaa
- [X] exit codeを管理する "add exit code"
- [X] ccat を実行したときの return status を 127 にする
