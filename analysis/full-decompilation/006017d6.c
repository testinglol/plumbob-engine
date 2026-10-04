
undefined1 FUN_006017d6(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int extraout_ECX;
  undefined1 uVar4;
  int unaff_EBP;
  int *piStack_18;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 8);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 8);
  piStack_18 = (int *)0x6017fc;
  (**(code **)(iVar1 + 4))();
  piVar2 = *(int **)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piStack_18 = (int *)*piVar2;
  if (piStack_18 != piVar2) {
    piVar3 = *(int **)(unaff_EBP + 8);
    do {
      if ((((piStack_18[2] == *piVar3) && (piStack_18[3] == piVar3[1])) &&
          (piStack_18[4] == piVar3[2])) && (piStack_18[5] == piVar3[3])) {
        *(int ***)(unaff_EBP + 8) = &piStack_18;
        FUN_00602846(unaff_EBP + 8);
        uVar4 = 1;
        goto LAB_0060184d;
      }
      piStack_18 = (int *)*piStack_18;
    } while (piStack_18 != piVar2);
  }
  uVar4 = 0;
LAB_0060184d:
  iVar1 = *(int *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piStack_18 = (int *)0x601858;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

