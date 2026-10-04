
undefined4 FUN_005dcd25(void)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int unaff_EBP;
  int *piVar6;
  int *piStack_4c;
  int *piStack_48;
  int *piStack_44;
  int *piStack_40;
  int *piVar7;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  if (extraout_ECX[0x16] == 0) {
    if (((char)extraout_ECX[0x18] != '\0') || (*(char *)(unaff_EBP + 8) != '\0')) {
      *(undefined1 *)(unaff_EBP + -0x14) = 1;
      goto LAB_005dcd60;
    }
    *(undefined1 *)(unaff_EBP + -0x14) = 0;
LAB_005dcd66:
    if (extraout_ECX[0x2d] != 0) {
      *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)((int)extraout_ECX + 0xcd);
      goto LAB_005dcd7b;
    }
LAB_005dcee9:
    if (*(char *)(unaff_EBP + -0x14) != '\0') {
      iVar2 = extraout_ECX[0x18];
      *(undefined1 *)(extraout_ECX + 0x18) = 0;
      *(char *)((int)extraout_ECX + 0x61) = (char)iVar2;
      piStack_40 = (int *)0x5dcf0a;
      cVar1 = (**(code **)(*extraout_ECX + 0x164))();
      *(char *)(unaff_EBP + -0x14) = cVar1;
      if (cVar1 != '\0') {
        piStack_40 = (int *)0x1;
        piStack_44 = (int *)0x5dcf1d;
        cVar1 = (**(code **)(*extraout_ECX + 0x8c))();
        if ((cVar1 != '\0') && (extraout_ECX[0x10] != 0)) {
          piStack_44 = extraout_ECX + 3;
          piStack_40 = (int *)0x0;
          piStack_48 = (int *)0x5dcf35;
          (**(code **)(*extraout_ECX + 0xd4))();
        }
      }
      piStack_40 = (int *)0x8;
      piStack_44 = (int *)0x5dcf41;
      cVar1 = (**(code **)(*extraout_ECX + 0x8c))();
      if (cVar1 == '\0') {
LAB_005dcf58:
        piStack_40 = (int *)0x5dcf67;
        cVar1 = (**(code **)(*extraout_ECX + 0x8c))();
        if (cVar1 == '\0') goto LAB_005dcf8e;
      }
      else {
        piStack_40 = (int *)0x5dcf54;
        cVar1 = (**(code **)(*extraout_ECX + 0x8c))();
        if (cVar1 == '\0') goto LAB_005dcf58;
      }
      (**(code **)(*extraout_ECX + 0x168))();
      piVar6 = (int *)FUN_004b46a0();
      piStack_40 = (int *)0x5dcf8e;
      (**(code **)(*piVar6 + 0x170))();
    }
  }
  else {
    *(char *)(unaff_EBP + -0x14) = (char)extraout_ECX[0x18];
LAB_005dcd60:
    if (*(char *)(unaff_EBP + -0x14) == '\0') goto LAB_005dcd66;
LAB_005dcd7b:
    if (extraout_ECX[0x2d] == 0) goto LAB_005dcee9;
    cVar1 = (**(code **)(*extraout_ECX + 0xb4))();
    if (cVar1 != '\0') {
      piVar6 = (int *)0x0;
      iVar2 = (**(code **)(*extraout_ECX + 0x18))();
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*extraout_ECX + 0x18))();
        piVar6 = *(int **)(iVar2 + 0x5c);
      }
      if (extraout_ECX[0x34] == 0) {
        piVar7 = (int *)0x64;
        piStack_40 = (int *)0x5dcdbf;
        pvVar3 = operator_new(100);
        *(void **)(unaff_EBP + -0x18) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar3 == (void *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = (undefined4 *)FUN_005dfb13();
          piVar7 = extraout_ECX_00;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x34] = (int)puVar4;
        if (puVar4 != (undefined4 *)0x0) {
          uVar5 = *puVar4;
          piStack_40 = (int *)0x0;
          piStack_44 = (int *)0x0;
          *(int ***)(unaff_EBP + -0x18) = &piStack_4c;
          *(undefined4 *)(unaff_EBP + -0x18) = uVar5;
          piStack_4c = piVar7;
          piStack_48 = piVar7;
          FUN_00436a50(4);
          uVar5 = FUN_00551006();
          uVar5 = FUN_0050a296(uVar5);
          cVar1 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0xc))(uVar5);
          if (cVar1 != '\0') goto LAB_005dce35;
        }
        if ((undefined4 *)extraout_ECX[0x34] != (undefined4 *)0x0) {
          piStack_40 = (int *)0x5dce2b;
          (*(code *)**(undefined4 **)extraout_ECX[0x34])();
        }
        extraout_ECX[0x34] = 0;
      }
