
void __fastcall FUN_00487238(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x3c) != (int *)0x0) {
    if (*(int *)(param_1 + 0x30) != 0) {
      if (*(char *)(param_1 + 0x75) == '\0') {
        FUN_0048be02(3);
        FUN_0049341e(*(undefined4 *)(param_1 + 0x30));
      }
      else {
        (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(1);
      }
      FUN_00485b4c();
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    FUN_0042194f();
    uVar1 = CONCAT22((short)((uint)*(int *)(param_1 + 0x3c) >> 0x10),
                     *(undefined2 *)(*(int *)(param_1 + 0x3c) + 0xf0));
    FUN_00492b05(uVar1);
    FUN_0044127f(uVar1);
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  FUN_00486ec8(0,0);
  FUN_00486e21();
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_00485b4c();
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  FUN_00487f26();
  return;
}

