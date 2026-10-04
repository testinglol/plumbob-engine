
void __thiscall
FUN_0047034e(int param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,undefined1 param_5
            ,char param_6)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 0x54) = param_3;
  *(undefined4 *)(param_1 + 0x58) = param_4;
  *(undefined1 *)(param_1 + 0x5c) = param_5;
  if (param_6 < '\0') {
    param_6 = *(char *)(DAT_006e486c + 100) + -1;
  }
  *(char *)(param_1 + 0x5d) = param_6;
  return;
}

