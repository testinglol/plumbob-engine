
void FUN_0051e3b5(void)

{
  undefined4 *puVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int *piVar7;
  int extraout_ECX;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x20) = *(int *)(extraout_ECX + 0x450) + -1;
  FUN_004e99a9();
  iVar4 = FUN_004e9744();
  if (iVar4 == 0) goto LAB_0051e9b4;
  iVar4 = FUN_00425769();
  if (iVar4 == 0) goto LAB_0051e9b4;
  iVar4 = FUN_0042a8e3();
  *(int *)(unaff_EBP + -0x14) = iVar4;
  if (iVar4 == 0) goto LAB_0051e9b4;
  iVar4 = *(int *)(extraout_ECX + 0x1b0);
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  iVar4 = *(int *)(iVar4 + 0xe0);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  if (iVar4 == 1) {
    sVar3 = FUN_0041f7a9();
    *(int *)(unaff_EBP + -0x34) = (int)sVar3;
    sVar3 = FUN_0041f7a9();
    *(int *)(unaff_EBP + -0x30) = (int)sVar3;
    sVar3 = FUN_0041f7a9();
    *(int *)(unaff_EBP + -0x2c) = (int)sVar3;
  }
  else if (*(int *)(*(int *)(extraout_ECX + 0x1b4) + 0xe0) == 1) {
    sVar3 = FUN_0041f7a9();
    *(int *)(unaff_EBP + -0x24) = (int)sVar3;
  }
  else if (*(int *)(*(int *)(extraout_ECX + 0x1ac) + 0xe0) == 1) {
    sVar3 = FUN_0041f7a9();
    *(int *)(unaff_EBP + -0x28) = (int)sVar3;
  }
  FUN_0042ed71(*(undefined4 *)(extraout_ECX + 0x434),*(undefined4 *)(extraout_ECX + 0x438));
  puVar1 = (undefined4 *)(extraout_ECX + 0x440);
  for (piVar7 = *(int **)(extraout_ECX + 0x440); piVar7 != *(int **)(extraout_ECX + 0x444);
      piVar7 = piVar7 + 1) {
    *(undefined2 *)(*piVar7 + 0x198) = 0;
    (**(code **)(*(int *)*piVar7 + 0x98))();
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 0xffffffff;
  *(undefined2 *)(unaff_EBP + -0x3c) = 1;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  if (0 < *(int *)(unaff_EBP + -0x34)) {
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x34);
    do {
      FUN_0041f69e(0,unaff_EBP + -0x10,0);
      FUN_0041f6fd(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x44);
      piVar7 = (int *)*puVar1;
      piVar2 = *(int **)(extraout_ECX + 0x444);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      for (; piVar7 != piVar2; piVar7 = piVar7 + 1) {
        if (*(int *)(*piVar7 + 0x194) == *(int *)(unaff_EBP + -0x40)) {
          iVar4 = *piVar7;
          *(int *)(unaff_EBP + -0x18) = iVar4;
          if (iVar4 != 0) goto LAB_0051e5b3;
          break;
        }
      }
      pvVar5 = operator_new(0x1bc);
      *(void **)(unaff_EBP + -0x38) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0050e555(*(undefined4 *)(extraout_ECX + 0x430),
                             *(undefined4 *)(unaff_EBP + -0x40));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
      FUN_005202aa();
      (**(code **)(**(int **)(extraout_ECX + 0x410) + 0x20))();
      (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x98))();
LAB_0051e5b3:
      FUN_005202aa();
      piVar7 = (int *)(unaff_EBP + -0x1c);
      *piVar7 = *piVar7 + -1;
      iVar4 = *piVar7;
      *(undefined2 *)(*(int *)(unaff_EBP + -0x18) + 0x198) = *(undefined2 *)(unaff_EBP + -0x3c);
    } while (iVar4 != 0);
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 0xffffffff;
  if (0 < *(int *)(unaff_EBP + -0x30)) {
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x30);
    do {
      FUN_0041f69e(4,unaff_EBP + -0x10,0);
      FUN_0041f6fd(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x44);
      piVar7 = (int *)*puVar1;
      piVar2 = *(int **)(extraout_ECX + 0x444);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      for (; piVar7 != piVar2; piVar7 = piVar7 + 1) {
        if (*(int *)(*piVar7 + 0x194) == *(int *)(unaff_EBP + -0x40)) {
          iVar4 = *piVar7;
          *(int *)(unaff_EBP + -0x18) = iVar4;
          if (iVar4 != 0) goto LAB_0051e68b;
          break;
        }
      }
      pvVar5 = operator_new(0x1bc);
      *(void **)(unaff_EBP + -0x38) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0050e555(*(undefined4 *)(extraout_ECX + 0x430),
                             *(undefined4 *)(unaff_EBP + -0x40));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
      FUN_005202aa();
      (**(code **)(**(int **)(extraout_ECX + 0x410) + 0x20))();
      (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x98))();
