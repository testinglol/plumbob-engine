
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005d378c(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *extraout_ECX;
  int iVar8;
  int unaff_EBP;
  undefined4 uVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  iVar6 = *(int *)(*(int *)(unaff_EBP + 8) + 0x60);
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(int *)(unaff_EBP + -0x1c) = iVar6;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  if ((*(int *)(unaff_EBP + 0xc) == 0) || (*(int *)(unaff_EBP + 0xc) == 2)) {
    uVar4 = (**(code **)(*extraout_ECX + 0x18))();
    uVar5 = FUN_005cf73a(*(undefined4 *)(unaff_EBP + 8),uVar4);
    if (uVar5 == 0) goto LAB_005d37c6;
    if ((_DAT_006734a4 & uVar5) != 0) {
      SetRect((LPRECT)(extraout_ECX + 1),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
      iVar6 = 0;
      goto LAB_005d3b12;
    }
  }
  else {
LAB_005d37c6:
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
  *(LPRECT *)(unaff_EBP + -0x20) = (LPRECT)(extraout_ECX + 1);
  SetRect((LPRECT)(extraout_ECX + 1),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
  piVar1 = *(int **)(iVar6 + 0x38);
  FUN_0049b1e4();
  iVar6 = extraout_ECX[0x3c];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = extraout_ECX[0x3b];
  *(undefined4 *)(unaff_EBP + 0xc) = 0;
  if (iVar6 - iVar2 >> 2 != 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    do {
      iVar6 = *(int *)(extraout_ECX[0x3b] + *(int *)(unaff_EBP + 0xc) * 4);
      *(int *)(unaff_EBP + -0x18) = iVar6;
      if (iVar6 != 0) {
        (**(code **)(*piVar1 + 0x60))(piVar1,8,0);
        *(int *)(unaff_EBP + -0x24) = *piVar1;
        uVar4 = FUN_00603fc3();
        (**(code **)(*(int *)(unaff_EBP + -0x24) + 0x60))(piVar1,1,uVar4);
        iVar6 = *piVar1;
        uVar4 = FUN_005d4785();
        (**(code **)(iVar6 + 0x58))(piVar1,1,uVar4);
        iVar6 = extraout_ECX[0x44];
        uVar4 = 0;
        if ((iVar6 == 0) && ((*(byte *)(extraout_ECX + 0x31) & 2) == 0)) {
          (**(code **)(*piVar1 + 0xa0))(piVar1,0,1,2);
          iVar6 = *piVar1;
          uVar10 = 2;
          uVar9 = 2;
LAB_005d38eb:
          (**(code **)(iVar6 + 0xa0))(piVar1,0,uVar9,uVar10);
        }
        else if ((iVar6 == 1) || (iVar6 == 2)) {
          (**(code **)(*piVar1 + 0xa0))(piVar1,0,2,2);
          (**(code **)(*piVar1 + 0xa0))(piVar1,0,3,0);
          iVar6 = *piVar1;
          uVar10 = 4;
          uVar9 = 1;
          goto LAB_005d38eb;
        }
        FUN_005ce783(unaff_EBP + -0x88);
        if (*(int *)(unaff_EBP + -0x80) == 2) {
          (**(code **)(*piVar1 + 0xa0))(piVar1,0,0x11,2);
          iVar6 = *piVar1;
          uVar9 = 2;
        }
        else {
          (**(code **)(*piVar1 + 0xa0))(piVar1,0,0x11,1);
          iVar6 = *piVar1;
          uVar9 = 1;
        }
        (**(code **)(iVar6 + 0xa0))(piVar1,0,0x10,uVar9);
        if ((*(byte *)(extraout_ECX + 0x31) & 2) == 0) {
          iVar6 = FUN_005d47ab();
          if (iVar6 == 0) {
            iVar6 = *piVar1;
          }
          else {
            cVar3 = FUN_005d48d2();
            iVar6 = *piVar1;
            if (cVar3 != '\0') {
              (**(code **)(iVar6 + 0x58))(piVar1,0xe,0);
              goto LAB_005d395f;
            }
          }
          (**(code **)(iVar6 + 0x58))(piVar1,0xe,1);
          iVar6 = *piVar1;
          uVar10 = 0;
          uVar9 = 0x1b;
        }
        else {
LAB_005d395f:
          (**(code **)(*piVar1 + 0x58))(piVar1,0x1b,1);
          (**(code **)(*piVar1 + 0x58))(piVar1,0x13,5);
          iVar6 = *piVar1;
          uVar10 = 6;
          uVar9 = 0x14;
        }
        (**(code **)(iVar6 + 0x58))(piVar1,uVar9,uVar10);
        if (*(int *)(unaff_EBP + -0x10) == 0) {
          uVar4 = 4;
        }
        puVar7 = (undefined4 *)(extraout_ECX[0x35] + *(int *)(unaff_EBP + -0x14));
        iVar8 = *(int *)(unaff_EBP + 0xc) * 8;
        *(undefined4 *)(unaff_EBP + -0x24) = puVar7[1];
        uVar9 = *puVar7;
        *(undefined4 *)(unaff_EBP + -0x18) = uVar9;
        *(undefined4 *)(unaff_EBP + -0x28) = uVar9;
        iVar6 = extraout_ECX[0x38];
        iVar2 = *(int *)(unaff_EBP + -0x1c);
        *(undefined4 *)(unaff_EBP + -0x2c) = **(undefined4 **)(*(int *)(unaff_EBP + -0x1c) + 0x38);
        iVar6 = (**(code **)(*(int *)(unaff_EBP + -0x2c) + 0x74))
                          (*(undefined4 *)(iVar2 + 0x38),4,0x112,
                           *(int *)(iVar8 + iVar6) * 0x20 + extraout_ECX[0x32],
                           (*(int *)(iVar8 + 4 + iVar6) - *(int *)(iVar8 + iVar6)) + 1,
                           *(undefined4 *)(unaff_EBP + -0x28),
                           *(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x18) >> 1,uVar4);
        if (iVar6 < 0) goto LAB_005d3b12;
        _memset((void *)(unaff_EBP + -0x5c),0,0x20);
        *(undefined4 *)(unaff_EBP + -0x5c) = 2;
        iVar6 = (**(code **)(**(int **)(iVar2 + 0x38) + 0x7c))
                          (*(int **)(iVar2 + 0x38),unaff_EBP + -0x5c);
        if (iVar6 < 0) goto LAB_005d3b12;
        uVar4 = __ftol();
        *(undefined4 *)(unaff_EBP + -0x3c) = uVar4;
        uVar4 = __ftol();
        *(undefined4 *)(unaff_EBP + -0x38) = uVar4;
        uVar4 = __ftol();
        *(undefined4 *)(unaff_EBP + -0x34) = uVar4;
        uVar9 = __ftol();
        uVar4 = _DAT_006735d0;
        *(undefined4 *)(unaff_EBP + -0x30) = uVar9;
        *(undefined4 *)(unaff_EBP + -0x54) = uVar4;
        *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
        uVar4 = _DAT_006735cc;
        *(undefined4 *)(unaff_EBP + -0x50) = _DAT_006735cc;
        *(undefined4 *)(unaff_EBP + -0x48) = uVar4;
        uVar4 = (**(code **)(**(int **)(iVar2 + 0x38) + 0x78))
                          (*(int **)(iVar2 + 0x38),unaff_EBP + -0x5c);
        *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
        FUN_00422698();
      }
      iVar6 = extraout_ECX[0x3c];
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
      iVar2 = extraout_ECX[0x3b];
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0xc;
    } while (*(uint *)(unaff_EBP + 0xc) < (uint)(iVar6 - iVar2 >> 2));
  }
  FUN_005cf1d4(*(undefined4 *)(unaff_EBP + -0x20));
  iVar6 = *(int *)(unaff_EBP + -0x24);
LAB_005d3b12:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar6;
}

