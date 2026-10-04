
void FUN_005ba499(void)

{
  byte bVar1;
  char cVar2;
  HANDLE hFindFile;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int unaff_EBP;
  int iStack_20c;
  int iStack_208;
  int iStack_204;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b9589();
  iStack_204 = unaff_EBP + -0xac;
  iStack_208 = 0x5ba4d2;
  FUN_00412a04();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b86bd();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401729();
  iStack_204 = 0x5ba501;
  hFindFile = FindFirstFileA(*(LPCSTR *)(unaff_EBP + -0x18),(LPWIN32_FIND_DATAA)(unaff_EBP + -0x1f8)
                            );
  *(HANDLE *)(unaff_EBP + -0x24) = hFindFile;
  if (hFindFile != (HANDLE)0xffffffff) {
    iStack_204 = 0x5ba51f;
    FindNextFileA(hFindFile,(LPWIN32_FIND_DATAA)(unaff_EBP + -0x1f8));
    iStack_204 = 0x5ba52e;
    FUN_005a509f();
    iVar3 = *(int *)(unaff_EBP + -0x38);
    if (iVar3 == 0) {
      iStack_204 = unaff_EBP + -0x19;
      iStack_208 = 100;
      iStack_20c = 0x5ba54f;
      FUN_005bace3();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005bad33();
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005bb9b7();
      iStack_204 = 0x5ba58e;
      FUN_005bb8cd();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005ba44c();
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005bb5f0();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005481b6();
      if (*(char *)(unaff_EBP + -0x28) == '\0') goto LAB_005ba7e6;
      iVar3 = *(int *)(unaff_EBP + -0x30);
      *(int *)(unaff_EBP + -0x38) = iVar3;
      *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x2c);
    }
    *(int *)(unaff_EBP + -0x20) = iVar3 + 0x10;
    iStack_204 = 0x5ba5d8;
    iVar3 = FindNextFileA(hFindFile,(LPWIN32_FIND_DATAA)(unaff_EBP + -0x1f8));
    while (iVar3 != 0) {
      FUN_005d4bbf();
      FUN_005b9589();
      uVar5 = *(uint *)(unaff_EBP + -0x1f8) >> 4;
      iStack_204 = 0x5ba615;
      FUN_005a509f();
      iVar3 = *(int *)(unaff_EBP + -0x5c);
      if (iVar3 == 0) {
        *(undefined1 *)(unaff_EBP + -0x40) = 0;
        *(undefined1 *)(unaff_EBP + -0x3f) = 0;
        *(undefined1 *)(unaff_EBP + -0x3e) = 0;
        *(undefined4 *)(unaff_EBP + -0x50) = 0;
        *(undefined4 *)(unaff_EBP + -0x4c) = 0;
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
        FUN_005b86bd();
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005bb113();
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_005bb4b8();
        iStack_204 = 0x5ba671;
        FUN_005bb337();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_005b8770();
        if (*(char *)(unaff_EBP + -0x28) == '\0') goto LAB_005ba7e6;
        iVar3 = *(int *)(unaff_EBP + -0x30);
        *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x2c);
        *(int *)(unaff_EBP + -0x5c) = iVar3;
      }
      if ((uVar5 & 1) == 0) {
        iStack_204 = 0x5ba73f;
        FUN_005b87db();
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        FUN_005b890b();
        iStack_204 = 0x5ba755;
        cVar2 = FUN_00460748();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_005b8770();
        if (cVar2 == '\0') {
          *(undefined1 *)(iVar3 + 0x20) = 0;
          bVar1 = *(byte *)(unaff_EBP + -0x1f8);
          *(undefined4 *)(iVar3 + 0x14) = 0;
          *(undefined4 *)(iVar3 + 0x1c) = 0;
          *(undefined1 *)(iVar3 + 0x22) = 0;
          *(byte *)(iVar3 + 0x21) = ~bVar1 & 1;
        }
        else if (*(char *)(unaff_EBP + 0x18) != '\0') {
          iStack_204 = unaff_EBP + -0xb8;
          iStack_208 = 0x5ba786;
          iStack_208 = FUN_00412ab1();
          *(int **)(unaff_EBP + -0x3c) = &iStack_204;
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          iStack_20c = 0x5ba795;
          FUN_005b86bd();
          iStack_208 = 0x5ba79c;
          FUN_005b9c7d();
          *(undefined1 *)(unaff_EBP + -4) = 3;
          goto LAB_005ba724;
        }
      }
      else {
        *(undefined1 *)(iVar3 + 0x20) = 0;
        cVar2 = *(char *)(unaff_EBP + 0x14);
        *(byte *)(iVar3 + 0x21) = ~*(byte *)(unaff_EBP + -0x1f8) & 1;
        *(undefined4 *)(iVar3 + 0x14) = 0;
        *(undefined4 *)(iVar3 + 0x1c) = 0;
        *(byte *)(iVar3 + 0x22) = (byte)uVar5 & 1;
        if (cVar2 != '\0') {
          iStack_204 = unaff_EBP + -0x18;
          iStack_208 = unaff_EBP + 8;
          iStack_20c = unaff_EBP + -0x88;
          uVar4 = FUN_00412ab1();
          *(undefined1 *)(unaff_EBP + -4) = 10;
          uVar4 = FUN_00412cef(unaff_EBP + -0x94,uVar4,0x5c);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          *(int **)(unaff_EBP + -0x3c) = &iStack_20c;
          FUN_005b86bd(uVar4);
          FUN_005ba499();
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_00401729();
          *(undefined1 *)(unaff_EBP + -4) = 3;
LAB_005ba724:
          FUN_00401729();
        }
      }
      iStack_204 = 0x5ba7d8;
      iVar3 = FindNextFileA(*(HANDLE *)(unaff_EBP + -0x24),(LPWIN32_FIND_DATAA)(unaff_EBP + -0x1f8))
      ;
    }
    FindClose(*(HANDLE *)(unaff_EBP + -0x24));
  }
LAB_005ba7e6:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

