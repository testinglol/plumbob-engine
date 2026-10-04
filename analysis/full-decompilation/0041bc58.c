
int FUN_0041bc58(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_14 [2];
  int local_c [2];
  
  iVar2 = 0;
  FUN_00575b11(local_14,&param_1);
  if (local_14[0] != 0) {
    FUN_00580a92(local_c);
    iVar1 = 1;
    if (local_c[0] != 0) {
      do {
        if (iVar1 == param_2) break;
        FUN_0041ddb4();
        iVar1 = iVar1 + 1;
      } while (local_c[0] != 0);
      if ((local_c[0] != 0) && (iVar1 == param_2)) {
        iVar2 = local_c[0] + 7;
      }
    }
  }
  return iVar2;
}

