
void FUN_00476b8f(undefined4 param_1)

{
  int *piVar1;
  
  for (piVar1 = DAT_006e54b0; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    (**(code **)(*piVar1 + 0x40))(param_1);
  }
  return;
}

