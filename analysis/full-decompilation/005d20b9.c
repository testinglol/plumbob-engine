
int * __thiscall FUN_005d20b9(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_5;
  
  FUN_005bfbc9(param_2[1] - *param_2 >> 1,&local_5);
  iVar1 = *param_1;
  iVar2 = (param_2[1] - *param_2 >> 1) * 2;
  FUN_00635190(iVar1,*param_2,iVar2);
  param_1[1] = iVar2 + iVar1;
  return param_1;
}

