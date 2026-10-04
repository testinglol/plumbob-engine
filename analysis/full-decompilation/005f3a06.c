
void FUN_005f3a06(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int *piVar8;
  int *extraout_ECX;
  int iVar9;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 8) < 0) {
    *(undefined4 *)(unaff_EBP + 8) = 0;
  }
  iVar1 = FUN_005f4175(*(undefined4 *)(unaff_EBP + 8));
  *(int *)(unaff_EBP + -0x14) = iVar1;
  if (iVar1 < 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
  else {
    if (iVar1 < extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2) {
      puVar2 = *(undefined4 **)(extraout_ECX[0x3c] + iVar1 * 4);
    }
    else {
      iVar1 = extraout_ECX[0x3c];
      iVar5 = (extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2) + -1;
      *(int *)(unaff_EBP + -0x14) = iVar5;
      puVar2 = *(undefined4 **)(iVar1 + iVar5 * 4);
    }
    *(undefined4 *)(unaff_EBP + -0x10) = *puVar2;
  }
  iVar1 = (extraout_ECX[0x3a] - extraout_ECX[0x39]) + -1;
  *(int *)(unaff_EBP + -0x24) = iVar1;
  if (iVar1 == 0) {
    uVar3 = (**(code **)(*(int *)extraout_ECX[0x45] + 0x58))();
    piVar8 = extraout_ECX + 0x3c;
    FUN_005f3eb5(0,*(undefined4 *)(unaff_EBP + -0x10),0,uVar3,0,extraout_ECX[0x42],
                 extraout_ECX[0x45],extraout_ECX[0x4a]);
    extraout_ECX[0x35] = 0;
    extraout_ECX[0x36] = 0;
    piVar4 = (int *)FUN_005f2e1e(unaff_EBP + -0x28,0);
    extraout_ECX[0x37] = *piVar4;
    extraout_ECX[0x38] = piVar4[1];
    if (1 < (uint)(extraout_ECX[0x3d] - *piVar8 >> 2)) {
      iVar1 = extraout_ECX[0x3d];
      *(undefined4 *)(unaff_EBP + 8) = 1;
      if (4 < (int)(iVar1 - *piVar8 & 0xfffffffcU)) {
        do {
          iVar1 = *(int *)(*piVar8 + *(int *)(unaff_EBP + 8) * 4);
          if (iVar1 != 0) {
            FUN_0048c4c9();
            FUN_006321f0(iVar1);
          }
          iVar1 = extraout_ECX[0x3d];
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
        } while (*(int *)(unaff_EBP + 8) < iVar1 - *piVar8 >> 2);
      }
      FUN_0052ea87(*piVar8 + 4,extraout_ECX[0x3d]);
    }
  }
  else {
    if (*(int *)(unaff_EBP + -0x10) < iVar1) {
      piVar8 = extraout_ECX + 0x3c;
LAB_005f3b6d:
      while (extraout_ECX[0x3d] - *piVar8 >> 2 <= *(int *)(unaff_EBP + -0x14)) {
        pvVar7 = operator_new(0x24);
        if (pvVar7 == (void *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_005f19e9();
        }
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
        FUN_005f4a70(unaff_EBP + -0x1c);
      }
      if (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x10)) {
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
      }
      else {
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + 8) - *(int *)(unaff_EBP + -0x10);
      }
      piVar4 = (int *)extraout_ECX[0x45];
      *(int *)(unaff_EBP + -0x20) = extraout_ECX[0x39];
      uVar3 = (**(code **)(*piVar4 + 0x58))();
      iVar1 = *(int *)(unaff_EBP + -0x14);
      iVar5 = FUN_005f3eb5(iVar1,*(undefined4 *)(unaff_EBP + -0x10),
                           *(undefined4 *)(unaff_EBP + -0x18),uVar3,
                           *(undefined4 *)(unaff_EBP + -0x20),extraout_ECX[0x42],extraout_ECX[0x45],
                           extraout_ECX[0x4a]);
      piVar4 = (int *)(unaff_EBP + -0x10);
      *piVar4 = *piVar4 + iVar5;
      if ((*piVar4 == 0) ||
         (*(int *)(unaff_EBP + -0x10) < (extraout_ECX[0x3a] - extraout_ECX[0x39]) + -1))
      goto LAB_005f3c0c;
      iVar9 = extraout_ECX[0x3d];
      iVar6 = *piVar8;
      iVar5 = iVar1 + 1;
      *(int *)(unaff_EBP + -0x18) = iVar5;
      if (iVar5 < iVar9 - iVar6 >> 2) {
        *(int *)(unaff_EBP + 8) = iVar5;
        while (*(int *)(unaff_EBP + 8) < extraout_ECX[0x3d] - *piVar8 >> 2) {
          iVar9 = *(int *)(*piVar8 + *(int *)(unaff_EBP + 8) * 4);
          *(int *)(unaff_EBP + -0x24) = iVar9;
          if (iVar9 != 0) {
            FUN_0048c4c9();
            FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x24));
            iVar5 = *(int *)(unaff_EBP + -0x18);
          }
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
        }
        FUN_0052ea87(*piVar8 + iVar5 * 4,extraout_ECX[0x3d]);
      }
      if ((extraout_ECX[0x4d] == -1) && (*(char *)(*(int *)(*piVar8 + iVar1 * 4) + 0x21) == '\x01'))
      {
        pvVar7 = operator_new(0x24);
        if (pvVar7 == (void *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_005f19e9();
        }
        *(undefined4 *)(unaff_EBP + 8) = uVar3;
        FUN_005f4a70(unaff_EBP + 8);
        uVar3 = (**(code **)(*(int *)extraout_ECX[0x45] + 0x58))();
        FUN_005f3eb5(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x10),0,uVar3,0
                     ,extraout_ECX[0x42],extraout_ECX[0x45],extraout_ECX[0x4a]);
      }
    }
