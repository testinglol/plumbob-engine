
undefined1 FUN_005bf892(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint bFailIfExists;
  LPCSTR lpNewFileName;
  LPCSTR lpExistingFileName;
  BOOL BVar5;
  int unaff_EBP;
  undefined1 uVar6;
  
  FUN_00634c24();
  if (DAT_006fe584 == (code *)0x0) {
    FUN_004dc9d9();
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_004dc9d9();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005c0622(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x4c,0xffffffff);
    FUN_005c0622(*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + -0x38,0xffffffff);
    bFailIfExists = (uint)(*(char *)(unaff_EBP + 0x10) == '\0');
    lpNewFileName = (LPCSTR)FUN_00401f73();
    lpExistingFileName = (LPCSTR)FUN_00401f73();
    BVar5 = CopyFileA(lpExistingFileName,lpNewFileName,bFailIfExists);
    uVar6 = BVar5 != 0;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x38) = &PTR_LAB_0066933c;
    FUN_00401729();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x4c) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  else {
    puVar3 = (undefined4 *)FUN_005be30b(unaff_EBP + -0x24,*(undefined4 *)(unaff_EBP + 0xc));
    uVar1 = *puVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    puVar3 = (undefined4 *)FUN_005be30b(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 8));
    uVar2 = *puVar3;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar4 = (*DAT_006fe584)(uVar2,uVar1,*(char *)(unaff_EBP + 0x10) == '\0');
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(bool *)(unaff_EBP + 0x13) = iVar4 != 0;
    FUN_005bdc4a();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005bdc4a();
    uVar6 = *(undefined1 *)(unaff_EBP + 0x13);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

