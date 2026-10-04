
void __thiscall FUN_004703f1(int param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x5c) = 0;
  *(undefined1 *)(param_1 + 0x5d) = 0;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 0x54) = param_3;
  *(undefined4 *)(param_1 + 0x58) = 0x53545223;
  iVar1 = FUN_0046ffa4(0,1);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x5d) = 0;
    *(undefined4 *)(param_1 + 4) = param_2;
    *(undefined2 *)(param_1 + 0x54) = param_3;
    *(undefined4 *)(param_1 + 0x58) = 0x435354;
    *(undefined1 *)(param_1 + 0x5c) = 1;
    FUN_0046ffa4(0,1);
  }
  return;
}

