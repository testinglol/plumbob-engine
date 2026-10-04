
void FUN_0062b310(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = FUN_0062ac30(param_1,param_2);
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0x254);
    *(undefined4 *)(iVar2 + 8) = param_3;
    *(undefined4 *)(iVar2 + 0xc) = param_4;
    uVar1 = *(undefined4 *)(param_1 + 0x238);
    *(undefined4 *)(iVar2 + 0x10) = param_5;
    *(undefined4 *)(iVar2 + 0x14) = uVar1;
    *(undefined4 *)(iVar2 + 0x18) = param_6;
    *(undefined4 *)(iVar2 + 0x1c) = param_7;
    return;
  }
  FUN_0062af30(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

