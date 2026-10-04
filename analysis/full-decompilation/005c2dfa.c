
undefined4 * FUN_005c2dfa(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  iVar5 = 0;
  *(undefined4 **)(unaff_EBP + -0x20) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  pcVar1 = *(char **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*pcVar1 == ';') {
    uVar3 = FUN_005b8680();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004d5f61(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    iVar5 = 1;
  }
  do {
    cVar2 = pcVar1[iVar5];
    iVar4 = *(int *)(unaff_EBP + -0x10);
    do {
      *(char *)(unaff_EBP + -0x120 + iVar4) = cVar2;
      cVar2 = pcVar1[iVar5 + 1];
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 1;
      if (cVar2 == ';') break;
    } while (cVar2 != '\0');
    *(undefined1 *)(unaff_EBP + -0x120 + iVar4) = 0;
    FUN_005b870f(unaff_EBP + -0x120);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005c2fef(unaff_EBP + -0x1c);
    FUN_004d5f61(unaff_EBP + -0x1c);
    cVar2 = pcVar1[iVar5];
    if (cVar2 == '\0') {
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return extraout_ECX;
    }
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    if (cVar2 == ';') {
      do {
        iVar4 = iVar5 + 1;
        iVar5 = iVar5 + 1;
        iVar4 = FUN_00636918((int)pcVar1[iVar4]);
      } while (iVar4 != 0);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
  } while( true );
}

