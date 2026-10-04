
bool FUN_0048fb2b(void)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -0x12) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004619d2(unaff_EBP + -0x20);
  piVar1 = *(int **)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *piVar1 = 0;
  puVar3 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + -0x18) = *puVar3;
  FUN_00461b74(puVar3 + 1);
  while( true ) {
    iVar4 = FUN_004619d2(unaff_EBP + -0x28);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    cVar2 = FUN_0046198c(iVar4 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (cVar2 != '\0') break;
    if (*(int *)(extraout_ECX + 0x2c) == 0) {
      pcVar5 = (char *)FUN_00461941(unaff_EBP + 0xc);
      if (0xf < *(byte *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x38) + 0x10) + *pcVar5 * 4) +
                         (int)pcVar5[1])) {
        *piVar1 = *piVar1 + 1;
      }
    }
    else {
      pcVar5 = (char *)FUN_00461941(unaff_EBP + -0x10);
      if (*(byte *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x38) + 0x10) + *pcVar5 * 4) +
                   (int)pcVar5[1]) < 0x10) {
        *piVar1 = *piVar1 + -1;
      }
    }
    FUN_00461961();
  }
  if (*(int *)(extraout_ECX + 0x2c) == 0) {
    iVar4 = *piVar1 * DAT_006c5fe8;
  }
  else {
    iVar4 = 0;
  }
  cVar2 = FUN_00492b81(iVar4);
  if (cVar2 == '\0') {
    *(undefined4 *)(extraout_ECX + 0x54) = 0x19;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return cVar2 != '\0';
}

