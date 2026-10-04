
undefined4 FUN_0048c3d6(undefined4 param_1)

{
  short *psVar1;
  undefined4 uVar2;
  short sVar3;
  
  sVar3 = (short)param_1;
  if (sVar3 == 0) {
    return 0;
  }
  psVar1 = (short *)FUN_0048c320(param_1);
  if (psVar1 == (short *)0x0) {
    uVar2 = FUN_00407498((int)sVar3);
    psVar1 = operator_new(0x14);
    psVar1[2] = 0;
    psVar1[3] = 0;
    *(undefined1 *)(psVar1 + 8) = 0;
    *psVar1 = sVar3;
    *(undefined4 *)(psVar1 + 6) = uVar2;
    *(int *)(psVar1 + 4) = DAT_006c5f9c;
    DAT_006c5f9c = DAT_006c5f9c + 1;
    FUN_0048c3aa(psVar1);
  }
  *(int *)(psVar1 + 2) = *(int *)(psVar1 + 2) + 1;
  return *(undefined4 *)(psVar1 + 4);
}

