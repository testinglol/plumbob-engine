
void __thiscall
FUN_004c3d8e(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_004c3e0d(param_3,param_4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (0 < param_3) {
      iVar1 = FUN_004c3e0d(param_3 + -1,param_4);
      if (iVar1 != 0) {
        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1;
      }
    }
    if (0 < param_4) {
      iVar1 = FUN_004c3e0d(param_3,param_4 + -1);
      if (iVar1 != 0) {
        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 2;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 3;
  }
  (**(code **)(**(int **)(param_1 + 4) + 0x14))(param_2,param_3,param_4,param_5);
  (**(code **)(**(int **)(param_1 + 8) + 0x14))(param_2,param_3,param_4,param_5);
  return;
}

