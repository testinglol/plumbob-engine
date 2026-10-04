
void FUN_004c5715(void)

{
  char cVar1;
  short sVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int extraout_ECX;
  int iVar10;
  int iVar11;
  int unaff_EBP;
  int iVar12;
  
  FUN_00634c24();
  iVar5 = *(int *)(extraout_ECX + 0x120);
  iVar6 = *(int *)(unaff_EBP + 8);
  iVar12 = *(int *)(extraout_ECX + 0x11c);
  uVar9 = *(undefined4 *)(iVar6 + 4);
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + 8) = uVar9;
  for (; iVar5 != iVar12; iVar12 = iVar12 + 0xc) {
    cVar1 = FUN_00460748(iVar12,*(undefined4 *)(unaff_EBP + 8));
    if (cVar1 != '\0') {
      if (iVar5 != iVar12) goto LAB_004c5c39;
      break;
    }
  }
  pvVar3 = operator_new(0x2c);
  *(void **)(unaff_EBP + 8) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_0041c1a9();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(unaff_EBP + -0x18) = piVar4;
  iVar5 = (**(code **)(*piVar4 + 0xc))(iVar6,0);
  piVar4 = *(int **)(unaff_EBP + -0x18);
  if (iVar5 == 0) {
    sVar2 = (**(code **)(*piVar4 + 0x34))(0x53505223);
    iVar5 = (int)sVar2 / 3;
    *(int *)(unaff_EBP + -0x28) = iVar5;
    if (0 < iVar5) {
      *(undefined4 *)(unaff_EBP + -0x20) = 1;
      if (0 < iVar5) {
        do {
          iVar5 = *(int *)(unaff_EBP + -0x1c);
          cVar1 = FUN_004a1c36(unaff_EBP + 10);
          if (cVar1 == '\0') {
            *(undefined4 *)(unaff_EBP + -0x10) = 0xffff;
          }
          else {
            *(uint *)(unaff_EBP + -0x10) = (uint)*(ushort *)(unaff_EBP + 10);
          }
          if (*(int *)(unaff_EBP + -0x10) == 0xffff) break;
          iVar6 = (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x38))
                            (0x53505223,*(undefined4 *)(unaff_EBP + -0x20),0);
          if (iVar6 != 0) {
            pvVar3 = operator_new(0x30);
            *(void **)(unaff_EBP + -0x40) = pvVar3;
            *(undefined4 *)(unaff_EBP + -4) = 3;
            if (pvVar3 == (void *)0x0) {
              piVar4 = (int *)0x0;
            }
            else {
              piVar4 = (int *)FUN_004c56dd();
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_0046f824(unaff_EBP + -0xf4,0,0x40);
            *(undefined ***)(unaff_EBP + -0x100) = &PTR_FUN_0066651c;
            (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x48))(iVar6,unaff_EBP + -0x100);
            if (*(short *)(unaff_EBP + -0xf8) == 9) {
              iVar5 = *(int *)(unaff_EBP + -0xfc);
              cVar1 = *(char *)(iVar5 + 1);
              if ((cVar1 < '0') || ('9' < cVar1)) {
                if ((cVar1 < 'A') || ('F' < cVar1)) {
                  iVar6 = 0;
                }
                else {
                  iVar6 = cVar1 + -0x37;
                }
              }
              else {
                iVar6 = cVar1 + -0x30;
              }
              cVar1 = *(char *)(iVar5 + 2);
              if ((cVar1 < '0') || ('9' < cVar1)) {
                if ((cVar1 < 'A') || ('F' < cVar1)) {
                  iVar12 = 0;
                }
                else {
                  iVar12 = cVar1 + -0x37;
                }
              }
              else {
                iVar12 = cVar1 + -0x30;
              }
              cVar1 = *(char *)(iVar5 + 4);
              if ((cVar1 < '0') || ('9' < cVar1)) {
                if ((cVar1 < 'A') || ('F' < cVar1)) {
                  iVar7 = 0;
                }
                else {
                  iVar7 = cVar1 + -0x37;
                }
              }
              else {
                iVar7 = cVar1 + -0x30;
              }
              if ((cVar1 < '0') || ('9' < cVar1)) {
                if ((cVar1 < 'A') || ('F' < cVar1)) {
                  iVar10 = 0;
                }
                else {
                  iVar10 = cVar1 + -0x37;
                }
              }
              else {
                iVar10 = cVar1 + -0x30;
              }
              cVar1 = *(char *)(iVar5 + 7);
              if ((cVar1 < '0') || ('9' < cVar1)) {
                if ((cVar1 < 'A') || ('F' < cVar1)) {
                  iVar8 = 0;
                }
                else {
                  iVar8 = cVar1 + -0x37;
                }
              }
              else {
                iVar8 = cVar1 + -0x30;
              }
              cVar1 = *(char *)(iVar5 + 8);
              if ((cVar1 < '0') || ('9' < cVar1)) {
                if ((cVar1 < 'A') || ('F' < cVar1)) {
                  iVar11 = 0;
                }
                else {
                  iVar11 = cVar1 + -0x37;
                }
              }
              else {
                iVar11 = cVar1 + -0x30;
              }
              iVar5 = *(int *)(unaff_EBP + -0x1c);
              piVar4[0xb] = (((iVar6 * 0x10 + iVar12) * 0x100 | iVar7 * 0x10 + iVar10) << 8 |
                            iVar8 * 0x10 + iVar11) << 8;
            }
            *piVar4 = *(int *)(iVar5 + 0x28) - *(int *)(iVar5 + 0x24) >> 3;
            iVar6 = *(int *)(unaff_EBP + -0x20);
            piVar4[1] = iVar6;
            piVar4[3] = iVar6 + 0x800;
            piVar4[2] = iVar6 + 0x700;
            piVar4[4] = *(int *)(iVar5 + 0x108);
            iVar5 = (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x38))(0x53545223,0,FUN_00470449);
            if (iVar5 != 0) {
              (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x50))(iVar5,unaff_EBP + -0x24);
              FUN_00465a06(iVar5);
              FUN_0046fca5();
              *(undefined ***)(unaff_EBP + -0xb4) = &PTR_FUN_0066643c;
              *(undefined4 *)(unaff_EBP + -4) = 4;
              FUN_0047034e(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x24),
                           0x53545223,0,0xffffffff);
              FUN_0046ffa4(0,1);
              iVar5 = FUN_004705f2(1,0xffffffff);
              if (iVar5 == 0) {
                FUN_005d4bbf(&DAT_006de560);
              }
              else {
                uVar9 = FUN_004705f2(1,0xffffffff);
                FUN_005d49b7(uVar9);
              }
              iVar5 = FUN_004705f2(2,0xffffffff);
              if (iVar5 != 0) {
                uVar9 = FUN_004705f2(2,0xffffffff);
                iVar5 = FUN_00635f62(uVar9);
                piVar4[4] = iVar5;
              }
              iVar5 = FUN_004705f2(3,0xffffffff);
              if (iVar5 == 0) {
                FUN_005d4bbf(&DAT_006de560);
              }
              else {
                uVar9 = FUN_004705f2(3,0xffffffff);
                FUN_005d49b7(uVar9);
              }
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              FUN_00470467();
            }
            *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x10);
            *(int **)(unaff_EBP + -0x38) = piVar4;
            FUN_004c662a(unaff_EBP + -0x48,unaff_EBP + -0x3c);
          }
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
        } while (*(int *)(unaff_EBP + -0x20) <= *(int *)(unaff_EBP + -0x28));
      }
      pvVar3 = operator_new(0x28);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 5;
      if (pvVar3 == (void *)0x0) {
        uVar9 = 0;
      }
      else {
        uVar9 = FUN_004c71c6(*(undefined4 *)(unaff_EBP + -0x18));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
      FUN_004a1711(unaff_EBP + -0x18);
      goto LAB_004c5c39;
    }
    (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x18))();
    if (*(undefined4 **)(unaff_EBP + -0x18) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_EBP + -0x18))(1);
    }
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar6 + 4);
    iVar5 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x114);
    iVar12 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x110);
    *(int *)(unaff_EBP + 8) = iVar5;
    if (iVar12 != iVar5) {
      do {
        cVar1 = FUN_00460748(iVar12,*(undefined4 *)(unaff_EBP + -0x10));
        if (cVar1 != '\0') break;
        iVar12 = iVar12 + 0xc;
      } while (iVar12 != *(int *)(unaff_EBP + 8));
    }
    if (*(int *)(unaff_EBP + 8) != iVar12) goto LAB_004c5c39;
    FUN_005d4956(*(undefined4 *)(iVar6 + 4));
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_004054fa(unaff_EBP + -0x34);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else {
    if (piVar4 != (int *)0x0) {
      (**(code **)*piVar4)(1);
    }
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar6 + 4);
    iVar5 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x114);
    iVar12 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x110);
    *(int *)(unaff_EBP + 8) = iVar5;
    if (iVar12 != iVar5) {
      do {
        cVar1 = FUN_00460748(iVar12,*(undefined4 *)(unaff_EBP + -0x10));
        if (cVar1 != '\0') break;
        iVar12 = iVar12 + 0xc;
      } while (iVar12 != *(int *)(unaff_EBP + 8));
    }
    if (*(int *)(unaff_EBP + 8) != iVar12) goto LAB_004c5c39;
    FUN_005d4956(*(undefined4 *)(iVar6 + 4));
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004054fa(unaff_EBP + -0x34);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_005b8770();
LAB_004c5c39:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

