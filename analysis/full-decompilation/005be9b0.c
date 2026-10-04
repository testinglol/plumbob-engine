
undefined4 FUN_005be9b0(void)

{
  char cVar1;
  int iVar2;
  HANDLE pvVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  LPCSTR lpFileName;
  DWORD dwDesiredAccess;
  DWORD dwShareMode;
  DWORD DVar5;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 0x10))();
  if (cVar1 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    if ((*(byte *)(unaff_EBP + 8) & 1) != 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0x80000000;
    }
    if ((*(byte *)(unaff_EBP + 8) & 2) != 0) {
      *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) | 0x40;
    }
    if ((*(byte *)(unaff_EBP + 0x10) & 1) != 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
    }
    if ((*(byte *)(unaff_EBP + 0x10) & 2) != 0) {
      *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 3;
    }
    iVar2 = *(int *)(unaff_EBP + 0xc);
    if (iVar2 == 0) {
      DVar5 = 1;
LAB_005bea31:
      if (DAT_006fe580 == (code *)0x0) {
        FUN_004dc9d9();
        *(undefined4 *)(unaff_EBP + -4) = 3;
        FUN_005c0622(extraout_ECX + 1,unaff_EBP + -0x40,0xffffffff);
        iVar2 = FUN_005be418(*(undefined4 *)(unaff_EBP + -0x3c),unaff_EBP + -0x148,0x104);
        if ((iVar2 == 0) || (iVar2 == -1)) {
          dwShareMode = *(DWORD *)(unaff_EBP + -0x10);
          dwDesiredAccess = *(DWORD *)(unaff_EBP + -0x14);
          lpFileName = *(LPCSTR *)(unaff_EBP + -0x3c);
        }
        else {
          dwShareMode = *(DWORD *)(unaff_EBP + -0x10);
          lpFileName = (LPCSTR)(unaff_EBP + -0x148);
          dwDesiredAccess = *(DWORD *)(unaff_EBP + -0x14);
        }
        pvVar3 = CreateFileA(lpFileName,dwDesiredAccess,dwShareMode,(LPSECURITY_ATTRIBUTES)0x0,DVar5
                             ,0,(HANDLE)0x0);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[7] = (int)pvVar3;
        *(undefined ***)(unaff_EBP + -0x40) = &PTR_LAB_0066933c;
        FUN_00401729();
      }
      else {
        FUN_005be30b(unaff_EBP + -0x2c,extraout_ECX + 1);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        FUN_005bfbfb(8);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005bfb53();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        cVar1 = FUN_005be5c9(unaff_EBP + -0x2c,unaff_EBP + -0x20);
        if (cVar1 != '\0') {
          FUN_005bfaad(unaff_EBP + -0x20);
        }
        iVar2 = (*DAT_006fe580)(*(undefined4 *)(unaff_EBP + -0x2c),
                                *(undefined4 *)(unaff_EBP + -0x14),
                                *(undefined4 *)(unaff_EBP + -0x10),0,DVar5,0,0);
        extraout_ECX[7] = iVar2;
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005bdc4a();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005bdc4a();
      }
      if (extraout_ECX[7] != -1) {
        *(undefined1 *)(extraout_ECX + 6) = 1;
        if ((DVar5 == 2) || (DVar5 == 4)) {
          FUN_005bfa81();
        }
        extraout_ECX[8] = *(int *)(unaff_EBP + 8);
        extraout_ECX[9] = *(int *)(unaff_EBP + 0xc);
        extraout_ECX[10] = *(int *)(unaff_EBP + 0x10);
        DVar5 = SetFilePointer((HANDLE)extraout_ECX[7],0,(PLONG)0x0,1);
        extraout_ECX[0x13] = DVar5;
        extraout_ECX[0x12] = DVar5;
        extraout_ECX[0x18] = 0;
        extraout_ECX[0x19] = 0;
        extraout_ECX[0x1e] = 0;
        extraout_ECX[0x1f] = 0;
        goto LAB_005beb93;
      }
      FUN_005bfa81();
    }
    else {
      if (iVar2 == 1) {
        DVar5 = 2;
        goto LAB_005bea31;
      }
      if (iVar2 == 2) {
        DVar5 = 3;
        goto LAB_005bea31;
      }
      if (iVar2 == 3) {
        DVar5 = 4;
        goto LAB_005bea31;
      }
      if (iVar2 == 4) {
        DVar5 = 5;
        goto LAB_005bea31;
      }
    }
    uVar4 = 0;
  }
  else {
LAB_005beb93:
    uVar4 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

