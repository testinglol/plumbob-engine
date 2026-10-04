
int FUN_004c81b6(char *param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5,
                int *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_004aeea6();
  if (iVar1 < 1) {
    return iVar1;
  }
  FUN_004b5717(param_2);
  iVar2 = FUN_004b5ea5(param_2);
  *param_3 = (int)*param_1;
  *param_4 = (int)param_1[1];
  if (iVar1 == 2) {
    *param_5 = (int)param_1[2];
    *param_6 = (int)param_1[3];
    iVar1 = FUN_00636bef(*param_5);
    if ((iVar2 < iVar1) || (iVar1 = FUN_00636bef(*param_6), param_1 = (char *)0x2, iVar2 < iVar1)) {
      param_1 = (char *)0x1;
    }
    iVar1 = FUN_00636bef(*param_3);
    if ((iVar1 <= iVar2) && (iVar1 = FUN_00636bef(*param_4), iVar1 <= iVar2)) {
      return (int)param_1;
    }
    if (param_1 == (char *)0x2) {
      *param_3 = *param_5;
      *param_4 = *param_6;
      return 1;
    }
  }
  else {
    iVar3 = FUN_00636bef(*param_3);
    if ((iVar3 <= iVar2) && (iVar3 = FUN_00636bef(*param_4), iVar3 <= iVar2)) {
      return iVar1;
    }
  }
  return 0;
}

