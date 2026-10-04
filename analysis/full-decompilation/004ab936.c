
void FUN_004ab936(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  
  FUN_00584808(0);
  piVar3 = (int *)FUN_00440389();
  piVar4 = (int *)*piVar3;
  if (piVar4 != (int *)piVar3[1]) {
    do {
      piVar1 = (int *)*piVar4;
      if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x28))(), cVar2 != '\0')) {
        FUN_004ab779(piVar1,param_1);
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != (int *)piVar3[1]);
  }
  FUN_00587d21(param_1);
  return;
}

