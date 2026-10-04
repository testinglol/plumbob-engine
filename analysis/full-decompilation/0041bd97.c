
void FUN_0041bd97(void)

{
  int local_14 [2];
  int local_c [2];
  
  FUN_00580a92(local_14);
  while (local_14[0] != 0) {
    FUN_00580a92(local_c);
    while (local_c[0] != 0) {
      if (*(int *)(local_c[0] + 0xf) != 0) {
        FUN_00420028(*(int *)(local_c[0] + 0xf));
      }
      FUN_0041ddb4();
    }
    FUN_00576e56();
  }
  return;
}

