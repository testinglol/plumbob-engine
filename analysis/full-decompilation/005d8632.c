
undefined1 FUN_005d8632(void)

{
  undefined *puVar1;
  char cVar2;
  undefined4 uVar3;
  HANDLE pvVar4;
  BOOL BVar5;
  int extraout_ECX;
  undefined1 uVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x24) = extraout_ECX + 0x34;
  uVar3 = FUN_00412ab1(unaff_EBP + -0x78,extraout_ECX + 0x28,extraout_ECX + 0x34);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00401729();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -0x8c) = 0;
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  *(undefined1 *)(unaff_EBP + -0xe) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  pvVar4 = FindFirstFileA(*(LPCSTR *)(unaff_EBP + -0x3c),(LPWIN32_FIND_DATAA)(unaff_EBP + -0x1cc));
  *(HANDLE *)(unaff_EBP + -0x20) = pvVar4;
  if (pvVar4 == (HANDLE)0xffffffff) {
    uVar6 = 0;
    goto LAB_005d89e5;
  }
  if ((*(byte *)(unaff_EBP + -0x1cc) & 0x10) == 0) {
    if ((*(byte *)(unaff_EBP + 0xc) & 8) != 0) {
      uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_00575805(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      goto LAB_005d87e0;
    }
  }
  else if ((*(byte *)(unaff_EBP + 0xc) & 4) != 0) {
    uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
    puVar1 = PTR_DAT_006d71e4;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    cVar2 = FUN_00460748(uVar3,puVar1);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    if (cVar2 == '\0') {
      uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
      puVar1 = PTR_DAT_006d71e8;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      cVar2 = FUN_00460748(uVar3,puVar1);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8770();
      if (cVar2 == '\0') {
        uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_00575805(uVar3);
        *(undefined1 *)(unaff_EBP + -4) = 3;
      }
      else {
        *(undefined1 *)(unaff_EBP + -0xd) = 1;
        if ((*(byte *)(unaff_EBP + 0xc) & 2) == 0) goto LAB_005d87e5;
        uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_00575805(uVar3);
        *(undefined1 *)(unaff_EBP + -4) = 3;
      }
    }
    else {
      *(undefined1 *)(unaff_EBP + -0xe) = 1;
      if ((*(byte *)(unaff_EBP + 0xc) & 1) == 0) goto LAB_005d87e5;
      uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_00575805(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 3;
    }
LAB_005d87e0:
    FUN_005b8770();
  }
LAB_005d87e5:
  pvVar4 = *(HANDLE *)(unaff_EBP + -0x20);
  while( true ) {
    BVar5 = FindNextFileA(pvVar4,(LPWIN32_FIND_DATAA)(unaff_EBP + -0x1cc));
    if (BVar5 == 0) break;
    if ((*(byte *)(unaff_EBP + -0x1cc) & 0x10) == 0) {
      if ((*(byte *)(unaff_EBP + 0xc) & 8) != 0) {
        uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
        *(undefined1 *)(unaff_EBP + -4) = 0xf;
        FUN_00575805(uVar3);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        goto LAB_005d8938;
      }
    }
    else if ((*(byte *)(unaff_EBP + 0xc) & 4) != 0) {
      if (*(char *)(unaff_EBP + -0xe) == '\0') {
        uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
        puVar1 = PTR_DAT_006d71e4;
        *(undefined1 *)(unaff_EBP + -4) = 10;
        cVar2 = FUN_00460748(uVar3,puVar1);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_005b8770();
        if (cVar2 != '\0') {
          *(undefined1 *)(unaff_EBP + -0xe) = 1;
          if ((*(byte *)(unaff_EBP + 0xc) & 1) != 0) {
            uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
            *(undefined1 *)(unaff_EBP + -4) = 0xb;
            FUN_00575805(uVar3);
            *(undefined1 *)(unaff_EBP + -4) = 3;
            goto LAB_005d8938;
          }
          goto LAB_005d893d;
        }
      }
      if (*(char *)(unaff_EBP + -0xd) == '\0') {
        uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
        puVar1 = PTR_DAT_006d71e8;
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        cVar2 = FUN_00460748(uVar3,puVar1);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_005b8770();
        if (cVar2 != '\0') {
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
          if ((*(byte *)(unaff_EBP + 0xc) & 2) != 0) {
            uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
            *(undefined1 *)(unaff_EBP + -4) = 0xd;
            FUN_00575805(uVar3);
            *(undefined1 *)(unaff_EBP + -4) = 3;
            goto LAB_005d8938;
          }
          goto LAB_005d893d;
        }
      }
      uVar3 = FUN_005d4956(unaff_EBP + -0x1a0);
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      FUN_00575805(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 3;
LAB_005d8938:
      FUN_005b8770();
    }
LAB_005d893d:
    pvVar4 = *(HANDLE *)(unaff_EBP + -0x20);
  }
  FindClose(*(HANDLE *)(unaff_EBP + -0x20));
  if (((*(byte *)(unaff_EBP + 0xc) & 2) != 0) && (*(char *)(unaff_EBP + -0xd) == '\0')) {
    cVar2 = FUN_00460748(*(undefined4 *)(unaff_EBP + -0x24),PTR_DAT_006d71e0);
    if (cVar2 != '\0') {
      uVar3 = FUN_005d4956(PTR_DAT_006d71e8);
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      FUN_005757e5(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8770();
    }
  }
  if (((*(byte *)(unaff_EBP + 0xc) & 1) != 0) && (*(char *)(unaff_EBP + -0xe) == '\0')) {
    cVar2 = FUN_00460748(*(undefined4 *)(unaff_EBP + -0x24),PTR_DAT_006d71e0);
    if (cVar2 != '\0') {
      uVar3 = FUN_005d4956(PTR_DAT_006d71e4);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_005757e5(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8770();
    }
  }
  uVar6 = 1;
LAB_005d89e5:
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

