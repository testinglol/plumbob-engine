
undefined4 FUN_005fabab(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  
  cVar2 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar2 == '\0') {
    uVar3 = 1;
  }
  else {
    piVar1 = *(int **)(DAT_006fed78 + 0x38);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x44))(piVar1);
    }
    uVar3 = FUN_005f95ef(param_1,param_2,param_3);
  }
  return uVar3;
}

