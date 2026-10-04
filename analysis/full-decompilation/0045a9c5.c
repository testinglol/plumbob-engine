
undefined4 FUN_0045a9c5(void)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int *extraout_ECX;
  uint uVar8;
  int *piVar9;
  int unaff_EBP;
  
  FUN_00634c24();
  sVar1 = *(short *)(*(int *)(unaff_EBP + 8) + 4);
  if (sVar1 == 0) {
    *(undefined4 *)(unaff_EBP + 8) = 0x15;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
  }
  uVar8 = (uint)sVar1;
  iVar3 = extraout_ECX[0x37];
  if (((((int)uVar8 < 1) || ((*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 2) + 1U <= uVar8))
      || (iVar3 = *(int *)(*(int *)(iVar3 + 0x18) + -4 + uVar8 * 4), iVar3 == 0)) ||
     (iVar6 = FUN_00457e1c(), iVar6 == 0)) {
    uVar7 = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x10) = (int)*(short *)((int)extraout_ECX + 0x72);
    piVar9 = *(int **)(iVar6 + 0x10);
    if (piVar9 != (int *)0x0) {
      iVar6 = *(int *)(iVar6 + 4);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar6;
      if (0 < iVar6) {
        do {
          iVar6 = *piVar9;
          if (*(int *)(iVar6 + 0x18) == *(int *)(unaff_EBP + -0x10)) goto LAB_0045aa6d;
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
          piVar9 = piVar9 + 1;
        } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x14));
      }
    }
    iVar6 = 0;
LAB_0045aa6d:
    if (iVar6 == 0) {
      *(undefined4 *)(unaff_EBP + 8) = 0x16;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
    }
    uVar2 = *(undefined2 *)(iVar6 + 2);
    iVar4 = *extraout_ECX;
    *(undefined2 *)(unaff_EBP + -0x1c) = 0;
    *(undefined2 *)(unaff_EBP + -0x1a) = 0;
    *(undefined2 *)(unaff_EBP + -0x18) = 0;
    *(undefined2 *)(unaff_EBP + -0x16) = 0;
    cVar5 = (**(code **)(iVar4 + 0x34))
                      (iVar3,unaff_EBP + -0x1c,CONCAT22((short)((uint)iVar6 >> 0x10),uVar2),0);
    if (cVar5 == '\0') {
      uVar7 = 0xffffffff;
    }
    else {
      FUN_0041f010(extraout_ECX,iVar3,*(undefined4 *)(unaff_EBP + -0x10),2);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0041f0db(unaff_EBP + -0x1c);
      FUN_0045e839(unaff_EBP + -0x60);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar7 = 3;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

