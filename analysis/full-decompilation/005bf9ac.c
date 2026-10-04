
undefined4 FUN_005bf9ac(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  HANDLE pvVar3;
  LPCSTR lpFileName;
  undefined4 uVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  LPWIN32_FIND_DATAA lpFindFileData;
  
  FUN_00634c24();
  uVar4 = 0xffffffff;
  if (DAT_006fe58c == (code *)0x0) {
    FUN_004dc9d9();
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005c0622(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x20,0xffffffff);
    lpFindFileData = (LPWIN32_FIND_DATAA)(unaff_EBP + -0x16c);
    lpFileName = (LPCSTR)FUN_00401f73();
    pvVar3 = FindFirstFileA(lpFileName,lpFindFileData);
    if (pvVar3 != (HANDLE)0xffffffff) {
      uVar4 = *(undefined4 *)(unaff_EBP + -0x14c);
      FindClose(pvVar3);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  else {
    puVar2 = (undefined4 *)FUN_005be30b(unaff_EBP + -0x2c,*(undefined4 *)(unaff_EBP + 8));
    uVar1 = *puVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pvVar3 = (HANDLE)(*DAT_006fe58c)(uVar1,unaff_EBP + -0x3bc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005bdc4a();
    if (pvVar3 != (HANDLE)0xffffffff) {
      uVar4 = *(undefined4 *)(unaff_EBP + -0x39c);
      FindClose(pvVar3);
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar4;
}

