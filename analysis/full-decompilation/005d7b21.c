
void FUN_005d7b21(void)

{
  undefined4 uVar1;
  BOOL BVar2;
  int iVar3;
  HGLOBAL hMem;
  LPVOID pvVar4;
  int unaff_EBP;
  uint uVar5;
  
  FUN_00634c24();
  if (*(char *)(DAT_006fe8f4 + 0x1f0) != '\0') {
    uVar1 = FUN_005db0bf();
    FUN_005b86bd(uVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    BVar2 = OpenClipboard(*(HWND *)(unaff_EBP + 8));
    if (BVar2 != 0) {
      EmptyClipboard();
      iVar3 = *(int *)(unaff_EBP + -0x14);
      uVar5 = 0;
      if (iVar3 != *(int *)(unaff_EBP + -0x18)) {
        do {
          if (*(char *)(uVar5 + *(int *)(unaff_EBP + -0x18)) == '\n') {
            FUN_004015e4(0xd);
            iVar3 = *(int *)(unaff_EBP + -0x14);
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < (uint)(iVar3 - *(int *)(unaff_EBP + -0x18)));
      }
      hMem = GlobalAlloc(0x2002,(iVar3 - *(int *)(unaff_EBP + -0x18)) + 1);
      if (hMem != (HGLOBAL)0x0) {
        pvVar4 = GlobalLock(hMem);
        if (pvVar4 != (LPVOID)0x0) {
          FUN_00636510(pvVar4,*(undefined4 *)(unaff_EBP + -0x18),
                       (*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)) + 1);
          GlobalUnlock(hMem);
          SetClipboardData(1,hMem);
        }
      }
    }
    CloseClipboard();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

