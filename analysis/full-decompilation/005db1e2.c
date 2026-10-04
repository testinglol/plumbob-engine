
void __fastcall FUN_005db1e2(int param_1)

{
  uint uVar1;
  BOOL BVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  HWND hWnd;
  tagMSG local_1c;
  
  hWnd = *(HWND *)(param_1 + 0x40);
  while (BVar2 = PeekMessageA(&local_1c,hWnd,0x100,0x108,1), BVar2 != 0) {
    hWnd = *(HWND *)(param_1 + 0x40);
  }
  do {
    BVar2 = PeekMessageA(&local_1c,*(HWND *)(param_1 + 0x40),0x200,0x20a,1);
  } while (BVar2 != 0);
  piVar4 = (int *)(param_1 + 0x154);
  uVar3 = 0;
  if ((*(int *)(param_1 + 0x158) - *piVar4) / 0x14 != 0) {
    iVar5 = 0;
    do {
      uVar1 = *(uint *)(*piVar4 + iVar5 + 4);
      if (((6 < uVar1) && (uVar1 < 0x10)) || ((3 < uVar1 && (uVar1 < 7)))) {
        FUN_005db35d(*piVar4 + iVar5);
        uVar3 = uVar3 - 1;
        iVar5 = iVar5 + -0x14;
      }
      uVar3 = uVar3 + 1;
      iVar5 = iVar5 + 0x14;
    } while (uVar3 < (uint)((*(int *)(param_1 + 0x158) - *piVar4) / 0x14));
  }
  return;
}

