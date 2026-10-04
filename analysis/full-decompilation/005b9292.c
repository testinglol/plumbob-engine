
void FUN_005b9292(void)

{
  int *piVar1;
  int local_c [2];
  
  FUN_00580a92(local_c);
  while (local_c[0] != 0) {
    piVar1 = *(int **)(local_c[0] + 0x10);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))();
      (**(code **)(*piVar1 + 0x80))(1);
    }
    FUN_005bb2f8();
  }
  FUN_005a5484();
  FUN_005bbb04();
  return;
}

