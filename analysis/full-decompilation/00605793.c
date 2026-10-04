
void FUN_00605793(void)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x184) != 0) {
    piVar1 = *(int **)(extraout_ECX + 8);
    if (piVar1 == (int *)0x0) {
      piVar1 = *(int **)(extraout_ECX + 4);
    }
    iVar2 = (**(code **)(*piVar1 + 0x70))(piVar1,0);
    if (iVar2 != 0) {
      *(int *)(unaff_EBP + -0x14) = iVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
      (*(code *)PTR_FUN_00675038)(0);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_0067504c;
    }
    (**(code **)(**(int **)(extraout_ECX + 0x184) + 8))(*(int **)(extraout_ECX + 0x184));
  }
  FUN_00604d8c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

