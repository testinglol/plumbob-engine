
void FUN_004443eb(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x274) = extraout_ECX;
  if ((*(byte *)(*(int *)(unaff_EBP + 0x10) + 5) & 0x7f) == 5) {
    pvVar1 = operator_new(0x1f8);
    *(void **)(unaff_EBP + -0x2c) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*(int *)(unaff_EBP + -0x2c) == 0) {
      *(undefined4 *)(unaff_EBP + -0x278) = 0;
    }
    else {
      uVar2 = FUN_00549f7f(0);
      *(undefined4 *)(unaff_EBP + -0x278) = uVar2;
    }
    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x278);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x10);
    FUN_00448554(unaff_EBP + -0x30);
  }
  else if ((*(byte *)(*(int *)(unaff_EBP + 0x10) + 5) & 0x7f) == 8) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if ((*(ushort *)(DAT_006e486c + 0x66) & 0x20) == 0) {
      pvVar1 = operator_new(0x1b0);
      *(void **)(unaff_EBP + -0x40) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (*(int *)(unaff_EBP + -0x40) == 0) {
        *(undefined4 *)(unaff_EBP + -0x280) = 0;
      }
      else {
        uVar2 = FUN_004425e8(0);
        *(undefined4 *)(unaff_EBP + -0x280) = uVar2;
      }
      *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x280);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x3c);
    }
    else {
      pvVar1 = operator_new(0x20c);
      *(void **)(unaff_EBP + -0x38) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (*(int *)(unaff_EBP + -0x38) == 0) {
        *(undefined4 *)(unaff_EBP + -0x27c) = 0;
      }
      else {
        uVar2 = FUN_005569af(0);
        *(undefined4 *)(unaff_EBP + -0x27c) = uVar2;
      }
      *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x27c);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x34);
    }
    *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x14);
    FUN_00448554(unaff_EBP + -0x44);
  }
  else if ((*(byte *)(*(int *)(unaff_EBP + 0x10) + 5) & 0x7f) == 7) {
    pvVar1 = operator_new(0x200);
    *(void **)(unaff_EBP + -0x4c) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    if (*(int *)(unaff_EBP + -0x4c) == 0) {
      *(undefined4 *)(unaff_EBP + -0x284) = 0;
    }
    else {
      uVar2 = FUN_00568898(0);
      *(undefined4 *)(unaff_EBP + -0x284) = uVar2;
    }
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x284);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x48);
    *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x18);
    FUN_00448554(unaff_EBP + -0x50);
  }
  else if ((*(byte *)(*(int *)(unaff_EBP + 0x10) + 5) & 0x7f) == 0xb) {
    pvVar1 = operator_new(0x478);
    *(void **)(unaff_EBP + -0x58) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    if (*(int *)(unaff_EBP + -0x58) == 0) {
      *(undefined4 *)(unaff_EBP + -0x288) = 0;
    }
    else {
      uVar2 = FUN_00564664(0);
      *(undefined4 *)(unaff_EBP + -0x288) = uVar2;
    }
    *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x288);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x54);
    *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x1c);
    FUN_00448554(unaff_EBP + -0x5c);
  }
  else if ((*(byte *)(*(int *)(unaff_EBP + 0x10) + 5) & 0x7f) == 0xd) {
    pvVar1 = operator_new(0x1f0);
    *(void **)(unaff_EBP + -100) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    if (*(int *)(unaff_EBP + -100) == 0) {
      *(undefined4 *)(unaff_EBP + -0x28c) = 0;
    }
    else {
      uVar2 = FUN_00551513(0);
      *(undefined4 *)(unaff_EBP + -0x28c) = uVar2;
    }
    *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x28c);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x60);
    *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x20);
    FUN_00448554(unaff_EBP + -0x68);
  }
  else {
    pvVar1 = operator_new(0x78);
    *(void **)(unaff_EBP + -0x70) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    if (*(int *)(unaff_EBP + -0x70) == 0) {
      *(undefined4 *)(unaff_EBP + -0x290) = 0;
    }
    else {
      uVar2 = FUN_00435e2f(*(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x290) = uVar2;
    }
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x290);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x6c);
    FUN_004360c1(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
    FUN_00448554(unaff_EBP + -0x24);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