LAB_0051e68b:
      FUN_005202aa();
      piVar7 = (int *)(unaff_EBP + -0x1c);
      *piVar7 = *piVar7 + -1;
      iVar4 = *piVar7;
      *(undefined2 *)(*(int *)(unaff_EBP + -0x18) + 0x198) = *(undefined2 *)(unaff_EBP + -0x3c);
    } while (iVar4 != 0);
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 0xffffffff;
  if (0 < *(int *)(unaff_EBP + -0x2c)) {
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x2c);
    do {
      FUN_0041f69e(5,unaff_EBP + -0x10,0);
      FUN_0041f6fd(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x44);
      piVar7 = (int *)*puVar1;
      piVar2 = *(int **)(extraout_ECX + 0x444);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      for (; piVar7 != piVar2; piVar7 = piVar7 + 1) {
        if (*(int *)(*piVar7 + 0x194) == *(int *)(unaff_EBP + -0x40)) {
          iVar4 = *piVar7;
          *(int *)(unaff_EBP + -0x18) = iVar4;
          if (iVar4 != 0) goto LAB_0051e763;
          break;
        }
      }
      pvVar5 = operator_new(0x1bc);
      *(void **)(unaff_EBP + -0x38) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0050e555(*(undefined4 *)(extraout_ECX + 0x430),
                             *(undefined4 *)(unaff_EBP + -0x40));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
      FUN_005202aa();
      (**(code **)(**(int **)(extraout_ECX + 0x410) + 0x20))();
      (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x98))();
LAB_0051e763:
      FUN_005202aa();
      piVar7 = (int *)(unaff_EBP + -0x1c);
      *piVar7 = *piVar7 + -1;
      iVar4 = *piVar7;
      *(undefined2 *)(*(int *)(unaff_EBP + -0x18) + 0x198) = *(undefined2 *)(unaff_EBP + -0x3c);
    } while (iVar4 != 0);
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 0xffffffff;
  if (0 < *(int *)(unaff_EBP + -0x28)) {
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x28);
    do {
      FUN_0041f69e(7,unaff_EBP + -0x10,0);
      FUN_0041f6fd(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x44);
      piVar7 = (int *)*puVar1;
      piVar2 = *(int **)(extraout_ECX + 0x444);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      for (; piVar7 != piVar2; piVar7 = piVar7 + 1) {
        if (*(int *)(*piVar7 + 0x194) == *(int *)(unaff_EBP + -0x40)) {
          iVar4 = *piVar7;
          *(int *)(unaff_EBP + -0x18) = iVar4;
          if (iVar4 != 0) goto LAB_0051e83b;
          break;
        }
      }
      pvVar5 = operator_new(0x1bc);
      *(void **)(unaff_EBP + -0x38) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0050e555(*(undefined4 *)(extraout_ECX + 0x430),
                             *(undefined4 *)(unaff_EBP + -0x40));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
      FUN_005202aa();
      (**(code **)(**(int **)(extraout_ECX + 0x410) + 0x20))();
      (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x98))();
LAB_0051e83b:
      FUN_005202aa();
      piVar7 = (int *)(unaff_EBP + -0x1c);
      *piVar7 = *piVar7 + -1;
      iVar4 = *piVar7;
      *(undefined2 *)(*(int *)(unaff_EBP + -0x18) + 0x198) = *(undefined2 *)(unaff_EBP + -0x3c);
    } while (iVar4 != 0);
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 0xffffffff;
  if (0 < *(int *)(unaff_EBP + -0x24)) {
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x24);
    do {
      FUN_0041f69e(8,unaff_EBP + -0x10,0);
      FUN_0041f6fd(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x44);
      piVar7 = (int *)*puVar1;
      piVar2 = *(int **)(extraout_ECX + 0x444);
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      for (; piVar7 != piVar2; piVar7 = piVar7 + 1) {
        if (*(int *)(*piVar7 + 0x194) == *(int *)(unaff_EBP + -0x40)) {
          iVar4 = *piVar7;
          *(int *)(unaff_EBP + -0x1c) = iVar4;
          if (iVar4 != 0) goto LAB_0051e913;
          break;
        }
      }
      pvVar5 = operator_new(0x1bc);
      *(void **)(unaff_EBP + -0x38) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0050e555(*(undefined4 *)(extraout_ECX + 0x430),
                             *(undefined4 *)(unaff_EBP + -0x40));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar6;
      FUN_005202aa();
      (**(code **)(**(int **)(extraout_ECX + 0x410) + 0x20))();
      (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x98))();
