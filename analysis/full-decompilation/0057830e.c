
bool FUN_0057830e(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  uVar2 = FUN_00401742(0xc);
  *(undefined4 *)(unaff_EBP + -0x28) = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(int *)(*(int *)(unaff_EBP + -0x28) + 4) = *(int *)(unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = _rand();
  iVar7 = extraout_ECX[0x11];
  *(uint *)(unaff_EBP + -0x18) = uVar3 >> 8 & 0xff;
  iVar8 = extraout_ECX[0x1e];
  *(uint *)(unaff_EBP + -0x10) = uVar3 & 0xff;
  iVar4 = iVar7 - iVar8;
  *(int *)(unaff_EBP + -0x2c) = iVar4;
  if (iVar4 < 0) {
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  }
  iVar4 = extraout_ECX[0x12];
  iVar1 = extraout_ECX[0x1d];
  iVar5 = iVar4 - iVar1;
  *(int *)(unaff_EBP + -0x24) = iVar5;
  if (iVar5 < 0) {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
  }
  *(int *)(unaff_EBP + -0x20) = iVar8 + iVar7;
  iVar7 = extraout_ECX[0xd];
  iVar5 = *(int *)(iVar7 + 0x24);
  *(int *)(unaff_EBP + -0x30) = iVar5;
  if (iVar5 <= *(int *)(unaff_EBP + -0x20)) {
    *(int *)(unaff_EBP + -0x20) = iVar5 + -1;
  }
  iVar7 = *(int *)(iVar7 + 0x28);
  iVar4 = iVar1 + iVar4;
  *(int *)(unaff_EBP + -0x1c) = iVar4;
  *(int *)(unaff_EBP + -0x34) = iVar7;
  if (iVar7 <= iVar4) {
    *(int *)(unaff_EBP + -0x1c) = iVar7 + -1;
  }
  *(int *)(unaff_EBP + -0x18) =
       ((int)*(short *)(unaff_EBP + -0x18) % (iVar8 * 2 + 1) - iVar8) + extraout_ECX[0x11];
  iVar7 = ((int)*(short *)(unaff_EBP + -0x10) % (iVar1 * 2 + 1) - iVar1) + extraout_ECX[0x12];
  if (*(int *)(unaff_EBP + -0x18) < 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
  }
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  if (*(int *)(unaff_EBP + -0x30) <= *(int *)(unaff_EBP + -0x18)) {
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x30) + -1;
  }
  if (*(int *)(unaff_EBP + -0x34) <= iVar7) {
    iVar7 = *(int *)(unaff_EBP + -0x34) + -1;
  }
  for (iVar8 = *(int *)(unaff_EBP + -0x18); iVar8 <= *(int *)(unaff_EBP + -0x20); iVar8 = iVar8 + 1)
  {
    *(int *)(unaff_EBP + -0x10) = iVar7;
    if (iVar7 <= *(int *)(unaff_EBP + -0x1c)) {
      do {
        iVar4 = (**(code **)(*extraout_ECX + 0x9c))
                          (iVar8,*(undefined4 *)(unaff_EBP + -0x10),
                           *(undefined4 *)(unaff_EBP + 0x10));
        if (*(int *)(unaff_EBP + -0x14) < iVar4) {
          uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
          *(int *)(unaff_EBP + -0x14) = iVar4;
          **(int **)(unaff_EBP + 8) = iVar8;
          **(undefined4 **)(unaff_EBP + 0xc) = uVar2;
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) <= *(int *)(unaff_EBP + -0x1c));
    }
    iVar4 = *(int *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x10) = iVar4;
    while (iVar4 < iVar7) {
      iVar4 = (**(code **)(*extraout_ECX + 0x9c))
                        (iVar8,*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 0x10))
      ;
      if (*(int *)(unaff_EBP + -0x14) < iVar4) {
        uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
        *(int *)(unaff_EBP + -0x14) = iVar4;
        **(int **)(unaff_EBP + 8) = iVar8;
        **(undefined4 **)(unaff_EBP + 0xc) = uVar2;
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      iVar4 = *(int *)(unaff_EBP + -0x10);
    }
  }
  for (iVar8 = *(int *)(unaff_EBP + -0x2c); iVar8 < *(int *)(unaff_EBP + -0x18); iVar8 = iVar8 + 1)
  {
    *(int *)(unaff_EBP + -0x10) = iVar7;
    if (iVar7 <= *(int *)(unaff_EBP + -0x1c)) {
      do {
        iVar4 = (**(code **)(*extraout_ECX + 0x9c))
                          (iVar8,*(undefined4 *)(unaff_EBP + -0x10),
                           *(undefined4 *)(unaff_EBP + 0x10));
        if (*(int *)(unaff_EBP + -0x14) < iVar4) {
          uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
          *(int *)(unaff_EBP + -0x14) = iVar4;
          **(int **)(unaff_EBP + 8) = iVar8;
          **(undefined4 **)(unaff_EBP + 0xc) = uVar2;
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) <= *(int *)(unaff_EBP + -0x1c));
    }
    iVar4 = *(int *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x10) = iVar4;
    while (iVar4 < iVar7) {
      iVar4 = (**(code **)(*extraout_ECX + 0x9c))
                        (iVar8,*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 0x10))
      ;
      if (*(int *)(unaff_EBP + -0x14) < iVar4) {
        uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
        *(int *)(unaff_EBP + -0x14) = iVar4;
        **(int **)(unaff_EBP + 8) = iVar8;
        **(undefined4 **)(unaff_EBP + 0xc) = uVar2;
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      iVar4 = *(int *)(unaff_EBP + -0x10);
    }
  }
  if ((*(int *)(unaff_EBP + 0x10) == 3) && (*(int *)(unaff_EBP + -0x14) < 2)) {
    for (puVar6 = (undefined4 *)**(undefined4 **)(unaff_EBP + -0x28);
        puVar6 != *(undefined4 **)(unaff_EBP + -0x28); puVar6 = (undefined4 *)*puVar6) {
    }
  }
  iVar7 = *(int *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006029b3();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar7 != 0;
}

