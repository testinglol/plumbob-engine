
undefined4 FUN_005ec94a(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  if ((char)piVar1[0x57] == '\0') {
    iVar3 = *piVar1;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    (**(code **)(iVar3 + 0x14))(unaff_EBP + -0x14);
    cVar2 = *(char *)(unaff_EBP + 0x1c);
    piVar1[6] = *(int *)(unaff_EBP + 0xc);
    iVar3 = *(int *)(unaff_EBP + 0x10);
    piVar1[3] = 0x6c;
    piVar1[5] = iVar3;
    piVar1[4] = 7;
    if (cVar2 == '\0') {
      piVar1[0x1d] = 0x2014;
    }
    else {
      piVar1[0x1d] = 0x2030;
    }
    if ((*(int *)(unaff_EBP + 0x18) == 0) || (DAT_006fe914 != '\0')) {
      *(byte *)((int)piVar1 + 0x75) = *(byte *)((int)piVar1 + 0x75) | 8;
LAB_005eca2b:
      *(undefined1 *)((int)piVar1 + 0x15d) = 0;
      (**(code **)(*DAT_006fe8bc + 0x1c))();
      iVar3 = FUN_005eff44(piVar1,0,0);
      if (iVar3 != 0) {
        *(int *)(unaff_EBP + -0x20) = iVar3;
        *(undefined4 *)(unaff_EBP + -4) = 2;
        *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_00675034;
        (*(code *)PTR_FUN_00675038)(0);
        *(undefined4 *)(unaff_EBP + -4) = 3;
        (**(code **)(*(int *)(unaff_EBP + -0x24) + 0x10))();
        piVar1[1] = 0;
        goto LAB_005eca95;
      }
    }
    else {
      *(byte *)((int)piVar1 + 0x75) = *(byte *)((int)piVar1 + 0x75) | 0x40;
      *(undefined1 *)((int)piVar1 + 0x15d) = 1;
      (**(code **)(*DAT_006fe8bc + 0x1c))();
      iVar3 = FUN_005eff44(piVar1,0,0);
      if (iVar3 != 0) {
        *(int *)(unaff_EBP + -0x14) = iVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
        (*(code *)PTR_FUN_00675038)(0);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (*(int *)(unaff_EBP + 0x18) == 1) goto LAB_005eca95;
        piVar1[0x1d] = piVar1[0x1d] & 0xffffbfffU | 0x800;
        goto LAB_005eca2b;
      }
    }
    cVar2 = (**(code **)(*piVar1 + 0x48))(*(undefined4 *)(unaff_EBP + 0x14),piVar1 + 0x15);
    if (cVar2 != '\0') {
      *(undefined1 *)(piVar1 + 0x57) = 1;
      uVar4 = 1;
      goto LAB_005ecaa2;
    }
  }
LAB_005eca95:
  uVar4 = 0;
LAB_005ecaa2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

