
void FUN_00612fc0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x18);
  FUN_00583543(((int)(iVar1 * param_2 + (iVar1 * param_2 >> 0x1f & 7U)) >> 3) + param_1[2] * param_3
               + param_1[1],(int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3);
  return;
}

