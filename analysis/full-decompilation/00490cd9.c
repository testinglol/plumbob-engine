
void FUN_00490cd9(int *param_1,undefined2 param_2)

{
  short sVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    iVar2 = FUN_0043acf5(0x2f39b7a6);
    if (iVar2 != 0) {
      FUN_00492b05(iVar2);
      sVar1 = FUN_00440b6d(iVar2);
      iVar2 = (int)sVar1;
      FUN_00492b05(iVar2);
      iVar2 = FUN_00407498(iVar2);
      *param_1 = iVar2;
      if (iVar2 != 0) {
        *(undefined2 *)(iVar2 + 0x4a) = param_2;
        (**(code **)(*(int *)*param_1 + 0x50))(1);
      }
    }
  }
  return;
}

