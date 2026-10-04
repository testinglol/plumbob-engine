
int __thiscall FUN_005e5fd3(int param_1,int param_2)

{
  if (param_1 != param_2) {
    FUN_005d6061(param_2 + 4);
    FUN_005d6061(param_2 + 0x10);
    FUN_005d499c(param_2 + 0x1c);
    *(undefined1 *)(param_1 + 0x28) = *(undefined1 *)(param_2 + 0x28);
  }
  return param_1;
}

