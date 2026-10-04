
void FUN_004a08bd(void)

{
  char cVar1;
  short sVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 8);
  iVar7 = *(int *)(extraout_ECX + 0x128);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar5 + 4);
  iVar8 = *(int *)(extraout_ECX + 300);
  *(int *)(unaff_EBP + 8) = iVar8;
  if (iVar7 != iVar8) {
    do {
      cVar1 = FUN_00460748(iVar7,*(undefined4 *)(unaff_EBP + -0x10));
      if (cVar1 != '\0') break;
      iVar7 = iVar7 + 0xc;
    } while (iVar7 != *(int *)(unaff_EBP + 8));
  }
  if (*(int *)(unaff_EBP + 8) != iVar7) goto LAB_004a0ca8;
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
  iVar7 = (**(code **)(*piVar4 + 0xc))(iVar5,0);
  piVar4 = *(int **)(unaff_EBP + -0x18);
  if (iVar7 == 0) {
    sVar2 = (**(code **)(*piVar4 + 0x34))(0x53505232);
    iVar7 = 1;
    *(int *)(unaff_EBP + -0x20) = (int)sVar2 / 3;
    if (0 < (int)sVar2 / 3) {
      do {
        cVar1 = FUN_004a1c36(unaff_EBP + 10);
        if (cVar1 == '\0') {
          *(undefined4 *)(unaff_EBP + -0x1c) = 0xffff;
        }
        else {
          *(uint *)(unaff_EBP + -0x1c) = (uint)*(ushort *)(unaff_EBP + 10);
        }
        if (*(int *)(unaff_EBP + -0x1c) == 0xffff) break;
        piVar4 = (int *)0x0;
        iVar5 = (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x38))(0x53505232,iVar7,0);
        *(int *)(unaff_EBP + -0x10) = iVar5;
        if (iVar5 != 0) {
          pvVar3 = operator_new(0x30);
          *(void **)(unaff_EBP + -0x3c) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 3;
          if (pvVar3 != (void *)0x0) {
            piVar4 = (int *)FUN_004a0873();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_0046f824(unaff_EBP + -0xf0,0,0x40);
          *(undefined ***)(unaff_EBP + -0xfc) = &PTR_FUN_0066651c;
          (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x48))
                    (*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0xfc);
          FUN_0049ff0e(unaff_EBP + -0xfc);
          iVar5 = *(int *)(extraout_ECX + 0x28);
          iVar8 = *(int *)(extraout_ECX + 0x24);
          piVar4[1] = iVar7;
          *piVar4 = iVar5 - iVar8 >> 3;
          piVar4[3] = iVar7 + 0x200;
          piVar4[2] = iVar7 + 0x100;
          piVar4[4] = *(int *)(extraout_ECX + 0x114);
          iVar5 = (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x38))(0x53545223,0,FUN_00470449);
          *(int *)(unaff_EBP + -0x10) = iVar5;
          if (iVar5 != 0) {
            (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x50))
                      (*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x30);
            FUN_00465a06(*(undefined4 *)(unaff_EBP + -0x10));
            FUN_0046fca5();
            *(undefined ***)(unaff_EBP + -0xb0) = &PTR_FUN_0066643c;
            *(undefined4 *)(unaff_EBP + -4) = 4;
            FUN_0047034e(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x30),
                         0x53545223,0,0xffffffff);
            FUN_0046ffa4(0,1);
            iVar5 = FUN_004705f2(1,0xffffffff);
            if (iVar5 == 0) {
              FUN_005d4bbf(&DAT_006de560);
            }
            else {
              uVar6 = FUN_004705f2(1,0xffffffff);
              FUN_005d49b7(uVar6);
            }
            iVar5 = FUN_004705f2(2,0xffffffff);
            if (iVar5 != 0) {
              uVar6 = FUN_004705f2(2,0xffffffff);
              iVar5 = FUN_00635f62(uVar6);
              piVar4[4] = iVar5;
            }
            iVar5 = FUN_004705f2(3,0xffffffff);
            if (iVar5 == 0) {
              FUN_005d4bbf(&DAT_006de560);
            }
            else {
              uVar6 = FUN_004705f2(3,0xffffffff);
              FUN_005d49b7(uVar6);
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_00470467();
          }
          *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x1c);
          *(int **)(unaff_EBP + -0x34) = piVar4;
          FUN_004c662a(unaff_EBP + -0x44,unaff_EBP + -0x38);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 <= *(int *)(unaff_EBP + -0x20));
      pvVar3 = operator_new(0x28);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 5;
      if (pvVar3 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_004c71c6(*(undefined4 *)(unaff_EBP + -0x18));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
      FUN_004a1711(unaff_EBP + -0x18);
      goto LAB_004a0ca8;
    }
    (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x18))();
    if (*(undefined4 **)(unaff_EBP + -0x18) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_EBP + -0x18))(1);
    }
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar5 + 4);
    iVar7 = *(int *)(extraout_ECX + 0x120);
    iVar8 = *(int *)(extraout_ECX + 0x11c);
    *(int *)(unaff_EBP + 8) = iVar7;
    if (iVar8 != iVar7) {
      do {
        cVar1 = FUN_00460748(iVar8,*(undefined4 *)(unaff_EBP + -0x10));
        if (cVar1 != '\0') break;
        iVar8 = iVar8 + 0xc;
      } while (iVar8 != *(int *)(unaff_EBP + 8));
    }
    if (*(int *)(unaff_EBP + 8) != iVar8) goto LAB_004a0ca8;
    FUN_005d4956(*(undefined4 *)(iVar5 + 4));
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_004054fa(unaff_EBP + -0x2c);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else {
    if (piVar4 != (int *)0x0) {
      (**(code **)*piVar4)(1);
    }
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar5 + 4);
    iVar7 = *(int *)(extraout_ECX + 0x120);
    iVar8 = *(int *)(extraout_ECX + 0x11c);
    *(int *)(unaff_EBP + 8) = iVar7;
    if (iVar8 != iVar7) {
      do {
        cVar1 = FUN_00460748(iVar8,*(undefined4 *)(unaff_EBP + -0x10));
        if (cVar1 != '\0') break;
        iVar8 = iVar8 + 0xc;
      } while (iVar8 != *(int *)(unaff_EBP + 8));
    }
    if (*(int *)(unaff_EBP + 8) != iVar8) goto LAB_004a0ca8;
    FUN_005d4956(*(undefined4 *)(iVar5 + 4));
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004054fa(unaff_EBP + -0x2c);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_005b8770();
LAB_004a0ca8:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

