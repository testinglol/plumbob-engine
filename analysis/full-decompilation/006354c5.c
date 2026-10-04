
undefined4 FUN_006354c5(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  FUN_00637d91();
  uVar1 = FUN_00640e9d(DAT_00705358);
  if (uVar1 < (uint)((int)DAT_00705354 + (4 - DAT_00705358))) {
    iVar2 = FUN_00640e9d(DAT_00705358);
    iVar2 = FUN_00640b6e(DAT_00705358,iVar2 + 0x10);
    if (iVar2 == 0) {
      param_1 = 0;
      goto LAB_0063553a;
    }
    DAT_00705354 = (undefined4 *)(iVar2 + ((int)DAT_00705354 - DAT_00705358 >> 2) * 4);
    DAT_00705358 = iVar2;
  }
  *DAT_00705354 = param_1;
  DAT_00705354 = DAT_00705354 + 1;
LAB_0063553a:
  FUN_00637d9a();
  return param_1;
}

