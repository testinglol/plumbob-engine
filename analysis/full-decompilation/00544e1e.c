
undefined1 FUN_00544e1e(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  int *extraout_ECX;
  int iVar9;
  uint uVar10;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar6 = (**(code **)(*extraout_ECX + 200))();
  if (cVar6 == '\0') {
    cVar6 = FUN_005dbf32();
    uVar7 = 0;
    if (cVar6 != '\0') {
      (**(code **)(*extraout_ECX + 0x174))(1,0);
      extraout_ECX[0x4c] = DAT_006f2aa4;
      extraout_ECX[0x4d] = DAT_006f2a9c;
      FUN_005a5631(0x14b4,extraout_ECX + 0x39,4);
      (**(code **)(*extraout_ECX + 0x60))(0,0,0x71,0x7a);
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      FUN_0054821c(5,unaff_EBP + -0xd);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar8 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x20),5,unaff_EBP + -0x14,
                           *(undefined4 *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar8;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      piVar1 = extraout_ECX + 0x36;
      FUN_00520490(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      FUN_0051dfa3(*piVar1,extraout_ECX[0x37] - *piVar1 >> 2,0);
      iVar9 = extraout_ECX[0x37];
      iVar2 = *piVar1;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (iVar9 - iVar2 >> 2 != 0) {
        do {
          iVar9 = *(int *)(unaff_EBP + -0x14) * 4;
          if (*(int *)(iVar9 + *piVar1) != 0) {
            (**(code **)(**(int **)(iVar9 + *piVar1) + 0x90))(2,0);
            (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(iVar9 + *piVar1));
            *(undefined4 *)(*(int *)(iVar9 + *piVar1) + 0xf8) = 3;
            FUN_005e433f(2);
            *(undefined1 *)(*(int *)(iVar9 + *piVar1) + 0x1d8) = 1;
          }
          iVar9 = extraout_ECX[0x37];
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar9 - *piVar1 >> 2));
      }
      piVar3 = (int *)*piVar1;
      *(int **)(unaff_EBP + -0x14) = piVar3;
      iVar9 = *piVar3;
      extraout_ECX[0x3a] = *(int *)(iVar9 + 0x88) - *(int *)(iVar9 + 0x80);
      iVar5 = DAT_006f4f9c;
      iVar9 = DAT_006f4f98;
      iVar4 = DAT_006f4f90;
      *(int *)(unaff_EBP + -0x48) = DAT_006f4f98;
      *(int *)(unaff_EBP + -0x44) = iVar5;
      *(int *)(unaff_EBP + -0x1c) = iVar4 + 1 + iVar9;
      iVar9 = extraout_ECX[0x37];
      iVar2 = *piVar1;
      *(int *)(unaff_EBP + -0x40) = iVar4;
      uVar10 = 0;
      *(int *)(unaff_EBP + -0x34) = (iVar9 - iVar2 >> 2) * DAT_006f4f94 + iVar5;
      *(int *)(unaff_EBP + -0x3c) = DAT_006f4f94;
      *(int *)(unaff_EBP + -0x2c) = extraout_ECX[0x3a];
      iVar9 = extraout_ECX[0x37];
      iVar2 = *piVar1;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 1;
      FUN_004ebf01(*(undefined4 *)(unaff_EBP + -0x14),iVar9 - iVar2 >> 2);
      if (extraout_ECX[0x37] - *piVar1 >> 2 != 0) {
        do {
          iVar9 = *(int *)(*piVar1 + uVar10 * 4);
          iVar2 = *(int *)(iVar9 + 0x7c);
          iVar4 = *(int *)(iVar9 + 0x84);
          *(int *)(unaff_EBP + -0x14) = iVar2;
          if (extraout_ECX[0x21] - extraout_ECX[0x1f] < (iVar4 - iVar2) + iVar2) {
            FUN_004ec186((*(int *)(iVar9 + 0x84) - *(int *)(iVar9 + 0x7c)) +
                         *(int *)(unaff_EBP + -0x14));
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < (uint)(extraout_ECX[0x37] - *piVar1 >> 2));
      }
      (**(code **)(*extraout_ECX + 0x90))(0x40000,1);
      uVar7 = 1;
    }
  }
  else {
    uVar7 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

