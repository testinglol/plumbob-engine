
uint FUN_0053a1d4(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  uVar4 = FUN_00634c24();
  if (*(char *)(unaff_EBP + 8) != '\0') {
    uVar5 = FUN_004cfe7a();
    FUN_005d4956(uVar5);
    iVar1 = *(int *)(extraout_ECX + 0x1d0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar3 = FUN_005d49dc(iVar1 + 0x4c);
    if (cVar3 == '\0') {
      uVar5 = FUN_004cfe7a();
      FUN_005d4956(uVar5);
      piVar2 = *(int **)(extraout_ECX + 0x1d0);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      (**(code **)(*piVar2 + 0x9c))(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    uVar4 = FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4 & 0xffffff00;
}

