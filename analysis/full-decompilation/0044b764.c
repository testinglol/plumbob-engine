
undefined4 FUN_0044b764(void)

{
  ushort uVar1;
  byte *pbVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int extraout_ECX;
  uint uVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  pbVar2 = *(byte **)(unaff_EBP + 0xc);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  if ((*pbVar2 & 1) == 0) {
    *(int *)(unaff_EBP + -0x10) = extraout_ECX;
    iVar4 = extraout_ECX;
  }
  else {
    iVar4 = FUN_00407498((int)*(short *)(*(int *)(unaff_EBP + 8) + 4));
    *(int *)(unaff_EBP + -0x10) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)(unaff_EBP + 8) = 0x15;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
    }
  }
  if ((*(int *)(iVar4 + 0x14c) - *(int *)(iVar4 + 0x148)) / 0x3c == 0) goto LAB_0044ba52;
  iVar4 = *(int *)(iVar4 + 0x148);
  iVar5 = 1;
  if ((*(ushort *)(pbVar2 + 2) & 0xff00) == 0x400) {
    iVar5 = 2;
  }
  if ((*(int *)(iVar4 + 0x10) != 0) && (iVar5 < *(int *)(iVar4 + 0x34))) goto LAB_0044ba52;
  *(int *)(iVar4 + 0x34) = iVar5;
  uVar1 = *(ushort *)(pbVar2 + 2);
  uVar7 = (int)(short)uVar1 & 0xff;
  *(uint *)(unaff_EBP + -0x18) = uVar7;
  *(uint *)(unaff_EBP + 0xc) = uVar7;
  if ((uVar7 == 0xffffffff) || (*(short *)(pbVar2 + 4) == 0)) {
    FUN_0046e15e(0);
    goto LAB_0044ba52;
  }
  iVar5 = extraout_ECX;
  if ((*(ushort *)(pbVar2 + 6) >> 0xc & 1) != 0) {
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + (int)*(short *)(extraout_ECX + 0x3a);
    iVar5 = *(int *)(unaff_EBP + -0x14);
  }
  if ((uVar1 & 0xff00) == 0x700) {
    iVar6 = *(int *)(unaff_EBP + -0x18);
    if (iVar6 == 0) {
      sVar3 = *(short *)(*(int *)(unaff_EBP + 8) + 4);
      iVar5 = *(int *)(iVar5 + 0xdc);
LAB_0044b8e4:
      uVar7 = (uint)sVar3;
      if ((((int)uVar7 < 1) ||
          ((*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U <= uVar7)) ||
         (*(int *)(*(int *)(iVar5 + 0x18) + -4 + uVar7 * 4) == 0)) goto LAB_0044ba52;
      iVar5 = FUN_004573f9();
    }
    else {
      if (iVar6 != 1) {
        if (iVar6 != 2) goto LAB_0044ba52;
        sVar3 = *(short *)pbVar2;
        if ((short)(ushort)*(byte *)(*(int *)(unaff_EBP + 8) + 6) <= sVar3 >> 1) {
          *(undefined4 *)(unaff_EBP + 8) = 0x33;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
        }
        iVar5 = FUN_004752fc();
        sVar3 = *(short *)(iVar5 + (sVar3 >> 1) * 2);
        iVar5 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0xdc);
        goto LAB_0044b8e4;
      }
      iVar5 = FUN_0042573e((int)*(short *)(*(int *)(unaff_EBP + 8) + 4));
      if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 8), iVar5 == 0)) goto LAB_0044ba52;
    }
    FUN_0046e105(iVar5);
  }
  else {
    FUN_004169e6((char)(uVar1 >> 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar3 = FUN_00416a49(*(undefined4 *)(unaff_EBP + 0xc));
    iVar5 = (int)sVar3;
    if (iVar5 == 0) {
LAB_0044b943:
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00416a38();
      goto LAB_0044ba52;
    }
    iVar6 = FUN_004c8f58(iVar5);
    if (iVar6 / 3 == 0) goto LAB_0044b943;
    FUN_0046e0d1(DAT_006f0bb8,iVar5,iVar6 / 3,*(ushort *)(pbVar2 + 6) >> 10 & 0xff01);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00416a38();
  }
  sVar3 = FUN_00416b9f(pbVar2[6]);
  *(int *)(iVar4 + 0x2c) = (int)sVar3;
  if ((*(ushort *)(pbVar2 + 6) & 0x200) == 0) {
    *(undefined4 *)(iVar4 + 0x30) = 0;
  }
  else {
    FUN_004169e6(1);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    sVar3 = FUN_00416a49(3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(iVar4 + 0x30) = (int)sVar3;
    FUN_00416a38();
  }
  *(byte *)(iVar4 + 0x38) = (byte)((ushort)*(undefined2 *)(pbVar2 + 6) >> 8) & 1;
  if (*(short *)(pbVar2 + 4) == -1) {
    iVar4 = -1;
LAB_0044ba08:
    FUN_0046e15e(iVar4);
  }
  else {
    iVar4 = (int)*(short *)(pbVar2 + 4);
    if ((*(ushort *)(pbVar2 + 6) & 0x800) == 0) goto LAB_0044ba08;
    FUN_0046e16c(iVar4);
  }
  iVar4 = *(int *)(unaff_EBP + -0x10);
  FUN_004341a6(0);
  FUN_0044578b((int)*(short *)(iVar4 + 0xf0));
LAB_0044ba52:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

