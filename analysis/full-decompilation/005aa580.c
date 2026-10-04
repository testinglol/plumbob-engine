
undefined4 FUN_005aa580(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = (&DAT_00703ea0)[param_1 & 0xf];
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x38) != 0) {
      FUN_005b6840(*(int *)(iVar1 + 0x38));
      *(undefined4 *)(iVar1 + 0x38) = 0;
    }
    FUN_005a9250(iVar1,0,0x44);
    (&DAT_00703ea0)[param_1 & 0xf] = 0;
    uVar2 = 1;
  }
  return uVar2;
}