LAB_0051e913:
      FUN_005202aa();
      piVar7 = (int *)(unaff_EBP + -0x18);
      *piVar7 = *piVar7 + -1;
      iVar4 = *piVar7;
      *(undefined2 *)(*(int *)(unaff_EBP + -0x1c) + 0x198) = *(undefined2 *)(unaff_EBP + -0x3c);
    } while (iVar4 != 0);
  }
  FUN_005207b0(*(undefined4 *)(extraout_ECX + 0x434),*(undefined4 *)(extraout_ECX + 0x438),
               &LAB_0051ead0);
  iVar4 = *(int *)(unaff_EBP + -0x24) + *(int *)(unaff_EBP + -0x28) + *(int *)(unaff_EBP + -0x2c) +
          *(int *)(unaff_EBP + -0x30) + *(int *)(unaff_EBP + -0x34);
  *(int *)(unaff_EBP + -0x34) = iVar4;
  *(int *)(extraout_ECX + 0x44c) = iVar4;
  FUN_00636ac8((double)*(int *)(unaff_EBP + -0x34) / (double)*(int *)(unaff_EBP + -0x20));
  iVar4 = __ftol();
  *(int *)(extraout_ECX + 0x458) = iVar4;
  if (*(int *)(extraout_ECX + 0x44c) == 0) {
    (**(code **)(**(int **)(extraout_ECX + 0x41c) + 0x98))();
    (**(code **)(**(int **)(extraout_ECX + 0x418) + 0x98))();
    goto LAB_0051e9b4;
  }
  if (iVar4 <= *(int *)(extraout_ECX + 0x454)) {
    *(int *)(extraout_ECX + 0x454) = iVar4 + -1;
  }
  if (*(int *)(extraout_ECX + 0x454) == 0) {
    (**(code **)(**(int **)(extraout_ECX + 0x418) + 0x98))();
    iVar4 = **(int **)(extraout_ECX + 0x41c);
    if (*(int *)(extraout_ECX + 0x458) == 1) goto LAB_0051e9fd;
LAB_0051ea30:
    (**(code **)(iVar4 + 0x94))();
  }
  else {
    if (*(int *)(extraout_ECX + 0x454) != iVar4 + -1) {
      (**(code **)(**(int **)(extraout_ECX + 0x418) + 0x94))();
      iVar4 = **(int **)(extraout_ECX + 0x41c);
      goto LAB_0051ea30;
    }
    (**(code **)(**(int **)(extraout_ECX + 0x418) + 0x94))();
    iVar4 = **(int **)(extraout_ECX + 0x41c);
LAB_0051e9fd:
    (**(code **)(iVar4 + 0x98))();
  }
  iVar4 = *(int *)(extraout_ECX + 0x454);
  for (iVar8 = iVar4 * *(int *)(unaff_EBP + -0x20);
      (iVar8 < (iVar4 + 1) * *(int *)(unaff_EBP + -0x20) &&
      (iVar8 != *(int *)(extraout_ECX + 0x438) - *(int *)(extraout_ECX + 0x434) >> 2));
      iVar8 = iVar8 + 1) {
    iVar4 = *(int *)(*(int *)(extraout_ECX + 0x434) + iVar8 * 4);
    FUN_004cb21d((*(int *)(iVar4 + 0x84) - *(int *)(iVar4 + 0x7c)) *
                 (iVar8 % *(int *)(unaff_EBP + -0x20)) + *(int *)(extraout_ECX + 0x420),
                 ((((*(int *)(*(int *)(extraout_ECX + 0x410) + 0x88) -
                    *(int *)(*(int *)(extraout_ECX + 0x410) + 0x80)) - *(int *)(iVar4 + 0x88)) +
                  *(int *)(iVar4 + 0x80)) - *(int *)(extraout_ECX + 0x424)) / 2 +
                 *(int *)(extraout_ECX + 0x424));
    (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x434) + iVar8 * 4) + 0x94))();
    iVar4 = *(int *)(extraout_ECX + 0x454);
  }
LAB_0051e9b4:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

