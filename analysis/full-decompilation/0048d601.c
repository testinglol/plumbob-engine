
void FUN_0048d601(void)

{
  short sVar1;
  int iVar2;
  char *pcVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0045fcbd(*(undefined4 *)(extraout_ECX + 0x30),*(undefined4 *)(extraout_ECX + 0x34));
  if ((*(int *)(unaff_EBP + 0xc) != 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    iVar2 = FUN_0048e01d(*(undefined4 *)(unaff_EBP + 0xc));
    *(int *)(unaff_EBP + -0x10) = iVar2;
    if (iVar2 != 0) {
      iVar2 = 1;
      sVar1 = FUN_0046fbe5(0xffffffff);
      if (1 < sVar1) {
        do {
          pcVar3 = (char *)FUN_004705f2((short)iVar2 + 1,0xffffffff);
          if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
            FUN_0041ee31(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),iVar2);
            *(undefined4 *)(unaff_EBP + -4) = 0;
            FUN_00458cd7(unaff_EBP + -0x54);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
          }
          iVar2 = iVar2 + 1;
          sVar1 = FUN_0046fbe5(0xffffffff);
        } while (iVar2 < sVar1);
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

