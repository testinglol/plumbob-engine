
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005426c6(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  
  iVar1 = param_2[7];
  iVar2 = param_2[3];
  iVar3 = param_2[2];
  iVar7 = param_2[4];
  if (*(char *)(param_1 + 0x388) == '\0') {
    iVar6 = *param_2;
    uVar8 = CONCAT44(iVar7,param_2[1] + iVar3);
    goto LAB_00542860;
  }
  dVar4 = (double)(iVar1 % 0x5a0) * _DAT_0066f3f0;
  FUN_00636d14(dVar4);
  iVar5 = __ftol();
  FUN_00637084();
  iVar6 = __ftol();
  if (dVar4 == _DAT_006669e8) {
    if (iVar1 % 0x23 == 0) {
LAB_00542833:
      iVar7 = 2;
    }
  }
  else if ((((((_DAT_006669e8 < dVar4) && (dVar4 < _DAT_006687d0)) && (iVar7 < 6)) ||
            (((_DAT_006687d0 < dVar4 && (dVar4 < _DAT_006682f8)) && (iVar7 < 10)))) ||
           (((_DAT_006682f8 < dVar4 && (dVar4 < _DAT_0066f3e8)) && (iVar7 < 0xe)))) ||
          (((_DAT_0066f3e8 < dVar4 && (dVar4 < _DAT_006687c8)) && (iVar7 < 0x10)))) {
    if (iVar1 % 0x23 == 0) {
      iVar7 = iVar7 + 1;
    }
  }
  else if ((_DAT_006687c8 < dVar4) && (dVar4 < _DAT_00666dc0)) {
    if (iVar7 == 0xf) {
      iVar7 = 0;
    }
    if (iVar1 % 0x23 == 0) {
      iVar7 = iVar7 + 1;
    }
    if (2 < iVar7) goto LAB_00542833;
  }
  if (0xe < iVar7) {
    iVar7 = 0xf;
  }
  param_2[7] = param_2[7] + 1;
  param_2[1] = iVar5;
  *param_2 = iVar6;
  uVar8 = CONCAT44(iVar7,iVar3 + iVar5);
  param_2[4] = iVar7;
LAB_00542860:
  FUN_00542913(iVar6 + iVar2,uVar8);
  return;
}