LAB_005dce35:
      if ((piVar6 != (int *)0x0) && ((int *)extraout_ECX[0x34] != (int *)0x0)) {
        piStack_40 = (int *)0x5dce4a;
        cVar1 = (**(code **)(*(int *)extraout_ECX[0x34] + 0x20))();
        if (cVar1 != '\0') {
          (**(code **)(*extraout_ECX + 0x18))();
          piStack_40 = (int *)(unaff_EBP + -0x38);
          piStack_44 = (int *)0x5dce65;
          FUN_004df599();
          piVar7 = (int *)extraout_ECX[0x34];
          piStack_40 = (int *)(unaff_EBP + -0x28);
          piStack_44 = (int *)(unaff_EBP + -0x38);
          *(int *)(unaff_EBP + -0x28) = piVar7[5];
          *(int *)(unaff_EBP + -0x24) = piVar7[6];
          *(int *)(unaff_EBP + -0x20) = piVar7[7];
          *(int *)(unaff_EBP + -0x1c) = piVar7[8];
          piStack_4c = (int *)0x5dce95;
          piStack_48 = piVar6;
          (**(code **)(*piVar7 + 0x9c))();
          piStack_4c = (int *)0x10;
          (**(code **)(*(int *)extraout_ECX[0x34] + 0x24))();
        }
      }
    }
    if (extraout_ECX[0x2d] == 0) goto LAB_005dcee9;
    if (*(char *)(unaff_EBP + -0x14) != '\0') {
      if ((extraout_ECX[0x34] != 0) && ((int *)extraout_ECX[0x16] != (int *)0x0)) {
        piStack_40 = (int *)0x5dceca;
        cVar1 = (**(code **)(*(int *)extraout_ECX[0x16] + 0x20))();
        if (cVar1 != '\0') {
          piStack_48 = (int *)extraout_ECX[0x34];
          piStack_40 = extraout_ECX + 7;
          piStack_44 = piStack_48 + 5;
          piStack_4c = (int *)0x5dcee9;
          (**(code **)(*(int *)extraout_ECX[0x16] + 0x9c))();
        }
      }
      goto LAB_005dcee9;
    }
  }
LAB_005dcf8e:
  iVar2 = FUN_0060783f();
  if (iVar2 != 0) {
    iVar2 = extraout_ECX[0xe];
    do {
      iVar2 = *(int *)(iVar2 + 4);
      piVar6 = *(int **)(iVar2 + 8);
      piStack_40 = (int *)0x5dcfb0;
      cVar1 = (**(code **)(*piVar6 + 0x8c))();
      if (cVar1 != '\0') {
        piStack_40 = (int *)0x5dcfc1;
        cVar1 = (**(code **)(*piVar6 + 0x178))();
        if (cVar1 != '\0') {
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
        }
      }
    } while (iVar2 != *(int *)extraout_ECX[0xe]);
  }
  piStack_40 = (int *)0x5dcff0;
  cVar1 = (**(code **)(*extraout_ECX + 0x17c))();
  if (cVar1 != '\0') {
    *(undefined1 *)(unaff_EBP + -0x14) = 1;
  }
  if ((*(char *)(unaff_EBP + -0x14) != '\0') && (DAT_006fe8f1 != '\0')) {
    piStack_40 = (int *)0x5dd00e;
    FUN_005de1ac();
  }
  if ((extraout_ECX[0x16] == 0) || ((int *)extraout_ECX[0x10] == (int *)0x0)) {
LAB_005dd061:
    if ((*(char *)(unaff_EBP + -0xd) != '\0') || (*(char *)(unaff_EBP + -0x14) != '\0')) {
      uVar5 = 1;
      goto LAB_005dd074;
    }
  }
  else if ((*(char *)(unaff_EBP + -0xd) != '\0') ||
          (((*(char *)(unaff_EBP + -0x14) != '\0' || (*(char *)(unaff_EBP + 8) != '\0')) ||
           (extraout_ECX[0x2d] != 0)))) {
    piStack_40 = (int *)0x5dd03c;
    piStack_44 = (int *)(**(code **)(*(int *)extraout_ECX[0x10] + 0x180))();
    if (piStack_44 != (int *)0x0) {
      piStack_40 = extraout_ECX + 0x23;
      piStack_48 = (int *)0x5dd052;
      (**(code **)(*extraout_ECX + 0xd0))();
      piStack_4c = extraout_ECX + 3;
      piStack_48 = (int *)0x0;
      (**(code **)(*extraout_ECX + 0xd4))();
    }
    goto LAB_005dd061;
  }
  uVar5 = 0;
LAB_005dd074:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

