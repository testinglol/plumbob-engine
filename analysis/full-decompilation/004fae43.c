
void FUN_004fae43(void)

{
  undefined4 uVar1;
  int iVar2;
  LPCSTR pCVar3;
  DWORD DVar4;
  uint dwFileAttributes;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x110,0,0x104);
  *(undefined ***)(unaff_EBP + -0x11c) = &PTR_FUN_006664e8;
  uVar1 = FUN_0041532c(0x57,0,unaff_EBP + -0x11c);
  FUN_004eea6b(uVar1);
  FUN_004de865(unaff_EBP + -0x11c,&DAT_006cbf64);
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
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

