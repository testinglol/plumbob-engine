
undefined4 FUN_00604dbc(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(extraout_ECX + 8);
  if (piVar1 == (int *)0x0) {
    piVar1 = *(int **)(extraout_ECX + 4);
  }
  iVar2 = (**(code **)(*piVar1 + 0x6c))(piVar1);
  if (iVar2 == 0) {
    if (*(code **)(extraout_ECX + 0x164) != (code *)0x0) {
      (**(code **)(extraout_ECX + 0x164))
                (*(undefined4 *)(extraout_ECX + 0x168),*(undefined4 *)(extraout_ECX + 0x16c));
    }
    uVar3 = 1;
  }
  else {
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