LAB_005f3cef:
    piVar8 = extraout_ECX + 0x3c;
    iVar1 = 0;
    if (0 < (int)(extraout_ECX[0x3d] - *piVar8 & 0xfffffffcU)) {
      iVar5 = extraout_ECX[0x35];
      do {
        piVar4 = *(int **)(*piVar8 + iVar1 * 4);
        iVar9 = *piVar4;
        *(int *)(unaff_EBP + -0x20) = iVar9;
        if (iVar5 < iVar9) {
LAB_005f3d32:
          if (iVar5 == piVar4[1] + iVar9) {
LAB_005f3d5a:
            if (iVar1 < (extraout_ECX[0x3d] - *piVar8 >> 2) + -1) {
              iVar1 = iVar1 + 1;
            }
            goto LAB_005f3d68;
          }
          if (iVar9 <= iVar5) {
            iVar6 = -3;
            goto LAB_005f3d42;
          }
        }
        else {
          iVar6 = extraout_ECX[0x35];
          iVar5 = iVar6;
          if (piVar4[1] + iVar9 <= iVar6) {
            iVar9 = *(int *)(unaff_EBP + -0x20);
            goto LAB_005f3d32;
          }
LAB_005f3d42:
          if (-1 < iVar6) {
LAB_005f3d68:
            extraout_ECX[0x36] = iVar1;
            break;
          }
          if (iVar6 == -1) goto LAB_005f3d5a;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < extraout_ECX[0x3d] - *piVar8 >> 2);
    }
  }
  if (((extraout_ECX[0x4c] != 0) &&
      (extraout_ECX[0x4c] < extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2)) &&
     (extraout_ECX[0x44] == 0)) {
    pvVar7 = operator_new(0x158);
    *(void **)(unaff_EBP + -0x24) = pvVar7;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar7 == (void *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_005f65e3();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x44] = iVar1;
    if (iVar1 != 0) {
      FUN_004cb1a2(1,extraout_ECX[0x22] - extraout_ECX[0x20]);
      (**(code **)(*(int *)extraout_ECX[0x44] + 0x1b4))(2);
      piVar8 = (int *)FUN_005e7743();
      iVar1 = (**(code **)(*piVar8 + 0x10))(4);
      if (iVar1 != 0) {
        (**(code **)(*(int *)extraout_ECX[0x44] + 0x1b8))(iVar1,0);
        FUN_004cb21d((extraout_ECX[0x21] - *(int *)(iVar1 + 0x1c) / 0xc) - extraout_ECX[0x1f],0);
      }
      (**(code **)(*(int *)extraout_ECX[0x44] + 0x90))(0x2000,1);
      uVar3 = FUN_005e749a(0);
      FUN_005dde6d(uVar3);
      (**(code **)(*(int *)extraout_ECX[0x44] + 0x90))(0x2000,1);
      (**(code **)(*(int *)extraout_ECX[0x44] + 0x98))();
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x44]);
      FUN_00436e16();
    }
  }
  FUN_005f4008();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
LAB_005f3c0c:
  *(int *)(unaff_EBP + -0x14) = iVar1 + 1;
  if (*(int *)(unaff_EBP + -0x24) <= *(int *)(unaff_EBP + -0x10)) goto LAB_005f3cef;
  goto LAB_005f3b6d;
}

