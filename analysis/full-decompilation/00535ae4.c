
void __thiscall
FUN_00535ae4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  
  FUN_005dda18(param_2,param_3,param_4,param_5);
  iVar1 = *(int *)(param_1 + 0xf4);
  if (iVar1 != 0) {
    FUN_004cb21d(((*(int *)(param_1 + 0x84) - *(int *)(iVar1 + 0x84)) - *(int *)(param_1 + 0x7c)) +
                 -5 + *(int *)(iVar1 + 0x7c),5);
  }
  return;
}

