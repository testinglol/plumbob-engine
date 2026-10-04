
void __thiscall FUN_005591a7(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0055c216(param_2);
  if (iVar1 != 0) {
    iVar1 = FUN_0042ba25(param_2);
    if (iVar1 == 1) {
      (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))(DAT_006f57a8 + 0xc,DAT_006f57a8,0,0);
    }
    else if (iVar1 == 2) {
      FUN_005dac30(0x10,param_1,param_2);
    }
  }
  return;
}

