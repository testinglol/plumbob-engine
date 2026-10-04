
undefined2 FUN_00421619(void)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  int *piVar10;
  
  FUN_00634c24();
  piVar10 = (int *)0x0;
  if (*(int *)(unaff_EBP + 0x14) == 0) {
    *(undefined4 *)(unaff_EBP + 0x14) = 1;
  }
  if (*(int *)(unaff_EBP + 0x10) == 0) {
LAB_00421802:
    uVar3 = 0;
  }
  else {
    uVar7 = (uint)*(short *)(unaff_EBP + 0xc);
    iVar9 = *(int *)(unaff_EBP + 8);
    piVar6 = (int *)0x0;
    if ((0 < (int)uVar7) && (uVar7 < (*(int *)(iVar9 + 0x1c) - *(int *)(iVar9 + 0x18) >> 2) + 1U)) {
      piVar6 = *(int **)(*(int *)(iVar9 + 0x18) + -4 + uVar7 * 4);
    }
    *(int **)(unaff_EBP + -0x10) = piVar6;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    if (piVar6 == (int *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x1c) = 0x80;
      *(undefined4 *)(unaff_EBP + -0x20) = 0x80;
LAB_004216e5:
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    else {
      *(int *)(unaff_EBP + -0x20) = piVar6[0x3d];
      *(int *)(unaff_EBP + -0x1c) = piVar6[0x3e];
      if (*(short *)(piVar6[0x46] + 0x14) == 0) goto LAB_004216e5;
      piVar5 = (int *)piVar6[100];
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      if (piVar5 != (int *)0x0) {
        *(int **)(unaff_EBP + -0x10) = piVar5;
        piVar6 = piVar5;
      }
    }
    iVar8 = 0;
    if (piVar6 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar6 + 0x68))();
      if (cVar1 == '\0') goto LAB_00421802;
      iVar8 = *(int *)(unaff_EBP + -0x10);
    }
    if (*(short *)(unaff_EBP + -0x14) == 0) {
      pvVar4 = operator_new(0x1cc);
      *(void **)(unaff_EBP + 0xc) = pvVar4;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar4 == (void *)0x0) {
        piVar10 = (int *)0x0;
      }
      else {
        piVar10 = (int *)FUN_00421b2e(*(undefined4 *)(unaff_EBP + 0x10),
                                      *(undefined4 *)(unaff_EBP + -0x10),0,iVar9);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      sVar2 = FUN_0044350d(piVar10,0,0);
      if (sVar2 == 0) {
LAB_004217ef:
        if (piVar10 != (int *)0x0) {
          FUN_0044127f((short)piVar10[0x3c]);
        }
        goto LAB_00421802;
      }
      if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x6c))(0);
      }
      (**(code **)(*piVar10 + 0x3c))();
      (**(code **)(*piVar10 + 0x40))(0);
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar8;
      if (iVar8 != 0) {
        while( true ) {
          pvVar4 = operator_new(0x1cc);
          *(void **)(unaff_EBP + -0x18) = pvVar4;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          if (pvVar4 == (void *)0x0) {
            piVar6 = (int *)0x0;
          }
          else {
            piVar6 = (int *)FUN_00421b2e(*(undefined4 *)(unaff_EBP + 0x10),
                                         *(undefined4 *)(unaff_EBP + -0x14),piVar10,iVar9);
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          sVar2 = FUN_0044350d(piVar6,0,0);
          if (piVar10 == (int *)0x0) {
            piVar10 = piVar6;
          }
          if (sVar2 == 0) goto LAB_004217ef;
          (**(code **)(*piVar6 + 0x3c))();
          iVar9 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0x18c);
          *(int *)(unaff_EBP + -0x14) = iVar9;
          if (iVar9 == 0) break;
          iVar9 = *(int *)(unaff_EBP + 8);
        }
        (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x6c))(0);
        if (piVar10 != (int *)0x0) {
          (**(code **)(*piVar10 + 0x40))(1);
          do {
            if (*(short *)(piVar10[0x6b] + 0xf0) == *(short *)(unaff_EBP + 0xc)) break;
            piVar10 = (int *)piVar10[99];
          } while (piVar10 != (int *)0x0);
        }
      }
      (**(code **)(*piVar10 + 0x88))();
      piVar6 = (int *)piVar10[100];
      piVar5 = piVar10;
      if (piVar6 != (int *)0x0) goto LAB_0042179d;
      while (piVar6 = piVar5, piVar6 != (int *)0x0) {
LAB_0042179d:
        piVar5 = (int *)piVar6[99];
      }
    }
    cVar1 = (**(code **)(*piVar10 + 0x54))(unaff_EBP + -0x20,*(undefined4 *)(unaff_EBP + 0x14),0,0);
    if (cVar1 != '\0') {
      (**(code **)(*piVar10 + 0x58))(unaff_EBP + -0x20,*(undefined4 *)(unaff_EBP + 0x14),0,0,1);
    }
    piVar6 = piVar10;
    piVar5 = (int *)piVar10[100];
    if ((int *)piVar10[100] != (int *)0x0) goto LAB_0042185c;
    while (piVar5 = piVar6, piVar6 != (int *)0x0) {
LAB_0042185c:
      *(byte *)(piVar5 + 0x45) = *(byte *)(piVar5 + 0x45) | 0x80;
      piVar6 = (int *)piVar5[99];
    }
    FUN_004a69f6(piVar10);
    FUN_0040766a(0xe2,(int)(short)piVar10[0x3c]);
    uVar3 = (undefined2)piVar10[0x3c];
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

