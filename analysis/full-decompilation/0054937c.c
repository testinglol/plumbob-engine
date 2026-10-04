
undefined4 FUN_0054937c(void)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  int *extraout_ECX;
  uint uVar10;
  int unaff_EBP;
  int iVar11;
  int iVar12;
  bool bVar13;
  int *piVar14;
  
  FUN_00634c24();
  iVar8 = *(int *)(unaff_EBP + 8);
  if (iVar8 == 1) {
    iVar8 = *(int *)(unaff_EBP + 0xc);
    if (iVar8 == extraout_ECX[0x52]) {
      if (DAT_006f5070 == '\0') {
        DAT_006f5070 = 1;
        pvVar5 = operator_new(0x208);
        *(void **)(unaff_EBP + 0xc) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar5 == (void *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)FUN_005458e5();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (piVar6 != (int *)0x0) {
          (**(code **)(*extraout_ECX + 0x98))();
          iVar8 = extraout_ECX[0x1f];
          iVar11 = extraout_ECX[0x20];
          iVar12 = extraout_ECX[0x21];
          *(int *)(unaff_EBP + -0x3c) = extraout_ECX[0x22];
          (**(code **)(*piVar6 + 0x60))(iVar8,iVar11,iVar12,*(undefined4 *)(unaff_EBP + -0x3c));
          FUN_005ea5ab(extraout_ECX);
          FUN_005d4bbf(*(undefined4 *)(extraout_ECX[0x45] + 0xe4));
          cVar3 = (**(code **)(*piVar6 + 0xc))();
          if (cVar3 != '\0') {
            (**(code **)(*(int *)extraout_ECX[0x45] + 0x98))();
            piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
            piVar1 = DAT_006fe8bc;
            piVar14 = piVar6;
            uVar4 = (**(code **)(*piVar7 + 8))(piVar6);
            (**(code **)(*piVar1 + 0x18))(uVar4);
            FUN_005daa44(uVar4,piVar14);
            (**(code **)(*(int *)extraout_ECX[0x45] + 0x94))();
            FUN_00436e16();
            FUN_005db1e2();
          }
          FUN_005da4c7(piVar6);
          FUN_005e4b90(1);
          (**(code **)(*extraout_ECX + 0x94))();
        }
        DAT_006f5070 = '\0';
      }
    }
    else if (iVar8 == extraout_ECX[0x53]) {
      if ((extraout_ECX[0x51] != -1) &&
         (iVar8 = (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))
                            (extraout_ECX + 0x5b,extraout_ECX + 0x58,2,0), iVar8 == 4)) {
        FUN_004e1e40(*(undefined4 *)(extraout_ECX[0x46] + extraout_ECX[0x51] * 4));
        FUN_005db2f2(extraout_ECX[0x46] + extraout_ECX[0x51] * 4);
        extraout_ECX[0x51] = -1;
LAB_005493d2:
        FUN_00549a98();
      }
    }
    else {
      if (iVar8 != extraout_ECX[0x54]) {
        if (iVar8 == extraout_ECX[0x55]) {
          iVar8 = FUN_004f6994(extraout_ECX[0x67],extraout_ECX[100],1,0);
          if (iVar8 != 3) {
LAB_00549925:
            FUN_005e4b90(1);
            goto LAB_005493d9;
          }
          uVar4 = FUN_004e1ac7();
          iVar8 = extraout_ECX[0x45];
          if (iVar8 == 0) {
            uVar9 = FUN_005b870f(s_The_Symptoms_006cd5f0);
            *(undefined4 *)(unaff_EBP + -4) = 3;
            FUN_004e1d27(uVar4,uVar9);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          }
          else {
            uVar9 = FUN_005b86cf(*(int *)(iVar8 + 0xe4),
                                 (*(int *)(iVar8 + 0xe8) - *(int *)(iVar8 + 0xe4)) + -1);
            *(undefined4 *)(unaff_EBP + -4) = 2;
            FUN_004e1d27(uVar4,uVar9);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          }
          FUN_005b8770();
          uVar10 = 0;
          if (extraout_ECX[0x47] - extraout_ECX[0x46] >> 2 != 0) {
            do {
              FUN_004e1e77(uVar4,*(undefined4 *)(extraout_ECX[0x46] + uVar10 * 4));
              uVar10 = uVar10 + 1;
            } while (uVar10 < (uint)(extraout_ECX[0x47] - extraout_ECX[0x46] >> 2));
          }
          FUN_004e1978(uVar4);
          puVar2 = (undefined4 *)extraout_ECX[0x57];
          if (puVar2 != (undefined4 *)0x0) {
            *(undefined4 *)(unaff_EBP + -0x38) = 3;
            *(undefined4 *)(unaff_EBP + -0x34) = 0x1e;
            *(undefined4 *)(unaff_EBP + -0x30) = uVar4;
            cVar3 = FUN_005da398(puVar2);
            if (cVar3 != '\0') {
              (**(code **)*puVar2)(unaff_EBP + -0x38);
            }
          }
          iVar8 = *(int *)(unaff_EBP + 0xc);
        }
        else if (iVar8 == extraout_ECX[0x56]) {
          if (((extraout_ECX[0x47] - extraout_ECX[0x46] & 0xfffffffcU) != 0) &&
             (iVar11 = FUN_004f6994(extraout_ECX[0x61],extraout_ECX[0x5e],1,0), iVar11 != 3))
          goto LAB_00549925;
          uVar10 = 0;
          if (extraout_ECX[0x47] - extraout_ECX[0x46] >> 2 != 0) {
            do {
              FUN_004e1e40(*(undefined4 *)(extraout_ECX[0x46] + uVar10 * 4));
              uVar10 = uVar10 + 1;
            } while (uVar10 < (uint)(extraout_ECX[0x47] - extraout_ECX[0x46] >> 2));
          }
          FUN_004e1978(0xffffffff);
        }
        else {
          *(undefined4 *)(unaff_EBP + 8) = 0xffffffff;
          iVar11 = 0;
          piVar6 = extraout_ECX + 0x49;
          do {
            if (iVar8 == *piVar6) {
              *(int *)(unaff_EBP + 8) = iVar11;
              if (iVar11 != -1) {
                if ((iVar11 != extraout_ECX[0x51]) && (extraout_ECX[0x51] != -1)) {
                  FUN_005e46f0(0);
                }
                extraout_ECX[0x51] = iVar11;
                FUN_005e46f0(1);
                iVar8 = *(int *)(unaff_EBP + 0xc);
              }
              break;
            }
            iVar11 = iVar11 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar11 < 8);
          piVar1 = (int *)extraout_ECX[0x53];
          piVar6 = piVar1 + 0x5a;
          if (extraout_ECX[0x51] == -1) {
            if ((char)*piVar6 != '\0') {
              *(char *)piVar6 = '\0';
              (**(code **)(*piVar1 + 0x168))();
            }
            piVar6 = (int *)extraout_ECX[0x54];
            if ((char)piVar6[0x5a] != '\0') {
              *(undefined1 *)(piVar6 + 0x5a) = 0;
LAB_00549a80:
              (**(code **)(*piVar6 + 0x168))();
            }
          }
          else {
            if ((char)*piVar6 != '\x01') {
              *(char *)piVar6 = '\x01';
              (**(code **)(*piVar1 + 0x168))();
            }
            piVar6 = (int *)extraout_ECX[0x54];
            if ((char)piVar6[0x5a] != '\x01') {
              *(undefined1 *)(piVar6 + 0x5a) = 1;
              goto LAB_00549a80;
            }
          }
          if (*(int *)(unaff_EBP + 8) != -1) goto LAB_005493d9;
        }
        uVar4 = 1;
        goto LAB_005493b4;
      }
      if (DAT_006f5071 == '\0') {
        DAT_006f5071 = 1;
        pvVar5 = operator_new(0x208);
        *(void **)(unaff_EBP + 0xc) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar5 == (void *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)FUN_005458e5();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (piVar6 != (int *)0x0) {
          (**(code **)(*extraout_ECX + 0x98))();
          iVar8 = extraout_ECX[0x1f];
          iVar11 = extraout_ECX[0x20];
          *(int *)(unaff_EBP + -0x40) = extraout_ECX[0x21];
          (**(code **)(*piVar6 + 0x60))
                    (iVar8,iVar11,*(undefined4 *)(unaff_EBP + -0x40),extraout_ECX[0x22]);
          FUN_00547736(*(undefined4 *)(extraout_ECX[0x46] + extraout_ECX[0x51] * 4),0);
          FUN_005ea5ab(extraout_ECX);
          FUN_005d4bbf(*(undefined4 *)(extraout_ECX[0x45] + 0xe4));
          cVar3 = (**(code **)(*piVar6 + 0xc))();
          if (cVar3 != '\0') {
            piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
            piVar1 = DAT_006fe8bc;
            piVar14 = piVar6;
            uVar4 = (**(code **)(*piVar7 + 8))(piVar6);
            (**(code **)(*piVar1 + 0x18))(uVar4);
            FUN_005daa44(uVar4,piVar14);
            FUN_00549a98();
          }
          FUN_005da4c7(piVar6);
          FUN_005e4b90(1);
          (**(code **)(*extraout_ECX + 0x94))();
        }
        DAT_006f5071 = '\0';
      }
    }
  }
  else if (iVar8 == 0x16) {
    *(undefined4 *)(unaff_EBP + 8) = 0;
    *(undefined1 *)(unaff_EBP + 0xf) = 1;
    iVar8 = *(int *)(*(int *)(unaff_EBP + 0xc) + 0xe4);
    iVar11 = *(int *)(*(int *)(unaff_EBP + 0xc) + 0xe8) - iVar8;
    iVar12 = iVar11 + -1;
    if (0 < iVar12) {
      do {
        cVar3 = *(char *)(*(int *)(unaff_EBP + 8) + iVar8);
        if ((cVar3 != '\0') &&
           (cVar3 = (**(code **)(**(int **)(extraout_ECX[0x45] + 0x114) + 0x38))((int)cVar3),
           cVar3 == '\0')) {
          *(undefined1 *)(unaff_EBP + 0xf) = 0;
        }
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      } while (*(int *)(unaff_EBP + 8) < iVar12);
    }
    if ((iVar11 == 1) || (*(char *)(unaff_EBP + 0xf) != '\0')) {
      piVar6 = (int *)extraout_ECX[0x52];
      if ((char)piVar6[0x5a] != '\0') {
        *(undefined1 *)(piVar6 + 0x5a) = 0;
        (**(code **)(*piVar6 + 0x168))();
      }
      piVar6 = (int *)extraout_ECX[0x55];
      if ((char)piVar6[0x5a] != '\0') {
        *(undefined1 *)(piVar6 + 0x5a) = 0;
LAB_005494e0:
        (**(code **)(*piVar6 + 0x168))();
      }
    }
    else {
      piVar1 = (int *)extraout_ECX[0x52];
      bVar13 = (uint)(extraout_ECX[0x47] - extraout_ECX[0x46] >> 2) < 8;
      piVar6 = piVar1 + 0x5a;
      if ((bool)(char)*piVar6 != bVar13) {
        *(bool *)piVar6 = bVar13;
        (**(code **)(*piVar1 + 0x168))();
      }
      if ((extraout_ECX[0x47] - extraout_ECX[0x46] & 0xfffffffcU) != 0) {
        piVar6 = (int *)extraout_ECX[0x55];
        if ((char)piVar6[0x5a] != '\x01') {
          *(undefined1 *)(piVar6 + 0x5a) = 1;
          goto LAB_005494e0;
        }
      }
    }
  }
  else if (iVar8 == 0x18) {
    iVar8 = *extraout_ECX;
    iVar11 = extraout_ECX[0x56];
LAB_00549414:
    (**(code **)(iVar8 + 300))(1,iVar11);
  }
  else {
    if (iVar8 != 0x1a) {
      if (iVar8 == 0x1f) {
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + 0xc);
        FUN_0042eab4(unaff_EBP + -0x10);
        goto LAB_005493d2;
      }
      iVar8 = *(int *)(unaff_EBP + 0xc);
      uVar4 = *(undefined4 *)(unaff_EBP + 8);
LAB_005493b4:
      uVar4 = FUN_005e9006(uVar4,iVar8);
      goto LAB_005493db;
    }
    for (piVar6 = extraout_ECX + 0x49; extraout_ECX + 0x51 != piVar6; piVar6 = piVar6 + 1) {
      if (*piVar6 == *(int *)(unaff_EBP + 0xc)) {
        if (extraout_ECX + 0x51 != piVar6) {
          iVar8 = *extraout_ECX;
          iVar11 = extraout_ECX[0x54];
          goto LAB_00549414;
        }
        break;
      }
    }
  }
LAB_005493d9:
  uVar4 = 1;
LAB_005493db:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

