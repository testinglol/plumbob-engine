
undefined4 FUN_00577447(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar3 = DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  *(int **)(unaff_EBP + -0x10) = &DAT_006f63e8;
  (**(code **)(iVar3 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piVar1 = (int *)(extraout_ECX + 8);
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (*(undefined4 **)(extraout_ECX + 0xc) != (undefined4 *)0x0)) {
    (**(code **)**(undefined4 **)(extraout_ECX + 0xc))(DAT_006cf0c8);
    (**(code **)(**(int **)(extraout_ECX + 0xc) + 8))(DAT_006cf0c4);
  }
  iVar3 = DAT_006f63e8;
  uVar2 = *(undefined4 *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar3 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

