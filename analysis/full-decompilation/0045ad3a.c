
undefined4 __thiscall FUN_0045ad3a(int param_1,int param_2,short *param_3)

{
  byte bVar1;
  short sVar2;
  short *psVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  
  iVar6 = param_2;
  if (*(int *)(param_2 + 8) != 0) {
    iVar6 = 0;
    goto LAB_0045aec3;
  }
  iVar5 = FUN_00407498((int)*(short *)(param_2 + 4));
  if (iVar5 == 0) {
    param_2 = 0x34;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_00698f30);
  }
  cVar4 = FUN_00432644();
  psVar3 = param_3;
  if (cVar4 == '\0') {
    return 0;
  }
  sVar2 = param_3[1];
  if (sVar2 == 0) {
    if ((*param_3 < 0) && ((short)(ushort)*(byte *)(iVar6 + 7) <= *param_3)) {
      param_2 = 8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_2,&DAT_00698f30);
    }
    iVar6 = FUN_004752f8();
    uVar8 = (uint)*(short *)(iVar6 + *psVar3 * 2);
    if (((int)uVar8 < 0) ||
       ((uint)((*(int *)(iVar5 + 0x140) - *(int *)(iVar5 + 0x13c)) / 0x3c) <= uVar8)) {
      param_2 = 0x25;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_2,&DAT_00698f30);
    }
LAB_0045ae21:
    iVar6 = uVar8 * 0x3c + *(int *)(iVar5 + 0x13c);
  }
  else {
    if (sVar2 == 1) {
      uVar8 = (uint)*param_3;
      if (((int)uVar8 < 0) ||
         ((uint)((*(int *)(iVar5 + 0x140) - *(int *)(iVar5 + 0x13c)) / 0x3c) <= uVar8)) {
        param_2 = 0x25;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&param_2,&DAT_00698f30);
      }
      goto LAB_0045ae21;
    }
    if (sVar2 != 2) {
      param_2 = 0x25;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_2,&DAT_00698f30);
    }
    uVar8 = (uint)*param_3;
    if (((int)uVar8 < 0) ||
       (iVar6 = *(int *)(*(int *)(param_1 + 0xdc) + 0x9c),
       (uint)((*(int *)(*(int *)(param_1 + 0xdc) + 0xa0) - iVar6) / 0x3c) <= uVar8)) {
      param_2 = 0x25;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_2,&DAT_00698f30);
    }
    iVar6 = uVar8 * 0x3c + iVar6;
  }
  bVar1 = *(byte *)(psVar3 + 2);
  *(byte *)(iVar6 + 0x1d) = *(byte *)(iVar6 + 0x1d) & 0xbf;
  if ((~bVar1 & 1) != 0) {
    *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x4000;
  }
LAB_0045aec3:
  uVar7 = FUN_0045aecf(param_2,iVar6);
  return uVar7;
}

