
void __fastcall FUN_00484c30(int param_1)

{
  short sVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x44) == 0) {
    iVar2 = FUN_0043acf5(0x2f39b7a6);
    if (iVar2 != 0) {
      FUN_00492b05(iVar2);
      sVar1 = FUN_00440b6d(iVar2);
      iVar2 = (int)sVar1;
      FUN_00492b05(iVar2);
      iVar2 = FUN_00407498(iVar2);
      *(int *)(param_1 + 0x44) = iVar2;
      if (iVar2 != 0) {
        *(undefined2 *)(iVar2 + 0x4a) = 3;
        (**(code **)(**(int **)(param_1 + 0x44) + 0x50))(1);
      }
    }
  }
  return;
}

