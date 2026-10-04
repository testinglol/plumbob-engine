
void FUN_004ba904(int param_1,int *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_14;
  
  if (param_3 == (int *)0x0) {
    local_14 = *(int *)(param_1 + 0x14);
    iVar3 = *(int *)(param_1 + 0x18);
    iVar2 = *(int *)(param_1 + 0x20);
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  else {
    local_14 = *param_3;
    iVar3 = param_3[1];
    iVar2 = param_3[3];
    iVar1 = param_3[2];
  }
  FUN_004ba98d((float)*param_2 / (float)(iVar1 - local_14),
               (float)param_2[1] / (float)(iVar2 - iVar3),param_1,param_3,param_4);
  return;
}

