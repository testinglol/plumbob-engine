
undefined4 FUN_005bf41a(void)

{
  undefined4 *puVar1;
  HANDLE pvVar2;
  LPCSTR lpFileName;
  undefined4 uVar3;
  int unaff_EBP;
  bool bVar4;
  DWORD dwDesiredAccess;
  DWORD dwShareMode;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  DWORD dwCreationDisposition;
  DWORD dwFlagsAndAttributes;
  
  FUN_00634c24();
  bVar4 = DAT_006fe580 == (code *)0x0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0xc;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (bVar4) {
    FUN_004dc9d9();
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005c0622(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x38,0xffffffff);
    lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)(unaff_EBP + -0x18);
    pvVar2 = (HANDLE)0x0;
    dwFlagsAndAttributes = 0x80;
    dwCreationDisposition = 4;
    dwShareMode = 3;
    dwDesiredAccess = 0x80000000;
    lpFileName = (LPCSTR)FUN_00401f73();
    pvVar2 = CreateFileA(lpFileName,dwDesiredAccess,dwShareMode,lpSecurityAttributes,
                         dwCreationDisposition,dwFlagsAndAttributes,pvVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x38) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  else {
    puVar1 = (undefined4 *)FUN_005be30b(unaff_EBP + -0x24,*(undefined4 *)(unaff_EBP + 8));
    uVar3 = *puVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pvVar2 = (HANDLE)(*DAT_006fe580)(uVar3,0x80000000,3,unaff_EBP + -0x18,4,0x80,0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005bdc4a();
  }
  if (pvVar2 == (HANDLE)0xffffffff) {
    uVar3 = 0;
  }
  else {
    if (*(char *)(unaff_EBP + 0xc) != '\0') {
      SetFilePointer(pvVar2,0,(PLONG)0x0,0);
      SetEndOfFile(pvVar2);
    }
    CloseHandle(pvVar2);
    uVar3 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

