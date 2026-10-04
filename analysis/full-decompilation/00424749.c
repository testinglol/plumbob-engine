
void FUN_00424749(void)

{
  undefined4 uVar1;
  int iVar2;
  LPCSTR pCVar3;
  DWORD DVar4;
  uint dwFileAttributes;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x18) = &DAT_006de560;
  uVar1 = FUN_0041532c(0x53);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  uVar1 = FUN_0041532c(0x54);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  puVar6 = (undefined4 *)(unaff_EBP + -0x18);
  iVar5 = 3;
  do {
    FUN_0046f824(unaff_EBP + -0x11c,0,0x104);
    *(undefined ***)(unaff_EBP + -0x128) = &PTR_FUN_006664e8;
    FUN_004eea6b(*puVar6,0,unaff_EBP + -0x128);
    FUN_004de865(unaff_EBP + -0x128,&PTR_LAB_006c2584);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    while( true ) {
      iVar2 = FUN_004deaa1();
      if (iVar2 == 0) break;
      pCVar3 = (LPCSTR)FUN_004deaa1();
      DVar4 = GetFileAttributesA(pCVar3);
      dwFileAttributes = DVar4 & 0xfffffffe;
      pCVar3 = (LPCSTR)FUN_004deaa1();
      SetFileAttributesA(pCVar3,dwFileAttributes);
      FUN_004de998();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004de981();
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

