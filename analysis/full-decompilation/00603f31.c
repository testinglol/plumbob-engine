
int FUN_00603f31(void)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar3 = *(int *)(extraout_ECX + 0x5c);
  if (iVar3 == 0) {
    pvVar1 = operator_new(0x40);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_005fb408();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(extraout_ECX + 0x5c) = piVar2;
    (**(code **)(*piVar2 + 8))();
    (**(code **)**(undefined4 **)(extraout_ECX + 0x5c))();
    DAT_006fed78 = *(undefined4 *)(extraout_ECX + 0x5c);
    iVar3 = *(int *)(extraout_ECX + 0x5c);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}

