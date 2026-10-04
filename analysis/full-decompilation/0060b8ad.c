
void __thiscall FUN_0060b8ad(int *param_1,uint param_2)

{
  (**(code **)(*param_1 + 0x28))(param_2);
  if ((param_2 == 4) || (param_2 == 0x10)) {
    if ((char)param_2 == '\0') {
      param_1[3] = param_1[3] & ~param_2;
    }
    else {
      param_1[3] = param_1[3] | param_2;
    }
  }
  return;
}

