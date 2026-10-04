
void FUN_004e8b76(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = DAT_006f2648;
  if (DAT_006f2654 != '\0') {
    for (; piVar1 != DAT_006f264c; piVar1 = piVar1 + 0x11) {
      piVar1[2] = 0;
    }
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    iVar2 = FUN_0043ad1f(0);
    piVar1 = DAT_006f2648;
    while (DAT_006f2648 = piVar1, iVar2 != 0) {
      if (*(short *)(*(int *)(iVar2 + 0x60) + 0x12) == 2) {
        if (piVar1 != DAT_006f264c) {
          do {
            iVar2 = FUN_0045741b();
            if (*piVar1 == iVar2) {
              iVar2 = ((int)piVar1 - (int)DAT_006f2648) / 0x44;
              goto LAB_004e8bfa;
            }
            piVar1 = piVar1 + 0x11;
          } while (piVar1 != DAT_006f264c);
        }
        iVar2 = -1;
LAB_004e8bfa:
        if (iVar2 == -1) {
          uVar3 = FUN_0045741b();
          uVar3 = FUN_004e8a46(uVar3);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_004eb2b2(uVar3);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_00635f6d(unaff_EBP + -0x48,8,7,&LAB_004e8a75);
        }
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      iVar2 = FUN_0043ad1f(*(undefined4 *)(unaff_EBP + -0x10));
      piVar1 = DAT_006f2648;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

