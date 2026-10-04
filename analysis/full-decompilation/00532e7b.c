
undefined4 FUN_00532e7b(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int iVar4;
  int unaff_EBP;
  char *pcVar5;
  
  FUN_00634c24();
  piVar1 = DAT_006f2a9c;
  iVar4 = *(int *)(extraout_ECX + 0x20);
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(extraout_ECX + 0x1c);
  cVar2 = FUN_004cff80();
  if (cVar2 != '\0') {
    iVar4 = iVar4 + 5;
  }
  (**(code **)(*piVar1 + 0x68))
            (*(int *)(extraout_ECX + 0xd4),
             *(int *)(extraout_ECX + 0xd8) - *(int *)(extraout_ECX + 0xd4));
  (**(code **)(*piVar1 + 0x58))();
  (**(code **)(*piVar1 + 0x78))
            (*(undefined4 *)(extraout_ECX + 0x5c),*(undefined4 *)(unaff_EBP + -0x28),iVar4,
             *(int *)(extraout_ECX + 0xd4),
             *(int *)(extraout_ECX + 0xd8) - *(int *)(extraout_ECX + 0xd4),0,0,0);
  uVar3 = FUN_004e99a9();
  iVar4 = FUN_004ea85e(uVar3);
  pcVar5 = s_No_cJob_Object__006ccdc0;
  if (iVar4 != 0) {
    uVar3 = FUN_004e99a9();
    iVar4 = FUN_004ea9c8(uVar3);
    pcVar5 = (char *)FUN_004034e6(iVar4);
    if (iVar4 < 10) {
      FUN_005307d9();
    }
    else {
      FUN_005307ab(0x14d);
    }
  }
  if (*(int *)(extraout_ECX + 0xf8) != 0) {
    cVar2 = FUN_0053308c(pcVar5,*(int *)(extraout_ECX + 0xf8) + 0x4c);
    if (cVar2 == '\0') {
      FUN_005d4956(pcVar5);
      piVar1 = *(int **)(extraout_ECX + 0xf8);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(*piVar1 + 0x9c))(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

