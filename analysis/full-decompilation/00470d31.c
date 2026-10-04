
void __thiscall FUN_00470d31(int param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 0x54) = param_3;
  *(undefined4 *)(param_1 + 0x58) = 0x53545223;
  *(char *)(param_1 + 0x5d) = *(char *)(DAT_006e486c + 100) + -1;
  iVar1 = FUN_00470d9f(param_4,1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = param_2;
    *(undefined2 *)(param_1 + 0x54) = param_3;
    *(undefined4 *)(param_1 + 0x58) = 0x435354;
    *(undefined1 *)(param_1 + 0x5c) = 1;
    *(char *)(param_1 + 0x5d) = *(char *)(DAT_006e486c + 100) + -1;
    FUN_00470d9f(param_4,1);
  }
  return;
}

