# Leaks / Bugs / Segflts

**Leaks:**

Src: ft_push_back / ft_joinvect<br />
Reason: env => export OK=555 => env => OK=67 => env

**Bugs:**

Src: print_promt => get_prompt => getpwuid<br />
Reason: env vars must be obtained from sgetenv function