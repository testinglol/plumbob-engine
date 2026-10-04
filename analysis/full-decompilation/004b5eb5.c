
bool __thiscall FUN_004b5eb5(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  
  if (((int)param_3 < 0) || ((uint)(param_1[1] - *param_1 >> 2) <= param_3)) {
    bVar2 = false;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1[param_4 * 3] + param_3 * 4) + 4);
    iVar3 = FUN_00636bef(param_2);
    bVar2 = iVar3 <= iVar1;
  }
  return bVar2;
}

