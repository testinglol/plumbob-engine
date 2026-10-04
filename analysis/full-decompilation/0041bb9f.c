
int FUN_0041bb9f(int param_1,undefined4 *param_2)

{
  int local_14 [2];
  int local_c [2];
  
  FUN_00580a92(local_c);
  do {
    if (local_c[0] == 0) {
      *param_2 = 0;
      return 0;
    }
    FUN_00580a92(local_14);
    while (local_14[0] != 0) {
      if (*(int *)(local_14[0] + 0xf) == param_1) {
        *param_2 = *(undefined4 *)(local_c[0] + 4);
        return local_14[0] + 7;
      }
      FUN_0041ddb4();
    }
    FUN_00576e56();
  } while( true );
}

