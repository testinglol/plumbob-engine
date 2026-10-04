
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00529cbc(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  int *piVar7;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x28) = 0x10;
  *(undefined4 *)(unaff_EBP + -0x24) = 0x10;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x10;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x10;
  if (*(int *)(unaff_EBP + 8) == 1) {
    piVar1 = extraout_ECX + 0x3b;
    for (piVar7 = extraout_ECX + 0x35; (piVar7 != piVar1 && (*piVar7 != *(int *)(unaff_EBP + 0xc)));
        piVar7 = piVar7 + 1) {
    }
    if (piVar7 == piVar1) {
      for (piVar7 = (int *)*piVar1; piVar7 != (int *)extraout_ECX[0x3c]; piVar7 = piVar7 + 1) {
        if (*piVar7 == *(int *)(unaff_EBP + 0xc)) {
          if (piVar7 != (int *)extraout_ECX[0x3c]) {
            uVar5 = (int)piVar7 - *piVar1 >> 2;
            pvVar6 = operator_new(0x34);
            *(void **)(unaff_EBP + 0xc) = pvVar6;
            *(undefined4 *)(unaff_EBP + -4) = 1;
            if (pvVar6 == (void *)0x0) {
              iVar4 = 0;
            }
            else {
              iVar4 = FUN_0049060c();
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            if (iVar4 != 0) {
              *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;
            }
            FUN_004cf0ab(8,0);
            FUN_005b86bd(extraout_ECX[0x3e] + uVar5 * 0xc);
            *(undefined4 *)(unaff_EBP + -4) = 2;
            cVar2 = FUN_0056f32e(*(undefined4 *)(unaff_EBP + -0x18));
            if (cVar2 != '\0') {
              FUN_0049341e(iVar4);
            }
            if (iVar4 != 0) {
              FUN_00485b4c();
            }
            FUN_0052a21f(extraout_ECX[0x46]);
            if ((extraout_ECX[0x49] != 0) && (*(char *)(extraout_ECX[0x49] + 0xf0) != '\0')) {
              if ((-1 < (int)uVar5) &&
                 (uVar5 < (uint)(extraout_ECX[0x42] - extraout_ECX[0x41] >> 2))) {
                FUN_004cd0b4(*(undefined4 *)(extraout_ECX[0x41] + uVar5 * 4),1,unaff_EBP + -0x28);
              }
              uVar3 = (**(code **)(*extraout_ECX + 0x18))();
              FUN_005083f4(extraout_ECX[0x4b],uVar3);
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
          }
          break;
        }
      }
      goto LAB_0052a040;
    }
    *(int *)(unaff_EBP + 8) = (int)piVar7 + (-0xd4 - (int)extraout_ECX) >> 2;
    pvVar6 = operator_new(0x34);
    *(void **)(unaff_EBP + 0xc) = pvVar6;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar6 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + 0xc) = 0;
    }
    else {
      uVar3 = FUN_0049060c();
      *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + 0xc) != 0) {
      piVar7 = (int *)(*(int *)(unaff_EBP + 0xc) + 8);
      *piVar7 = *piVar7 + 1;
    }
    iVar4 = *(int *)(unaff_EBP + 8);
    uVar3 = _DAT_00666a44;
    if ((iVar4 == 0) || (uVar3 = _DAT_00666a40, iVar4 == 1)) {
LAB_00529e9d:
      cVar2 = FUN_0056f23d(uVar3);
      FUN_004cf0ab(8,0);
      FUN_0052a21f(extraout_ECX[0x46]);
      if (cVar2 != '\0') {
        FUN_0049341e(*(undefined4 *)(unaff_EBP + 0xc));
      }
    }
    else {
      if (iVar4 == 2) {
        uVar3 = 0x3f800000;
        goto LAB_00529e9d;
      }
      if (iVar4 == 3) {
        iVar4 = extraout_ECX[0x44] + -1;
LAB_00529e63:
        FUN_0052a053(iVar4);
        FUN_0052a21f(extraout_ECX[0x46]);
        piVar7 = (int *)(**(code **)(*extraout_ECX + 0x18))();
        (**(code **)(*piVar7 + 0x168))();
      }
      else {
        if (iVar4 == 4) {
          iVar4 = extraout_ECX[0x44] + 1;
          goto LAB_00529e63;
        }
        if (iVar4 == 5) {
          uVar3 = 0;
          goto LAB_00529e9d;
        }
      }
    }
    if (*(int *)(unaff_EBP + 0xc) != 0) {
      FUN_00485b4c();
    }
    iVar4 = *(int *)(unaff_EBP + 8);
    if (((((iVar4 == 0) || (iVar4 == 1)) || (iVar4 == 2)) || (iVar4 == 5)) &&
       ((extraout_ECX[0x49] != 0 && (*(char *)(extraout_ECX[0x49] + 0xf0) != '\0')))) {
LAB_00529d4e:
      uVar3 = (**(code **)(*extraout_ECX + 0x18))();
      iVar4 = extraout_ECX[0x4a];
LAB_00529d5c:
      FUN_005083f4(iVar4,uVar3);
    }
  }
  else {
    if (*(int *)(unaff_EBP + 8) != 0x13) {
      uVar3 = FUN_005dd97f(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
      goto LAB_0052a042;
    }
    if (extraout_ECX[0x49] != 0) {
      piVar1 = extraout_ECX + 0x3b;
      for (piVar7 = extraout_ECX + 0x35;
          (piVar7 != piVar1 && (*piVar7 != *(int *)(unaff_EBP + 0xc))); piVar7 = piVar7 + 1) {
      }
      iVar4 = (int)piVar7 + (-0xd4 - (int)extraout_ECX) >> 2;
      if (piVar7 != piVar1) {
        if ((((iVar4 != 0) && (iVar4 != 1)) && (iVar4 != 2)) && (iVar4 != 5)) goto LAB_0052a040;
        goto LAB_00529d4e;
      }
      for (piVar7 = (int *)*piVar1; piVar7 != (int *)extraout_ECX[0x3c]; piVar7 = piVar7 + 1) {
        if (*piVar7 == *(int *)(unaff_EBP + 0xc)) {
          if (piVar7 != (int *)extraout_ECX[0x3c]) {
            uVar5 = (int)piVar7 - *piVar1 >> 2;
            if ((-1 < (int)uVar5) && (uVar5 < (uint)(extraout_ECX[0x42] - extraout_ECX[0x41] >> 2)))
            {
              FUN_004cd0b4(*(undefined4 *)(extraout_ECX[0x41] + uVar5 * 4),1,unaff_EBP + -0x28);
            }
            uVar3 = (**(code **)(*extraout_ECX + 0x18))();
            iVar4 = extraout_ECX[0x4b];
            goto LAB_00529d5c;
          }
          break;
        }
      }
    }
  }
LAB_0052a040:
  uVar3 = 1;
LAB_0052a042:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

