
int * __fastcall FUN_0043f3b9(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_14;
  int local_10;
  
  if (param_1[1] != 0) {
    iVar4 = 0;
    iVar5 = param_1[1];
    do {
      iVar1 = *(int *)(iVar5 + 0x134);
      iVar2 = *(int *)(iVar5 + 0x130);
      do {
        if ((iVar1 - iVar2) / 0x24 <= iVar4) break;
        iVar3 = FUN_004328d2(iVar4);
        iVar4 = iVar4 + 1;
        param_1[1] = iVar3;
      } while (iVar3 == 0);
      if (param_1[1] != 0) {
        return param_1;
      }
      if (iVar5 == *param_1) {
        return param_1;
      }
      FUN_004327ad(iVar5);
      iVar4 = local_10 + 1;
      iVar5 = local_14;
    } while (param_1[1] == 0);
  }
  return param_1;
}

