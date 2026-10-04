
void FUN_005774b9(void)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar3;
  
  FUN_00634c24();
  iVar2 = DAT_006f63e8;
  if (*(char *)(extraout_ECX + 0x28) != '\0') {
    *(int **)(unaff_EBP + -0x10) = &DAT_006f63e8;
    *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
    (**(code **)(iVar2 + 4))();
    piVar1 = *(int **)(extraout_ECX + 0x24);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    piVar3 = (int *)*piVar1;
    if (piVar3 != piVar1) {
      do {
        (**(code **)(*(int *)piVar3[2] + 0x14))();
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)*(int *)(extraout_ECX + 0x24));
    }
    iVar2 = DAT_006f63e8;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    (**(code **)(iVar2 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

