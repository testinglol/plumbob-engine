
void __fastcall FUN_0050677a(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x424) - *(int *)(param_1 + 0x420) >> 2 != 0) {
    do {
      if ((*(int *)(*(int *)(param_1 + 0x420) + uVar2 * 4) != 0) &&
         (iVar1 = FUN_00492d2c(), iVar1 != 0)) {
        uVar3 = 0;
        FUN_00492d2c(0);
        FUN_005e46f0(uVar3);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0x424) - *(int *)(param_1 + 0x420) >> 2));
  }
  return;
}

