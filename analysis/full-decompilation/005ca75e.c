
int FUN_005ca75e(void)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = (**(code **)(**(int **)(extraout_ECX + 0xa4) + 0xc))
                    (*(int **)(extraout_ECX + 0xa4),FUN_005ca911,extraout_ECX);
  *(int *)(extraout_ECX + 4) = iVar1;
  if (-1 < iVar1) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    iVar1 = *(int *)(extraout_ECX + 0x998);
    iVar2 = *(int *)(extraout_ECX + 0x99c);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar1 != iVar2) {
      do {
        if ((*(char *)(iVar1 + 0x2cd) != '\0') && (*(char *)(iVar1 + 0x2cc) != '\0')) {
          FUN_005cb537(iVar1);
        }
        iVar1 = iVar1 + 0x2f0;
      } while (iVar1 != iVar2);
      iVar1 = *(int *)(unaff_EBP + -0x18);
      if (iVar1 != *(int *)(unaff_EBP + -0x14)) {
        if (*(int *)(unaff_EBP + 8) == 0) {
          *(undefined4 **)(unaff_EBP + 8) = &DAT_006772a8;
        }
        do {
          iVar2 = _memcmp(*(void **)(unaff_EBP + 8),(void *)(iVar1 + 700),0x10);
          if (iVar2 == 0) {
            FUN_005ca85e(iVar1);
            iVar1 = (**(code **)**(undefined4 **)(extraout_ECX + 0xa4))
                              (*(undefined4 **)(extraout_ECX + 0xa4),&DAT_006772c8,
                               extraout_ECX + 0xa0);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(int *)(extraout_ECX + 4) = iVar1;
            goto LAB_005ca843;
          }
          iVar1 = iVar1 + 0x2f0;
        } while (iVar1 != *(int *)(unaff_EBP + -0x14));
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar1 = -0x64f4ffe4;
LAB_005ca843:
    FUN_005cb56f();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

