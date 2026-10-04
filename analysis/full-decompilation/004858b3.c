
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004858b3(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x30) = extraout_ECX;
  FUN_00492ad8();
  extraout_ECX[0xb] = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 1;
  extraout_ECX[0xe] = 0xffffffff;
  extraout_ECX[0x1f] = 0xffffffff;
  extraout_ECX[0xf] = 0;
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x12] = 0;
  *(undefined2 *)(extraout_ECX + 0x13) = 0;
  extraout_ECX[0x14] = 0;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  *(undefined1 *)(extraout_ECX + 0x1d) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x75) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x76) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x77) = 0;
  *(undefined1 *)(extraout_ECX + 0x1e) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x79) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x7a) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x7b) = 0;
  *(undefined1 *)(extraout_ECX + 0x20) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x81) = 0;
  extraout_ECX[0x21] = 0;
  *(undefined1 *)(extraout_ECX + 0x22) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x89) = 0;
  extraout_ECX[0x23] = 0;
  extraout_ECX[0x24] = 0;
  *(undefined1 *)(extraout_ECX + 0x25) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x95) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x96) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x97) = 1;
  *(undefined1 *)(extraout_ECX + 0x26) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x99) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x9a) = 0;
  extraout_ECX[0x27] = 0;
  extraout_ECX[0x28] = 0;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x2a] = 0;
  *(undefined1 *)(extraout_ECX + 0x2b) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xad) = 0;
  *extraout_ECX = &PTR_FUN_00667cd0;
  iVar2 = DAT_006e575c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((iVar2 - _DAT_006e5758 & 0xfffffffcU) == 0) {
    iVar2 = FUN_0043ac6a();
    *(int *)(unaff_EBP + -0x2c) = iVar2;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    if (0 < iVar2) {
      do {
        iVar2 = FUN_0043ad1f(*(undefined4 *)(unaff_EBP + 8));
        if (*(short *)(*(int *)(iVar2 + 0x60) + 0x4e) == 0) {
          sVar1 = *(short *)(*(int *)(iVar2 + 0x60) + 0x8a);
          if (sVar1 == 1) {
            uVar3 = FUN_0045741b();
            *(undefined4 *)(unaff_EBP + -0x28) = uVar3;
            iVar2 = unaff_EBP + -0x28;
          }
          else if (sVar1 == 2) {
            uVar3 = FUN_0045741b();
            *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
            iVar2 = unaff_EBP + -0x24;
          }
          else if (sVar1 == 3) {
            uVar3 = FUN_0045741b();
            *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
            iVar2 = unaff_EBP + -0x20;
          }
          else if (sVar1 == 4) {
            uVar3 = FUN_0045741b();
            *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
            iVar2 = unaff_EBP + -0x1c;
          }
          else if (sVar1 == 5) {
            uVar3 = FUN_0045741b();
            *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
            iVar2 = unaff_EBP + -0x18;
          }
          else if (sVar1 == 6) {
            uVar3 = FUN_0045741b();
            *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
            iVar2 = unaff_EBP + -0x14;
          }
          else {
            if (sVar1 != 7) goto LAB_00485a9e;
            uVar3 = FUN_0045741b();
            *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
            iVar2 = unaff_EBP + -0x10;
          }
          FUN_0040555d(iVar2);
        }
LAB_00485a9e:
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x2c));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x28] = 0xfffffff0;
  extraout_ECX[0x27] = 0xfffffff0;
  extraout_ECX[0x2a] = 0xfffffff0;
  extraout_ECX[0x29] = 0xfffffff0;
  return extraout_ECX;
}

