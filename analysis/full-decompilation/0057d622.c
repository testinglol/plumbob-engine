
int FUN_0057d622(void)

{
  int iVar1;
  int local_c [2];
  
  iVar1 = 0;
  FUN_00580a92(local_c);
  while (local_c[0] != 0) {
    if (iVar1 < *(int *)(local_c[0] + 8)) {
      iVar1 = *(int *)(local_c[0] + 8);
    }
    FUN_00576e56();
  }
  return iVar1;
}

