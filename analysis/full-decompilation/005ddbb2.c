
undefined4 FUN_005ddbb2(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int unaff_EBP;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(extraout_ECX + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(extraout_ECX + 0x20);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(extraout_ECX + 0x24);
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(extraout_ECX + 0x28);
  iVar5 = *(int *)(extraout_ECX + 0x5c);
  *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(iVar5 + 0x14);
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar5 + 0x18);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar5 + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar5 + 0x20);
  iStack_40 = unaff_EBP + -0x28;
  uStack_44 = 0x5ddc13;
  FUN_005de841();
  if ((((*(int *)(unaff_EBP + -0x28) == *(int *)(extraout_ECX + 0x1c)) &&
       (*(int *)(unaff_EBP + -0x20) == *(int *)(extraout_ECX + 0x24))) &&
      (*(int *)(unaff_EBP + -0x24) == *(int *)(extraout_ECX + 0x20))) &&
     (*(int *)(unaff_EBP + -0x1c) == *(int *)(extraout_ECX + 0x28))) {
    uStack_4c = 100;
    iStack_40 = 0x5ddc49;
    pvVar2 = operator_new(100);
    *(void **)(unaff_EBP + -0x18) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005dfb13();
      uStack_4c = extraout_ECX_00;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(unaff_EBP + -0x10) = piVar3;
    if (piVar3 != (int *)0x0) {
      iVar5 = *piVar3;
      iStack_40 = 0;
      uStack_44 = 0;
      *(undefined4 **)(unaff_EBP + -0x18) = &uStack_4c;
      *(int *)(unaff_EBP + -0x18) = iVar5;
      uStack_48 = uStack_4c;
      FUN_00436a50(4);
      uVar4 = FUN_00551006();
      uVar4 = FUN_0050a296(uVar4);
      cVar1 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0xc))(uVar4);
      if (cVar1 != '\0') {
        cVar1 = (*(code *)((undefined4 *)*piVar3)[8])(0x10);
        if (cVar1 == '\0') goto LAB_005ddd95;
        (**(code **)(*piVar3 + 0x9c))
                  (*(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x5c),(int *)(extraout_ECX + 0x1c),
                   piVar3 + 5,0);
        iVar5 = *piVar3;
LAB_005ddcd0:
        (**(code **)(iVar5 + 0x24))(0x10);
        goto LAB_005ddd95;
      }
      (**(code **)*piVar3)(1);
    }
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
  else {
    if ((*(int *)(unaff_EBP + -0x20) <= *(int *)(unaff_EBP + -0x28)) ||
       (*(int *)(unaff_EBP + -0x1c) <= *(int *)(unaff_EBP + -0x24))) goto LAB_005ddd95;
    uStack_4c = 100;
    iStack_40 = 0x5ddcff;
    pvVar2 = operator_new(100);
    *(void **)(unaff_EBP + -0x18) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005dfb13();
      uStack_4c = extraout_ECX_01;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(unaff_EBP + -0x10) = piVar3;
    if (piVar3 != (int *)0x0) {
      iVar5 = *piVar3;
      iStack_40 = 0;
      uStack_44 = 0;
      *(undefined4 **)(unaff_EBP + -0x18) = &uStack_4c;
      *(int *)(unaff_EBP + -0x18) = iVar5;
      uStack_48 = uStack_4c;
      FUN_00436a50(4);
      uVar4 = FUN_004a946b();
      uVar4 = FUN_004a9465(uVar4);
      cVar1 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0xc))(uVar4);
      if (cVar1 != '\0') {
        cVar1 = (*(code *)((undefined4 *)*piVar3)[8])(0x10);
        if (cVar1 == '\0') goto LAB_005ddd95;
        (**(code **)(*piVar3 + 0x9c))
                  (*(undefined4 *)(extraout_ECX + 0x5c),unaff_EBP + -0x28,piVar3 + 5,0);
        iVar5 = *piVar3;
        goto LAB_005ddcd0;
      }
      (**(code **)*piVar3)(1);
    }
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
LAB_005ddd95:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

