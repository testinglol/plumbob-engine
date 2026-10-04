
void FUN_00476bf8(void)

{
  int *piVar1;
  
  for (piVar1 = DAT_006e54b0; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    (**(code **)(*piVar1 + 0x48))();
  }
  return;
}

