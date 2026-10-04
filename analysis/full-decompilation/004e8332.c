
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_004e8332(void)

{
  int iVar1;
  float fVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_EBP;
  undefined2 uVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  iVar7 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if (iVar7 == 2) {
    uVar10 = 9000;
LAB_004e836f:
    FUN_005a5631(uVar10,unaff_EBP + -0x14,4);
    if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(unaff_EBP + -0x5c) = 0x10;
      *(undefined4 *)(unaff_EBP + -0x58) = 0x10;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x20;
      *(undefined4 *)(unaff_EBP + -0x50) = 0x20;
      *(undefined4 *)(unaff_EBP + -0x48) = 0;
      *(undefined4 *)(unaff_EBP + -0x44) = 0;
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      iVar8 = **(int **)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -100) = 0;
      *(undefined4 *)(unaff_EBP + -0x60) = 0;
      uVar9 = 0xffff;
      cVar3 = (**(code **)(iVar8 + 0x20))(0x40);
      if (cVar3 != '\0') {
        iVar5 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0xd0))();
        iVar8 = *(int *)(unaff_EBP + -0x50 + iVar7 * 8);
        iVar1 = *(int *)(unaff_EBP + -0x54 + iVar7 * 8);
        iVar6 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0xcc))();
        uVar9 = *(undefined2 *)(iVar6 + (((uint)(iVar5 * iVar8) >> 1) + iVar1) * 2);
        (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x24))(0x40);
      }
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      FUN_005c1719();
      fVar2 = DAT_00673438 * _DAT_00669420;
      uVar10 = *(undefined4 *)(unaff_EBP + -0x68 + iVar7 * 8);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      cVar3 = FUN_004e7902(*(undefined4 *)(unaff_EBP + 0xc),DAT_00673438 * _DAT_0066941c,fVar2,
                           *(undefined4 *)(unaff_EBP + -0x6c + iVar7 * 8),uVar10,unaff_EBP + -0x24,
                           uVar9,unaff_EBP + 8,0);
      if (cVar3 == '\0') {
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
      }
      cVar3 = FUN_005a5e72();
      if (cVar3 != '\0') {
        cVar3 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x20))(0x10);
        if (cVar3 != '\0') {
          iVar7 = FUN_004096c2();
          *(int *)(unaff_EBP + 0xc) = iVar7 + 0x14;
          iVar7 = **(int **)(unaff_EBP + -0x14);
          iVar8 = FUN_004096c2(0);
          uVar10 = FUN_004e84f4(unaff_EBP + -0x34,iVar8 + 0x14);
          uVar10 = FUN_004096c2(*(undefined4 *)(unaff_EBP + 0xc),uVar10);
          cVar3 = (**(code **)(iVar7 + 0x9c))(uVar10);
          if (cVar3 == '\0') {
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
          }
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x24))(0x10);
        }
      }
      FUN_005a5e48(*(undefined4 *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005a5e09();
      uVar4 = *(undefined1 *)(unaff_EBP + -0xd);
      goto LAB_004e84e6;
    }
  }
  else if (iVar7 == 3) {
    uVar10 = 0x2329;
    goto LAB_004e836f;
  }
  uVar4 = 0;
LAB_004e84e6:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

