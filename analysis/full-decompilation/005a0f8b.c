
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a0f8b(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(unaff_EBP + 8) == '\0') {
    cVar2 = FUN_00599544();
    if (cVar2 != '\0') goto LAB_005a1276;
  }
  iVar5 = *(int *)(extraout_ECX + 4);
  _vector_constructor_iterator_
            ((void *)(unaff_EBP + -0x58),0xc,2,(_func_void_ptr_void_ptr *)&LAB_005a1287);
  FUN_00462be8(iVar5 + 0xbc);
  FUN_00462be8(iVar5 + 200);
  iVar5 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar5 = *(int *)(iVar5 + 0x8c) - *(int *)(iVar5 + 0x88) >> 2;
  *(int *)(unaff_EBP + -0x14) = iVar5;
  uVar3 = _DAT_0066745c;
  if (iVar5 == 0) {
    cVar2 = FUN_0059a443();
    uVar3 = _DAT_0066745c;
    if (cVar2 == '\0') {
      iVar5 = *(int *)(extraout_ECX + 4);
      *(undefined4 *)(iVar5 + 0xc4) = _DAT_0066745c;
      *(undefined4 *)(iVar5 + 0xc0) = uVar3;
      *(undefined4 *)(iVar5 + 0xbc) = uVar3;
      uVar3 = _DAT_00667458;
      *(undefined4 *)(iVar5 + 0xd0) = _DAT_00667458;
      *(undefined4 *)(iVar5 + 0xcc) = uVar3;
      *(undefined4 *)(iVar5 + 200) = uVar3;
      FUN_00599556();
      uVar3 = _DAT_0066745c;
      *(undefined4 *)(unaff_EBP + 8) = _DAT_0066745c;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
      uVar3 = FUN_00462bc9(unaff_EBP + -0x18,unaff_EBP + -0x14,unaff_EBP + 8);
      FUN_00462be8(uVar3);
      uVar3 = _DAT_00667458;
      *(undefined4 *)(unaff_EBP + -0x10) = _DAT_00667458;
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
      *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
      uVar3 = FUN_00462bc9(unaff_EBP + -0x20,unaff_EBP + -0x1c,unaff_EBP + -0x10);
      FUN_00462be8(uVar3);
      FUN_005a0e57(unaff_EBP + -0xa0);
    }
    cVar2 = FUN_005995eb();
    if (cVar2 == '\0') {
      FUN_005995c6();
    }
    cVar2 = FUN_00599544();
    if (cVar2 == '\0') {
      FUN_0059951f();
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = _DAT_0066745c;
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
    *(undefined4 *)(unaff_EBP + -0x40) = uVar3;
    uVar3 = FUN_00462bc9(unaff_EBP + -0x40,unaff_EBP + -0x1c,unaff_EBP + -0x20);
    FUN_00462be8(uVar3);
    uVar3 = _DAT_00667458;
    *(undefined4 *)(unaff_EBP + -0x38) = _DAT_00667458;
    *(undefined4 *)(unaff_EBP + -0x30) = uVar3;
    *(undefined4 *)(unaff_EBP + -0x3c) = uVar3;
    uVar3 = FUN_00462bc9(unaff_EBP + -0x3c,unaff_EBP + -0x30,unaff_EBP + -0x38);
    FUN_00462be8(uVar3);
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    if (0 < *(int *)(unaff_EBP + -0x14)) {
      do {
        iVar5 = *(int *)(*(int *)(*(int *)(extraout_ECX + 4) + 0x88) + *(int *)(unaff_EBP + 8) * 4);
        iVar4 = (*(int *)(iVar5 + 0xc) - *(int *)(iVar5 + 8)) / 0xc;
        if (0 < iVar4) {
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          *(int *)(unaff_EBP + -0x18) = iVar4;
          do {
            iVar4 = *(int *)(*(int *)(unaff_EBP + -0x10) + 8 + *(int *)(iVar5 + 8));
            *(int *)(unaff_EBP + -0x34) = iVar4;
            if (*(int *)(iVar4 + 0xc) != 0) {
              FUN_005a2404(iVar4 + 0xc);
            }
            uVar3 = _DAT_0066745c;
            *(undefined4 *)(iVar4 + 0x24) = _DAT_0066745c;
            *(undefined4 *)(iVar4 + 0x20) = uVar3;
            *(undefined4 *)(iVar4 + 0x1c) = uVar3;
            uVar3 = _DAT_00667458;
            *(undefined4 *)(iVar4 + 0x30) = _DAT_00667458;
            *(undefined4 *)(iVar4 + 0x2c) = uVar3;
            *(undefined4 *)(iVar4 + 0x28) = uVar3;
            FUN_00599c53(0);
            cVar2 = FUN_0059a443();
            if (cVar2 == '\0') {
              FUN_005c73b0();
            }
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0xc;
            piVar1 = (int *)(unaff_EBP + -0x18);
            *piVar1 = *piVar1 + -1;
          } while (*piVar1 != 0);
        }
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x14));
    }
    FUN_0059951f();
    cVar2 = FUN_0059a443();
    if (cVar2 == '\0') {
      FUN_005a128a(unaff_EBP + -0x70);
      FUN_005a0e57(unaff_EBP + -0x70);
      iVar4 = *(int *)(unaff_EBP + -0x28);
      for (iVar5 = *(int *)(unaff_EBP + -0x2c); iVar5 != iVar4; iVar5 = iVar5 + 4) {
        FUN_00463049(unaff_EBP + -0x70);
      }
    }
    else {
      FUN_005a128a(unaff_EBP + -0x58);
      FUN_005a0e57(unaff_EBP + -0x58);
      iVar4 = *(int *)(unaff_EBP + -0x28);
      for (iVar5 = *(int *)(unaff_EBP + -0x2c); iVar5 != iVar4; iVar5 = iVar5 + 4) {
        FUN_00463049(unaff_EBP + -0x58);
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0048c4c9();
  }
LAB_005a1276:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

