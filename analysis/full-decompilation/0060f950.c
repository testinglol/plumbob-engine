
void FUN_0060f950(int *param_1,int param_2,int param_3,undefined4 *param_4,undefined1 *param_5)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if (-1 < param_2) {
    iVar2 = *param_1;
    if (((param_2 < *(int *)(iVar2 + 0x10)) && (-1 < param_3)) && (param_3 < *(int *)(iVar2 + 0x14))
       ) {
      param_2 = *(int *)(iVar2 + 0x18) * param_2;
      puVar3 = (undefined1 *)
               (((int)(param_2 + (param_2 >> 0x1f & 7U)) >> 3) + param_1[2] * param_3 + param_1[1]);
      param_5[3] = puVar3[3];
      param_5[2] = puVar3[2];
      uVar1 = *puVar3;
      param_5[1] = puVar3[1];
      *param_5 = uVar1;
      *param_4 = 1;
      return;
    }
  }
  param_5[3] = 0;
  param_5[2] = 0;
  param_5[1] = 0;
  *param_5 = 0;
  *param_4 = 0;
  return;
}

