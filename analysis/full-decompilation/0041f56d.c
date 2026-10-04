
undefined1 FUN_0041f56d(void)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  undefined1 uVar5;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  uVar5 = 0;
  if (*(short *)(unaff_EBP + 0xc) == 0) {
    uVar5 = 1;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    iVar6 = *(int *)(extraout_ECX + 8);
    piVar1 = (int *)(extraout_ECX + 4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if ((uint)(int)*(short *)(unaff_EBP + 8) < (uint)((iVar6 - *piVar1) / 0xc)) {
      iVar6 = *(int *)(extraout_ECX + 8);
      iVar4 = *piVar1;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if ((iVar6 - iVar4) / 0xc != 0) {
        iVar6 = 0;
        do {
          if (*(int *)(unaff_EBP + -0x10) == (int)*(short *)(unaff_EBP + 8)) {
            if (-1 < *(short *)(unaff_EBP + 0xc)) {
              sVar2 = *(short *)(*piVar1 + 8 + iVar6);
              iVar4 = *piVar1 + iVar6;
              if ((int)sVar2 == (int)*(short *)(unaff_EBP + 0xc) ||
                  (int)sVar2 - (int)*(short *)(unaff_EBP + 0xc) < 0) {
                *(undefined2 *)(iVar4 + 8) = 0;
              }
              else {
                *(short *)(iVar4 + 8) = sVar2 - (short)*(undefined4 *)(unaff_EBP + 0xc);
              }
              iVar4 = *piVar1;
              if (0 < *(short *)(iVar6 + 8 + iVar4)) goto LAB_0041f60d;
            }
          }
          else {
            iVar4 = *piVar1;
LAB_0041f60d:
            FUN_0041f7ca(iVar4 + iVar6);
          }
          iVar4 = *(int *)(extraout_ECX + 8);
          iVar3 = *piVar1;
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          iVar6 = iVar6 + 0xc;
        } while (*(uint *)(unaff_EBP + -0x10) < (uint)((iVar4 - iVar3) / 0xc));
      }
      FUN_0041f957(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      uVar5 = 1;
    }
    else {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    FUN_004d6053();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

