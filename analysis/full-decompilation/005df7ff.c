
undefined4 FUN_005df7ff(void)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar4 = *(int **)(*(int *)(extraout_ECX + 0x48) + 8);
  if (piVar4 == (int *)0x0) {
    piVar4 = *(int **)(*(int *)(extraout_ECX + 0x48) + 4);
    if (piVar4 != (int *)0x0) {
      iVar2 = *piVar4;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0x20000;
      iVar2 = (**(code **)(iVar2 + 0x30))(piVar4,unaff_EBP + -0x18,unaff_EBP + -0x14);
      if ((-1 < iVar2) && (*(int *)(unaff_EBP + -0x14) != 0)) {
        pvVar3 = operator_new(100);
        *(void **)(unaff_EBP + -0x10) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar3 == (void *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)FUN_005dfb13();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int **)(extraout_ECX + 0x5c) = piVar4;
        if (piVar4 != (int *)0x0) {
          cVar1 = (**(code **)(*piVar4 + 8))(*(undefined4 *)(unaff_EBP + -0x14));
          if (cVar1 == '\0') goto LAB_005df90c;
          FUN_005e357a();
        }
        piVar4 = *(int **)(unaff_EBP + -0x14);
        goto LAB_005df902;
      }
    }
  }
  else {
    iVar2 = *piVar4;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0x20000;
    iVar2 = (**(code **)(iVar2 + 0x30))(piVar4,unaff_EBP + -0x28,unaff_EBP + -0x10);
    if ((-1 < iVar2) && (*(int *)(unaff_EBP + -0x10) != 0)) {
      pvVar3 = operator_new(100);
      *(void **)(unaff_EBP + -0x18) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_005dfb13();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int **)(extraout_ECX + 0x5c) = piVar4;
      if (piVar4 != (int *)0x0) {
        cVar1 = (**(code **)(*piVar4 + 4))(*(undefined4 *)(unaff_EBP + -0x10));
        if (cVar1 == '\0') goto LAB_005df90c;
        FUN_005e357a();
      }
      piVar4 = *(int **)(unaff_EBP + -0x10);
LAB_005df902:
      (**(code **)(*piVar4 + 8))(piVar4);
      uVar5 = 1;
      goto LAB_005df90e;
    }
  }
LAB_005df90c:
  uVar5 = 0;
LAB_005df90e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

