
undefined1 FUN_005ec357(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  
  FUN_00634c24();
  *(uint *)(unaff_EBP + -0x14) = (uint)((char)extraout_ECX[0x1f] != '\0');
  piVar4 = operator_new(0x188);
  *(int **)(unaff_EBP + -0x20) = piVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    FUN_00604cd2();
    piVar4[0x61] = 0;
    *piVar4 = (int)&PTR_FUN_00674fd4;
  }
  uVar6 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x26] = (int)piVar4;
  piVar1 = extraout_ECX + 2;
  cVar2 = (**(code **)(*piVar4 + 0x58))(piVar1,uVar6);
  if ((cVar2 != '\0') &&
     (((*piVar1 != 3 && (*piVar1 != 2)) ||
      (cVar2 = (**(code **)(*extraout_ECX + 0x124))(), cVar2 != '\0')))) {
    cVar2 = (**(code **)(*(int *)(extraout_ECX[0x1e] + 0x48) + 0x18))();
    if (cVar2 == '\0') {
      (**(code **)(*DAT_006fe8bc + 0x1c))();
      cVar2 = (**(code **)(*(int *)extraout_ECX[0x26] + 0x44))(DAT_006fe8cc);
      if (cVar2 == '\0') goto LAB_005ec7fb;
    }
    if (DAT_006fea78 == '\0') {
      _memset(&DAT_006fea58,0,0x20);
      DAT_006fea58 = 0x20;
    }
    piVar4 = *(int **)(extraout_ECX[0x26] + 8);
    if (piVar4 == (int *)0x0) {
      piVar4 = *(int **)(extraout_ECX[0x26] + 4);
      puVar14 = &DAT_006fea58;
      (**(code **)(*piVar4 + 0x54))(piVar4,&DAT_006fea58);
    }
    else {
      puVar14 = &DAT_006fea58;
      (**(code **)(*piVar4 + 0x54))(piVar4,&DAT_006fea58);
    }
    DAT_006fea78 = '\x01';
    *(int *)(unaff_EBP + -0x28) = extraout_ECX[0x26];
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    FUN_005ece44(unaff_EBP + -0x2c);
    uVar13 = 0;
    uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
    uVar10 = 0;
    iVar9 = extraout_ECX[3];
    uVar5 = (**(code **)(*extraout_ECX + 0x108))(*piVar1,iVar9,0,uVar6,0);
    uVar5 = (**(code **)(*extraout_ECX + 0x104))(uVar5);
    uVar3 = FUN_005e278c(uVar5,iVar9,uVar10,uVar6,uVar13,piVar4,puVar14);
    *(undefined1 *)(unaff_EBP + -0xe) = uVar3;
    if (*(char *)(unaff_EBP + 8) != '\0') {
      puVar14 = operator_new(0x188);
      *(undefined4 **)(unaff_EBP + -0x20) = puVar14;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (puVar14 == (undefined4 *)0x0) {
        puVar14 = (undefined4 *)0x0;
      }
      else {
        FUN_00604cd2();
        puVar14[0x61] = 0;
        *puVar14 = &PTR_FUN_00673ce8;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x2a] = (int)puVar14;
      uVar3 = DAT_006fe914;
      if (puVar14 != (undefined4 *)0x0) {
        DAT_006fe914 = 0;
        *(undefined1 *)(unaff_EBP + -0xd) = uVar3;
        iVar9 = *(int *)extraout_ECX[0x2a];
        uVar6 = (**(code **)(*extraout_ECX + 0x108))(extraout_ECX + 2,1,0);
        uVar6 = (**(code **)(*extraout_ECX + 0x104))(uVar6);
        cVar2 = (**(code **)(iVar9 + 0x34))(uVar6);
        DAT_006fe914 = *(undefined1 *)(unaff_EBP + -0xd);
        if (cVar2 == '\0') goto LAB_005ec7fb;
      }
    }
    if (*(char *)(unaff_EBP + -0xe) != '\0') {
LAB_005ec582:
      *(int *)(unaff_EBP + -0x28) = extraout_ECX[0x12];
      *(undefined4 *)(unaff_EBP + -0x2c) = 1;
      FUN_005ece44(unaff_EBP + -0x2c);
      uVar8 = extraout_ECX[0x21];
      *(undefined4 *)(unaff_EBP + -0x20) = 2;
      if (1 < uVar8) {
        do {
          piVar4 = operator_new(0x188);
          *(int **)(unaff_EBP + -0x1c) = piVar4;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (piVar4 == (int *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            FUN_00604cd2();
            piVar4[0x61] = 0;
            *piVar4 = (int)&PTR_FUN_00673ce8;
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(int **)(unaff_EBP + -0x18) = piVar4;
          iVar9 = *piVar4;
          uVar6 = (**(code **)(*extraout_ECX + 0x108))
                            (extraout_ECX + 2,*(undefined4 *)(unaff_EBP + -0x14),0);
          uVar6 = (**(code **)(*extraout_ECX + 0x104))(uVar6);
          cVar2 = (**(code **)(iVar9 + 0x34))(uVar6);
          if (cVar2 == '\0') {
            iVar9 = *extraout_ECX;
            if (*(int *)(unaff_EBP + -0x14) != 1) goto LAB_005ec7ff;
            (**(code **)(iVar9 + 0x130))();
            uVar6 = *(undefined4 *)(unaff_EBP + 8);
            *(undefined1 *)(extraout_ECX + 0x1f) = 0;
            uVar3 = (**(code **)(*extraout_ECX + 300))(uVar6);
            goto LAB_005ec80b;
          }
          iVar9 = *(int *)(unaff_EBP + -0x20);
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
          *(int *)(unaff_EBP + -0x2c) = iVar9;
          FUN_005ece44(unaff_EBP + -0x2c);
          uVar7 = iVar9 + 1;
          uVar8 = extraout_ECX[0x21];
          *(uint *)(unaff_EBP + -0x20) = uVar7;
        } while (uVar7 <= uVar8);
      }
      if (*(int *)(unaff_EBP + -0x14) == 1) {
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0x40;
        *(undefined4 *)(unaff_EBP + -0x20) = 0x40;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        do {
          piVar4 = operator_new(0x188);
          *(int **)(unaff_EBP + -0x24) = piVar4;
          *(undefined1 *)(unaff_EBP + -4) = 4;
          if (piVar4 == (int *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            FUN_00604cd2();
            piVar4[0x61] = 0;
            *piVar4 = (int)&PTR_FUN_00673ce8;
          }
          *(int **)(unaff_EBP + -0x30) = piVar4;
          iVar9 = *piVar4;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          cVar2 = (**(code **)(iVar9 + 0x34))
                            (*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x20),
                             extraout_ECX + 2,1,1);
          if (cVar2 == '\0') {
            if (*(undefined4 **)(unaff_EBP + -0x30) != (undefined4 *)0x0) {
              (**(code **)**(undefined4 **)(unaff_EBP + -0x30))(1);
            }
            break;
          }
          FUN_005ece44(unaff_EBP + -0x34);
          *(int *)(unaff_EBP + -0x14) =
               *(int *)(unaff_EBP + -0x14) +
               ((uint)extraout_ECX[3] >> 3) * *(int *)(unaff_EBP + -0x20) *
               *(int *)(unaff_EBP + -0x1c);
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
          if (*(int *)(unaff_EBP + -0x18) == 8) {
            *(undefined4 *)(unaff_EBP + -0x1c) = 0x80;
            *(undefined4 *)(unaff_EBP + -0x20) = 0x80;
          }
        } while (*(uint *)(unaff_EBP + -0x14) <= (uint)extraout_ECX[0x20]);
        uVar8 = 0;
        if (*(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x40) >> 3 != 0) {
          do {
            (**(code **)(**(int **)(*(int *)(unaff_EBP + -0x40) + 4 + uVar8 * 8) + 4))();
            puVar14 = *(undefined4 **)(*(int *)(unaff_EBP + -0x40) + 4 + uVar8 * 8);
            if (puVar14 != (undefined4 *)0x0) {
              (**(code **)*puVar14)(1);
            }
            uVar8 = uVar8 + 1;
            *(undefined4 *)(*(int *)(unaff_EBP + -0x40) + -4 + uVar8 * 8) = 0;
          } while (uVar8 < (uint)(*(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x40) >> 3));
        }
        if (*(uint *)(unaff_EBP + -0x14) <= (uint)extraout_ECX[0x20]) {
          (**(code **)(*extraout_ECX + 0x130))();
          uVar6 = *(undefined4 *)(unaff_EBP + 8);
          *(undefined1 *)(extraout_ECX + 0x1f) = 0;
          uVar3 = (**(code **)(*extraout_ECX + 300))(uVar6);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_00542b02();
          goto LAB_005ec80b;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00542b02();
      }
      uVar8 = 2;
      if (1 < (uint)extraout_ECX[0x21]) {
        do {
          cVar2 = (**(code **)(**(int **)(extraout_ECX[0x27] + 0xc) + 0x24))
                            (*(undefined4 *)(extraout_ECX[0x27] + 4 + uVar8 * 8));
          if (cVar2 == '\0') goto LAB_005ec7fb;
          uVar8 = uVar8 + 1;
        } while (uVar8 <= (uint)extraout_ECX[0x21]);
      }
      for (iVar9 = extraout_ECX[0x21]; iVar9 != 0; iVar9 = iVar9 + -1) {
        cVar2 = (**(code **)(*extraout_ECX + 0x100))(iVar9);
        if (cVar2 == '\0') goto LAB_005ec7fb;
      }
      uVar3 = 1;
      goto LAB_005ec80b;
    }
    if (*(int *)(unaff_EBP + -0x14) == 1) {
      iVar9 = *extraout_ECX;
      uVar15 = 0;
      uVar13 = 0;
      uVar10 = 0;
      iVar12 = extraout_ECX[3];
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      iVar11 = extraout_ECX[2];
      uVar6 = (**(code **)(iVar9 + 0x108))(iVar11,iVar12,0,0,0);
      uVar5 = (**(code **)(*extraout_ECX + 0x104))(uVar6);
      cVar2 = FUN_005e278c(uVar5,uVar6,iVar11,iVar12,uVar10,uVar13,uVar15);
      if (cVar2 != '\0') goto LAB_005ec582;
    }
  }
LAB_005ec7fb:
  iVar9 = *extraout_ECX;
LAB_005ec7ff:
  (**(code **)(iVar9 + 0x130))();
  uVar3 = 0;
LAB_005ec80b:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

