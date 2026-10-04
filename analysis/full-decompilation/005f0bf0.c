
undefined4 FUN_005f0bf0(void)

{
  DWORD DVar1;
  char *pcVar2;
  LPSTR pCVar3;
  char cVar4;
  undefined1 uVar5;
  DWORD DVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 extraout_ECX;
  LPSTR lpReturnedString;
  int unaff_EBP;
  uint uVar9;
  uint nSize;
  
  FUN_00634c24();
  lpReturnedString = (LPSTR)0x0;
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  uVar9 = 0;
  do {
    nSize = uVar9 + 0x800;
    FUN_006321f0(lpReturnedString);
    lpReturnedString = operator_new(nSize);
    DVar6 = GetPrivateProfileStringA
                      ((LPCSTR)**(undefined4 **)(unaff_EBP + 8),(LPCSTR)0x0,s_NO_ENTRIES_006d7b80,
                       lpReturnedString,nSize,*(LPCSTR *)(*(int *)(unaff_EBP + -0x14) + 4));
    DVar1 = uVar9 + 0x7fe;
    uVar9 = nSize;
  } while (DVar1 == DVar6);
  uVar7 = FUN_005d4956(lpReturnedString);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar4 = FUN_00460748(uVar7,s_NO_ENTRIES_006d7b80);
  if ((cVar4 == '\0') && (lpReturnedString != (LPSTR)0x0)) {
    uVar7 = FUN_005d4956(lpReturnedString);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar5 = FUN_00460748(uVar7,&DAT_006de560);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined1 *)(unaff_EBP + -0xd) = uVar5;
    FUN_005b8770();
    if (*(char *)(unaff_EBP + -0xd) == '\0') {
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      goto LAB_005f0c9d;
    }
  }
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
LAB_005f0c9d:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  if (*(char *)(unaff_EBP + -0xd) == '\0') {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_005d48d9();
    cVar4 = *lpReturnedString;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    pCVar3 = lpReturnedString;
    while (cVar4 != '\0') {
      FUN_005d4bbf(pCVar3);
      cVar4 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x10))
                        (*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x20,unaff_EBP + -0x2c);
      if (cVar4 != '\0') {
        (**(code **)(unaff_EBP + 0xc))
                  (unaff_EBP + -0x20,unaff_EBP + -0x2c,*(undefined4 *)(unaff_EBP + 0x10));
      }
      iVar8 = (*(code *)PTR__strlen_006d7028)(pCVar3);
      pcVar2 = pCVar3 + iVar8 + 1;
      pCVar3 = pCVar3 + iVar8 + 1;
      cVar4 = *pcVar2;
    }
    FUN_006321f0(lpReturnedString);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar7 = 1;
  }
  else {
    FUN_006321f0(lpReturnedString);
    uVar7 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

