
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005d337d(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar8;
  
  FUN_00634c24();
  iVar7 = *(int *)(unaff_EBP + 8);
  iVar1 = *(int *)(iVar7 + 0x60);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  if ((*(int *)(unaff_EBP + 0xc) == 0) || (*(int *)(unaff_EBP + 0xc) == 2)) {
    uVar5 = (**(code **)(*extraout_ECX + 0x18))();
    uVar6 = FUN_005cf73a(iVar7,uVar5);
    if (uVar6 == 0) goto LAB_005d33b3;
    if ((_DAT_006734a4 & uVar6) != 0) {
      SetRect((LPRECT)(extraout_ECX + 1),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
      goto LAB_005d3698;
    }
  }
  else {
LAB_005d33b3:
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
  SetRect((LPRECT)(extraout_ECX + 1),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
  piVar2 = *(int **)(iVar1 + 0x38);
  (**(code **)(*piVar2 + 0x58))(piVar2,0xe,1);
  iVar7 = extraout_ECX[0x3c];
  *(undefined4 *)(unaff_EBP + 0xc) = 0;
  if (iVar7 - extraout_ECX[0x3b] >> 2 != 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    do {
      (**(code **)(*piVar2 + 0x60))(piVar2,8,0);
      iVar7 = *piVar2;
      uVar5 = FUN_00603fc3();
      (**(code **)(iVar7 + 0x60))(piVar2,1,uVar5);
      iVar7 = *piVar2;
      uVar5 = FUN_005d4785();
      (**(code **)(iVar7 + 0x58))(piVar2,1,uVar5);
      iVar7 = extraout_ECX[0x44];
      if (iVar7 == 0) {
        (**(code **)(*piVar2 + 0xa0))(piVar2,0,1,2);
        iVar7 = *piVar2;
        uVar8 = 2;
        uVar5 = 2;
LAB_005d34bd:
        (**(code **)(iVar7 + 0xa0))(piVar2,0,uVar5,uVar8);
      }
      else if ((iVar7 == 1) || (iVar7 == 2)) {
        (**(code **)(*piVar2 + 0xa0))(piVar2,0,2,2);
        (**(code **)(*piVar2 + 0xa0))(piVar2,0,3,0);
        iVar7 = *piVar2;
        uVar8 = 4;
        uVar5 = 1;
        goto LAB_005d34bd;
      }
      FUN_0049b1e4();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005ce783(unaff_EBP + -0x80);
      if (*(int *)(unaff_EBP + -0x78) == 2) {
        (**(code **)(*piVar2 + 0xa0))(piVar2,0,0x11,2);
        iVar7 = *piVar2;
        uVar5 = 2;
      }
      else {
        (**(code **)(*piVar2 + 0xa0))(piVar2,0,0x11,1);
        iVar7 = *piVar2;
        uVar5 = 1;
      }
      (**(code **)(iVar7 + 0xa0))(piVar2,0,0x10,uVar5);
      iVar7 = *piVar2;
      if ((*(byte *)(extraout_ECX + 0x31) & 2) == 0) {
        uVar8 = 0;
        uVar5 = 0x1b;
      }
      else {
        (**(code **)(iVar7 + 0x58))(piVar2,0x1b,1);
        (**(code **)(*piVar2 + 0x58))(piVar2,0x13,3);
        iVar7 = *piVar2;
        uVar8 = 4;
        uVar5 = 0x14;
      }
      (**(code **)(iVar7 + 0x58))(piVar2,uVar5,uVar8);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (*(int *)(unaff_EBP + -0x10) == 0) {
        *(undefined4 *)(unaff_EBP + -0x18) = 4;
      }
      iVar7 = *(int *)(*(int *)(unaff_EBP + -0x14) + 4 + extraout_ECX[0x35]);
      iVar1 = *(int *)(*(int *)(unaff_EBP + -0x14) + extraout_ECX[0x35]);
      *(int *)(unaff_EBP + -0x24) = iVar1;
      piVar3 = *(int **)(*(int *)(unaff_EBP + -0x1c) + 0x38);
      iVar4 = extraout_ECX[0x45];
      *(int *)(unaff_EBP + -0x20) = iVar1;
      iVar7 = (**(code **)(*piVar3 + 0x8c))
                        (piVar3,4,iVar4,iVar1,iVar7 - iVar1 >> 1,*(undefined4 *)(unaff_EBP + -0x18))
      ;
      if (iVar7 < 0) goto LAB_005d369a;
      _memset((void *)(unaff_EBP + -0x54),0,0x20);
      iVar1 = *(int *)(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x54) = 2;
      piVar3 = *(int **)(iVar1 + 0x38);
      iVar7 = (**(code **)(*piVar3 + 0x7c))(piVar3,unaff_EBP + -0x54);
      if (iVar7 < 0) goto LAB_005d369a;
      uVar5 = __ftol();
      *(undefined4 *)(unaff_EBP + -0x34) = uVar5;
      uVar5 = __ftol();
      *(undefined4 *)(unaff_EBP + -0x30) = uVar5;
      uVar5 = __ftol();
      *(undefined4 *)(unaff_EBP + -0x2c) = uVar5;
      uVar8 = __ftol();
      uVar5 = _DAT_006735d0;
      *(undefined4 *)(unaff_EBP + -0x28) = uVar8;
      piVar3 = *(int **)(iVar1 + 0x38);
      *(undefined4 *)(unaff_EBP + -0x4c) = uVar5;
      *(undefined4 *)(unaff_EBP + -0x44) = uVar5;
      uVar5 = _DAT_006735cc;
      *(undefined4 *)(unaff_EBP + -0x48) = _DAT_006735cc;
      *(undefined4 *)(unaff_EBP + -0x40) = uVar5;
      (**(code **)(*piVar3 + 0x78))(piVar3,unaff_EBP + -0x54);
      FUN_00422698();
      iVar7 = extraout_ECX[0x3c];
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar1 = extraout_ECX[0x3b];
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0xc;
    } while (*(uint *)(unaff_EBP + 0xc) < (uint)(iVar7 - iVar1 >> 2));
  }
  FUN_005cf1d4(extraout_ECX + 1);
LAB_005d3698:
  iVar7 = 0;
LAB_005d369a:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar7;
}

