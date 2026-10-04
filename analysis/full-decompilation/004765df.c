
void FUN_004765df(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = FUN_00476603(param_1);
  piVar2 = (int *)FUN_00476615(uVar1);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x160))(param_2);
  }
  return;
}

