
int FUN_0041bc05(undefined4 param_1,int param_2)

{
  int local_14 [2];
  int local_c [2];
  
  FUN_00575b11(local_14,&param_1);
  if (local_14[0] != 0) {
    FUN_00580a92(local_c);
    while (local_c[0] != 0) {
      if (param_2 == *(short *)(local_c[0] + 0xd)) {
        return local_c[0] + 7;
      }
      FUN_0041ddb4();
    }
  }
  return 0;
}

