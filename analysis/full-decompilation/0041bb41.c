
int FUN_0041bb41(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int local_14 [2];
  int local_c [2];
  
  FUN_00575b11(local_14,&param_1);
  if (local_14[0] != 0) {
    FUN_00580a92(local_c);
    while (local_c[0] != 0) {
      iVar1 = local_c[0] + 7;
      iVar2 = FUN_0046f973(param_2);
      if (iVar2 == 0) {
        return iVar1;
      }
      FUN_0041ddb4();
    }
  }
  return 0;
}

