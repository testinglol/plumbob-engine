
bool FUN_005bf6e7(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  LPCSTR lpFileName;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006fe590 == (code *)0x0) {
    FUN_004dc9d9();
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005c0622(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x2c,0xffffffff);
    lpFileName = (LPCSTR)FUN_00401f73();
    iVar3 = DeleteFileA(lpFileName);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x2c) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  else {
    puVar2 = (undefined4 *)FUN_005be30b(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 8));
    uVar1 = *puVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar3 = (*DAT_006fe590)(uVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005bdc4a();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3 != 0;
}

