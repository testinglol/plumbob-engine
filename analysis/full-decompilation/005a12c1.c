
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a12c1(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar3 = _DAT_0066745c;
  *(undefined4 *)(unaff_EBP + -0x20) = _DAT_0066745c;
  *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x28) = uVar3;
  uVar3 = FUN_00462bc9(unaff_EBP + -0x28,unaff_EBP + -0x24,unaff_EBP + -0x20);
  FUN_00462be8(uVar3);
  uVar3 = _DAT_00667458;
  *(undefined4 *)(unaff_EBP + -0x2c) = _DAT_00667458;
  *(undefined4 *)(unaff_EBP + -0x30) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
  uVar3 = FUN_00462bc9(unaff_EBP + -0x34,unaff_EBP + -0x30,unaff_EBP + -0x2c);
  FUN_00462be8(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  iVar5 = *(int *)(extraout_ECX + 4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(int *)(unaff_EBP + -0x1c) = *(int *)(iVar5 + 0x8c) - *(int *)(iVar5 + 0x88) >> 2;
  iVar5 = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  if (0 < *(int *)(unaff_EBP + -0x1c)) {
    do {
      iVar5 = *(int *)(*(int *)(*(int *)(extraout_ECX + 4) + 0x88) + iVar5 * 4);
      iVar4 = (*(int *)(iVar5 + 0xc) - *(int *)(iVar5 + 8)) / 0xc;
      if (0 < iVar4) {
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        *(int *)(unaff_EBP + -0x14) = iVar4;
        do {
          if ((uint)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x10) + *(int *)(iVar5 + 8)) + 0xc) ==
                    0) != *(uint *)(unaff_EBP + 8)) {
            iVar4 = *(int *)(*(int *)(unaff_EBP + -0x10) + 8 + *(int *)(iVar5 + 8));
            if (*(int *)(iVar4 + 0xc) != 0) {
              FUN_005a2404(iVar4 + 0xc);
            }
            cVar2 = FUN_00599cd3();
            if (cVar2 != '\0') {
              FUN_00599c53(0);
              cVar2 = FUN_0059a443();
              if (cVar2 == '\0') {
                FUN_005c73b0();
              }
              piVar1 = (int *)(*(int *)(extraout_ECX + 4) + 0xb4);
              *piVar1 = *piVar1 + 1;
            }
          }
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0xc;
          piVar1 = (int *)(unaff_EBP + -0x14);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
      iVar5 = *(int *)(unaff_EBP + -0x18) + 1;
      *(int *)(unaff_EBP + -0x18) = iVar5;
    } while (iVar5 < *(int *)(unaff_EBP + -0x1c));
  }
  cVar2 = FUN_0059a443();
  if (cVar2 == '\0') {
    iVar4 = *(int *)(unaff_EBP + -0x3c);
    for (iVar5 = *(int *)(unaff_EBP + -0x40); iVar5 != iVar4; iVar5 = iVar5 + 4) {
      FUN_00463049(unaff_EBP + -0x70);
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

