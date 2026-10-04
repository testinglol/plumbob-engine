
void __thiscall FUN_004ac357(int param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = *param_3;
  bVar2 = (byte)param_4;
  if (iVar3 == 1) {
    iVar3 = 8 << (bVar2 & 0x1f);
    param_2[2] = -1;
    *param_2 = -1 - iVar3;
    iVar3 = iVar3 + 1;
    param_2[1] = 1 - *(int *)(param_1 + (0x4c - param_4) * 4);
  }
  else {
    if (iVar3 == 2) {
      *param_2 = -1;
      iVar1 = 8 << (bVar2 & 0x1f);
      param_2[2] = iVar1 + -1;
      iVar3 = *(int *)(param_1 + (0x4c - param_4) * 4);
      param_2[3] = iVar1;
      param_2[1] = -iVar3;
      goto LAB_004ac459;
    }
    if (iVar3 == 0x10) {
      iVar1 = 8 << (bVar2 & 0x1f);
      *param_2 = -1 - iVar1;
      iVar3 = 4 << (bVar2 & 0x1f);
      param_2[2] = iVar1 + -1;
      iVar1 = *(int *)(param_1 + (0x4c - param_4) * 4);
      param_2[3] = iVar3;
      param_2[1] = iVar3 - iVar1;
      goto LAB_004ac459;
    }
    if (iVar3 == 0x20) {
      iVar3 = 8 >> (3 - bVar2 & 0x1f);
      param_2[2] = iVar3;
      *param_2 = -iVar3;
      param_2[1] = -*(int *)(param_1 + (0x4c - param_4) * 4);
      param_2[3] = 8 << (bVar2 & 0x1f);
      goto LAB_004ac459;
    }
    iVar3 = 0;
    *param_2 = 0;
    param_2[2] = 0;
    param_2[1] = 0;
  }
  param_2[3] = iVar3;
LAB_004ac459:
  param_2[1] = param_2[1] + (-1 << (bVar2 & 0x1f));
  return;
}

