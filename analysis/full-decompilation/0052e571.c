
undefined4 FUN_0052e571(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  char *pcVar6;
  int extraout_ECX;
  int iVar7;
  int iVar8;
  int unaff_EBP;
  code *pcVar9;
  int iVar10;
  undefined *puVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  FUN_00416780();
  FUN_00416618(unaff_EBP + -0x6c);
  cVar2 = (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x20))(0x10);
  pcVar9 = wsprintfA_exref;
  if (cVar2 != '\0') {
    iVar8 = 0;
    if (*(int *)(extraout_ECX + 0xd4) != 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      do {
        if (iVar8 < 5) {
          if (iVar8 == 0) {
            iVar3 = FUN_004167a5();
LAB_0052e613:
            if (iVar3 < 0x65) {
              if (iVar3 < 0) goto LAB_0052e621;
            }
            else {
              iVar3 = 100;
            }
          }
          else {
            if (iVar8 == 1) {
              iVar3 = FUN_00416847();
              goto LAB_0052e613;
            }
            if (iVar8 == 2) {
              iVar3 = FUN_00416890();
              goto LAB_0052e613;
            }
            if (iVar8 == 3) {
              iVar3 = FUN_004168ca();
              goto LAB_0052e613;
            }
            if (iVar8 == 4) {
              iVar3 = FUN_0060b844();
              goto LAB_0052e613;
            }
LAB_0052e621:
            iVar3 = 0;
          }
          uVar12 = 0;
          iVar7 = **(int **)(extraout_ECX + 0x5c);
          iVar10 = unaff_EBP + -0xd8;
          *(int *)(unaff_EBP + -0x10) = iVar3 / 10;
          *(int *)(unaff_EBP + -0x14) = *(int *)(extraout_ECX + 0xd8) + 0x14;
          piVar5 = &DAT_006f3ee0 + iVar8 * 2;
          FUN_004df599(unaff_EBP + -0x88,extraout_ECX + 0x1c);
          uVar4 = FUN_004df599(iVar10,piVar5);
          (**(code **)(iVar7 + 0x9c))
                    (*(undefined4 *)(extraout_ECX + 0xd8),*(undefined4 *)(unaff_EBP + -0x14),uVar4,
                     uVar12);
          pcVar9 = wsprintfA_exref;
          if (0 < *(int *)(unaff_EBP + -0x10)) {
            iVar3 = *(int *)(extraout_ECX + 0xd4);
            iVar10 = *(int *)(iVar3 + 0x14);
            *(int *)(unaff_EBP + -0x40) = iVar10;
            *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(iVar3 + 0x18);
            iVar7 = *(int *)(iVar3 + 0x1c);
            *(int *)(unaff_EBP + -0x38) = iVar7;
            *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar3 + 0x20);
            iVar1 = (&DAT_006f3ee0)[iVar8 * 2];
            *(int *)(unaff_EBP + -0x14) = iVar7 - iVar10;
            iVar8 = (&DAT_006f3ee4)[iVar8 * 2] + *(int *)(extraout_ECX + 0x20);
            iVar7 = iVar1 + *(int *)(extraout_ECX + 0x1c) + iVar10;
            *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x3c) + iVar8;
            *(int *)(unaff_EBP + -0x28) = iVar7;
            *(int *)(unaff_EBP + -0x1c) = iVar8 + *(int *)(unaff_EBP + -0x34);
            iVar8 = *(int *)(unaff_EBP + -0x10) * 4;
            if (*(int *)(unaff_EBP + -0x14) < iVar8) {
              iVar8 = *(int *)(unaff_EBP + -0x14);
            }
            *(int *)(unaff_EBP + -0x38) = iVar8 + iVar10;
            piVar5 = *(int **)(extraout_ECX + 0x5c);
            *(int *)(unaff_EBP + -0x20) = iVar7 + iVar8;
            (**(code **)(*piVar5 + 0x9c))(iVar3,unaff_EBP + -0x40,unaff_EBP + -0x28,0);
            pcVar9 = wsprintfA_exref;
          }
        }
        else {
          if (iVar8 == 5) {
            uVar4 = FUN_004096c2();
            piVar5 = DAT_006fe8bc;
            *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
            piVar5 = (int *)(**(code **)(*piVar5 + 4))();
            cVar2 = (**(code **)(*piVar5 + 0x88))(0xffffffff);
            if (cVar2 != '\0') {
              uVar4 = __ftol();
              *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
            }
            pcVar6 = *(char **)(unaff_EBP + -0x10);
            puVar11 = *(undefined **)(extraout_ECX + 0x124);
LAB_0052e83a:
            (*pcVar9)(unaff_EBP + -200,puVar11,pcVar6);
          }
          else {
            if (iVar8 == 6) {
              puVar11 = *(undefined **)(extraout_ECX + 0x130);
              pcVar6 = (char *)FUN_00401f6f();
              goto LAB_0052e83a;
            }
            if (iVar8 == 7) {
              puVar11 = *(undefined **)(extraout_ECX + 0x13c);
              pcVar6 = (char *)FUN_00401f77();
              goto LAB_0052e83a;
            }
            if (iVar8 == 8) {
              iVar8 = FUN_0060b848();
              if (iVar8 == 0) {
                pcVar6 = (char *)**(undefined4 **)(extraout_ECX + 0x108);
              }
              else if (iVar8 == 1) {
                pcVar6 = *(char **)(*(int *)(extraout_ECX + 0x108) + 0xc);
              }
              else {
                if (iVar8 != 2) {
                  pcVar6 = s___Unknown___006cccb0;
                  puVar11 = &DAT_006c08e0;
                  goto LAB_0052e83a;
                }
                pcVar6 = *(char **)(*(int *)(extraout_ECX + 0x108) + 0x18);
              }
              puVar11 = *(undefined **)(extraout_ECX + 0x148);
              goto LAB_0052e83a;
            }
          }
          FUN_005d4956(unaff_EBP + -200);
          iVar8 = *(int *)(extraout_ECX + 0xdc);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          (**(code **)(**(int **)(iVar8 + *(int *)(unaff_EBP + -0x2c) * 4) + 0x9c))
                    (unaff_EBP + -0x78);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        iVar8 = *(int *)(unaff_EBP + -0x2c) + 1;
        *(int *)(unaff_EBP + -0x2c) = iVar8;
      } while (iVar8 < 9);
    }
    (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x24))(0x10);
  }
  cVar2 = FUN_004cff80();
  if (cVar2 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 5;
    *(undefined4 *)(unaff_EBP + -0x20) = 100;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x14;
    uVar4 = FUN_004e84f4(unaff_EBP + -0x88,unaff_EBP + -0x28);
    FUN_0051b33b(uVar4);
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 5;
    iVar8 = unaff_EBP + -0x30;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x28) = 5;
    *(undefined4 *)(unaff_EBP + -0x24) = 5;
    *(undefined4 *)(unaff_EBP + -0x20) = 200;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x14;
    uVar4 = FUN_004e84f4(unaff_EBP + -0x88,unaff_EBP + -0x28);
    FUN_0051b33b(uVar4);
    *(undefined4 *)(unaff_EBP + -0x18) = 0xd;
    *(undefined4 *)(unaff_EBP + -0x14) = 8;
    iVar8 = unaff_EBP + -0x18;
  }
  FUN_0051eb1f(extraout_ECX + 0x118,*(undefined4 *)(extraout_ECX + 0x5c),extraout_ECX + 0x1c,iVar8,
               0xb);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

