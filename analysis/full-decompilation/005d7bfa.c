
void FUN_005d7bfa(void)

{
  byte bVar1;
  BOOL BVar2;
  HANDLE hMem;
  LPVOID pvVar3;
  int unaff_EBP;
  uint uVar4;
  
  FUN_00634c24();
  BVar2 = OpenClipboard(*(HWND *)(unaff_EBP + 8));
  if (BVar2 != 0) {
    hMem = GetClipboardData(1);
    if (hMem != (HANDLE)0x0) {
      pvVar3 = GlobalLock(hMem);
      if (pvVar3 != (LPVOID)0x0) {
        FUN_005d4956(pvVar3);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        uVar4 = 0;
        if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + -0x18)) {
          do {
            bVar1 = *(byte *)(uVar4 + *(int *)(unaff_EBP + -0x18));
            if (bVar1 == 0xd) {
LAB_005d7c7b:
              FUN_00406466(uVar4,1);
            }
            else if (bVar1 == 9) {
              FUN_00406466(uVar4,1);
              FUN_005d7d32(uVar4,0x20,4);
            }
            else if ((bVar1 < 0x20) && (bVar1 != 10)) goto LAB_005d7c7b;
            uVar4 = uVar4 + 1;
          } while (uVar4 < (uint)(*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)));
        }
        FUN_005db0c6(unaff_EBP + -0x18,0);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
      }
    }
    CloseClipboard();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

