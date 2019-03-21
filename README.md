# 42sh
Pahom's shell, some segflts and ~~amazing~~ useless readline.

**Minishell Part**

[✓] Prompt display<br>
[✓] Run commands with their parameters and _PATH_ monitoring<br>
[✓] Error monitoring, without using _errno_, and return values of commands<br>
[✓] Correct spaces and tabulations monitoring<br>

**21sh Part**

[✓] Full edition of command line<br>
[✓] Redirection and aggregation operators: _\>_, _\>>_, _\<<_, _\<<_, _\>&_, _\<&_, _\|_, _\;_<br>

**42sh Part**

Builtins:<br>
[✓] _cd_<br>
[✓] _echo_<br>
[✓] _exit_<br>
[✓] _type_<br>
[✓] _env_<br>
[✓] _setenv_<br>
[✓] _unsetenv_<br>
[✓] _set_<br>
[−] _unset_<br>

[✓] _\&&_, _\||_<br>

[✓] Intern variable creation depending on syntax: _name=value_<br>
[✓] Intern variable exportation to the environment, via built-in _export_<br>
[✓] Possibility to list shell intern variables via built-in _set_ (-n, -o options)<br>
[−] Intern and environement variables revocation, via built-in _unset_ (no optionrequired)<br>
[✓] Environment variable creation for unique command, for instance: _HOME=/tmp cd_<br>
[−] Simple expansion of parameters depending on syntax _${}_ (no additionnal format required)<br>
[−] Exit code access of previously command via the expansion _${?}_<br>

[−] Job control monitoring<br>
[+] Built-in _jobs_<br>
[+] Built-in _fg_<br>
[−] Built-in _bg_<br>
[+] _&_<br>

[+] Correct monitoring of signals<br>

[✓] Each built-in must have enounced options by POSIX, except _set_ / _unset_<br>

[−] Inhibitors _” ’_<br>
[✓] Glob: _* ? [] !_<br>

[✓] ~<br>
[✓] ${parameter:-word}<br>
[✓] ${parameter:=word}<br>
[✓] ${parameter:?word}<br>
[✓] ${parameter:+word}<br>
[✓] ${#parameter}<br>
[✓] ${parameter%}<br>
[−] ${parameter%%}<br>
[✓] ${parameter#}<br>
[−] ${parameter##}<br>
[✓] $[5 + 3 arithm]<br>
[✓] $((5 + 3 arithm))<br>

[−] Control groups and sub-shells: _()_, _{}_<br>
[−] Control substitution: _$()_<br>
[−] Arithmetic expansion: _(())_<br>
[−] Process substitution: _<()_, _>()_<br>

[−] !!<br>
[−] !word<br>
[−] !number<br>
[−] !-number<br>
[−] File for history<br>
[−] Built-in _fc_<br>
[−] Search via _Ctrl-R_<br>

[✓] Contextual autocomplete<br>

[✓] Vi / Emacs mods<br>

[✓] Alias management with built-ins _alias_ / _unalias_<br>

[✓] Hash table and built-in _hash_<br>

[−] Built-in _test_ and operations: _-b, -c, -d, -e, -f, -g, -L, -p, -r, -S, -s, -u, -w, -x, -z, =, !=, -eq, -ne, -ge, -lt, -le, !_<br>

[−] Shell scripting (_while, for, if, case, function, etc._)<br>

[✓] Autocompletion for order/built-in parameters<br>

[✓] Compliant with POSIX<br>

**Bugs**

Ariphmetic:<br>
    1) Division by zero<br>

Butch code:<br>
    1) If extention returns NULL, 42sh gives seg fault<br>
    2) ls -la | cet (killed)<br>
    3) bar ()<br>
    {<br>
        ls<br>
    }<br>
    4) alias glog="git log --pretty=oneline --pretty=format:'%H - %an, %ar: %s' --graph"<br>
