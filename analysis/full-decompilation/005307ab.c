
void __thiscall FUN_005307ab(int param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 0x1a5) == '\0') {
    *(undefined1 *)(param_1 + 0x1a5) = 1;
    *(undefined4 *)(param_1 + 0x1a8) = param_2;
    FUN_005dadff(param_1,param_2,0);
  }
  return;
}

