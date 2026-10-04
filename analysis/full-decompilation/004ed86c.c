
void FUN_004ed86c(void)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar2 = operator_new(0x34c);
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004ed274();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x10) = iVar3;
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8) = *(undefined4 *)(unaff_EBP + 0xc);
    FUN_004edf2f(*(int *)(unaff_EBP + -0x10) + 0x18,*(undefined4 *)(extraout_ECX + 0x18));
    FUN_004edfba(*(int *)(unaff_EBP + -0x10) + 0x128,*(undefined4 *)(extraout_ECX + 0x18),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
    FUN_004ee0c9(*(int *)(unaff_EBP + -0x10) + 0x238,*(undefined4 *)(extraout_ECX + 0x18));
    *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x348) = *(undefined4 *)(extraout_ECX + 0x18);
    **(undefined4 **)(unaff_EBP + -0x10) = 4;
    FUN_004ee1ee(unaff_EBP + -0x10);
    *(int *)(extraout_ECX + 0x18) = *(int *)(extraout_ECX + 0x18) + 1;
    *(int *)(extraout_ECX + 0x10) =
         (*(int *)(extraout_ECX + 8) - *(int *)(extraout_ECX + 4) >> 2) + -1;
    cVar1 = FUN_004ed555();
    if (cVar1 == '\0') {
      iVar3 = *(int *)(unaff_EBP + -0x10);
      *(int *)(extraout_ECX + 8) = *(int *)(extraout_ECX + 8) + -4;
      if (iVar3 != 0) {
        FUN_004ed447();
        FUN_006321f0(iVar3);
      }
      *(int *)(extraout_ECX + 0x18) = *(int *)(extraout_ECX + 0x18) + -1;
      *(int *)(extraout_ECX + 0x10) =
           (*(int *)(extraout_ECX + 8) - *(int *)(extraout_ECX + 4) >> 2) + -1;
    }
    else {
      **(undefined4 **)(unaff_EBP + -0x10) = 2;
      FUN_004ed482();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

