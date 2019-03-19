
**Minishell Part**

[✓] Prompt display<br>
[✓] Run commands with their parameters and PATH monitoring<br>
[✓] Error monitoring, without using errno, and return values of commands<br>
[✓] Correct spaces and tabulations monitoring<br>

**21sh Part**

[✓] Full edition of commands line<br>
[✓] Redirection and aggregation operators: _\>_, _\>>_, _\<<_, _\<<_, _\>&_, _\<&_, _\|_, _\;_<br>

**42sh Part**

[✓] cd<br>
[✓] echo<br>
[✓] exit<br>
[✓] type<br>

[✓] \&&, \||<br>

[✓] Intern variable creation depending on syntax: name=value<br>
[✓] Intern variable exportation to the environment, via built-in export<br>
[✓] Possibility to list shell intern variables via built-in set (no option required)<br>
[✓] Intern and environement variables revocation, via built-in unset (no optionrequired)<br>
[✓] Environment variable creation for unique command, for instance: HOME=/tmp cd<br>
[−] Simple expansion of parameters depending on syntax ${} (no additionnal format required)<br>
[−] Exit code access of previously command via the expansion ${?}<br>

[−] Job control monitoring<br>
[−] Built-in jobs<br>
[−] Built-in fg<br>
[−] Built-in bg<br>
[−] &<br>

[−] Correct monitoring of signals<br>

[−] Each built-in must have enounced options by POSIX, except set / unset<br>

[−] Inhibitors ” ’ \ <br>
[−] Glob: * ? [] ! \ <br>

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
[✓] $[5 + 3arithm]<br>
[✓] $((5 + 3arithm))<br>

[−] Control groups and sub-shells: (), {}<br>
[−] Control substitution: $()<br>
[−] Arithmetic expansion: (())<br>
[−] Process substitution: ()), <(), >()<br>

[−] !!<br>
[−] !word<br>
[−] !number<br>
[−] !-number<br>
[−] File for history<br>
[−] Built-in fc<br>
[−] Search via Ctrl-R<br>

[−] Contextual autocomplete<br>

[−] Vi / Readline mods<br>

[✓] Alias management with built-ins alias / unalias<br>

[✓] Hash table and built-in hash<br>

[−] Built-in test and operations: -b, -c, -d, -e, -f, -g, -L, -p, -r, -S, -s, -u, -w, -x, -z, =, !=, -eq, -ne, -ge, -lt, -le, !<br>

[−] Shell scripting (while, for, if, case, function, etc.)<br>

[−] Autocompletion for order/built-in parameters<br>

[−] Compliant with POSIX<br>

BUGS:

BUGS IN ARITHMETIC:
    1) Division byzero
    2) Just division

BUGS IN BUTCH:
    1) If extention returns NULL - 42sh seg fault
