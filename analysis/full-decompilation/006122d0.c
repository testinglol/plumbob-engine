
undefined4 FUN_006122d0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = param_1;
  iVar2 = *param_1;
  iVar4 = 0;
  if (0 < *(int *)(iVar2 + 0x14)) {
    do {
      iVar5 = 0;
      if (0 < *(int *)(iVar2 + 0x10)) {
        do {
          uVar3 = FUN_00612340(piVar1,iVar5,iVar4);
          param_1._3_1_ = (char)((uint)uVar3 >> 0x18);
          if (param_1._3_1_ == '\0') {
            return uVar3;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(*piVar1 + 0x10));
      }
      iVar2 = *piVar1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(iVar2 + 0x14));
  }
  return 0xffff;
}

