
void __thiscall FUN_00533de5(int param_1,uint *param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x14);
  uVar3 = param_2[1];
  if (((int)uVar3 < iVar2) ||
     ((((int)uVar3 <= iVar2 && (*param_2 < *(uint *)(param_1 + 0x10))) ||
      (*(uint *)(param_1 + 0x10) == 0 && iVar2 == 0)))) {
    *(uint *)(param_1 + 0x10) = *param_2;
    *(uint *)(param_1 + 0x14) = uVar3;
  }
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) + (float)param_2[2];
  fVar1 = (float)param_2[2];
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  *(float *)(param_1 + 0x1c) = fVar1 * fVar1 + *(float *)(param_1 + 0x1c);
  return;
}

