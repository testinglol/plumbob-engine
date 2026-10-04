
void __thiscall
FUN_005378dd(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  
  FUN_005dda18(param_2,param_3,param_4,param_5);
  if (*(int *)(param_1 + 0xd4) != 0) {
    FUN_004cb21d(0,0);
  }
  iVar1 = *(int *)(param_1 + 0xd8);
  if (iVar1 != 0) {
    FUN_004cb21d((((*(int *)(param_1 + 0x84) - *(int *)(iVar1 + 0x84)) - *(int *)(param_1 + 0x7c)) +
                 *(int *)(iVar1 + 0x7c)) / 2,0);
  }
  iVar1 = *(int *)(param_1 + 0xdc);
  if (iVar1 != 0) {
    FUN_004cb21d(((*(int *)(param_1 + 0x84) - *(int *)(iVar1 + 0x84)) - *(int *)(param_1 + 0x7c)) +
                 *(int *)(iVar1 + 0x7c),0);
  }
  return;
}

