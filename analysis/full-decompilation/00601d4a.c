
undefined1 FUN_00601d4a(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int extraout_ECX;
  undefined1 uVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  (**(code **)(*(int *)(extraout_ECX + 8) + 4))();
  piVar1 = *(int **)(extraout_ECX + 4);
  piVar4 = (int *)*piVar1;
  if (piVar4 != piVar1) {
    piVar2 = *(int **)(unaff_EBP + 8);
    do {
      if ((((piVar4[2] == *piVar2) && (piVar4[3] == piVar2[1])) && (piVar4[4] == piVar2[2])) &&
         (piVar4[5] == piVar2[3])) {
        uVar5 = 1;
        goto LAB_00601d9d;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != piVar1);
  }
  uVar5 = 0;
LAB_00601d9d:
  iVar3 = *(int *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar3 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

