
undefined4 FUN_00416375(void)

{
  short sVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar2 = *(uint *)(unaff_EBP + 0xc);
  if (*(int *)(extraout_ECX + 0x10) != 0) {
    FUN_00407664(*(undefined4 *)(unaff_EBP + 8),uVar2);
  }
  sVar1 = *(short *)(unaff_EBP + 8);
  if (sVar1 < 0xf2) {
    if (sVar1 == 0xf1) {
      FUN_00466c2d(uVar2);
    }
    else if (sVar1 == 0x85) {
      FUN_00466fe4(0);
    }
    else if (sVar1 == 0xdc) {
      puVar3 = (undefined4 *)(extraout_ECX + 0x40);
      iVar5 = 4;
      do {
        *puVar3 = puVar3[-2];
        puVar3[1] = puVar3[-1];
        puVar3 = puVar3 + 2;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      *(undefined4 *)(extraout_ECX + 0x38) = *(undefined4 *)(extraout_ECX + 0x60);
      *(undefined4 *)(extraout_ECX + 0x3c) = *(undefined4 *)(extraout_ECX + 100);
      *(undefined4 *)(extraout_ECX + 0x60) = 0;
      *(undefined4 *)(extraout_ECX + 100) = 0;
      FUN_0041607b();
    }
    else if (sVar1 == 0xdd) {
      FUN_00466c7b();
    }
    else if (sVar1 == 0xe2) {
      iVar5 = *(int *)(extraout_ECX + 0x14);
      if ((0 < (int)uVar2) && (uVar2 < (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U))
      {
        iVar5 = *(int *)(*(int *)(iVar5 + 0x18) + -4 + uVar2 * 4);
        if ((iVar5 != 0) && (*(short *)(*(int *)(iVar5 + 0x118) + 0x12) == 2)) {
          FUN_0042a2fe();
        }
      }
    }
    else {
      if (sVar1 != 0xf0) goto LAB_004164b1;
      FUN_00442699(uVar2);
      FUN_00466d14(uVar2);
    }
  }
  else if (sVar1 == 0xf3) {
    if (uVar2 != 0xfffb) {
      FUN_00466bdf(uVar2);
    }
  }
  else if (sVar1 == 0x103) {
    if (uVar2 == (int)*(short *)(*(int *)(extraout_ECX + 0x20) + 0x22)) {
      FUN_0046dae0(9,0);
      uVar4 = FUN_00425db3(0);
      *(undefined4 *)(extraout_ECX + 0x10) = uVar4;
    }
  }
  else if (sVar1 == 0x106) {
    *(undefined1 *)(unaff_EBP + 10) = 0;
    *(char *)(unaff_EBP + 8) = (char)uVar2;
    *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)(unaff_EBP + 0xe);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00467545(unaff_EBP + 8);
  }
  else {
    if (sVar1 != 0x3f4) {
LAB_004164b1:
      uVar4 = 0;
      goto LAB_00416519;
    }
    FUN_00467032();
  }
  uVar4 = 1;
LAB_00416519:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

